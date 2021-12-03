/*
 *  stm32f103c6.h
 *
 *  Created on: Jul 14, 2021
 *  Author: Eslam Gaber
 */

#ifndef INCLUDE_STM32F103X8_H_
#define INCLUDE_STM32F103X8_H_


/*================================================================================================
 											Includes
  ================================================================================================ */
#include <stdlib.h>
#include <stdint.h>

/* ---------------------------------- End of Includes Section ----------------------------------- */



/*================================================================================================
 										Peripherals' Base Addresses
  ================================================================================================ */

/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for Memories
 *  --------------------------------------------------------------------------------------------- */
#define SYSTEM_MEMORY_BASE					0x1FFFF000UL
#define FLASH_MEMORY_BASE					0x08000000UL
#define SRAM_MEMORY_BASE					0x20000000UL

#define CORTEX_M3_NTERNAL_PERIPHERALS		0xE0000000UL

#define NVIC_BASE							0xE000E100UL

#define NVIC_ISER_BASE						(NVIC_BASE + 0x000)
#define NVIC_ICER_BASE						(NVIC_BASE + 0x080)
#define NVIC_ISPR_BASE						(NVIC_BASE + 0x100)
#define NVIC_ICPR_BASE						(NVIC_BASE + 0x180)
#define NVIC_IABR_BASE						(NVIC_BASE + 0x200)


/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for AHB Peripherals
 *  --------------------------------------------------------------------------------------------- */

// Reset and Clock Control "RCC"
#define RCC_BASE							0x40021000UL


/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for ABP2 Peripherals
 *  --------------------------------------------------------------------------------------------- */

//	General Purpose Input Output "GPIO"
#define GPIOA_BASE							0x40010800UL
#define GPIOB_BASE							0x40010C00UL
#define GPIOC_BASE							0x40011000UL
#define GPIOD_BASE							0x40011400UL
#define GPIOE_BASE							0x40011800UL

// Alternative Function Input Output "AFIO"
#define AFIO_BASE							0x40010000UL


// External interrupt/event controller "EXTI"
#define EXTI_BASE							0x40010400UL

/* ----------------------------------------------------------------------------------------------
 * 		Base addresses for ABP1 Peripherals
 *  --------------------------------------------------------------------------------------------- */



/* -------------------------- End of Peripherals' Base Addresses Section ------------------------ */


/*================================================================================================
 										Peripherals' Register
  ================================================================================================ */

/* ----------------------------------------------------------------------------------------------
 * 		Peripheral Register for RCC
 *  --------------------------------------------------------------------------------------------- */
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;

/* ----------------------------------------------------------------------------------------------
 * 		Peripheral Register for GPIO
 *  --------------------------------------------------------------------------------------------- */
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_typeDef;

/* ----------------------------------------------------------------------------------------------
 * 		Peripheral Register for AFIO
 *  --------------------------------------------------------------------------------------------- */
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXRICR[4];
	uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_typeDef;

/* ----------------------------------------------------------------------------------------------
 * 		Peripheral Register for EXTI
 *  --------------------------------------------------------------------------------------------- */
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_typeDef;


/* ----------------------------------------------------------------------------------------------
 * 		Register for NVIC INTERRUPT CONTROLLER
 *  --------------------------------------------------------------------------------------------- */
typedef struct{
	volatile uint32_t ISER[3];
}NVIC_ISER_typedef;

typedef struct{
	volatile uint32_t ICER[3];
}NVIC_ICER_typedef;

typedef struct{
	volatile uint32_t ISPR[3];
}NVIC_ISPR_typedef;

typedef struct{
	volatile uint32_t ICPR[3];
}NVIC_ICPR_typedef;

typedef struct{
	volatile uint32_t IABR[3];
}NVIC_IABR_typedef;


#define NVIC_ISER					((NVIC_ISER_typedef *)(NVIC_ISER_BASE))
#define NVIC_ICER					((NVIC_ICER_typedef *)(NVIC_ICER_BASE))
#define NVIC_ISPR					((NVIC_ISPR_typedef *)(NVIC_ISPR_BASE))
#define NVIC_ICPR					((NVIC_ICPR_typedef *)(NVIC_ICPR_BASE))
#define NVIC_IABR					((NVIC_IABR_typedef *)(NVIC_IABR_BASE))




/* ----------------------------- End of Peripherals' Register Section --------------------------- */


/*================================================================================================
 										Peripheral Instants
  ================================================================================================ */
#define RCC							((RCC_TypeDef *)RCC_BASE)


// @ref GPIO_PORT_NUMBER
#define GPIO_PORT_A					((GPIO_typeDef *)GPIOA_BASE)
#define GPIO_PORT_B					((GPIO_typeDef *)GPIOB_BASE)
#define GPIO_PORT_C					((GPIO_typeDef *)GPIOC_BASE)
#define GPIO_PORT_D					((GPIO_typeDef *)GPIOD_BASE)
#define GPIO_PORT_E					((GPIO_typeDef *)GPIOE_BASE)

#define AFIO						((AFIO_typeDef *)AFIO_BASE)
#define EXTI						((EXTI_typeDef *)EXTI_BASE)

/* *----------------------------- End of Peripheral Instants Section ---------------------------- */


/*================================================================================================
 										Generic Macros
  ================================================================================================ */
#define setbit(reg, bitno)			 reg |= (1<<bitno)
#define clrbit(reg, bitno)			 reg &= (~(1<<bitno))
#define togglebit(reg, bitno)		 reg ^= (1<<bitno)
#define readbit(reg, bitno)			 ((reg >> bitno) & 1)
#define clear_reg(reg)				 reg = 0x00

/* *----------------------------- End of Generic Macros Section ---------------------------- */

#endif /* INCLUDE_STM32F103X8_H_ */
