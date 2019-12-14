/*
 * PIR.c
 *
 *  Created on: Dec 7, 2019
 *      Author: ROMA
 */


#include"PIR.h"


/* used function of IPR */

/* function to stop motor */

void Stop_motor(void){

	CLEAR_BIT(PIR_CTRL_PORT,INPUT1);
	CLEAR_BIT(PIR_CTRL_PORT,INPUT2);
}
/* function to move motor clockwise */

void Move_CLOCKWISE (void){

	CLEAR_BIT(PIR_CTRL_PORT,INPUT1);
	SET_BIT(PIR_CTRL_PORT,INPUT2);


}
/* function to move motor anticlockwise */

void Move_ANTICLOCKWISE (void){
	SET_BIT(PIR_CTRL_PORT,INPUT1);
	CLEAR_BIT(PIR_CTRL_PORT,INPUT2);

}
void pir (void){
	if(PINA & (1<<PA7)){
	Move_CLOCKWISE();
	_delay_ms(1000);
	Stop_motor();
	while(PINA & (1<<PA7)){}
	_delay_ms(500);
	Move_ANTICLOCKWISE();
	_delay_ms(1000);
	Stop_motor();
	}
}


uint8*  CTR_pir (uint8 *ptr){
static uint8 Dstat = 0 ;
static uint8 L_State[2]	;
	if (ptr[0]==0){
		pir();
		L_State[0]= 0 ;
		L_State[1] = 1 ;
		return L_State;
	} else if (ptr[0]==1){
		if (ptr[1]==1 && Dstat != 1){
			Move_CLOCKWISE();
			_delay_ms(1000);
			Stop_motor();
			Dstat = 1 ;
			L_State[0]= 1 ;
					L_State[1] = Dstat ;
					return L_State;

		}else if (ptr[1]==0 && Dstat !=0){
			Move_ANTICLOCKWISE();
			_delay_ms(1000);
			Stop_motor();
			Dstat = 0 ;
			L_State[0]= 1 ;
					L_State[1] = Dstat ;
					return L_State;
		}
	}

return 0 ;

}
