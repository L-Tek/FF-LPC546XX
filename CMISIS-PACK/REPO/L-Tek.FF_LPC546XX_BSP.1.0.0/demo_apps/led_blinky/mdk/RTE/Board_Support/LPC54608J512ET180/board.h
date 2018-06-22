/*
 * The Clear BSD License
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _BOARD_H_
#define _BOARD_H_

#include "clock_config.h"
#include "fsl_common.h"
#include "fsl_gpio.h"


/*******************************************************************************
 * Pinout
 *******************************************************************************
 
    LED1 = P1_3,
    LED2 = P1_27,
    LED3 = P1_26,
    LED4 = P1_28,

    // USB Pins
    USBTX = P0_30,
    USBRX = P0_29,

    A0 = P0_16,
    A1 = P0_31,
    A2 = P1_0,
    A3 = P2_0,
    A4 = P3_4,
    A5 = P1_1,

    p5  = P1_24,
    p6  = P1_25,
    p7  = P1_23,
    p8  = P1_8,
    p9  = P0_26,
    p10 = P0_27,
    p11 = P1_4,
    p12 = P1_5,
    p13 = P1_6,
    p14 = P1_7,
    p15 = P0_15,
    p16 = P0_16,
    p17 = P0_23,
    p18 = P0_31,
    p19 = P1_0,
    p20 = P0_10,
    p21 = P0_17,
    p22 = P0_18,
    p23 = P0_19,
    p24 = P0_22,
    p25 = P0_28,
    p26 = P1_31,
    p27 = P1_30,
    p28 = P1_29,
    p29 = P0_0,
    p30 = P0_1
	
**/


/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The board name */
#define BOARD_NAME "FF-LPC546XX"

#define BOARD_EXTCLKINRATE (0)

/*! @brief The UART to use for debug messages. */
/* TODO: rename UART to USART */
#define BOARD_DEBUG_UART_TYPE DEBUG_CONSOLE_DEVICE_TYPE_FLEXCOMM
#define BOARD_DEBUG_UART_BASEADDR (uint32_t) USART0
#define BOARD_DEBUG_UART_INSTANCE 0U
#define BOARD_DEBUG_UART_CLK_FREQ CLOCK_GetFreq(kCLOCK_Flexcomm0)
#define BOARD_DEBUG_UART_CLK_ATTACH kFRO12M_to_FLEXCOMM0
#define BOARD_DEBUG_UART_RST kFC0_RST_SHIFT_RSTn
#define BOARD_DEBUG_UART_CLKSRC kCLOCK_Flexcomm0
#define BOARD_UART_IRQ_HANDLER FLEXCOMM0_IRQHandler
#define BOARD_UART_IRQ FLEXCOMM0_IRQn
/* TODO: obsolete */
#define BOARD_DEBUG_SPI_CLK_FREQ 12000000

#ifndef BOARD_DEBUG_UART_BAUDRATE
#define BOARD_DEBUG_UART_BAUDRATE 115200
#endif /* BOARD_DEBUG_UART_BAUDRATE */



#ifndef BOARD_LED1_GPIO
#define BOARD_LED1_GPIO GPIO
#endif
#define BOARD_LED1_GPIO_PORT 1U
#ifndef BOARD_LED1_GPIO_PIN
#define BOARD_LED1_GPIO_PIN 3U
#endif
#ifndef BOARD_LED2_GPIO
#define BOARD_LED2_GPIO GPIO
#endif
#define BOARD_LED2_GPIO_PORT 1U
#ifndef BOARD_LED2_GPIO_PIN
#define BOARD_LED2_GPIO_PIN 27U
#endif
#ifndef BOARD_LED3_GPIO
#define BOARD_LED3_GPIO GPIO
#endif
#define BOARD_LED3_GPIO_PORT 1U
#ifndef BOARD_LED3_GPIO_PIN
#define BOARD_LED3_GPIO_PIN 26U
#endif
#define BOARD_LED4_GPIO_PORT 1U
#ifndef BOARD_LED4_GPIO_PIN
#define BOARD_LED4_GPIO_PIN 28U
#endif





/* Board led color mapping */
#define LOGIC_LED_ON 0U
#define LOGIC_LED_OFF 1U

#define LED1_INIT(output)                                                    \
    GPIO_PinInit(BOARD_LED1_GPIO, BOARD_LED1_GPIO_PORT, BOARD_LED1_GPIO_PIN, \
                 &(gpio_pin_config_t){kGPIO_DigitalOutput, (output)}) /*!< Enable target LED1 */
#define LED1_ON() \
    GPIO_PortClear(BOARD_LED1_GPIO, BOARD_LED1_GPIO_PORT, 1U << BOARD_LED1_GPIO_PIN) /*!< Turn on target LED1 */
#define LED1_OFF() \
    GPIO_PortSet(BOARD_LED1_GPIO, BOARD_LED1_GPIO_PORT, 1U << BOARD_LED1_GPIO_PIN) /*!< Turn off target LED1 */
#define LED1_TOGGLE()                                            \
    GPIO_PortToggle(BOARD_LED1_GPIO, BOARD_LED1_GPIO_PORT, \
                          1U << BOARD_LED1_GPIO_PIN) /*!< Toggle on target LED1 */
#define LED2_INIT(output)                                                    \
    GPIO_PinInit(BOARD_LED2_GPIO, BOARD_LED2_GPIO_PORT, BOARD_LED2_GPIO_PIN, \
                 &(gpio_pin_config_t){kGPIO_DigitalOutput, (output)}) /*!< Enable target LED2 */
#define LED2_ON() \
    GPIO_PortClear(BOARD_LED2_GPIO, BOARD_LED2_GPIO_PORT, 1U << BOARD_LED2_GPIO_PIN) /*!< Turn on target LED2 */
#define LED2_OFF() \
    GPIO_PortSet(BOARD_LED2_GPIO, BOARD_LED2_GPIO_PORT, 1U << BOARD_LED2_GPIO_PIN) /*!< Turn off target LED2 */
#define LED2_TOGGLE()                                            \
    GPIO_PortToggle(BOARD_LED2_GPIO, BOARD_LED2_GPIO_PORT, \
                          1U << BOARD_LED2_GPIO_PIN) /*!< Toggle on target LED2 */

#define LED3_INIT(output)                                                    \
    GPIO_PinInit(BOARD_LED3_GPIO, BOARD_LED3_GPIO_PORT, BOARD_LED3_GPIO_PIN, \
                 &(gpio_pin_config_t){kGPIO_DigitalOutput, (output)}) /*!< Enable target LED3 */
#define LED3_ON() \
    GPIO_PortClear(BOARD_LED3_GPIO, BOARD_LED3_GPIO_PORT, 1U << BOARD_LED3_GPIO_PIN) /*!< Turn on target LED3 */
#define LED3_OFF() \
    GPIO_PortSet(BOARD_LED3_GPIO, BOARD_LED3_GPIO_PORT, 1U << BOARD_LED3_GPIO_PIN) /*!< Turn off target LED3 */
#define LED3_TOGGLE()                                            \
    GPIO_PortToggle(BOARD_LED3_GPIO, BOARD_LED3_GPIO_PORT, \
                          1U << BOARD_LED3_GPIO_PIN) /*!< Toggle on target LED3 */

#define LED4_INIT(output)                                                    \
    GPIO_PinInit(BOARD_LED4_GPIO, BOARD_LED4_GPIO_PORT, BOARD_LED4_GPIO_PIN, \
                 &(gpio_pin_config_t){kGPIO_DigitalOutput, (output)}) /*!< Enable target LED4 */
#define LED4_ON() \
    GPIO_PortClear(BOARD_LED4_GPIO, BOARD_LED4_GPIO_PORT, 1U << BOARD_LED4_GPIO_PIN) /*!< Turn on target LED4 */
#define LED4_OFF() \
    GPIO_PortSet(BOARD_LED4_GPIO, BOARD_LED4_GPIO_PORT, 1U << BOARD_LED4_GPIO_PIN) /*!< Turn off target LED4 */
#define LED4_TOGGLE()                                            \
    GPIO_PortToggle(BOARD_LED4_GPIO, BOARD_LED4_GPIO_PORT, \
                          1U << BOARD_LED4_GPIO_PIN) /*!< Toggle on target LED4 */

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/

status_t BOARD_InitDebugConsole(void);
void BOARD_InitSDRAM(void);



#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _BOARD_H_ */
