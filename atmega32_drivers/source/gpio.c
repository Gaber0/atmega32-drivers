/*
 * gpio_driver.c
 *
 * Created: Sun, 6, 27, 2021 3:00:38 AM
 *  Author: Eslam
 */ 

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "gpio.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */

void GPIO_Port_Init(u8 GPIO_Port_num, u8 direction)
{
	switch(GPIO_Port_num)
	{
		case PA:
		DDRA = direction;
		break;
		
		case PB:
		DDRB = direction;
		break;
		
		case PC:
		DDRC = direction;
		break;
		
		case PD:
		DDRD = direction;
		break;
	}
}


void GPIO_Port_Set(u8 GPIO_Port_num, u8 value)
{
	switch(GPIO_Port_num)
	{
		case PA:
		PORTA = value;
		break;
		
		case PB:
		PORTB = value;
		break;
		
		case PC:
		PORTC = value;
		break;
		
		case PD:
		PORTD = value;
		break;
	}
}


u8 GPIO_Port_Read(u8 GPIO_Port_num)
{
	u8 data=0;
	switch(GPIO_Port_num)
	{
		case PA:
		data = PINA;
		break;

		case PB:
		data = PINB;
		break;
		
		case PC:
		data = PINC;
		break;
		
		case PD:
		data = PIND;
		break;
	}
	return data;
}


void GPIO_port_state(u8 GPIO_Port_num, u8 mode)
{
	if(mode == PULL_UP)
	{
		GPIO_Port_Set(GPIO_Port_num, HIGH);
	}
	
	else if(mode == Hi_Z)
	{
		GPIO_Port_Set(GPIO_Port_num, LOW);
	}
}


void GPIO_Pin_Init(u8 GPIO_Port_num, u8 GPIO_Pin_num, u8 direction)
{
	if( direction == OUTPUT )
	{
		switch(GPIO_Port_num)
		{
			case PA:
			setbit(DDRA, GPIO_Pin_num);
			break;
			
			case PB:
			setbit(DDRB, GPIO_Pin_num);
			break;
			
			case PC:
			setbit(DDRC, GPIO_Pin_num);
			break;
			
			case PD:
			setbit(DDRD, GPIO_Pin_num);
			break;
		}
	}
	
	else if( direction == INPUT )
	{
		switch(GPIO_Port_num)
		{
			case PA:
			clrbit(DDRA, GPIO_Pin_num);
			break;
			
			case PB:
			clrbit(DDRB, GPIO_Pin_num);
			break;
			
			case PC:
			clrbit(DDRC, GPIO_Pin_num);
			break;
			
			case PD:
			clrbit(DDRD, GPIO_Pin_num);
			break;
		}
	}
}


void GPIO_Pin_Set(u8 GPIO_Port_num, u8 GPIO_Pin_num, u8 value)
{
	if( value == HIGH )
	{
		switch(GPIO_Port_num)
		{
			case PA:
			setbit(PORTA, GPIO_Pin_num);
			break;
			
			case PB:
			setbit(PORTB, GPIO_Pin_num);
			break;
			
			case PC:
			setbit(PORTC, GPIO_Pin_num);
			break;
			
			case PD:
			setbit(PORTD, GPIO_Pin_num);
			break;
		}
	}
	
	else if( value == LOW )
	{
		switch(GPIO_Port_num)
		{
			case PA:
			clrbit(PORTA, GPIO_Pin_num);
			break;
			
			case PB:
			clrbit(PORTB, GPIO_Pin_num);
			break;
			
			case PC:
			clrbit(PORTC, GPIO_Pin_num);
			break;
			
			case PD:
			clrbit(PORTD, GPIO_Pin_num);
			break;
		}
	}
}


void GPIO_pin_state(u8 GPIO_Port_num, u8 GPIO_Pin_num, u8 mode)
{
	if( mode == PULL_UP )
	{
		GPIO_Pin_Set(GPIO_Port_num, GPIO_Pin_num, HIGH);
	}
	else if( mode == Hi_Z )
	{
		GPIO_Pin_Set(GPIO_Port_num, GPIO_Pin_num, LOW);
	}
}


u8 GPIO_Pin_Read(u8 GPIO_Port_num, u8 GPIO_Pin_num)
{
	u8 data=2;
	switch(GPIO_Port_num)
	{
		case PA:
		data = readbit(PINA, GPIO_Pin_num);
		break;

		case PB:
		data = readbit(PINB, GPIO_Pin_num);
		break;
		
		case PC:
		data = readbit(PINC, GPIO_Pin_num);
		break;
		
		case PD:
		data = readbit(PIND, GPIO_Pin_num);
		break;
	}
	return data;
}