/*
 * lcdconfig.h
 *
 *  Created on: Sep 16, 2019
 *      Author: OmarG
 */

#ifndef LCDCONFIG_H_
#define LCDCONFIG_H_

#define RS PC0
#define RW PC1
#define E  PC2
#define lcdCtrlPort PORTC
#define lcdCtrlPortDir DDRC
#define lcdDataPort PORTD
#define lcdDataPortDir DDRD
#define lcdDataPortPin PIND

#define DATA_BITS_MODE 8

#if (DATA_BITS_MODE == 4)
//#define UPPER_PORT_PINS
#endif /* Use port 4 -> 7 */



#endif /* LCDCONFIG_H_ */
