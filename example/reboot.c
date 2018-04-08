/* reboot.c - C source code to reboot to the bootloader.
 *
 * Copyright (C) 2018 EmbeddedEnterprises
 * Martin Koppehel <martin.koppehel@st.ovgu.de>
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#include <stdint.h>
#include "samd10.h"

void reboot_to_bootloader() {
    volatile uint32_t *ram = (volatile uint32_t*)HMCRAMC0_ADDR;
    ram[0] = ram[1] = ram[2] = ram[3] = 0xDEADBEEF;
    NVIC_SystemReset();
}
