/*
 * tempController.c
 *
 *  Created on: Dec 9, 2019
 *      Author: OmarG
 */

#include "tempController.h"



uint8* temp(uint8* L_Ctrl ){
	static uint8 L_State[2]	;

	uint16 temp;

	temp = tempRead();
	_delay_ms(20);
	//Automatic
	if (*(L_Ctrl)== 0 ){
		fanSpeedMapper(temp);
		L_State[0]= 0 ;
		L_State[1]= temp;
		return L_State ;

	}else{

		Timer0_PWM_Init(*(L_Ctrl+1));
		L_State[0]= 1 ;
		L_State[1]= temp;
		return L_State;

	}//Manual






}


void Timer0_PWM_Init(unsigned char set_duty_cycle)
{
	TCNT0 = 0;
	OCR0  = set_duty_cycle;
	DDRB  = DDRB | (1<<PB3);
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

void fanSpeedMapper(uint16 temp){

	_delay_ms(20);
	if(temp >=15 && temp <=30){
		Timer0_PWM_Init((255*(temp-15))/15);

	}
	if (temp>30){
		Timer0_PWM_Init(254);
	}
	if(temp<15){
		Timer0_PWM_Init(0);
	}





}

























