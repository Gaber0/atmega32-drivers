/*
 * SEV_Segment.h
 *
 * Created: Wed, 12, 1, 2021 6:15:35 PM
 *  Author: Eslam
 */ 


#ifndef SEV_SEGMENT_H_
#define SEV_SEGMENT_H_

#include "gpio.h"

#define SEV_S_PORT		PC

#define SEV_KATHODE 	0
#define SEV_ANODE	 	1

extern u8 segments[];

void sev_S_display(u8 num, u8 type);
void SEV_S_clear(u8 type);




#endif /* SEV_SEGMENT_H_ */