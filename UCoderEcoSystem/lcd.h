/*
 * lcd.h
 *
 *  Created on: Sep 16, 2019
 *      Author: OmarG
 */

#ifndef LCD_H_
#define LCD_H_

#include "lcdconfig.h"
#include "avr\io.h"
#include "Atmega16_regs.h"
#include "std_types.h"
#include "common_macros.h"
#include <util\delay.h>






/** for more generic use **/
#if (DATA_BITS_MODE == 4)
	#ifdef UPPER_PORT_PINS
		#define lcdInPin (lcdDataPortDir|0xf0)
	#else
		#define lcdInPin (lcdDataPortDir|0x0f)
	#endif


#else
#define lcdInPin 0xff
#endif

#if (DATA_BITS_MODE == 4)
	#ifdef UPPER_PORT_PINS
		#define lcdOutPin (lcdDataPortDir & 0x0f)
	#else
		#define lcdOutPin (lcdDataPortDir&0xf0)
	#endif


#else
#define lcdOutPin 0x00
#endif

/********************************
 *        Commands              *
 ********************************/

#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80

/********************************
 *        ProtoTypes            *
 ********************************/

void lcdDo(void);  // done
void lcdSendCommand(uint8 a_Command); //done
void lcdSendData(uint8 a_Data); //done
void lcdSendString(const char* str ); // done
void lcdInit(void); //done
void lcdClear(void); //done
void lcdGoTo(uint8 x ,uint8 y ); //done
void lcdSendInt(int data);
void lcdDispStringAt(uint8 x ,uint8 y ,const char* str);
void lcdSendFloat(float data,uint8 digits);











#endif /* LCD_H_ */
