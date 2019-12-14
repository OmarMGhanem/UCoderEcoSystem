/*
 * ctrlUnit.c
 *
 *  Created on: Dec 9, 2019
 *      Author: OmarG
 */
#include "tempCOntroller.h"
#include "PIR.h"
#include "LDR.h"




int main(void){

	CLEAR_BIT(PTR_STATE_DIR , PA7 );
	SET_BIT(PIR_CTRL_PORT_DIR,INPUT1);
	SET_BIT(PIR_CTRL_PORT_DIR,INPUT2);
	SET_BIT(LED_CTRL_DIR,LED);
	Stop_motor();

	uint8 TCtrl[2] = {0,127};
	uint8 DCtrl[2] = {0,0};
	uint8 LCtrl[2] = {1,1};
	uint8 *tempStatePtr ;
	uint8 *doorStatePtr ;
	uint8 *ledStatePtr ;
	while(1){

		tempStatePtr =temp(TCtrl);
		doorStatePtr=CTR_pir(DCtrl);
		ledStatePtr=CTR_ldr(LCtrl);

	}



	return 0 ;
}
