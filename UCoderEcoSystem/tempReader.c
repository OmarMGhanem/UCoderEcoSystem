/*
 * tempReader.c
 *
 *  Created on: Dec 9, 2019
 *      Author: OmarG
 */


#include "tempReader.h"


 ADC_CONFIG adcConfigStruct = {ADC0,AREF,PS8,OFF} ;

uint16 tempRead(){
	uint16 L_Temp;
	L_Temp =	adcRead(&adcConfigStruct);
	L_Temp = ((L_Temp*150)/306);
	if(L_Temp>=140)
		--L_Temp;
	return L_Temp ;




}



