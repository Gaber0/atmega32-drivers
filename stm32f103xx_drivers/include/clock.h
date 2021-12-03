/*
 * clock.h
 *
 *  Created on: Aug 10, 2021
 *      Author: Eslam
 */

#ifndef INCLUDE_CLOCK_H_
#define INCLUDE_CLOCK_H_

/*================================================================================================
 											Includes
  ================================================================================================ */
#include <stdint.h>
#include "stm32f103x8.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */


/*================================================================================================
 						CLOCK Configuration Options "SET BY USER APPLICATION"
  ================================================================================================ */

/* defines the clock source that used as system clock based on @ref SYSTEM_CLOCK_SOURCE */
#define SYSTEM_CLOCK_SOURCE						HSI

/* defines PLL clock source based on @ref PLL_ENTRY_CLOCK_SOURCE */
#define PLL_ENTRY								HSI_DIVIDED_2

/* defines the PLL multiplication factor based on @ref PLL_MULTIPLICATION_FACTOR */
#define PLL_MUL_FACTOR							PLL_x_8

/* defines the division factor of the AHB clock, based on @ref AHB_HIGH_SPEED_PRESCALAR */
#define AHB_PRESCALAR 							SYSCLK_NOT_DIVIDED

/* defines the division factor of the APB low-speed clock (PCLK1), based on @ref (APB1, APB2)_SPEED_PRESCALAR
*  WARNING: the software has to set correctly these bits to not exceed 36 MHz on this domain. */
#define APB1_PRESCALAR 							HCLK_DIVIDED_2

/* defines the division factor of the APB high-speed clock (PCLK2) based on @ref (APB1, APB2)_SPEED_PRESCALAR */
#define APB2_PRESCALAR 							HCLK_DIVIDED_2

/* defines whether clock security system is enabled or disabled
 * When CSSON bit is set, the clock detector is enabled by hardware when the HSE oscillator is ready,
 * and disabled by hardware if a HSE clock failure is detected.
 * */
#define CLOCK_SECURITY 							CLOCK_SECURITY_ON


/* -----------------------------------------------------------------------------------------------
 * 		MCU OUTPUT GPIO
 *  ---------------------------------------------------------------------------------------------- */
#define RCC_MCO_PORT			GPIO_PORT_A
#define RCC_MCO_PIN				GPIO_PIN8


/* -----------------------------------------------------------------------------------------------
 * 		Oscillator Values
 *  ---------------------------------------------------------------------------------------------- */

/* Values set in Mhz */
#define HSI_Value				8
#define HSE_Value				8

#define MCO_MAX					50


/* ----------------------- End of CLOCK Configuration Options Section --------------------------- */


/*================================================================================================
 									Macros Configuration References
  ================================================================================================ */

/* -----------------------------------------------------------------------------------------------
 * 		@ref SYSTEM_CLOCK_SOURCE
 *  ---------------------------------------------------------------------------------------------- */
#define HSI								0
#define HSE								1
#define PLL								2
#define HSE_BYPASS						3


/* -----------------------------------------------------------------------------------------------
 * 		@ref PLL_ENTRY_CLOCK_SOURCE
 *  ---------------------------------------------------------------------------------------------- */
#define HSI_DIVIDED_2					0
#define HSE_DIVIDED_2					1
#define HSE_OSC							2


/* -----------------------------------------------------------------------------------------------
 * 		@ref PLL_MULTIPLICATION_FACTOR
 *  ---------------------------------------------------------------------------------------------- */
#define PLL_x_2							0b0000
#define PLL_x_3							0b0001
#define PLL_x_4							0b0010
#define PLL_x_5							0b0011
#define PLL_x_6							0b0100
#define PLL_x_7							0b0101
#define PLL_x_8							0b0110
#define PLL_x_9							0b0111
#define PLL_x_10						0b1000
#define PLL_x_11						0b1001
#define PLL_x_12						0b1010
#define PLL_x_13						0b1011
#define PLL_x_14						0b1100
#define PLL_x_15						0b1101
#define PLL_x_16						0b1110


/* -----------------------------------------------------------------------------------------------
 * 		@ref AHB_HIGH_SPEED_PRESCALAR
 *  ---------------------------------------------------------------------------------------------- */
#define SYSCLK_NOT_DIVIDED				0x00
#define SYSCLK_DIVIDED_2				0x08
#define SYSCLK_DIVIDED_4				0x09
#define SYSCLK_DIVIDED_8				0x0A
#define SYSCLK_DIVIDED_16				0x0B
#define SYSCLK_DIVIDED_64				0x0C
#define SYSCLK_DIVIDED_128				0x0D
#define SYSCLK_DIVIDED_256				0x0E
#define SYSCLK_DIVIDED_512				0x0F


/* -----------------------------------------------------------------------------------------------
 * 		@ref (APB1, APB2)_SPEED_PRESCALAR
 *  ---------------------------------------------------------------------------------------------- */
#define HCLK_NOT_DIVIDED				0x00
#define HCLK_DIVIDED_2					0x04
#define HCLK_DIVIDED_4					0x05
#define HCLK_DIVIDED_8					0x06
#define HCLK_DIVIDED_16					0x07


/* -----------------------------------------------------------------------------------------------
 * 		@ref CLOCK_SECURITY
 *  ---------------------------------------------------------------------------------------------- */
#define CLOCK_SECURITY_ON 				1
#define CLOCK_SECURITY_OFF 				0


/* -----------------------------------------------------------------------------------------------
 * 		@ref MCU_CLOCK_OUTPUT
 *  ---------------------------------------------------------------------------------------------- */
#define RCC_MCO_NoClock                 ((uint8_t)0x00)
#define RCC_MCO_SYSCLK                  ((uint8_t)0x04)
#define RCC_MCO_HSI                     ((uint8_t)0x05)
#define RCC_MCO_HSE                     ((uint8_t)0x06)
#define RCC_MCO_PLLCLK_Div2  		    ((uint8_t)0x07)


/* -----------------------------------------------------------------------------------------------
 * 		@ref BUS_CLOCK_ENABLE
 *  ---------------------------------------------------------------------------------------------- */
#define AHB_BUS							0
#define APB1_BUS						1
#define APB2_BUS						2


/* -----------------------------------------------------------------------------------------------
 * 		MCO Return Status
 *  ---------------------------------------------------------------------------------------------- */
#define MCO_OK							1
#define MCO_ERROR 						0


/* --------------------------- End of Macros Configuration Section ------------------------------- */

/*================================================================================================
 									Bits of Peripherals' Register
  ================================================================================================ */

/* -----------------------------------------------------------------------------------------------
 * 		Clock control register (RCC_CR)
 *  ---------------------------------------------------------------------------------------------- */
#define HSION							0
#define HSIRDY							1
#define HSITRIM							3
#define HSICAL							8
#define HSEON							16
#define HSERDY							17
#define HSEBYP							18
#define CSSON							19
#define PLLON							24
#define PLLRDY							25


/* -----------------------------------------------------------------------------------------------
 * 		Clock configuration register (RCC_CFGR)
 *  ---------------------------------------------------------------------------------------------- */
#define SW								0
#define SWS								2
#define HPRE							4
#define PPRE1							8
#define PPRE2							11
#define ADCPRE							14
#define PLLSRC							16
#define PLLXTPRE						17
#define PLLMUL							18
#define USBPRE							22
#define MCO								24


/* -----------------------------------------------------------------------------------------------
 * 		APB2 peripheral reset register (RCC_APB2RSTR)
 *  ---------------------------------------------------------------------------------------------- */
#define AFIO_RST							0
#define IOPA_RST							2
#define IOPB_RST							3
#define IOPC_RST							4
#define IOPD_RST							5
#define IOPE_RST							6
#define IOPF_RST							7
#define IOPG_RST							8
#define ADC1_RST							9
#define ADC2_RST							10
#define TIM1_RST							11
#define SPI1_RST							12
#define TIM8_RST							13
#define USART1_RST							14
#define ADC3_RST							15
#define TIM9_RST							19
#define TIM10_RST							20
#define TIM11_RST							21


/* -----------------------------------------------------------------------------------------------
 * 		APB1 peripheral reset register (RCC_APB1RSTR)
 *  ---------------------------------------------------------------------------------------------- */
#define TIM2_RST							0
#define TIM3_RST							1
#define TIM4_RST							2
#define TIM5_RST							3
#define TIM6_RST							4
#define TIM7_RST							5
#define TIM12_RST							6
#define TIM13_RST							7
#define TIM14_RST							8
#define WWDG_RST							11
#define SPI2_RST							14
#define SPI3_RST							15
#define USART2_RST							17
#define USART3_RST							18
#define USART4_RST							19
#define USART5_RST							20
#define I2C1_RST							21
#define I2C2_RST							22
#define USB_RST								23
#define CAN_RST								25
#define BKP_RST								27
#define PWR_RST								28
#define DAC_RST								29


/* -----------------------------------------------------------------------------------------------
 * 		Control/status register (RCC_CSR)
 *  ---------------------------------------------------------------------------------------------- */
#define LSION								0
#define LSIRDY								1
#define RMVF								24
#define PINRSTF								26
#define PORRSTF								27
#define SFTRSTF								28
#define IWDGRSTF							29
#define WWDGSTF								30
#define LPWRRSTF							31


/* -----------------------------------------------------------------------------------------------
 * 		AHB peripheral Enable register (RCC_AHBENR)
 *  ---------------------------------------------------------------------------------------------- */
#define DMA1_EN							0
#define DMA2_EN							1
#define SRAM_EN							2
#define FLITF_EN						4
#define CRCE_EN							6
#define FSMC_EN							8
#define SDIO_EN							10


/* -----------------------------------------------------------------------------------------------
 * 		APB2 peripheral Enable register (RCC_APB2ENBR)
 *  ---------------------------------------------------------------------------------------------- */
#define AFIO_EN							0
#define IOPA_EN							2
#define IOPB_EN							3
#define IOPC_EN							4
#define IOPD_EN							5
#define IOPE_EN							6
#define IOPF_EN							7
#define IOPG_EN							8
#define ADC1_EN							9
#define ADC2_EN							10
#define TIM1_EN							11
#define SPI1_EN							12
#define TIM8_EN							13
#define USART1_EN						14
#define ADC3_EN							15
#define TIM9_EN							19
#define TIM10_EN						20
#define TIM11_EN						21


/* -----------------------------------------------------------------------------------------------
 * 		APB1 peripheral Enable register (RCC_APB1ENBR)
 *  ---------------------------------------------------------------------------------------------- */
#define TIM2_EN							0
#define TIM3_EN							1
#define TIM4_EN							2
#define TIM5_EN							3
#define TIM6_EN							4
#define TIM7_EN							5
#define TIM12_EN						6
#define TIM13_EN						7
#define TIM14_EN						8
#define WWDG_EN							11
#define SPI2_EN							14
#define SPI3_EN							15
#define USART2_EN						17
#define USART3_EN						18
#define USART4_EN						19
#define USART5_EN						20
#define I2C1_EN							21
#define I2C2_EN							22
#define USB_EN							23
#define CAN_EN							25
#define BKP_EN							27
#define PWR_EN							28
#define DAC_EN							29


/* ----------------------- End of Bits of Peripherals' Register Section -------------------------- */


/*================================================================================================
 							 APIs Prototypes Supported by "MCAL RCC DRIVER"
  ================================================================================================ */

/*
 * @Name:				- RCC_Init.
 * @Description: 		- Initializes the RCC Oscillators according to the specified parameters.
 * @parameter []: 		- none
 * @return: 			- none
 * Note:				- none
 */
void RCC_Init();

/*
 * @Name:				- RCC_DEinit.
 * @Description: 		- Resets the RCC clock configuration to the default reset state.
 * @parameter []: 		- none
 * @return: 			- none
 * Note:				- The default reset state of the clock configuration is given below:
  *           				- HSI ON and used as system clock source.
  *							- HSE, HSE_BYPASS and PLL OFF.
  *           				- AHB, APB1 and APB2 prescaler set to 1.
  *           				- CSS and MCO OFF
  *           				- All clock interrupts disabled
  * 					- This function does not modify the configuration of the Peripheral clocksLSI, LSE and RTC clocks.
  *
 */
void RCC_DEinit();

/*
 * @Name:				- RCC_MCO.
 * @Description: 		- Selects the clock source to output on MCO pin.
 * @parameter [in]: 	- MCO_Source -- specifies the clock source to output, set based on @ref MCU_CLOCK_OUTPUT.
 * @return: 			- none
 * Note:				- MCO pin should be configured in alternate function mode, the function handle this inside it.
 */
uint8_t RCC_MCO(uint8_t MCO_Source);
/*
 * @Name:				- RCC_Periperhal_Enable
 * @Description: 		- Enables the clock for the selected peripheral.
 * @parameter [in]: 	- Bus -- specifies the bus that connected to the peripheral, set based on @ref BUS_CLOCK_ENABLE.
 * 						- peripheral -- specifies the peripheral, set based on
 * 						  @ref AHB_PERIPHERAL_CLOCK_ENABLE, @ref APB1_PERIPHERAL_CLOCK_ENABLE, @ref APB2_PERIPHERAL_CLOCK_ENABLE
 * @return: 			- none
 * Note:				- After reset, the peripheral clock (used for registers read/write access) is disabled
 * 						  and the application software has to enable this clock before using it.
 */
void RCC_Periperhal_Enable(uint8_t Bus, uint8_t peripheral);

/*
 * @Name:				- RCC_Periperhal_Disable
 * @Description: 		- Disables the clock for the selected peripheral.
 * @parameter [in]: 	- Bus -- specifies the bus that connected to the peripheral, set based on @ref BUS_CLOCK_ENABLE.
 * 						- peripheral -- specifies the peripheral, set based on
 * 						  @ref AHB_PERIPHERAL_CLOCK_ENABLE, @ref APB1_PERIPHERAL_CLOCK_ENABLE, @ref APB2_PERIPHERAL_CLOCK_ENABLE
 * @return: 			- none
 * Note:				- none
 */
void RCC_Periperhal_Disable(uint8_t Bus, uint8_t peripheral);

/*
 * @Name:				- RCC_Periperhal_Reset
 * @Description: 		- reset the values of peripheral registers to the default values.
 * @parameter [in]: 	- Bus -- specifies the bus that connected to the peripheral, set based on @ref BUS_CLOCK_ENABLE.
 * 						- peripheral -- specifies the peripheral, set based on
 * 						  @ref AHB_PERIPHERAL_CLOCK_ENABLE, @ref APB1_PERIPHERAL_CLOCK_ENABLE, @ref APB2_PERIPHERAL_CLOCK_ENABLE
 * @return: 			- none
 * Note:				- none
 */
void RCC_Periperhal_Reset(uint8_t Bus, uint8_t peripheral);


/*
 * @Name:				- RCC_Get_SYSCLK.
 * @Description: 		- Indicates the system clock source.
 * @parameter []: 		- none
 * @return: 			- return Value that represent system clock source according to the following values:
 * 							0 -> HSI oscillator used as system clock
 *							1 -> HSE oscillator used as system clock
 *							2 -> PLL used as system clock
 *							3 -> not applicable
 * Note:				- none
 */
uint8_t RCC_Get_SYS_Source();



uint8_t RCC_Get_SYS_Freq();

void delay_ms(int ms);

/* ----------------- End of APIs Prototypes Supported by "MCAL RCC DRIVER" Section -------------- */



#endif /* INCLUDE_CLOCK_H_ */
