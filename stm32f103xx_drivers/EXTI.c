/*
 * EXTI.c
 *
 *  Created on: Sep 5, 2021
 *      Author: Eslam
 */


#include "EXTI.h"

// global array of pointers to function
void(*pf_IRQ_array[15])(void);

void MCAL_EXTI_DeInti()
{
	// Reset all EXTI register to reset values
	clear_reg(EXTI->IMR);
	clear_reg(EXTI->EMR);
	clear_reg(EXTI->RTSR);
	clear_reg(EXTI->FTSR);
	clear_reg(EXTI->SWIER);
	EXTI->PR = ~(clear_reg(EXTI->PR));

	// disable EXTI_IRQ from NVIC
	NVIC_IRQ_DISABLE(6);
	NVIC_IRQ_DISABLE(7);
	NVIC_IRQ_DISABLE(8);
	NVIC_IRQ_DISABLE(9);
	NVIC_IRQ_DISABLE(10);
	NVIC_IRQ_DISABLE(23);
	NVIC_IRQ_DISABLE(40);
}

void MCAL_EXTI_Init(EXTI_PinConfig_t *EXTI_config)
{
	// GPIO pin Configuration acts as input floating
	GPIO_PinConfig_t pinconfig;
	pinconfig.PIN_Number = EXTI_config->EXTI_pin.GPIO_PIN;
	pinconfig.GPIO_Mode = GPIO_MODE_INP_FLO;
	pinconfig.GPIO_Speed = GPIO_SPEED_INPUT;
	MCAL_GPIO_InitPin(EXTI_config->EXTI_pin.GPIO_PORT, &pinconfig);


	//Enable EXTI LINE from AFIO registers
	uint8_t index = EXTI_config->EXTI_pin.EXTI_Line / 4;
	uint8_t position = (EXTI_config->EXTI_pin.EXTI_Line % 4) * 4;
	uint8_t value = EXTICR_VALUE(EXTI_config->EXTI_pin.GPIO_PORT);

	AFIO->EXRICR[index] &= ~(0xF << position);
	AFIO->EXRICR[index] |= (value<<position);

	//programming the two trigger registers with the desired edge detection
	if(EXTI_config->trigger == EXTI_Trigger_RISING)
	{
		//disable FALLING Trigger
		clrbit(EXTI->FTSR, EXTI_config->EXTI_pin.EXTI_Line);
		//Enable RISING Trigger
		setbit(EXTI->RTSR, EXTI_config->EXTI_pin.EXTI_Line);
	}

	else if(EXTI_config->trigger == EXTI_Trigger_FALLING)
	{
		//disable RISING Trigger
		setbit(EXTI->FTSR, EXTI_config->EXTI_pin.EXTI_Line);
		//Enable FALLING Trigger
		clrbit(EXTI->RTSR, EXTI_config->EXTI_pin.EXTI_Line);
	}

	else if(EXTI_config->trigger == EXTI_Trigger_RISE_FALL)
	{
		setbit(EXTI->RTSR, EXTI_config->EXTI_pin.EXTI_Line);
		setbit(EXTI->FTSR, EXTI_config->EXTI_pin.EXTI_Line);
	}

	//IRQ Handling CALLBACK
	pf_IRQ_array[EXTI_config->EXTI_pin.EXTI_Line] = EXTI_config->pf_IRQ_call;

	// Enabling the interrupt request by writing a ‘1’ to the corresponding bit in the interrupt mask register
	if(EXTI_config->IRQ_Enable == EXTI_ENABLE)
	{
		setbit(EXTI->IMR, EXTI_config->EXTI_pin.EXTI_Line);
		NVIC_IRQ_ENABLE(EXTI_config->EXTI_pin.EXTI_IRQ);
	}

	else if(EXTI_config->IRQ_Enable == EXTI_DISABLE)
	{
		clrbit(EXTI->IMR, EXTI_config->EXTI_pin.EXTI_Line);
		NVIC_IRQ_DISABLE(EXTI_config->EXTI_pin.EXTI_IRQ);
	}
}



void EXTI0_IRQHandler(void)
{
	setbit(EXTI->PR, EXTI0);
	pf_IRQ_array[0]();
}

void EXTI1_IRQHandler(void)
{
	setbit(EXTI->PR, EXTI1);
	pf_IRQ_array[0]();
}

void EXTI2_IRQHandler(void)
{
	setbit(EXTI->PR, EXTI2);
	pf_IRQ_array[0]();
}

void EXTI3_IRQHandler(void)
{
	setbit(EXTI->PR, EXTI3);
	pf_IRQ_array[0]();
}

void EXTI4_IRQHandler(void)
{
	setbit(EXTI->PR, EXTI4);
	pf_IRQ_array[0]();
}

void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & 1<<5)
	{
		setbit(EXTI->PR, EXTI5);
		pf_IRQ_array[5]();
	}

	if(EXTI->PR & 1<<6)
	{
		setbit(EXTI->PR, EXTI6);
		pf_IRQ_array[6]();
	}

	if(EXTI->PR & 1<<7)
	{
		setbit(EXTI->PR, EXTI7);
		pf_IRQ_array[7]();
	}

	if(EXTI->PR & 1<<8)
	{
		setbit(EXTI->PR, EXTI8);
		pf_IRQ_array[8]();
	}

	if(EXTI->PR & 1<<9)
	{
		setbit(EXTI->PR, EXTI9);
		pf_IRQ_array[9]();
	}
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & 1<<10)
	{
		setbit(EXTI->PR, EXTI10);
		pf_IRQ_array[10]();
	}

	if(EXTI->PR & 1<<11)
	{
		setbit(EXTI->PR, EXTI11);
		pf_IRQ_array[11]();
	}

	if(EXTI->PR & 1<<12)
	{
		setbit(EXTI->PR, EXTI12);
		pf_IRQ_array[12]();
	}

	if(EXTI->PR & 1<<13)
	{
		setbit(EXTI->PR, EXTI13);
		pf_IRQ_array[13]();
	}

	if(EXTI->PR & 1<<14)
	{
		setbit(EXTI->PR, EXTI14);
		pf_IRQ_array[14]();
	}

	if(EXTI->PR & 1<<15)
	{
		setbit(EXTI->PR, EXTI15);
		pf_IRQ_array[15]();
	}
}

