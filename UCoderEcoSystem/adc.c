/*
 * adc.c
 *
 *  Created on: Sep 18, 2019
 *      Author: OmarG
 */
#include "adc.h"


static volatile void (*g_callBackPtr)(void) = NULL_PTR;

void adcInit(ADC_CONFIG * cofigstruct){

	ADMUX= (ADMUX & 0x3F) |  ((cofigstruct->RVOLT)<<6) ;
	ADCSRA = (ADCSRA & 0xF8 ) | (cofigstruct->PRESCALE);
	ADCSRA |= 1 << 7 ;
	ADCSRA = (ADCSRA & 0xF7)  | ((cofigstruct->INTENABLE)<<3);

}

uint16 adcRead(ADC_CONFIG * cofigstruct){
	ADMUX = (ADMUX & 0xE0) | cofigstruct->MUX ;
	DDRA= 0x00 ;
	if(cofigstruct->INTENABLE == OFF){
		SET_BIT(ADCSRA,ADSC);
		while(BIT_IS_CLEAR(ADCSRA,ADIF));
		SET_BIT(ADCSRA,ADIF);
		return ADC;
	}
	else{
		SET_BIT(ADCSRA,ADSC);
		return 0 ;
	}

}


void adcCallBack(void(*a_ptr)(void)){
	g_callBackPtr = a_ptr ;
}


ISR(ADC_vect){

	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)();
	}


}
