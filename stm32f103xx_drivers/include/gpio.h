/*
 * gpio.h
 *
 *  Created on: Jul 14, 2021
 *      Author: Eslam
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_


/*================================================================================================
 											Includes
  ================================================================================================ */
#include <stdint.h>
#include "stm32f103x8.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */



/*================================================================================================
 									User Type Definitions (structures)
  ================================================================================================ */

/* -----------------------------------------------------------------------------------------------
 * 		Configuration Structure
 *  ---------------------------------------------------------------------------------------------- */

/*
 *  @Name:		- GPIO_PinConfig_t
 *  @brief:     - It contains configuration information for initializing GPIO pin by passing it to the MCAL_GPIO_InitPin().
 *
 *  @Members:
 * 				- PIN_Number : It specifies the Pin Number to be configured, it must be set based on @ref GPIO_PINx_define.
 * 				- GPIO_Mode  : It specifies the Mode to be configured to the selected pin, it must be set based on @ref GPIO_MODE_define.
 * 				- GPIO_Speed : It specifies the Speed to be configured to the selected pin, it must be set based on @ref GPIO_SPEED_define.
 * */
typedef struct
{
	uint16_t PIN_Number;
	uint8_t GPIO_Mode;
	uint8_t GPIO_Speed;
}GPIO_PinConfig_t;

/* ---------------------- End of User type definitions (structures) Section ---------------------- */


/*================================================================================================
 									Macros Configuration References
  ================================================================================================ */
/* -----------------------------------------------------------------------------------------------
 * 		@ref GPIO_PIN_state
 *  ---------------------------------------------------------------------------------------------- */
#define HIGH    					1
#define LOW     					0

/* -----------------------------------------------------------------------------------------------
 * 		@ref GPIO_RETURN_LOCK
 *  ---------------------------------------------------------------------------------------------- */
#define GPIO_LOCK_Enabled    		1
#define GPIO_LOCK_ERROR     	    0

/* -----------------------------------------------------------------------------------------------
 * 		@ref GPIO_PINx_define
 *  ---------------------------------------------------------------------------------------------- */
#define GPIO_PIN0					0
#define GPIO_PIN1					1
#define GPIO_PIN2					2
#define GPIO_PIN3					3
#define GPIO_PIN4					4
#define GPIO_PIN5					5
#define GPIO_PIN6					6
#define GPIO_PIN7					7
#define GPIO_PIN8					8
#define GPIO_PIN9					9
#define GPIO_PIN10					10
#define GPIO_PIN11					11
#define GPIO_PIN12					12
#define GPIO_PIN13					13
#define GPIO_PIN14					14
#define GPIO_PIN15					15


/* -----------------------------------------------------------------------------------------------
 * 		@ref GPIO_MODE_define
 *  ---------------------------------------------------------------------------------------------- */
#define GPIO_MODE_ANALOG			0
#define GPIO_MODE_INP_FLO			1
#define GPIO_MODE_INP_PU			2
#define GPIO_MODE_INP_PD			3
#define GPIO_MODE_OUP_PP			0
#define GPIO_MODE_OUP_OD			1
#define GPIO_MODE_AFIO_PP			2
#define GPIO_MODE_AFIO_OD			3


/* -----------------------------------------------------------------------------------------------
 * 		@ref GPIO_SPEED_define
 *  ---------------------------------------------------------------------------------------------- */
#define GPIO_SPEED_INPUT			0
#define GPIO_SPEED_10M				1
#define GPIO_SPEED_2M				2
#define GPIO_SPEED_50M				3

/* ------------------------- End of Macros Configuration References Section ---------------------- */


/*================================================================================================
 										Register's Bits
  ================================================================================================ */
/* bit 16 in the GPIO LCKR register */
#define LCKK		16

/* --------------------------- End of Register's Bits Section Section ---------------------------- */


/*================================================================================================
 							 APIs Prototypes Supported by "MCAL GPIO DRIVER"
  ================================================================================================ */

/*
 * @Name:				- MCAL_GPIO_Init
 * @Description:  		- Initializes the configuration of PIN according to the specified parameters in the PinConfig.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @parameter [in]: 	- PinConfig -- pointer to a GPIO_PinConfig_t structure that contains the configuration information for the specified GPIO PIN.
 * @return: 			- none
 * Note:				- Stm32F103C8 MCU has GPIO A,B,C,D,E Modules.
 * 				 	 	  But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 */
void MCAL_GPIO_InitPin(GPIO_typeDef *GPIOx, GPIO_PinConfig_t *PinConfig);


/*
 * @Name:				- MCAL_GPIO_InitPort
 * @Description: 		- It initializes the configuration of PORT according to the passed parameters.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @parameter [in]: 	- GPIO_Mode -- It specifies the Mode to be configured to the selected pin, it must be set based on @ref GPIO_MODE_define.
 * @parameter [in]:   	- GPIO_Speed -- It specifies the Speed to be configured to the selected pin, it must be set based on @ref GPIO_SPEED_define.
 * @return: 			- none
 * Note:				- Stm32F103C8 MCU has GPIO A,B,C,D,E Modules.
 * 				 	 	  But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 */
void MCAL_GPIO_InitPort(GPIO_typeDef *GPIOx, uint8_t GPIO_Mode, uint8_t GPIO_Speed);


/*
 * @Name:				- MCAL_GPIO_ReadPin.
 * @Description:		- It read input value for specific PIN.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @parameter [in]: 	- PinNumber -- It specifies the PIN to be read. Set by @ref GPIO_PINS_define.
 * @return:				- Input pin value (two values based on @ref GPIO_PIN_state ).
 * Note:				- none.
 */
uint8_t MCAL_GPIO_ReadPin (GPIO_typeDef *GPIOx,uint16_t PinNumber);


/*
 * @Name:				- MCAL_GPIO_ReadPort.
 * @Description: 		- It read the input value for specified PORT.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @return:				- Input pin value.
 * Note:				- none.
 */
uint16_t MCAL_GPIO_ReadPort (GPIO_typeDef *GPIOx);


/*
 * @Name:				- MCAL_GPIO_WritePin.
 * @Description:		- It write passed value on PIN.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @parameter [in]: 	- PinNumber -- It specifies the PIN to be written. Set by @ref GPIO_PINS_define.
 * @parameter [in]:		- Value -- Value that will be written to PIN, set by @ref GPIO_PIN_state.
 * @return:				- none.
 * Note:				- none.
 */
void MCAL_GPIO_WritePin (GPIO_typeDef *GPIOx, uint16_t PinNumber, uint8_t Value);


/*
 * @Name:				- MCAL_GPIO_WritePort.
 * @Description:		- It write passed value on PORT.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @parameter [in]:		- Value -- Value that will be written PORT.
 * @return:				- none.
 * Note: 				- none.
 */
void MCAL_GPIO_WritePort (GPIO_typeDef *GPIOx , uint16_t Value);


/*
 * @Name:				- MCAL_GPIO_TogglePin.
 * @Description:		- It toggles the specified GPIO pin.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @parameter [in]: 	- PinNumber -- It specifies the PIN to be toggled. Set by @ref GPIO_PINS_define.
 * @return:				- none.
 * Note					- none.
 */
void MCAL_GPIO_TogglePin (GPIO_typeDef *GPIOx,uint16_t PinNumber);

/*
 * @Name:				- MCAL_GPIO_TogglePort.
 * @Description:		- It toggles the specified GPIO PORT.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @return:				- none.
 * Note:				- none.
 */
void MCAL_GPIO_TogglePort (GPIO_typeDef *GPIOx);

/*
 * @Name:				- MCAL_GPIO_LockPin.
 * @Description: 		- It makes the PIN configuration to be locked and can't be changed until the next reset.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @parameter [in]: 	- PinNumber -- It specifies the PIN to be locked. Set by @ref GPIO_PINS_define.
 * @return: 			- GPIO_LOCK_Enabled -- if pin configuration is locked /or/ GPIO_LOCK_ERROR -- if pin  not locked (defined @ref GPIO_RETURN_LOCK).
 * Note:				- none.
 */
uint8_t MCAL_GPIO_LockPin (GPIO_typeDef *GPIOx,uint16_t PinNumber);

/*
 * @Name:				- MCAL_GPIO_LockPort.
 * @Description: 		- It makes the PORT configuration to be locked and can't be changed until the next reset.
 * @parameter [in]: 	- GPIOx -- It specifies the PORT Number, where x can be (A..G depending on device used).
 * @return: 			- GPIO_LOCK_Enabled -- if pin configuration is locked /or/ GPIO_LOCK_ERROR -- if pin  not locked (defined @ref GPIO_RETURN_LOCK).
 * Note:				- none.
 */
uint8_t MCAL_GPIO_LockPort (GPIO_typeDef *GPIOx);


/* ---------------------- End of APIs Supported by "MCAL GPIO DRIVER" Section -------------------- */


#endif /* INCLUDE_GPIO_H_ */
