/*
 * EXTI.h
 *
 *  Created on: Sep 5, 2021
 *      Author: Eslam
 */

#ifndef INCLUDE_EXTI_H_
#define INCLUDE_EXTI_H_

/*================================================================================================
 											Includes
  ================================================================================================ */
#include <stdint.h>
#include "stm32f103x8.h"
#include "gpio.h"
#include "clock.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */


/*================================================================================================
 									User Type Definitions (structures)
  ================================================================================================ */

/* -----------------------------------------------------------------------------------------------
 * 		Configuration Structure
 *  ---------------------------------------------------------------------------------------------- */

/*
 *  @Name:		- EXTI_GPIO_Mapping_t
 *  @brief:     - It contains configuration information for initializing GPIO pin by passing it to the MCAL_GPIO_InitPin().
 *
 *  @Members:
 * 				- PIN_Number : It specifies the Pin Number to be configured, it must be set based on @ref GPIO_PINx_define.
 * 				- GPIO_Mode  : It specifies the Mode to be configured to the selected pin, it must be set based on @ref GPIO_MODE_define.
 * 				- GPIO_Speed : It specifies the Speed to be configured to the selected pin, it must be set based on @ref GPIO_SPEED_define.
 * */
typedef struct{
	uint16_t EXTI_Line;					// @ref EXTIx define
	GPIO_typeDef * GPIO_PORT;			// @ref GPIO_PORTx define
	uint16_t GPIO_PIN;					// @ref GPIO_PIN_define
	uint16_t EXTI_IRQ;					// @ref EXTIx_IRQ define
}EXTI_GPIO_Mapping_t;


/*
 *  @Name:		- EXTI_GPIO_Mapping_t
 *  @brief:     - It contains configuration information for initializing GPIO pin by passing it to the MCAL_GPIO_InitPin().
 *
 *  @Members:
 * 				- PIN_Number : It specifies the Pin Number to be configured, it must be set based on @ref GPIO_PINx_define.
 * 				- GPIO_Mode  : It specifies the Mode to be configured to the selected pin, it must be set based on @ref GPIO_MODE_define.
 * 				- GPIO_Speed : It specifies the Speed to be configured to the selected pin, it must be set based on @ref GPIO_SPEED_define.
 * */
typedef struct{
	EXTI_GPIO_Mapping_t EXTI_pin;			// @ref EXTIx_PINy define
	uint8_t trigger;						// @ref EXTI_Trigger_define
	uint8_t IRQ_Enable;						// @ref EXTI_State_define
	void(* pf_IRQ_call)(void);				// pointer to function to be called in ISR
}EXTI_PinConfig_t;


/* ---------------------- End of User type definitions (structures) Section ---------------------- */

/*================================================================================================
 									Macros Configuration References
  ================================================================================================ */

/* -----------------------------------------------------------------------------------------------
 * 		@ref EXTIx_PINy define
 *  ---------------------------------------------------------------------------------------------- */
// EXTI0
#define EXTI0_PINA0						(EXTI_GPIO_Mapping_t){EXTI0, GPIO_PORT_A, GPIO_PIN0, EXTI0_IRQ}
#define EXTI0_PINB0						(EXTI_GPIO_Mapping_t){EXTI0, GPIO_PORT_B, GPIO_PIN0, EXTI0_IRQ}
#define EXTI0_PINC0						(EXTI_GPIO_Mapping_t){EXTI0, GPIO_PORT_C, GPIO_PIN0, EXTI0_IRQ}
#define EXTI0_PIND0						(EXTI_GPIO_Mapping_t){EXTI0, GPIO_PORT_D, GPIO_PIN0, EXTI0_IRQ}

// EXTI1
#define EXTI1_PINA1                     (EXTI_GPIO_Mapping_t){EXTI1, GPIO_PORT_A, GPIO_PIN1, EXTI1_IRQ}
#define EXTI1_PINB1                     (EXTI_GPIO_Mapping_t){EXTI1, GPIO_PORT_B, GPIO_PIN1, EXTI1_IRQ}
#define EXTI1_PINC1                     (EXTI_GPIO_Mapping_t){EXTI1, GPIO_PORT_C, GPIO_PIN1, EXTI1_IRQ}
#define EXTI1_PIND1                     (EXTI_GPIO_Mapping_t){EXTI1, GPIO_PORT_D, GPIO_PIN1, EXTI1_IRQ}

// EXTI2
#define EXTI2_PINA2                     (EXTI_GPIO_Mapping_t){EXTI2, GPIO_PORT_A, GPIO_PIN2, EXTI2_IRQ}
#define EXTI2_PINB2                     (EXTI_GPIO_Mapping_t){EXTI2, GPIO_PORT_B, GPIO_PIN2, EXTI2_IRQ}
#define EXTI2_PINC2                     (EXTI_GPIO_Mapping_t){EXTI2, GPIO_PORT_C, GPIO_PIN2, EXTI2_IRQ}
#define EXTI2_PIND2                     (EXTI_GPIO_Mapping_t){EXTI2, GPIO_PORT_D, GPIO_PIN2, EXTI2_IRQ}

// EXTI3
#define EXTI3_PINA3                     (EXTI_GPIO_Mapping_t){EXTI3, GPIO_PORT_A, GPIO_PIN3, EXTI3_IRQ}
#define EXTI3_PINB3                     (EXTI_GPIO_Mapping_t){EXTI3, GPIO_PORT_B, GPIO_PIN3, EXTI3_IRQ}
#define EXTI3_PINC3                     (EXTI_GPIO_Mapping_t){EXTI3, GPIO_PORT_C, GPIO_PIN3, EXTI3_IRQ}
#define EXTI3_PIND3                     (EXTI_GPIO_Mapping_t){EXTI3, GPIO_PORT_D, GPIO_PIN3, EXTI3_IRQ}

// EXTI4
#define EXTI4_PINA4                     (EXTI_GPIO_Mapping_t){EXTI4, GPIO_PORT_A, GPIO_PIN4, EXTI4_IRQ}
#define EXTI4_PINB4                     (EXTI_GPIO_Mapping_t){EXTI4, GPIO_PORT_B, GPIO_PIN4, EXTI4_IRQ}
#define EXTI4_PINC4                     (EXTI_GPIO_Mapping_t){EXTI4, GPIO_PORT_C, GPIO_PIN4, EXTI4_IRQ}
#define EXTI4_PIND4                     (EXTI_GPIO_Mapping_t){EXTI4, GPIO_PORT_D, GPIO_PIN4, EXTI4_IRQ}

// EXTI5
#define EXTI5_PINA5                     (EXTI_GPIO_Mapping_t){EXTI5, GPIO_PORT_A, GPIO_PIN5, EXTI5_IRQ}
#define EXTI5_PINB5                     (EXTI_GPIO_Mapping_t){EXTI5, GPIO_PORT_B, GPIO_PIN5, EXTI5_IRQ}
#define EXTI5_PINC5                     (EXTI_GPIO_Mapping_t){EXTI5, GPIO_PORT_C, GPIO_PIN5, EXTI5_IRQ}
#define EXTI5_PIND5                     (EXTI_GPIO_Mapping_t){EXTI5, GPIO_PORT_D, GPIO_PIN5, EXTI5_IRQ}

//EXTI6
#define EXTI6_PINA6                     (EXTI_GPIO_Mapping_t){EXTI6, GPIO_PORT_A, GPIO_PIN6, EXTI6_IRQ}
#define EXTI6_PINB6                     (EXTI_GPIO_Mapping_t){EXTI6, GPIO_PORT_B, GPIO_PIN6, EXTI6_IRQ}
#define EXTI6_PINC6                     (EXTI_GPIO_Mapping_t){EXTI6, GPIO_PORT_C, GPIO_PIN6, EXTI6_IRQ}
#define EXTI6_PIND6                     (EXTI_GPIO_Mapping_t){EXTI6, GPIO_PORT_D, GPIO_PIN6, EXTI6_IRQ}

//EXTI7
#define EXTI7_PINA7                     (EXTI_GPIO_Mapping_t){EXTI7, GPIO_PORT_A, GPIO_PIN7, EXTI7_IRQ}
#define EXTI7_PINB7                     (EXTI_GPIO_Mapping_t){EXTI7, GPIO_PORT_B, GPIO_PIN7, EXTI7_IRQ}
#define EXTI7_PINC7                     (EXTI_GPIO_Mapping_t){EXTI7, GPIO_PORT_C, GPIO_PIN7, EXTI7_IRQ}
#define EXTI7_PIND7                     (EXTI_GPIO_Mapping_t){EXTI7, GPIO_PORT_D, GPIO_PIN7, EXTI7_IRQ}

//EXTI8
#define EXTI8_PINA8                     (EXTI_GPIO_Mapping_t){EXTI8, GPIO_PORT_A, GPIO_PIN8, EXTI8_IRQ}
#define EXTI8_PINB8                     (EXTI_GPIO_Mapping_t){EXTI8, GPIO_PORT_B, GPIO_PIN8, EXTI8_IRQ}
#define EXTI8_PINC8                     (EXTI_GPIO_Mapping_t){EXTI8, GPIO_PORT_C, GPIO_PIN8, EXTI8_IRQ}
#define EXTI8_PIND8                     (EXTI_GPIO_Mapping_t){EXTI8, GPIO_PORT_D, GPIO_PIN8, EXTI8_IRQ}

//EXTI9
#define EXTI9_PINA9                     (EXTI_GPIO_Mapping_t){EXTI9, GPIO_PORT_A, GPIO_PIN9, EXTI9_IRQ}
#define EXTI9_PINB9                     (EXTI_GPIO_Mapping_t){EXTI9, GPIO_PORT_B, GPIO_PIN9, EXTI9_IRQ}
#define EXTI9_PINC9                     (EXTI_GPIO_Mapping_t){EXTI9, GPIO_PORT_C, GPIO_PIN9, EXTI9_IRQ}
#define EXTI9_PIND9                     (EXTI_GPIO_Mapping_t){EXTI9, GPIO_PORT_D, GPIO_PIN9, EXTI9_IRQ}

//EXTI10
#define EXTI10_PINA10                   (EXTI_GPIO_Mapping_t){EXTI10, GPIO_PORT_A, GPIO_PIN10, EXTI10_IRQ}
#define EXTI10_PINB10                   (EXTI_GPIO_Mapping_t){EXTI10, GPIO_PORT_B, GPIO_PIN10, EXTI10_IRQ}
#define EXTI10_PINC10                   (EXTI_GPIO_Mapping_t){EXTI10, GPIO_PORT_C, GPIO_PIN10, EXTI10_IRQ}
#define EXTI10_PIND10                   (EXTI_GPIO_Mapping_t){EXTI10, GPIO_PORT_D, GPIO_PIN10, EXTI10_IRQ}

//EXTI11
#define EXTI11_PINA11                   (EXTI_GPIO_Mapping_t){EXTI11, GPIO_PORT_A, GPIO_PIN11, EXTI11_IRQ}
#define EXTI11_PINB11                   (EXTI_GPIO_Mapping_t){EXTI11, GPIO_PORT_B, GPIO_PIN11, EXTI11_IRQ}
#define EXTI11_PINC11                   (EXTI_GPIO_Mapping_t){EXTI11, GPIO_PORT_C, GPIO_PIN11, EXTI11_IRQ}
#define EXTI11_PIND11                   (EXTI_GPIO_Mapping_t){EXTI11, GPIO_PORT_D, GPIO_PIN11, EXTI11_IRQ}

//EXTI12
#define EXTI12_PINA12                   (EXTI_GPIO_Mapping_t){EXTI12, GPIO_PORT_A, GPIO_PIN12, EXTI12_IRQ}
#define EXTI12_PINB12                   (EXTI_GPIO_Mapping_t){EXTI12, GPIO_PORT_B, GPIO_PIN12, EXTI12_IRQ}
#define EXTI12_PINC12                   (EXTI_GPIO_Mapping_t){EXTI12, GPIO_PORT_C, GPIO_PIN12, EXTI12_IRQ}
#define EXTI12_PIND12                   (EXTI_GPIO_Mapping_t){EXTI12, GPIO_PORT_D, GPIO_PIN12, EXTI12_IRQ}

//EXTI13
#define EXTI13_PINA13                   (EXTI_GPIO_Mapping_t){EXTI13, GPIO_PORT_A, GPIO_PIN13, EXTI13_IRQ}
#define EXTI13_PINB13                   (EXTI_GPIO_Mapping_t){EXTI13, GPIO_PORT_B, GPIO_PIN13, EXTI13_IRQ}
#define EXTI13_PINC13                   (EXTI_GPIO_Mapping_t){EXTI13, GPIO_PORT_C, GPIO_PIN13, EXTI13_IRQ}
#define EXTI13_PIND13                   (EXTI_GPIO_Mapping_t){EXTI13, GPIO_PORT_D, GPIO_PIN13, EXTI13_IRQ}

//EXTI14
#define EXTI14_PINA14                   (EXTI_GPIO_Mapping_t){EXTI14, GPIO_PORT_A, GPIO_PIN14, EXTI14_IRQ}
#define EXTI14_PINB14                   (EXTI_GPIO_Mapping_t){EXTI14, GPIO_PORT_B, GPIO_PIN14, EXTI14_IRQ}
#define EXTI14_PINC14                   (EXTI_GPIO_Mapping_t){EXTI14, GPIO_PORT_C, GPIO_PIN14, EXTI14_IRQ}
#define EXTI14_PIND14                   (EXTI_GPIO_Mapping_t){EXTI14, GPIO_PORT_D, GPIO_PIN14, EXTI14_IRQ}

//EXTI15
#define EXTI15_PINA15                   (EXTI_GPIO_Mapping_t){EXTI15, GPIO_PORT_A, GPIO_PIN15, EXTI15_IRQ}
#define EXTI15_PINB15                   (EXTI_GPIO_Mapping_t){EXTI15, GPIO_PORT_B, GPIO_PIN15, EXTI15_IRQ}
#define EXTI15_PINC15                   (EXTI_GPIO_Mapping_t){EXTI15, GPIO_PORT_C, GPIO_PIN15, EXTI15_IRQ}
#define EXTI15_PIND15                   (EXTI_GPIO_Mapping_t){EXTI15, GPIO_PORT_D, GPIO_PIN15, EXTI15_IRQ}


/* -----------------------------------------------------------------------------------------------
 * 		@ref EXTI_lINE_NUMBER
 *  ---------------------------------------------------------------------------------------------- */
#define EXTI0				0
#define EXTI1				1
#define EXTI2				2
#define EXTI3				3
#define EXTI4				4
#define EXTI5				5
#define EXTI6				6
#define EXTI7				7
#define EXTI8				8
#define EXTI9				9
#define EXTI10				10
#define EXTI11				11
#define EXTI12				12
#define EXTI13				13
#define EXTI14				14
#define EXTI15				15


/* -----------------------------------------------------------------------------------------------
 * 		@ref EXTI_IRQ_NUMBER
 *  ---------------------------------------------------------------------------------------------- */
#define EXTI0_IRQ						6
#define EXTI1_IRQ						7
#define EXTI2_IRQ						8
#define EXTI3_IRQ						9
#define EXTI4_IRQ						10
#define EXTI5_IRQ						23
#define EXTI6_IRQ						23
#define EXTI7_IRQ						23
#define EXTI8_IRQ						23
#define EXTI9_IRQ						23
#define EXTI10_IRQ						40
#define EXTI11_IRQ						40
#define EXTI12_IRQ						40
#define EXTI13_IRQ						40
#define EXTI14_IRQ						40
#define EXTI15_IRQ						40

/* -----------------------------------------------------------------------------------------------
 * 		@ref EXTI_Trigger_define
 *  ---------------------------------------------------------------------------------------------- */
#define EXTI_Trigger_FALLING			0
#define EXTI_Trigger_RISING				1
#define EXTI_Trigger_RISE_FALL			2

/* -----------------------------------------------------------------------------------------------
 * 		@ref EXTI_State_define
 *  ---------------------------------------------------------------------------------------------- */
#define EXTI_DISABLE					0
#define EXTI_ENABLE						1

/* ------------------------- End of Macros Configuration References Section ---------------------- */

/*================================================================================================
 										EXTI Macros
  ================================================================================================ */
// Enable EXTI IRQ in NVIC registers "ISERx"
#define NVIC_IRQ_ENABLE(IRQ)			NVIC_ISER->ISER[(IRQ/32)] |= (1<<(IRQ%32))


// Disable EXTI IRQ in NVIC registers "ICERx"
#define NVIC_IRQ_DISABLE(IRQ)			NVIC_ICER->ICER[(IRQ/32)] &= ~((1<<IRQ%32))


#define EXTICR_VALUE(x)				(x == GPIO_PORT_A)? 0 :\
									(x == GPIO_PORT_B)? 1 :\
									(x == GPIO_PORT_C)? 2 :\
									(x == GPIO_PORT_D)? 3 : 0

/* *----------------------------- End of EXTI Macros Section ---------------------------- */


/*================================================================================================
 							 APIs Prototypes Supported by "MCAL EXTI DRIVER"
  ================================================================================================ */
void MCAL_EXTI_DeInti();
void MCAL_EXTI_Init(EXTI_PinConfig_t *EXTI_config);


/* ---------------------- End of APIs Supported by "MCAL EXTI DRIVER" Section -------------------- */

#endif /* INCLUDE_EXTI_H_ */
