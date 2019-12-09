/*
 * adc.h
 *
 *  Created on: Sep 18, 2019
 *      Author: OmarG
 */

#ifndef ADC_H_
#define ADC_H_
#include <avr\io.h>
#include "Atmega16_regs.h"
#include "std_types.h"
#include "common_macros.h"
#include <util\delay.h>
#include <avr/interrupt.h>

#define ON 1
#define OFF 0

typedef enum {AREF,AVCC,RESERVED,INT} RVOLTTYPE ;
typedef enum {ADC0,ADC1,ADC2,ADC3,ADC4,ADC5,ADC6,ADC7} MUXTYPE ;
typedef enum {PS2,PS22,PS4,PS8,PS16,PS32,PS64,PS128}PRESCALERTYPE;

typedef struct {
MUXTYPE MUX ;
RVOLTTYPE RVOLT ;
PRESCALERTYPE PRESCALE ;
uint8 INTENABLE ;
} ADC_CONFIG ;




void adcInit(ADC_CONFIG * cofigstruct);
uint16 adcRead(ADC_CONFIG * cofigstruct);
void adcCallBack(void(*a_ptr)(void));






#endif /* ADC_H_ */
