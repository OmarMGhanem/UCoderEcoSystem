/*
 * uart.h
 *
 *  Created on: Sep 23, 2019
 *      Author: OmarG
 */

#ifndef UART_H_
#define UART_H_

#include <avr\io.h>
#include "Atmega16_regs.h"
#include "std_types.h"
#include "common_macros.h"
#include <util\delay.h>
#include <avr/interrupt.h>


#define uartBaudRate 9600
#define uartInterruptEnable OFF
#define uartPreScale (((F_CPU / (uartBaudRate * 8UL))) - 1) // fix it for confieg if no doubled


void uartInit(void);
void uartSendByte(const uint8 a_byte);
uint8 uartReciveByte(void);
void uartSendString(char * a_str);
void uartReciveString(char * a_str);

















#endif /* UART_H_ */
