/*
 * SEV_Segment.c
 *
 *  Created on: Dec 1, 2021
 *      Author: Eslam
 */

#include "SEV_Segment.h"

uint8_t segments[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x03, 0x78, 0x00, 0x10};

void sev_S_display(GPIO_typeDef *GPIOx , uint8_t num, uint8_t type)
{
	RCC_Periperhal_Enable(APB2_BUS, IOPA_EN);
	MCAL_GPIO_InitPort(GPIOx, GPIO_MODE_OUP_PP, GPIO_SPEED_2M);

	if(type == SEV_ANODE)
	{
		MCAL_GPIO_WritePort(GPIOx, num);
	}

	else if(type == SEV_KATHODE)
	{
		MCAL_GPIO_WritePort(GPIOx, ~num);
	}
}
