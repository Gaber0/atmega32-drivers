/*
 * atmega32.h
 *
 * Created: Sun, 6, 27, 2021 2:59:59 AM
 *  Author: Eslam
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#ifndef F_CPU
#define F_CPU			8000000UL
#endif


/*================================================================================================
 											Includes
  ================================================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include "types.h"


/* ---------------------------------- End of Includes Section ----------------------------------- */



/*================================================================================================
 									Peripherals' Registers Base Addresses
  ================================================================================================ */


/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for GPIO's Registers
 *  --------------------------------------------------------------------------------------------- */
#define PORTA				*( (volatile u8 *)0x3B )
#define DDRA				*( (volatile u8 *)0x3A )
#define PINA				*( (volatile u8 *)0x39 )

#define PORTB				*( (volatile u8 *)0x38 )
#define DDRB				*( (volatile u8 *)0x37 )
#define PINB				*( (volatile u8 *)0x36 )

#define PORTC				*( (volatile u8 *)0x35 )
#define DDRC				*( (volatile u8 *)0x34 )
#define PINC				*( (volatile u8 *)0x33 )
		
#define PORTD				*( (volatile u8 *)0x32 )
#define DDRD				*( (volatile u8 *)0x31 )
#define PIND				*( (volatile u8 *)0x30 )


/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for Status Register "SREG"
 *  --------------------------------------------------------------------------------------------- */
#define SREG	*( (volatile u8 *)0x5F )


/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for External Interrupts registers "EXTI"
 *  --------------------------------------------------------------------------------------------- */
#define MCUCR				*( (volatile u8 *)0x55 )
#define MCUCSR				*( (volatile u8 *)0x54 )
#define GICR				*( (volatile u8 *)0x5B )
#define GIFR				*( (volatile u8 *)0x5A )


/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for USART Registers
 *  --------------------------------------------------------------------------------------------- */
#define UDR					*( (volatile u8 *)0x2C )
#define UCSRA				*( (volatile u8 *)0x2B )
#define UCSRB				*( (volatile u8 *)0x2A )
#define UCSRC				*( (volatile u8 *)0x40 )
#define UBRRL				*( (volatile u8 *)0x29 )
#define UBRRH				*( (volatile u8 *)0x40 )


/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for SPI Registers
 *  --------------------------------------------------------------------------------------------- */
#define SPCR				*( (volatile u8 *)0x2D )
#define SPSR				*( (volatile u8 *)0x2E )
#define SPDR				*( (volatile u8 *)0x2F )


/* -------------------------- End of Peripherals' Base Addresses Section ------------------------ */


/*================================================================================================
 									Bits of Peripherals' Register
  ================================================================================================ */

/* ----------------------------------------------------------------------------------------------
 * 		Bits of SREG Register
 *  --------------------------------------------------------------------------------------------- */
#define C_BIT				0
#define Z_BIT				1
#define N_BIT				2
#define V_BIT				3
#define S_BIT				4
#define H_BIT				5
#define T_BIT				6
#define I_BIT				7

/* -------------------------- End of Bits of Peripherals' Register Section ------------------------ */


/*================================================================================================
 										Generic Macros
  ================================================================================================ */
#define setbit(reg, bitno)			 reg |= (1<<bitno)
#define clrbit(reg, bitno)			 reg &= (~(1<<bitno))
#define togglebit(reg, bitno)		 reg ^= (1<<bitno)
#define readbit(reg, bitno)			 ((reg >> bitno) & 1)
#define clear_reg(reg)				 reg = 0x00

/* *----------------------------- End of Generic Macros Section ---------------------------- */


#endif /* ATMEGA32_H_ */