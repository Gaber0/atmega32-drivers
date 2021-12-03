/*
 * SEV_Segment.h
 *
 *  Created on: Dec 1, 2021
 *      Author: Eslam
 */

#ifndef INCLUDE_SEV_SEGMENT_H_
#define INCLUDE_SEV_SEGMENT_H_



#include "stm32f103x8.h"
#include "clock.h"
#include "gpio.h"
#include "SEV_Segment.h"


#define SEV_ANODE	 	1
#define SEV_KATHODE 	0

extern uint8_t segments[];

void sev_S_display(GPIO_typeDef *GPIOx , uint8_t num, uint8_t type);





#endif /* INCLUDE_SEV_SEGMENT_H_ */
