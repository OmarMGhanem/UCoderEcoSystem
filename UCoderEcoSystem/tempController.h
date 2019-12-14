/*
 * tempController.h
 *
 *  Created on: Dec 9, 2019
 *      Author: OmarG
 */

#ifndef TEMPCONTROLLER_H_
#define TEMPCONTROLLER_H_
#include "tempReader.h"
#include <avr\io.h>
#include "Atmega16_regs.h"
#include "std_types.h"
#include "common_macros.h"
#include <util\delay.h>
#include <avr/interrupt.h>
#include "adc.h"

extern ADC_CONFIG adcConfigStruct;
uint8* temp(uint8* );

void Timer0_PWM_Init(unsigned char set_duty_cycle);
void fanSpeedMapper(uint16 temp);

#endif /* TEMPCONTROLLER_H_ */
