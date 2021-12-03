/*
 * gpio.c
 *
 *  Created on: Jul 14, 2021
 *      Author: Eslam
 */

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "stm32f103x8.h"
#include "gpio.h"
#include <stdint.h>

/* ---------------------------------- End of Includes Section ----------------------------------- */


/*================================================================================================
 							 APIs definitions Supported by "MCAL GPIO DRIVER"
  ================================================================================================ */

void MCAL_GPIO_InitPin(GPIO_typeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	uint8_t number = 0;
	volatile uint32_t *config_reg = NULL;

	if(PinConfig->PIN_Number < 8)
	{
		config_reg = &GPIOx->CRL;
		number = (PinConfig->PIN_Number) * 4;
	}
	else
	{
		config_reg = &GPIOx->CRH;
		number = (PinConfig->PIN_Number - 8) * 4;
	}

	uint8_t PinValue = 0;

	PinValue = ( (PinConfig->GPIO_Mode << 2 ) | (PinConfig->GPIO_Speed) ) &0x0F;

	//Mask Four bits related to passed pin in configuration register (CRL or CRH)
	(*config_reg) &= ~(0x0F << number);
	(*config_reg) |= (PinValue << number);


	// after experiment, pull up or pull down must be put after setting configuration registers
	if(PinConfig->GPIO_Mode == GPIO_MODE_INP_PU)
	{
		setbit(GPIOx->ODR, PinConfig->PIN_Number);
	}

	else if(PinConfig->GPIO_Mode == GPIO_MODE_INP_PD)
	{
		clrbit(GPIOx->ODR, PinConfig->PIN_Number);
	}
}


void MCAL_GPIO_InitPort(GPIO_typeDef *GPIOx, uint8_t GPIO_Mode, uint8_t GPIO_Speed)
{
	uint8_t PinValue = ( (GPIO_Mode << 2 ) | (GPIO_Speed) ) &0x0F;

	uint32_t PortValue = 0;

	uint8_t i = 0;
	while(i < 8)
	{
		PortValue |= ( PinValue << (i*4) );
		i++;
	}
	GPIOx->CRL = PortValue;
	GPIOx->CRH = PortValue;

	if(GPIO_Mode == GPIO_MODE_INP_PU)
	{
		GPIOx->ODR = 0xFFFF;
	}

	else if(GPIO_Mode == GPIO_MODE_INP_PD)
	{
		GPIOx->ODR = 0x0000;
	}
}


uint8_t MCAL_GPIO_ReadPin (GPIO_typeDef *GPIOx,uint16_t PinNumber)
{
	uint8_t PIN_state = 0;

	PIN_state = readbit(GPIOx->IDR, PinNumber);
	/*if ( (GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		PIN_state = GPIO_PIN_SET;
	}
	else
	{
		PIN_state = GPIO_PIN_RESET;
	}*/
	return PIN_state;
}


uint16_t MCAL_GPIO_ReadPort (GPIO_typeDef *GPIOx)
{
	uint16_t PORT_state = 0;

	PORT_state = (uint16_t)GPIOx->IDR;
	return PORT_state;
}


void MCAL_GPIO_WritePin (GPIO_typeDef *GPIOx, uint16_t PinNumber, uint8_t Value)
{
	if(Value == HIGH)
	{
		setbit(GPIOx->ODR, PinNumber);
	}
	else
	{
		clrbit(GPIOx->ODR, PinNumber);
	}
}


void MCAL_GPIO_WritePort (GPIO_typeDef *GPIOx , uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;
}


void MCAL_GPIO_TogglePin (GPIO_typeDef *GPIOx,uint16_t PinNumber )
{
	togglebit(GPIOx->ODR, PinNumber);
}


void MCAL_GPIO_TogglePort (GPIO_typeDef *GPIOx)
{
	GPIOx->ODR ^= ( ~(0) ); // ~0 means 1 in all bits
}


uint8_t MCAL_GPIO_LockPin (GPIO_typeDef *GPIOx,uint16_t PinNumber)
{
	setbit(GPIOx->LCKR, PinNumber);

	// LOCK Key sequence
	setbit(GPIOx->LCKR, LCKK);
	clrbit(GPIOx->LCKR, LCKK);
	setbit(GPIOx->LCKR, LCKK);
	uint8_t lock_value = readbit(GPIOx->LCKR, LCKK);

	return (readbit(GPIOx->LCKR, LCKK))? GPIO_LOCK_Enabled : GPIO_LOCK_ERROR;
}


uint8_t MCAL_GPIO_LockPort (GPIO_typeDef *GPIOx)
{
	// SET all LCK PINS to lock all port
	GPIOx->LCKR = 0xFFFF;

	// LOCK Key sequence
	setbit(GPIOx->LCKR, LCKK);
	clrbit(GPIOx->LCKR, LCKK);
	setbit(GPIOx->LCKR, LCKK);
	uint8_t lock_value = readbit(GPIOx->LCKR, LCKK);

	return (readbit(GPIOx->LCKR, LCKK))? GPIO_LOCK_Enabled : GPIO_LOCK_ERROR;
}


/* ------------------------------------ End of APIs Section ------------------------------------- */

