/*
 * ctrlUnit.c
 *
 *  Created on: Dec 9, 2019
 *      Author: OmarG
 */
extern ADC_CONFIG adcConfigStruct ;




int main(void){
	adcInit(&adcConfigStruct);
	uint8 Ctrl[2] = {1,127};
	uint8 *tempStatePtr ;

	while(1){

		tempStatePtr =temp(Ctrl);


	}



	return 0 ;
}
