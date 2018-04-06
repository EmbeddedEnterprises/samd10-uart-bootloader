/**
 * \file
 *
 * \brief Peripheral I/O description for SAMD10C14A
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef _SAMD10C14A_PIO_
#define _SAMD10C14A_PIO_

#define PIN_PA04                           4  /**< \brief Pin Number for PA04 */
#define PORT_PA04                  (1u <<  4) /**< \brief PORT Mask  for PA04 */
#define PIN_PA05                           5  /**< \brief Pin Number for PA05 */
#define PORT_PA05                  (1u <<  5) /**< \brief PORT Mask  for PA05 */
#define PIN_PA08                           8  /**< \brief Pin Number for PA08 */
#define PORT_PA08                  (1u <<  8) /**< \brief PORT Mask  for PA08 */
#define PIN_PA09                           9  /**< \brief Pin Number for PA09 */
#define PORT_PA09                  (1u <<  9) /**< \brief PORT Mask  for PA09 */
#define PIN_PA14                          14  /**< \brief Pin Number for PA14 */
#define PORT_PA14                  (1u << 14) /**< \brief PORT Mask  for PA14 */
#define PIN_PA15                          15  /**< \brief Pin Number for PA15 */
#define PORT_PA15                  (1u << 15) /**< \brief PORT Mask  for PA15 */
#define PIN_PA24                          24  /**< \brief Pin Number for PA24 */
#define PORT_PA24                  (1u << 24) /**< \brief PORT Mask  for PA24 */
#define PIN_PA25                          25  /**< \brief Pin Number for PA25 */
#define PORT_PA25                  (1u << 25) /**< \brief PORT Mask  for PA25 */
#define PIN_PA28                          28  /**< \brief Pin Number for PA28 */
#define PORT_PA28                  (1u << 28) /**< \brief PORT Mask  for PA28 */
#define PIN_PA30                          30  /**< \brief Pin Number for PA30 */
#define PORT_PA30                  (1u << 30) /**< \brief PORT Mask  for PA30 */
#define PIN_PA31                          31  /**< \brief Pin Number for PA31 */
#define PORT_PA31                  (1u << 31) /**< \brief PORT Mask  for PA31 */
/* ========== PORT definition for CORE peripheral ========== */
#define PIN_PA30G_CORE_SWCLK              30  /**< \brief CORE signal: SWCLK on PA30 mux G */
#define MUX_PA30G_CORE_SWCLK               6
#define PINMUX_PA30G_CORE_SWCLK    ((PIN_PA30G_CORE_SWCLK << 16) | MUX_PA30G_CORE_SWCLK)
#define PORT_PA30G_CORE_SWCLK      (1u << 30)
/* ========== PORT definition for GCLK peripheral ========== */
#define PIN_PA08H_GCLK_IO0                 8  /**< \brief GCLK signal: IO0 on PA08 mux H */
#define MUX_PA08H_GCLK_IO0                 7
#define PINMUX_PA08H_GCLK_IO0      ((PIN_PA08H_GCLK_IO0 << 16) | MUX_PA08H_GCLK_IO0)
#define PORT_PA08H_GCLK_IO0        (1u <<  8)
#define PIN_PA24H_GCLK_IO0                24  /**< \brief GCLK signal: IO0 on PA24 mux H */
#define MUX_PA24H_GCLK_IO0                 7
#define PINMUX_PA24H_GCLK_IO0      ((PIN_PA24H_GCLK_IO0 << 16) | MUX_PA24H_GCLK_IO0)
#define PORT_PA24H_GCLK_IO0        (1u << 24)
#define PIN_PA25H_GCLK_IO0                25  /**< \brief GCLK signal: IO0 on PA25 mux H */
#define MUX_PA25H_GCLK_IO0                 7
#define PINMUX_PA25H_GCLK_IO0      ((PIN_PA25H_GCLK_IO0 << 16) | MUX_PA25H_GCLK_IO0)
#define PORT_PA25H_GCLK_IO0        (1u << 25)
#define PIN_PA30H_GCLK_IO0                30  /**< \brief GCLK signal: IO0 on PA30 mux H */
#define MUX_PA30H_GCLK_IO0                 7
#define PINMUX_PA30H_GCLK_IO0      ((PIN_PA30H_GCLK_IO0 << 16) | MUX_PA30H_GCLK_IO0)
#define PORT_PA30H_GCLK_IO0        (1u << 30)
#define PIN_PA31H_GCLK_IO0                31  /**< \brief GCLK signal: IO0 on PA31 mux H */
#define MUX_PA31H_GCLK_IO0                 7
#define PINMUX_PA31H_GCLK_IO0      ((PIN_PA31H_GCLK_IO0 << 16) | MUX_PA31H_GCLK_IO0)
#define PORT_PA31H_GCLK_IO0        (1u << 31)
#define PIN_PA09H_GCLK_IO1                 9  /**< \brief GCLK signal: IO1 on PA09 mux H */
#define MUX_PA09H_GCLK_IO1                 7
#define PINMUX_PA09H_GCLK_IO1      ((PIN_PA09H_GCLK_IO1 << 16) | MUX_PA09H_GCLK_IO1)
#define PORT_PA09H_GCLK_IO1        (1u <<  9)
#define PIN_PA14H_GCLK_IO4                14  /**< \brief GCLK signal: IO4 on PA14 mux H */
#define MUX_PA14H_GCLK_IO4                 7
#define PINMUX_PA14H_GCLK_IO4      ((PIN_PA14H_GCLK_IO4 << 16) | MUX_PA14H_GCLK_IO4)
#define PORT_PA14H_GCLK_IO4        (1u << 14)
#define PIN_PA15H_GCLK_IO5                15  /**< \brief GCLK signal: IO5 on PA15 mux H */
#define MUX_PA15H_GCLK_IO5                 7
#define PINMUX_PA15H_GCLK_IO5      ((PIN_PA15H_GCLK_IO5 << 16) | MUX_PA15H_GCLK_IO5)
#define PORT_PA15H_GCLK_IO5        (1u << 15)
/* ========== PORT definition for EIC peripheral ========== */
#define PIN_PA15A_EIC_EXTINT1             15  /**< \brief EIC signal: EXTINT1 on PA15 mux A */
#define MUX_PA15A_EIC_EXTINT1              0
#define PINMUX_PA15A_EIC_EXTINT1   ((PIN_PA15A_EIC_EXTINT1 << 16) | MUX_PA15A_EIC_EXTINT1)
#define PORT_PA15A_EIC_EXTINT1     (1u << 15)
#define PIN_PA30A_EIC_EXTINT2             30  /**< \brief EIC signal: EXTINT2 on PA30 mux A */
#define MUX_PA30A_EIC_EXTINT2              0
#define PINMUX_PA30A_EIC_EXTINT2   ((PIN_PA30A_EIC_EXTINT2 << 16) | MUX_PA30A_EIC_EXTINT2)
#define PORT_PA30A_EIC_EXTINT2     (1u << 30)
#define PIN_PA31A_EIC_EXTINT3             31  /**< \brief EIC signal: EXTINT3 on PA31 mux A */
#define MUX_PA31A_EIC_EXTINT3              0
#define PINMUX_PA31A_EIC_EXTINT3   ((PIN_PA31A_EIC_EXTINT3 << 16) | MUX_PA31A_EIC_EXTINT3)
#define PORT_PA31A_EIC_EXTINT3     (1u << 31)
#define PIN_PA04A_EIC_EXTINT4              4  /**< \brief EIC signal: EXTINT4 on PA04 mux A */
#define MUX_PA04A_EIC_EXTINT4              0
#define PINMUX_PA04A_EIC_EXTINT4   ((PIN_PA04A_EIC_EXTINT4 << 16) | MUX_PA04A_EIC_EXTINT4)
#define PORT_PA04A_EIC_EXTINT4     (1u <<  4)
#define PIN_PA24A_EIC_EXTINT4             24  /**< \brief EIC signal: EXTINT4 on PA24 mux A */
#define MUX_PA24A_EIC_EXTINT4              0
#define PINMUX_PA24A_EIC_EXTINT4   ((PIN_PA24A_EIC_EXTINT4 << 16) | MUX_PA24A_EIC_EXTINT4)
#define PORT_PA24A_EIC_EXTINT4     (1u << 24)
#define PIN_PA05A_EIC_EXTINT5              5  /**< \brief EIC signal: EXTINT5 on PA05 mux A */
#define MUX_PA05A_EIC_EXTINT5              0
#define PINMUX_PA05A_EIC_EXTINT5   ((PIN_PA05A_EIC_EXTINT5 << 16) | MUX_PA05A_EIC_EXTINT5)
#define PORT_PA05A_EIC_EXTINT5     (1u <<  5)
#define PIN_PA25A_EIC_EXTINT5             25  /**< \brief EIC signal: EXTINT5 on PA25 mux A */
#define MUX_PA25A_EIC_EXTINT5              0
#define PINMUX_PA25A_EIC_EXTINT5   ((PIN_PA25A_EIC_EXTINT5 << 16) | MUX_PA25A_EIC_EXTINT5)
#define PORT_PA25A_EIC_EXTINT5     (1u << 25)
#define PIN_PA08A_EIC_EXTINT6              8  /**< \brief EIC signal: EXTINT6 on PA08 mux A */
#define MUX_PA08A_EIC_EXTINT6              0
#define PINMUX_PA08A_EIC_EXTINT6   ((PIN_PA08A_EIC_EXTINT6 << 16) | MUX_PA08A_EIC_EXTINT6)
#define PORT_PA08A_EIC_EXTINT6     (1u <<  8)
#define PIN_PA09A_EIC_EXTINT7              9  /**< \brief EIC signal: EXTINT7 on PA09 mux A */
#define MUX_PA09A_EIC_EXTINT7              0
#define PINMUX_PA09A_EIC_EXTINT7   ((PIN_PA09A_EIC_EXTINT7 << 16) | MUX_PA09A_EIC_EXTINT7)
#define PORT_PA09A_EIC_EXTINT7     (1u <<  9)
#define PIN_PA14A_EIC_NMI                 14  /**< \brief EIC signal: NMI on PA14 mux A */
#define MUX_PA14A_EIC_NMI                  0
#define PINMUX_PA14A_EIC_NMI       ((PIN_PA14A_EIC_NMI << 16) | MUX_PA14A_EIC_NMI)
#define PORT_PA14A_EIC_NMI         (1u << 14)
/* ========== PORT definition for SERCOM0 peripheral ========== */
#define PIN_PA04D_SERCOM0_PAD0             4  /**< \brief SERCOM0 signal: PAD0 on PA04 mux D */
#define MUX_PA04D_SERCOM0_PAD0             3
#define PINMUX_PA04D_SERCOM0_PAD0  ((PIN_PA04D_SERCOM0_PAD0 << 16) | MUX_PA04D_SERCOM0_PAD0)
#define PORT_PA04D_SERCOM0_PAD0    (1u <<  4)
#define PIN_PA14C_SERCOM0_PAD0            14  /**< \brief SERCOM0 signal: PAD0 on PA14 mux C */
#define MUX_PA14C_SERCOM0_PAD0             2
#define PINMUX_PA14C_SERCOM0_PAD0  ((PIN_PA14C_SERCOM0_PAD0 << 16) | MUX_PA14C_SERCOM0_PAD0)
#define PORT_PA14C_SERCOM0_PAD0    (1u << 14)
#define PIN_PA05D_SERCOM0_PAD1             5  /**< \brief SERCOM0 signal: PAD1 on PA05 mux D */
#define MUX_PA05D_SERCOM0_PAD1             3
#define PINMUX_PA05D_SERCOM0_PAD1  ((PIN_PA05D_SERCOM0_PAD1 << 16) | MUX_PA05D_SERCOM0_PAD1)
#define PORT_PA05D_SERCOM0_PAD1    (1u <<  5)
#define PIN_PA15C_SERCOM0_PAD1            15  /**< \brief SERCOM0 signal: PAD1 on PA15 mux C */
#define MUX_PA15C_SERCOM0_PAD1             2
#define PINMUX_PA15C_SERCOM0_PAD1  ((PIN_PA15C_SERCOM0_PAD1 << 16) | MUX_PA15C_SERCOM0_PAD1)
#define PORT_PA15C_SERCOM0_PAD1    (1u << 15)
#define PIN_PA08D_SERCOM0_PAD2             8  /**< \brief SERCOM0 signal: PAD2 on PA08 mux D */
#define MUX_PA08D_SERCOM0_PAD2             3
#define PINMUX_PA08D_SERCOM0_PAD2  ((PIN_PA08D_SERCOM0_PAD2 << 16) | MUX_PA08D_SERCOM0_PAD2)
#define PORT_PA08D_SERCOM0_PAD2    (1u <<  8)
#define PIN_PA04C_SERCOM0_PAD2             4  /**< \brief SERCOM0 signal: PAD2 on PA04 mux C */
#define MUX_PA04C_SERCOM0_PAD2             2
#define PINMUX_PA04C_SERCOM0_PAD2  ((PIN_PA04C_SERCOM0_PAD2 << 16) | MUX_PA04C_SERCOM0_PAD2)
#define PORT_PA04C_SERCOM0_PAD2    (1u <<  4)
#define PIN_PA09D_SERCOM0_PAD3             9  /**< \brief SERCOM0 signal: PAD3 on PA09 mux D */
#define MUX_PA09D_SERCOM0_PAD3             3
#define PINMUX_PA09D_SERCOM0_PAD3  ((PIN_PA09D_SERCOM0_PAD3 << 16) | MUX_PA09D_SERCOM0_PAD3)
#define PORT_PA09D_SERCOM0_PAD3    (1u <<  9)
#define PIN_PA05C_SERCOM0_PAD3             5  /**< \brief SERCOM0 signal: PAD3 on PA05 mux C */
#define MUX_PA05C_SERCOM0_PAD3             2
#define PINMUX_PA05C_SERCOM0_PAD3  ((PIN_PA05C_SERCOM0_PAD3 << 16) | MUX_PA05C_SERCOM0_PAD3)
#define PORT_PA05C_SERCOM0_PAD3    (1u <<  5)
/* ========== PORT definition for SERCOM1 peripheral ========== */
#define PIN_PA30C_SERCOM1_PAD0            30  /**< \brief SERCOM1 signal: PAD0 on PA30 mux C */
#define MUX_PA30C_SERCOM1_PAD0             2
#define PINMUX_PA30C_SERCOM1_PAD0  ((PIN_PA30C_SERCOM1_PAD0 << 16) | MUX_PA30C_SERCOM1_PAD0)
#define PORT_PA30C_SERCOM1_PAD0    (1u << 30)
#define PIN_PA31C_SERCOM1_PAD1            31  /**< \brief SERCOM1 signal: PAD1 on PA31 mux C */
#define MUX_PA31C_SERCOM1_PAD1             2
#define PINMUX_PA31C_SERCOM1_PAD1  ((PIN_PA31C_SERCOM1_PAD1 << 16) | MUX_PA31C_SERCOM1_PAD1)
#define PORT_PA31C_SERCOM1_PAD1    (1u << 31)
#define PIN_PA30D_SERCOM1_PAD2            30  /**< \brief SERCOM1 signal: PAD2 on PA30 mux D */
#define MUX_PA30D_SERCOM1_PAD2             3
#define PINMUX_PA30D_SERCOM1_PAD2  ((PIN_PA30D_SERCOM1_PAD2 << 16) | MUX_PA30D_SERCOM1_PAD2)
#define PORT_PA30D_SERCOM1_PAD2    (1u << 30)
#define PIN_PA24C_SERCOM1_PAD2            24  /**< \brief SERCOM1 signal: PAD2 on PA24 mux C */
#define MUX_PA24C_SERCOM1_PAD2             2
#define PINMUX_PA24C_SERCOM1_PAD2  ((PIN_PA24C_SERCOM1_PAD2 << 16) | MUX_PA24C_SERCOM1_PAD2)
#define PORT_PA24C_SERCOM1_PAD2    (1u << 24)
#define PIN_PA08C_SERCOM1_PAD2             8  /**< \brief SERCOM1 signal: PAD2 on PA08 mux C */
#define MUX_PA08C_SERCOM1_PAD2             2
#define PINMUX_PA08C_SERCOM1_PAD2  ((PIN_PA08C_SERCOM1_PAD2 << 16) | MUX_PA08C_SERCOM1_PAD2)
#define PORT_PA08C_SERCOM1_PAD2    (1u <<  8)
#define PIN_PA31D_SERCOM1_PAD3            31  /**< \brief SERCOM1 signal: PAD3 on PA31 mux D */
#define MUX_PA31D_SERCOM1_PAD3             3
#define PINMUX_PA31D_SERCOM1_PAD3  ((PIN_PA31D_SERCOM1_PAD3 << 16) | MUX_PA31D_SERCOM1_PAD3)
#define PORT_PA31D_SERCOM1_PAD3    (1u << 31)
#define PIN_PA25C_SERCOM1_PAD3            25  /**< \brief SERCOM1 signal: PAD3 on PA25 mux C */
#define MUX_PA25C_SERCOM1_PAD3             2
#define PINMUX_PA25C_SERCOM1_PAD3  ((PIN_PA25C_SERCOM1_PAD3 << 16) | MUX_PA25C_SERCOM1_PAD3)
#define PORT_PA25C_SERCOM1_PAD3    (1u << 25)
#define PIN_PA09C_SERCOM1_PAD3             9  /**< \brief SERCOM1 signal: PAD3 on PA09 mux C */
#define MUX_PA09C_SERCOM1_PAD3             2
#define PINMUX_PA09C_SERCOM1_PAD3  ((PIN_PA09C_SERCOM1_PAD3 << 16) | MUX_PA09C_SERCOM1_PAD3)
#define PORT_PA09C_SERCOM1_PAD3    (1u <<  9)
/* ========== PORT definition for TCC0 peripheral ========== */
#define PIN_PA04F_TCC0_WO0                 4  /**< \brief TCC0 signal: WO0 on PA04 mux F */
#define MUX_PA04F_TCC0_WO0                 5
#define PINMUX_PA04F_TCC0_WO0      ((PIN_PA04F_TCC0_WO0 << 16) | MUX_PA04F_TCC0_WO0)
#define PORT_PA04F_TCC0_WO0        (1u <<  4)
#define PIN_PA14F_TCC0_WO0                14  /**< \brief TCC0 signal: WO0 on PA14 mux F */
#define MUX_PA14F_TCC0_WO0                 5
#define PINMUX_PA14F_TCC0_WO0      ((PIN_PA14F_TCC0_WO0 << 16) | MUX_PA14F_TCC0_WO0)
#define PORT_PA14F_TCC0_WO0        (1u << 14)
#define PIN_PA05F_TCC0_WO1                 5  /**< \brief TCC0 signal: WO1 on PA05 mux F */
#define MUX_PA05F_TCC0_WO1                 5
#define PINMUX_PA05F_TCC0_WO1      ((PIN_PA05F_TCC0_WO1 << 16) | MUX_PA05F_TCC0_WO1)
#define PORT_PA05F_TCC0_WO1        (1u <<  5)
#define PIN_PA15F_TCC0_WO1                15  /**< \brief TCC0 signal: WO1 on PA15 mux F */
#define MUX_PA15F_TCC0_WO1                 5
#define PINMUX_PA15F_TCC0_WO1      ((PIN_PA15F_TCC0_WO1 << 16) | MUX_PA15F_TCC0_WO1)
#define PORT_PA15F_TCC0_WO1        (1u << 15)
#define PIN_PA30F_TCC0_WO2                30  /**< \brief TCC0 signal: WO2 on PA30 mux F */
#define MUX_PA30F_TCC0_WO2                 5
#define PINMUX_PA30F_TCC0_WO2      ((PIN_PA30F_TCC0_WO2 << 16) | MUX_PA30F_TCC0_WO2)
#define PORT_PA30F_TCC0_WO2        (1u << 30)
#define PIN_PA08E_TCC0_WO2                 8  /**< \brief TCC0 signal: WO2 on PA08 mux E */
#define MUX_PA08E_TCC0_WO2                 4
#define PINMUX_PA08E_TCC0_WO2      ((PIN_PA08E_TCC0_WO2 << 16) | MUX_PA08E_TCC0_WO2)
#define PORT_PA08E_TCC0_WO2        (1u <<  8)
#define PIN_PA24E_TCC0_WO2                24  /**< \brief TCC0 signal: WO2 on PA24 mux E */
#define MUX_PA24E_TCC0_WO2                 4
#define PINMUX_PA24E_TCC0_WO2      ((PIN_PA24E_TCC0_WO2 << 16) | MUX_PA24E_TCC0_WO2)
#define PORT_PA24E_TCC0_WO2        (1u << 24)
#define PIN_PA31F_TCC0_WO3                31  /**< \brief TCC0 signal: WO3 on PA31 mux F */
#define MUX_PA31F_TCC0_WO3                 5
#define PINMUX_PA31F_TCC0_WO3      ((PIN_PA31F_TCC0_WO3 << 16) | MUX_PA31F_TCC0_WO3)
#define PORT_PA31F_TCC0_WO3        (1u << 31)
#define PIN_PA09E_TCC0_WO3                 9  /**< \brief TCC0 signal: WO3 on PA09 mux E */
#define MUX_PA09E_TCC0_WO3                 4
#define PINMUX_PA09E_TCC0_WO3      ((PIN_PA09E_TCC0_WO3 << 16) | MUX_PA09E_TCC0_WO3)
#define PORT_PA09E_TCC0_WO3        (1u <<  9)
#define PIN_PA25E_TCC0_WO3                25  /**< \brief TCC0 signal: WO3 on PA25 mux E */
#define MUX_PA25E_TCC0_WO3                 4
#define PINMUX_PA25E_TCC0_WO3      ((PIN_PA25E_TCC0_WO3 << 16) | MUX_PA25E_TCC0_WO3)
#define PORT_PA25E_TCC0_WO3        (1u << 25)
#define PIN_PA24F_TCC0_WO4                24  /**< \brief TCC0 signal: WO4 on PA24 mux F */
#define MUX_PA24F_TCC0_WO4                 5
#define PINMUX_PA24F_TCC0_WO4      ((PIN_PA24F_TCC0_WO4 << 16) | MUX_PA24F_TCC0_WO4)
#define PORT_PA24F_TCC0_WO4        (1u << 24)
#define PIN_PA08F_TCC0_WO4                 8  /**< \brief TCC0 signal: WO4 on PA08 mux F */
#define MUX_PA08F_TCC0_WO4                 5
#define PINMUX_PA08F_TCC0_WO4      ((PIN_PA08F_TCC0_WO4 << 16) | MUX_PA08F_TCC0_WO4)
#define PORT_PA08F_TCC0_WO4        (1u <<  8)
#define PIN_PA25F_TCC0_WO5                25  /**< \brief TCC0 signal: WO5 on PA25 mux F */
#define MUX_PA25F_TCC0_WO5                 5
#define PINMUX_PA25F_TCC0_WO5      ((PIN_PA25F_TCC0_WO5 << 16) | MUX_PA25F_TCC0_WO5)
#define PORT_PA25F_TCC0_WO5        (1u << 25)
#define PIN_PA09F_TCC0_WO5                 9  /**< \brief TCC0 signal: WO5 on PA09 mux F */
#define MUX_PA09F_TCC0_WO5                 5
#define PINMUX_PA09F_TCC0_WO5      ((PIN_PA09F_TCC0_WO5 << 16) | MUX_PA09F_TCC0_WO5)
#define PORT_PA09F_TCC0_WO5        (1u <<  9)
/* ========== PORT definition for TC1 peripheral ========== */
#define PIN_PA04E_TC1_WO0                  4  /**< \brief TC1 signal: WO0 on PA04 mux E */
#define MUX_PA04E_TC1_WO0                  4
#define PINMUX_PA04E_TC1_WO0       ((PIN_PA04E_TC1_WO0 << 16) | MUX_PA04E_TC1_WO0)
#define PORT_PA04E_TC1_WO0         (1u <<  4)
#define PIN_PA14E_TC1_WO0                 14  /**< \brief TC1 signal: WO0 on PA14 mux E */
#define MUX_PA14E_TC1_WO0                  4
#define PINMUX_PA14E_TC1_WO0       ((PIN_PA14E_TC1_WO0 << 16) | MUX_PA14E_TC1_WO0)
#define PORT_PA14E_TC1_WO0         (1u << 14)
#define PIN_PA05E_TC1_WO1                  5  /**< \brief TC1 signal: WO1 on PA05 mux E */
#define MUX_PA05E_TC1_WO1                  4
#define PINMUX_PA05E_TC1_WO1       ((PIN_PA05E_TC1_WO1 << 16) | MUX_PA05E_TC1_WO1)
#define PORT_PA05E_TC1_WO1         (1u <<  5)
#define PIN_PA15E_TC1_WO1                 15  /**< \brief TC1 signal: WO1 on PA15 mux E */
#define MUX_PA15E_TC1_WO1                  4
#define PINMUX_PA15E_TC1_WO1       ((PIN_PA15E_TC1_WO1 << 16) | MUX_PA15E_TC1_WO1)
#define PORT_PA15E_TC1_WO1         (1u << 15)
/* ========== PORT definition for TC2 peripheral ========== */
#define PIN_PA30E_TC2_WO0                 30  /**< \brief TC2 signal: WO0 on PA30 mux E */
#define MUX_PA30E_TC2_WO0                  4
#define PINMUX_PA30E_TC2_WO0       ((PIN_PA30E_TC2_WO0 << 16) | MUX_PA30E_TC2_WO0)
#define PORT_PA30E_TC2_WO0         (1u << 30)
#define PIN_PA31E_TC2_WO1                 31  /**< \brief TC2 signal: WO1 on PA31 mux E */
#define MUX_PA31E_TC2_WO1                  4
#define PINMUX_PA31E_TC2_WO1       ((PIN_PA31E_TC2_WO1 << 16) | MUX_PA31E_TC2_WO1)
#define PORT_PA31E_TC2_WO1         (1u << 31)
/* ========== PORT definition for ADC peripheral ========== */
#define PIN_PA04B_ADC_AIN2                 4  /**< \brief ADC signal: AIN2 on PA04 mux B */
#define MUX_PA04B_ADC_AIN2                 1
#define PINMUX_PA04B_ADC_AIN2      ((PIN_PA04B_ADC_AIN2 << 16) | MUX_PA04B_ADC_AIN2)
#define PORT_PA04B_ADC_AIN2        (1u <<  4)
#define PIN_PA05B_ADC_AIN3                 5  /**< \brief ADC signal: AIN3 on PA05 mux B */
#define MUX_PA05B_ADC_AIN3                 1
#define PINMUX_PA05B_ADC_AIN3      ((PIN_PA05B_ADC_AIN3 << 16) | MUX_PA05B_ADC_AIN3)
#define PORT_PA05B_ADC_AIN3        (1u <<  5)
#define PIN_PA14B_ADC_AIN6                14  /**< \brief ADC signal: AIN6 on PA14 mux B */
#define MUX_PA14B_ADC_AIN6                 1
#define PINMUX_PA14B_ADC_AIN6      ((PIN_PA14B_ADC_AIN6 << 16) | MUX_PA14B_ADC_AIN6)
#define PORT_PA14B_ADC_AIN6        (1u << 14)
#define PIN_PA15B_ADC_AIN7                15  /**< \brief ADC signal: AIN7 on PA15 mux B */
#define MUX_PA15B_ADC_AIN7                 1
#define PINMUX_PA15B_ADC_AIN7      ((PIN_PA15B_ADC_AIN7 << 16) | MUX_PA15B_ADC_AIN7)
#define PORT_PA15B_ADC_AIN7        (1u << 15)
#define PIN_PA04B_ADC_VREFP                4  /**< \brief ADC signal: VREFP on PA04 mux B */
#define MUX_PA04B_ADC_VREFP                1
#define PINMUX_PA04B_ADC_VREFP     ((PIN_PA04B_ADC_VREFP << 16) | MUX_PA04B_ADC_VREFP)
#define PORT_PA04B_ADC_VREFP       (1u <<  4)
/* ========== PORT definition for AC peripheral ========== */
#define PIN_PA04B_AC_AIN0                  4  /**< \brief AC signal: AIN0 on PA04 mux B */
#define MUX_PA04B_AC_AIN0                  1
#define PINMUX_PA04B_AC_AIN0       ((PIN_PA04B_AC_AIN0 << 16) | MUX_PA04B_AC_AIN0)
#define PORT_PA04B_AC_AIN0         (1u <<  4)
#define PIN_PA05B_AC_AIN1                  5  /**< \brief AC signal: AIN1 on PA05 mux B */
#define MUX_PA05B_AC_AIN1                  1
#define PINMUX_PA05B_AC_AIN1       ((PIN_PA05B_AC_AIN1 << 16) | MUX_PA05B_AC_AIN1)
#define PORT_PA05B_AC_AIN1         (1u <<  5)
#define PIN_PA14G_AC_CMP0                 14  /**< \brief AC signal: CMP0 on PA14 mux G */
#define MUX_PA14G_AC_CMP0                  6
#define PINMUX_PA14G_AC_CMP0       ((PIN_PA14G_AC_CMP0 << 16) | MUX_PA14G_AC_CMP0)
#define PORT_PA14G_AC_CMP0         (1u << 14)
#define PIN_PA15G_AC_CMP1                 15  /**< \brief AC signal: CMP1 on PA15 mux G */
#define MUX_PA15G_AC_CMP1                  6
#define PINMUX_PA15G_AC_CMP1       ((PIN_PA15G_AC_CMP1 << 16) | MUX_PA15G_AC_CMP1)
#define PORT_PA15G_AC_CMP1         (1u << 15)

#endif /* _SAMD10C14A_PIO_ */
