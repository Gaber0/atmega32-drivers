/*
 * usart.c
 *
 * Created: Sat, 9, 11, 2021 2:03:53 AM
 *  Author: Eslam
 */ 

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "usart.h"
#include "lcd.h"
#include "avr/interrupt.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */

static char *strPtr;
char buff[100];



void usart_init()
{
	// UBRRH register select
	clrbit(UCSRC, URSEL);
	
	// make condition to handle if UBRR value larger than 8 bits
	
	// Baud Rate
	UBRRL = 51;
	
	// UCSRC register select
	setbit(UCSRC, URSEL);
	
	#if(USART_MODE == SYNCHRONOUS)
		// Synchronous mode
		setbit(UCSRC, UMSEL);
		
		// Normal Transmission Mode
		clrbit(UCSRA, U2X);
		
		#if(USART_TX_CLK == RISING_XCK_EDGE)
			clrbit(UCSRC, UCPOL);
		#elif(USART_TX_CLK == FALLING_XCK_EDGE)
			setbit(UCSRC, UCPOL);
		#endif
	
	#elif(USART_MODE == ASYNCHRONOUS)
		
		// mask first 7 bits in UCSRC
		UCSRC &= (1 << 7);
	
		// Asynchronous mode
		clrbit(UCSRC, UMSEL);
		
		// Parity Mode
		UCSRC |= (USART_PARITY << UPM0);
		
		// Stop Bit Select
		UCSRC |= (USART_STOP << USBS);
		
		// character size 
		#if(USART_CHAR_SIZE == SIZE_9BIT)
			setbit(UCSRC, UCSZ0);
			setbit(UCSRC, UCSZ1);
			setbit(UCSRB, UCSZ2);	
		#else
			UCSRC |= (USART_CHAR_SIZE << UCSZ0);
			clrbit(UCSRB, UCSZ2);
		#endif
	
		#if(USART_SPEED == NORMAL_SPEED)
			clrbit(UCSRA, U2X);
		#elif(USART_SPEED == U2X_SPEED)
			setbit(UCSRA, U2X);
		#endif
				
	#endif
	
	// mask UCSRB register
	clear_reg(UCSRB);
	
	// Enable TX, RX
	setbit(UCSRB, TXEN);
	setbit(UCSRB, RXEN);
}

void usart_transmit(u8 data)
{
	while ( !(readbit(UCSRA, UDRE)) );
	UDR = data;	
}

u8 usart_receive()
{
	while( !(readbit(UCSRA, RXC)) );
	return UDR;
}

void usart_TX_integer(u32 integer)
{
	u8 i = 0;
	u8 *ptr = &integer;
	for(i = 0; i<4; i++)
	{
		usart_transmit(ptr[i]);
	}
}

u32 usart_RX_integer()
{
	u32 integer = 0;
	u8 *ptr = &integer;
	u8 i = 0;
	for(i = 0; i<4; i++)
	{
		ptr[i] = usart_receive();
	}
	return integer;
}

void usart_TX_String(char *string)
{
	u8 i = 0;
	while(string[i] != '\0')
	{
		usart_transmit(string[i++]);
	}
	usart_transmit('\0');
}

char* usart_RX_String()
{
	u8 i=0;
	buff[i] = usart_receive();			
	while(buff[i] != '\0')
	{
		i++;
		buff[i] = usart_receive();
	}
	buff[i]='\0';
	return buff;
}

void usart_transmit_int(char *string)
{
	setbit(UCSRB, TXCIE);
	strPtr = string;
	UDR = strPtr[0];
}

void usart_receive_int()
{
	lcd_Write_String(buff);
}

ISR(USART_RXC_vect)
{
	static u8 i = 0;			
	buff[i] = UDR;
	if(buff[i] != '\0')
	{
		i++;
	}
	else
	{
		clrbit(UCSRB, RXCIE);
		buff[i] = '\0';
		usart_receive_int();
	}
}

ISR(USART_TXC_vect)
{
	static u8 i = 1;
	if(strPtr[i] != '\0')
	{
		UDR = strPtr[i];
		i++;
	}
	else
	{
		UDR = '\0';
		clrbit(UCSRB, TXCIE);
	}
}


/*
struct queue* usart_RX_String()
{
	struct queue *start = malloc(sizeof(struct queue));
	struct queue *tmp = start;
	while( readbit(UCSRA, RXC) == 1 )
	{
		tmp->data = usart_receive();
		tmp->ptr = malloc(sizeof(struct queue));
		tmp = tmp->ptr;
	}
	return start;
}
*/