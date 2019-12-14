/*
 * PIR.h
 *
 *  Created on: Dec 7, 2019
 *      Author: ROMA
 */

#ifndef PIR_H_
#define PIR_H_

#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"

/* PIR hardware pins configration */

#define INPUT1 PC0
#define INPUT2 PC1
#define PIR_CTRL_PORT PORTC
#define PIR_CTRL_PORT_DIR DDRC
#define PTR_STATE_DIR DDRA

/* Functions Prototypes */

void Stop_motor(void);
void Move_CLOCKWISE (void);
void Move_ANTICLOCKWISE (void);
void pir (void);
uint8* CTR_pir (uint8 *ptr);


#endif /* PIR_H_ */
