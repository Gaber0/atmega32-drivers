/*
 * SEV_Segment.c
 *
 * Created: Wed, 12, 1, 2021 6:14:45 PM
 *  Author: Eslam
 */ 


#include "SEV_Segment.h"


u8 segments[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x03, 0x78, 0x00, 0x10};

void sev_S_display(u8 num, u8 type)
{
	
	GPIO_Port_Init(SEV_S_PORT, 0xFF);
	if(type == SEV_ANODE)
	{
		GPIO_Port_Set(SEV_S_PORT, num);
	}

	else if(type == SEV_KATHODE)
	{
		GPIO_Port_Set(SEV_S_PORT, ~num);
	}
}


void SEV_S_clear(u8 type)
{
	if(type == SEV_ANODE)
	{
		GPIO_Port_Set(SEV_S_PORT, 0xFF);
	}

	else if(type == SEV_KATHODE)
	{
		GPIO_Port_Set(SEV_S_PORT, 0x00);
	}
}