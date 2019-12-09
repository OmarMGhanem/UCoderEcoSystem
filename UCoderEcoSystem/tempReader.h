/*
 * tempReader.h
 *
 *  Created on: Dec 9, 2019
 *      Author: OmarG
 */

#ifndef TEMPREADER_H_
#define TEMPREADER_H_

#include <avr\io.h>
#include "Atmega16_regs.h"
#include "std_types.h"
#include "common_macros.h"
#include <util\delay.h>
#include <avr/interrupt.h>
#include "adc.h"



uint16 tempRead(void);


#endif /* TEMPREADER_H_ */
