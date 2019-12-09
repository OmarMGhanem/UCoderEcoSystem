/*
 * lcdconfig.h
 *
 *  Created on: Sep 16, 2019
 *      Author: OmarG
 */

#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

#define RS PC3
#define RW PC4
#define E  PC2
#define lcdCtrlPort PORTC
#define lcdCtrlPortDir DDRC
#define lcdDataPort PORTB
#define lcdDataPortDir DDRB
#define lcdDataPortPin PINB

#define DATA_BITS_MODE 8

#if (DATA_BITS_MODE == 4)
//#define UPPER_PORT_PINS
#endif /* Use port 4 -> 7 */



#endif /* LCDCONFIG_H_ */
