/*
 * gpio_driver.h
 *
 * Created: Sun, 6, 27, 2021 3:00:12 AM
 *  Author: Eslam
 */ 


#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "atmega32.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */

/*================================================================================================
 									Macros Configuration References
  ================================================================================================ */

/* -----------------------------------------------------------------------------------------------
 * 		@ref GPIO_PIN_state
 *  ---------------------------------------------------------------------------------------------- */
#define HIGH    					1
#define LOW     					0
#define OUTPUT						1	
#define INPUT						0
#define Hi_Z						0
#define PULL_UP						1

/* -----------------------------------------------------------------------------------------------
 * 		@ref GPIO_PORTx_define
 *  ---------------------------------------------------------------------------------------------- */
#define PA							1
#define PB							2
#define PC							3
#define PD							4

/* -----------------------------------------------------------------------------------------------
 * 		@ref GPIO_PINx_define
 *  ---------------------------------------------------------------------------------------------- */
#define PIN0						0
#define PIN1						1
#define PIN2						2
#define PIN3						3
#define PIN4						4
#define PIN5						5
#define PIN6						6
#define PIN7						7

/* ------------------------- End of Macros Configuration References Section ---------------------- */


/*================================================================================================
 							 APIs Prototypes Supported by "MCAL GPIO DRIVER"
  ================================================================================================ */

/*
 * @Name:				- GPIO_Port_Init
 * @Description:  		- It determines the direction of GPIO Port either acting as OUTPUT or INPUT.
 * @parameter [in]: 	- GPIO_Port_num -- determine the GPIO port name.
 * @parameter [in]: 	- direction -- determine the direction.
 * @return: 			- none
 * Note:				- none
 */
void GPIO_Port_Init(u8 GPIO_Port_num, u8 direction);


/*
 * @Name:				- GPIO_Port_Set
 * @Description:  		- determines the value of GPIO Port either acting as High or low.
 * @parameter [in]: 	- GPIO_Port_num -- used to determine the GPIO port name.
 * @parameter [in]: 	- value -- determine the value.
 * @return: 			- none
 * Note:				- none
 */

void GPIO_Port_Set(u8 GPIO_Port_num, u8 value);


/*
 * @Name:				- GPIO_port_state
 * @Description:  		- determines the state of GPIO port either Pull up resistor or high impedance.
 * @parameter [in]: 	- GPIO_Port_num -- determine the GPIO port name.
 * @parameter [in]: 	- mode -- determine the state of port.
 * @return: 			- none
 * Note:				- none
 */
void GPIO_port_state(u8 GPIO_Port_num, u8 mode);


/*
 * @Name:				- GPIO_Port_Read
 * @Description:  		- read the value of GPIO Port.
 * @parameter [in]: 	- GPIO_Port_num -- used to determine the GPIO port name.
 * @return: 			- value of port.
 * Note:				- none
 */
u8 GPIO_Port_Read(u8 GPIO_Port_num);


/*
 * @Name:				- GPIO_Pin_Init
 * @Description:  		- determines the direction of GPIO pin either acting as OUTPUT or INPUT.
 * @parameter [in]: 	- GPIO_Port_num -- used to determine the GPIO port name.
 * @parameter [in]: 	- GPIO_Pin_num -- used to determine the number of pin.
 * @parameter [in]: 	- direction -- used to determine the direction.
 * @return: 			- none
 * Note:				- none
 */
void GPIO_Pin_Init(u8 GPIO_Port_num, u8 GPIO_Pin_num, u8 direction);


/*
 * @Name:				- GPIO_Pin_Set
 * @Description:  		- determines the value of GPIO pin either acting as high or low.
 * @parameter [in]: 	- GPIO_Port_num -- used to determine the GPIO port name.
 * @parameter [in]: 	- GPIO_Pin_num -- used to determine the number of pin.
 * @parameter [in]: 	- value -- used to determine the value.
 * @return: 			- none
 * Note:				- none
 */
void GPIO_Pin_Set(u8 GPIO_Port_num, u8 GPIO_Pin_num, u8 value);


/*
 * @Name:				- GPIO_pin_state
 * @Description:  		- determines the state of GPIO pin either acting as pull up resistor or high impedance.
 * @parameter [in]: 	- GPIO_Port_num -- used to determine the GPIO port name.
 * @parameter [in]: 	- GPIO_Pin_num -- used to determine the number of pin.
 * @parameter [in]: 	- mode: -- used to determine the state of pin.
 * @return: 			- none
 * Note:				- none
 */
void GPIO_pin_state(u8 GPIO_Port_num, u8 GPIO_Pin_num, u8 mode);


/*
 * @Name:				- GPIO_Pin_Read
 * @Description:  		- read the value of GPIO pin.
 * @parameter [in]: 	- GPIO_Port_num -- used to determine the GPIO port name.
 * @parameter [in]: 	- GPIO_Pin_num -- used to determine the number of pin.
 * @return: 			- value of pin.
 * Note:				- none
 */
u8 GPIO_Pin_Read(u8 GPIO_Port_num, u8 GPIO_Pin_num);

/* ---------------------- End of APIs Supported by "MCAL GPIO DRIVER" Section -------------------- */


#endif /* GPIO_DRIVER_H_ */