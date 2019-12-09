/*
 * lcd.c
 *
 *  Created on: Sep 16, 2019
 *      Author: OmarG
 */
#include "lcd.h"



void lcdDo(){

	SET_BIT(lcdCtrlPort,E);
		_delay_us(100);

		CLEAR_BIT(lcdCtrlPort,E);
		_delay_us(100);

}


void lcdSendCommand(uint8 a_Command){
				CLEAR_BIT(lcdCtrlPort,RS);
				CLEAR_BIT(lcdCtrlPort,RW);


#if (DATA_BITS_MODE== 8)
			lcdDataPort= a_Command;
			lcdDo();
#elif (DATA_BITS_MODE== 4)
	#ifdef UPPER_PORT_PINS

			lcdDataPort = (lcdDataPort & 0x0F)   | (a_Command & 0xF0) ;
			lcdDo();
			_delay_ms(2);
			lcdDataPort = (lcdDataPort & 0x0F) | (a_Command << 4) ;
			lcdDo();



	#else

			lcdDataPort = (lcdDataPort & 0xF0)   | ((a_Command & 0xF0) >>4) ;
			lcdDo();
			lcdDataPort = (lcdDataPort & 0xF0) |(a_Command & 0x0F) ;
			lcdDo();

	#endif
#endif

}

void lcdInit(){

	lcdCtrlPortDir |= (1<<E) | (1<<RS) | (1<<RW);
	lcdDataPortDir = lcdInPin;
#if (DATA_BITS_MODE== 8)
	lcdSendCommand(TWO_LINE_LCD_Eight_BIT_MODE);
#else
	/**lcdSendCommand(0x33);
	lcdSendCommand(0x32);
	lcdSendCommand(0x28);**/
lcdSendCommand(FOUR_BITS_DATA_MODE);
lcdSendCommand(TWO_LINE_LCD_Four_BIT_MODE);

#endif

	lcdSendCommand(CURSOR_ON);
	lcdSendCommand(CLEAR_COMMAND);


}

void lcdSendData(uint8 a_Data){

	CLEAR_BIT(lcdCtrlPort,RW);
	SET_BIT(lcdCtrlPort,RS);
#if (DATA_BITS_MODE== 8)
	lcdDataPort = a_Data;
	lcdDo();
#elif (DATA_BITS_MODE== 4)
	#ifdef UPPER_PORT_PINS

			lcdDataPort = (lcdDataPort & 0x0F)   | (a_Data & 0xF0) ;
			lcdDo();
			lcdDataPort = (lcdDataPort & 0x0F) | (a_Data << 4) ;
			lcdDo();



	#else

			lcdDataPort = (lcdDataPort & 0xF0)   | ((a_Data & 0xF0) >>4) ;
			lcdDo();
			lcdDataPort = (lcdDataPort & 0xF0) |(a_Data & 0x0F) ;
			lcdDo();

	#endif
#endif

}

void lcdSendString(const char  *str){

	while(*str != '\0'){
		lcdSendData(*(str));
		str++;
	}}


void lcdGoTo(uint8 x,uint8 y){
	uint8 Address ;
	switch(x)
	{
	case 0:
		Address=y;
		break;
	case 1:
		Address=y+0x40;
		break;
	case 2:
		Address=y+0x10;
		break;
	case 3:
		Address=y+0x50;
		break;
	}

	lcdSendCommand((Address|SET_CURSOR_LOCATION));

}
void lcdClear(void){

	lcdSendCommand(CLEAR_COMMAND);

}




void lcdDispStringAt(uint8 x ,uint8 y ,const char* str){

	lcdGoTo(x,y);
	lcdSendString(str);


}
void lcdSendInt(int data){
char temp[32] ;
itoa(data,temp,10);

lcdSendString(temp);
}

void lcdSendFloat(float data,uint8 digits){
	uint8 i =0 ;
	lcdSendInt(data);
	if(digits !=0){
	lcdSendData('.');
	data = data-(unsigned int)data ;
	for(i=0;i<digits;i++){

		data=data*10 ;

	}
	data = data * (-1);
	lcdSendInt(data);}

}








