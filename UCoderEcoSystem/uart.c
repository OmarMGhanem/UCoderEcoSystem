/*
 * uart.c
 *
 *  Created on: Sep 23, 2019
 *      Author: OmarG
 */
#include "uart.h"





void uartInit(void){
	UCSRA = (1<<U2X);

#if uartInterruptEnable == ON
	UCSRB = (1<<RXCIE) | (1<<TXCIE) | /**(1<<UDRIE) | **/	(1<<RXEN) /**| (1<<TXEN) **/;

#else
	UCSRB = (1<<RXEN) | (1<<TXEN) ;
#endif

	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	UBRRH = uartPreScale>>8;
	UBRRL = uartPreScale;


}


void uartSendByte(const uint8 a_data)
{
#if uartInterruptEnable == ON
	UDR = a_data ;

#else
	while(BIT_IS_CLEAR(UCSRA,UDRE)){}

	UDR = a_data;
#endif



}



uint8 uartReciveByte(void){

#if uartInterruptEnable == ON
	return UDR ;

#else
	while(BIT_IS_CLEAR(UCSRA,RXC)){}

return UDR;
#endif




}

void uartSendString(char * a_str){
	uint8 i = 0;
	while(a_str[i]!= '\0'){
		uartSendByte(a_str[i]);
		i++;
	}


}
void uartReciveString(char * a_str){
	uint8 i = 0;
	a_str[i] = uartReciveByte();
	while(a_str[i] != 0x0D) // recive untill find 0x09 or any you wish
	{
		i++;
		a_str[i] = uartReciveByte();
	}
	a_str[i] = '\0';


}
























