/*
 * spi.c
 *
 * Created: Thu, 9, 23, 2021 12:21:31 AM
 *  Author: Eslam
 */ 

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "spi.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */


void SPI_Init()
{
	#if(SPI_DORD == LSB)
		setbit(SPCR, DORD);
	#elif(SPI_DORD == MSB)
		clrbit(SPCR, DORD);
	#endif	
	
	#if(SPI_DEVICE == MASTER)
		// configure device as master
		setbit(SPCR, MSTR);
		
		// configure SPI pins 
		GPIO_Pin_Init(SPI_PORT, MOSI, OUTPUT);
		GPIO_Pin_Init(SPI_PORT, SCK, OUTPUT);
		GPIO_Pin_Init(SPI_PORT, SS, OUTPUT);
		
		#if(SPI_SPEED == DOUBLE_SPEED)
			setbit(SPSR, SPI2X);
		#elif(SPI_SPEED == NORMAL_SPEED)
			clrbit(SPSR, SPI2X);
		#endif
		
		// SPI clock rate
		SPCR &= ~(0x03);
		SPCR |= SPI_CLK_RATE;
		
	#elif(SPI_DEVICE == SLAVE)
		// configure device as slave
		clrbit(SPCR, MSTR);
		
		// configure SPI pins 
		GPIO_Pin_Init(SPI_PORT, MISO, OUTPUT);
		GPIO_Pin_Set(SPI_PORT, SS, HIGH);
	#endif
	
	
	// SPI mode
	SPCR &= ~(0x0C);
	SPCR |= SPI_MODE;
	
	// Enable SPI module
	setbit(SPCR, SPE);
}

u8 SPI_transfer(u8 byte)
{
	#if(SPI_DEVICE == MASTER)
		GPIO_Pin_Set(SPI_PORT, SS, LOW);
	#endif
	SPDR = byte;
	while(readbit(SPSR, SPIF) != 1 );
	return SPDR;
	#if(SPI_DEVICE == MASTER)
		GPIO_Pin_Set(SPI_PORT, SS, HIGH);
	#endif
}


u32 SPI_transfer_Integer(u32 TX_Num)
{
	u8 i = 0; 
	
	u8 *TX_ptr = &TX_Num;
	
	u32 RX_Num = 0;
	char *RX_ptr = &RX_Num;
	
	for (; i < 4; i++)
	{	
		RX_ptr[i] = SPI_transfer(TX_ptr[i]);
	}
	return RX_Num;
}

