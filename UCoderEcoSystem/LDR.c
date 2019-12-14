/*
 * LDR.c
 *
 *  Created on: Dec 8, 2019
 *      Author: ROMA
 */

#include"LDR.h"
#include"ADC.h"
ADC_CONFIG adcConfigStruct1 = {ADC1,AREF,PS8,OFF} ;


/*function to make led on */

void LED_ON (void){
	SET_BIT(LED_CTRL,LED);
}
/*function to make led off */

void LED_OFF (void){
	CLEAR_BIT(LED_CTRL,LED);
}
void ldr (uint16 x){


	if (x <= 256){
		LED_OFF();
	}else {

		LED_ON();
	}

}


uint8* CTR_ldr (uint8 *ptr){
	static uint8 L_State[2]	;
	adcInit(&adcConfigStruct1);
	uint16 L_Temp;

	if (ptr[0]==0){
		L_Temp =	adcRead(&adcConfigStruct1);
		ldr(L_Temp);
		L_State[0]= 0 ;

		if (L_Temp <= 256)
			L_State[1]=0;
		else
			L_State[1]=1;

		return L_State ;

	} else {
		if (ptr[1]==1){
			LED_ON();
			L_State[0]= 1 ;
			L_State[1]= 1;
			return L_State ;
		}else {
			LED_OFF();
			L_State[0]= 1 ;
			L_State[1]= 0;
			return L_State ;
		}
	}



}
