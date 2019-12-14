/*
 * LDR.h
 *
 *  Created on: Dec 8, 2019
 *      Author: ROMA
 */

#ifndef LDR_H_
#define LDR_H_


#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"
#include "adc.h"

#define LED_CTRL_DIR DDRC
#define LED_CTRL PORTC
#define LED PC2


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LED_ON (void);
void LED_OFF (void);
void ldr (uint16 x);
uint8* CTR_ldr (uint8 *ptr) ;


#endif /* LDR_H_ */
