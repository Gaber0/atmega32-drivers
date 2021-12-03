/*
 * spi.h
 *
 * Created: Thu, 9, 23, 2021 12:21:10 AM
 *  Author: Eslam
 */ 


#ifndef SPI_H_
#define SPI_H_

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "gpio.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */


/*================================================================================================
 						USART Configuration Options "SET BY USER APPLICATION"
  ================================================================================================ */

// it determines the order of data in shift register. 
// it set based on @ref SPI_DATA_ORDER define.
#define SPI_DORD				LSB

// it determines the type of device in the connection.
// it set based on @ref SPI_DEVICE define.
#define SPI_DEVICE				MASTER

// it determines the mode of SPI.
// it set based on @ref SPI_MODE define
#define	SPI_MODE				MODE0

// it determines the speed mode of Master SPI.
// it set based on	@ref SPI_SPEED define
#define SPI_SPEED				NORMAL_SPEED

// it determines the clock rate of Master SPI.
// it set based on @ref SPI_Clock_Rate define
#define SPI_CLK_RATE			FOSC_4

/* -----------------------------------------------------------------------------------------------
 * 		SPI PIN CONFIG
 *  ---------------------------------------------------------------------------------------------- */
#define SPI_PORT		PB
#define SS				PIN4
#define MOSI			PIN5
#define MISO			PIN6
#define SCK				PIN7

/* ----------------------- End of USART Configuration Options Section --------------------------- */


/*================================================================================================
 									Macros Configuration References
  ================================================================================================ */

/* -----------------------------------------------------------------------------------------------
 * 		@ref SPI_DATA_ORDER define
 *  ---------------------------------------------------------------------------------------------- */
#define MSB			0
#define LSB			1

/* -----------------------------------------------------------------------------------------------
 * 		@ref SPI_DEVICE define
 *  ---------------------------------------------------------------------------------------------- */
#define SLAVE		0
#define MASTER		1

/* -----------------------------------------------------------------------------------------------
 * 		@ref SPI_MODE define
 *  ---------------------------------------------------------------------------------------------- */
#define MODE0		0
#define MODE1		1
#define MODE2		2
#define MODE3		3

/* -----------------------------------------------------------------------------------------------
 * 		@ref SPI_SPEED define
 *  ---------------------------------------------------------------------------------------------- */
#define NORMAL_SPEED		0
#define DOUBLE_SPEED		1

/* -----------------------------------------------------------------------------------------------
 * 		@ref SPI_Clock_Rate define
 *  ---------------------------------------------------------------------------------------------- */
#define FOSC_4			0	
#define FOSC_16			1
#define FOSC_64			2
#define FOSC_128		3


/*================================================================================================
 									Bits of Peripherals' Register
  ================================================================================================ */

/* ----------------------------------------------------------------------------------------------
 * 		Bits of SPI Status Register – SPSR
 *  --------------------------------------------------------------------------------------------- */
#define SPI2X   0
#define WCOL    6
#define SPIF    7


/* ----------------------------------------------------------------------------------------------
 * 		Bits of SPI Control Register – SPCR
 *  --------------------------------------------------------------------------------------------- */
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7


/* ------------------------- End of Macros Configuration References Section ---------------------- */


/*================================================================================================
 							 APIs Prototypes Supported by "MCAL SPI"
  ================================================================================================ */

/*
 * @Name:				- SPI_Init
 * @Description:  		- It initializes the SPI according to the USART Configuration Options.
 * @parameter []: 		- none
 * @return: 			- none
 * Note:				- none
 */
void SPI_Init();
u8 SPI_transfer(u8 byte);
u32 SPI_transfer_Integer(u32 num);

/* ---------------------- End of APIs Supported by "MCAL SPI" Section -------------------- */





#endif /* SPI_H_ */