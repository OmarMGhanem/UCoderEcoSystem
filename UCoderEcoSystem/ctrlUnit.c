/*
 * ctrlUnit.c
 *
 *  Created on: Dec 9, 2019
 *      Author: OmarG
 */
#include "tempCOntroller.h"
#include "PIR.h"


extern ADC_CONFIG adcConfigStruct ;



int main(void){
	adcInit(&adcConfigStruct);
	CLEAR_BIT(PTR_STATE_DIR , PA7 );
	SET_BIT(PIR_CTRL_PORT_DIR,INPUT1);
	SET_BIT(PIR_CTRL_PORT_DIR,INPUT2);
	Stop_motor();

	uint8 TCtrl[2] = {0,127};
	uint8 DCtrl[2] = {0,0};
	uint8 *tempStatePtr ;
	uint8 *doorStatePtr ;
	while(1){

		tempStatePtr =temp(TCtrl);
		doorStatePtr=CTR_pir(DCtrl);


	}



	return 0 ;
}
