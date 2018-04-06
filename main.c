//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "samd10.h"
#include "hal_gpio.h"

/*- Definitions -------------------------------------------------------------*/
#define I2C_BASE_ADDRESS      0x58 // 8-bit address
#define I2C_SDA_BIT           5
#define I2C_SCL_BIT           2

HAL_GPIO_PIN(RX,              A, 24);
HAL_GPIO_PIN(TX,              A, 25);
#define BL_SERCOM             SERCOM1
#define SERCOM_PMUX           HAL_GPIO_PMUX_C
#define SERCOM_GCLK_ID        SERCOM1_GCLK_ID_CORE
#define SERCOM_CLK_GEN        0
#define SERCOM_APBCMASK       PM_APBCMASK_SERCOM1
#define BAUD_RATE             57600

#define APPLICATION_START     0x400
#define PAGES_IN_ERASE_BLOCK  4
#define ERASE_BLOCK_SIZE      (FLASH_PAGE_SIZE * PAGES_IN_ERASE_BLOCK)
#define DATA_SIZE             64
#define DATA_SIZE_WORDS       (int)(DATA_SIZE / sizeof(uint32_t))
#define BL_REQUEST            0xDEADBEEF

enum
{
  BL_CMD_SOF    = 0xa0,
  BL_CMD_DATA   = 0xa1,
  BL_CMD_RESET  = 0xa2,
  BL_CMD_ACK    = 0x55,
  BL_CMD_NACK   = 0x66,
  BL_CMD_FLASH  = 0x77,
};

enum
{
  BL_STATUS_READY      = (1 << 0),
  BL_STATUS_ADDR       = (1 << 1),
  BL_STATUS_DATA       = (1 << 2),
  BL_STATUS_CRC        = (1 << 3),
  BL_STATUS_CRC_OK     = (1 << 4),
};

/*- Variables ---------------------------------------------------------------*/
static uint32_t *ram = (uint32_t *)HMCRAMC0_ADDR;
static uint8_t bl_status = BL_STATUS_READY;


static uint8_t flash_buffer[DATA_SIZE_WORDS * 4];
static uint32_t flash_addr = 0;
static uint32_t flash_crc = 0;
static uint8_t flash_offset = 0;

/*- Implementations ---------------------------------------------------------*/
//-----------------------------------------------------------------------------
static void uart_putc(char c) {
  while (!(BL_SERCOM->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_DRE));
  BL_SERCOM->USART.DATA.reg = c;
}

//-----------------------------------------------------------------------------
static void sys_init(void)
{
  uint64_t br = (uint64_t)65536 * (F_CPU - 16 * BAUD_RATE) / F_CPU;

  SYSCTRL->OSC8M.bit.PRESC = 0;
  PAC1->WPCLR.reg = PAC1->WPCLR.reg;
  PM->AHBMASK.reg |= PM_AHBMASK_NVMCTRL | PM_AHBMASK_DSU;
  PM->APBBMASK.reg |= PM_APBBMASK_NVMCTRL | PM_APBBMASK_DSU;
  NVMCTRL->CTRLB.reg = NVMCTRL_CTRLB_CACHEDIS;

  HAL_GPIO_RX_pmuxen(SERCOM_PMUX);
  HAL_GPIO_TX_pmuxen(SERCOM_PMUX);

  PM->APBCMASK.reg |= SERCOM_APBCMASK;

  GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID(SERCOM_GCLK_ID) |
      GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN(SERCOM_CLK_GEN);


  BL_SERCOM->USART.CTRLA.reg =
    SERCOM_USART_CTRLA_DORD | SERCOM_USART_CTRLA_MODE_USART_INT_CLK |
    SERCOM_USART_CTRLA_RXPO(3/*PAD3*/) | SERCOM_USART_CTRLA_TXPO(1/*PAD2*/);

  BL_SERCOM->USART.CTRLB.reg = SERCOM_USART_CTRLB_RXEN | SERCOM_USART_CTRLB_TXEN |
    SERCOM_USART_CTRLB_CHSIZE(0/*8 bits*/);
  BL_SERCOM->USART.BAUD.reg = (uint16_t)br+1;
  BL_SERCOM->USART.CTRLA.reg |= SERCOM_USART_CTRLA_ENABLE;
  uart_putc(bl_status);
}

static void uart_task(void)
{
  // Wait for complete frame.
  while(bl_status != BL_STATUS_CRC_OK) {
    // Wait until a char is available
    while(!(BL_SERCOM->USART.INTFLAG.reg & SERCOM_USART_INTFLAG_RXC));
    // Read the char
    uint8_t data = BL_SERCOM->USART.DATA.reg;
    // Process the char according to the current state
    if (bl_status == BL_STATUS_READY && data == BL_CMD_RESET) {
      ram[0] = ram[1] = ram[2] = ram[3] = 0;
      NVIC_SystemReset();
      break;
    }
    if (bl_status == BL_STATUS_READY && data == BL_CMD_SOF) {
      bl_status = BL_STATUS_ADDR;
      flash_offset = 0;
      flash_addr = 0;
      uart_putc(BL_CMD_ACK);
      continue;
    }
    if (bl_status == BL_STATUS_ADDR) {
      flash_addr |= (data << flash_offset);
      flash_offset += 8;
      if (flash_offset == 24) {
        bl_status = BL_STATUS_DATA;
        flash_offset = 0;
        uart_putc(BL_CMD_ACK);
      }
      continue;
    }
    if (bl_status == BL_STATUS_DATA) {
      flash_buffer[flash_offset++] = data;
      if (flash_offset == (DATA_SIZE_WORDS * 4) - 1) {
        bl_status = BL_STATUS_CRC;
        flash_offset = 0;
        flash_crc = 0;
        uart_putc(BL_CMD_ACK);
      }
      continue;
    }
    if (bl_status == BL_STATUS_CRC) {
      flash_crc |= (data << flash_offset);
      flash_offset += 8;
      if (flash_offset == 24) {
        bl_status = BL_STATUS_CRC_OK;
        uart_putc(BL_CMD_FLASH);
      }
    }
  }
}

//-----------------------------------------------------------------------------
static void flash_task(void)
{
  if (bl_status != BL_STATUS_CRC_OK) {
    // This should never happen. It's here for safety purposes.
    return;
  }

  uint32_t *flash_buf = (uint32_t *)flash_addr;
  NVMCTRL->ADDR.reg = flash_addr >> 1;

  if (0 == (flash_addr % ERASE_BLOCK_SIZE))
  {
    // Lock region size is always bigger than the row size
    NVMCTRL->CTRLA.reg = NVMCTRL_CTRLA_CMDEX_KEY | NVMCTRL_CTRLA_CMD_UR;
    while (0 == NVMCTRL->INTFLAG.bit.READY); // Unlocking is a fast operation

    // Erase the memory
    NVMCTRL->CTRLA.reg = NVMCTRL_CTRLA_CMDEX_KEY | NVMCTRL_CTRLA_CMD_ER;
    while (0 == NVMCTRL->INTFLAG.bit.READY);
  }

  // Reprogram memory
  for (int i = 0; i < DATA_SIZE_WORDS; i++)
    flash_buf[i] = flash_buffer[i];

  while (!NVMCTRL->INTFLAG.bit.READY);

  DSU->ADDR.reg = flash_addr;
  DSU->DATA.reg = 0xFFFFFFFF;
  DSU->LENGTH.reg = FLASH_PAGE_SIZE;
  DSU->CTRL.reg = DSU_CTRL_CRC;
  DSU->STATUSA.reg = DSU_STATUSA_DONE | DSU_STATUSA_BERR;

  while (!(DSU->STATUSA.reg & DSU_STATUSA_DONE));


  if (!(DSU->STATUSA.reg & DSU_STATUSA_BERR) && flash_crc == DSU->DATA.reg) {
    uart_putc(BL_CMD_ACK);
  } else {
    uart_putc(BL_CMD_NACK);
  }
  bl_status = BL_STATUS_READY;
}

//-----------------------------------------------------------------------------
static void run_application(void)
{
  uint32_t msp = *(uint32_t *)(APPLICATION_START);
  uint32_t reset_vector = *(uint32_t *)(APPLICATION_START + 4);

  if (0xffffffff == msp) {
    // enter the bootloader next time.
    ram[0] = ram[1] = ram[2] = ram[3] = BL_REQUEST;
    NVIC_SystemReset();
  }

  __set_MSP(msp);

  /* Rebase the vector table base address */
  SCB->VTOR = ((uint32_t) APPLICATION_START & SCB_VTOR_TBLOFF_Msk);
  asm("bx %0"::"r" (reset_vector));
}

//-----------------------------------------------------------------------------
static bool bl_request(void)
{
  /*
   * My version of the bootloader should only run when triggered via software.
   */
  return (BL_REQUEST == ram[0] && BL_REQUEST == ram[1] &&
      BL_REQUEST == ram[2] && BL_REQUEST == ram[3]);
}

//-----------------------------------------------------------------------------
int main(void)
{
  if (!bl_request())
    run_application();

  sys_init();

  while (1)
  {
    uart_task();
    flash_task();
  }

  return 0;
}
