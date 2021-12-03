/*
 * usart.h
 *
 * Created: Sat, 9, 11, 2021 2:03:29 AM
 *  Author: Eslam
 */ 


#ifndef USART_H_
#define USART_H_

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "gpio.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */


extern char buff[100];


/*================================================================================================
 						USART Configuration Options "SET BY USER APPLICATION"
  ================================================================================================ */
// set based on @ref USART_TX_SPEED define
#define USART_SPEED							NORMAL_SPEED

// set based on @ref USART_MODE define
#define USART_MODE							ASYNCHRONOUS

// set based on @ref USART_CHARACTER SIZE define
#define USART_CHAR_SIZE						SIZE_8BIT

// You can use datasheet for recommendation rates
#define BAUD_RATE							9600				

// THIS SET ONLY WITH ASYCHRONOUS MODE
// set based on @ref USART_PARITY_MODE define
#define USART_PARITY						PARITY_DISABLE

// set based on @ref USART_STOP_Bit define
#define USART_STOP							STOP_1BIT

// THIS SET ONLY WITH SYCHRONOUS MODE
//set based on @ref USART_CLOCK_POLARITY define
#define USART_TX_CLK						RISING_XCK_EDGE
#define USART_RX_CLK						FALLING_XCK_EDGE


/* ----------------------- End of USART Configuration Options Section --------------------------- */





/*================================================================================================
 									Macros Configuration References
  ================================================================================================ */
/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_INTERRUPT_STATE define
 *  ---------------------------------------------------------------------------------------------- */
#define USART_INT_DISABLE					0
#define USART_INT_ENABLE					1

/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_TX_SPEED define
 *  ---------------------------------------------------------------------------------------------- */
#define NORMAL_SPEED						0
#define U2X_SPEED							1

/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_ENABLE define
 *  ---------------------------------------------------------------------------------------------- */
#define USART_DISABLE						0
#define USART_ENABLE						1

/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_MODE define
 *  ---------------------------------------------------------------------------------------------- */
#define ASYNCHRONOUS					   0
#define SYNCHRONOUS						   1

/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_PARITY_MODE define
 *  ---------------------------------------------------------------------------------------------- */
#define PARITY_DISABLE						0
#define PARITY_EVEN							2
#define PARITY_ODD							3

/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_CHARACTER SIZE define
 *  ---------------------------------------------------------------------------------------------- */
#define SIZE_5BIT							0
#define SIZE_6BIT							1
#define SIZE_7BIT							2
#define SIZE_8BIT							3
#define SIZE_9BIT							4

/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_STOP_Bit define
 *  ---------------------------------------------------------------------------------------------- */
#define STOP_1BIT							0
#define STOP_2BIT							1

/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_CLOCK_POLARITY define
 *  ---------------------------------------------------------------------------------------------- */
#define RISING_XCK_EDGE						0
#define FALLING_XCK_EDGE					1


/* -----------------------------------------------------------------------------------------------
 * 		@ref USART_BAUD_RATE define
 *  ---------------------------------------------------------------------------------------------- */
#if(USART_SPEED == NORMAL_SPEED)
	#define UBRR		( F_CPU /16 * BAUD_RATE ) - 1
#elif(USART_SPEED == U2X_SPEED)
	#define UBRR		( F_CPU / (8 * BAUD_RATE) ) - 1
#elif(USART_MODE == SYNCHRONOUS)
	#define UBRR		( F_CPU / (2 * BAUD_RATE) ) - 1
#endif
/* ------------------------- End of Macros Configuration References Section ---------------------- */


struct queue{
	char data;
	struct queue *ptr;
};


/*================================================================================================
 									Bits of Peripherals' Register
  ================================================================================================ */

/* ----------------------------------------------------------------------------------------------
 * 		Bits of USART Control and Status Register A – UCSRA
 *  --------------------------------------------------------------------------------------------- */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* ----------------------------------------------------------------------------------------------
 * 		Bits of USART Control and Status Register B – UCSRB
 *  --------------------------------------------------------------------------------------------- */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* ----------------------------------------------------------------------------------------------
 * 		Bits of USART Control and Status Register C – UCSRC
 *  --------------------------------------------------------------------------------------------- */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0


/* -------------------------- End of Bits of Peripherals' Register Section ------------------------ */


/*================================================================================================
 							 APIs Prototypes Supported by "MCAL GPIO DRIVER"
  ================================================================================================ */

/*
 * @Name:				- usart_init
 * @Description:  		- It initializes the configuration of USART peripheral according to USART Configuration Options "SET BY USER APPLICATION" .
 * @parameter []: 		- none
 * @return: 			- none
 * Note:				- none
 */
void usart_init(void);

/*
 * @Name:				- usart_transmit
 * @Description:  		- It determines the direction of GPIO Port either acting as OUTPUT or INPUT.
 * @parameter [in]: 	- data -- determine the transmitted data through usart.
 * @return: 			- none
 * Note:				- none
 */
void usart_transmit(u8 data);

/*
 * @Name:				- usart_receive
 * @Description:  		- It returns the data that come from the transmitter.
 * @parameter []: 		- none.
 * @return: 			- received data.
 * Note:				- none
 */
u8 usart_receive();

void usart_TX_integer(u32 integer);
u32 usart_RX_integer();

void usart_TX_String(char *string);
char* usart_RX_String();

void usart_transmit_int(char *string);
void usart_receive_int();


#endif /* USART_H_ */