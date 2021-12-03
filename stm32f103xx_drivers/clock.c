/*
 * clock.c
 *
 *  Created on: Aug 10, 2021
 *      Author: Eslam
 */

#include "stm32f103x8.h"
#include "gpio.h"
#include "clock.h"

uint8_t Sys_clock = 0;


void RCC_Init()
{
	// Clock Source is HSI
#if(SYSTEM_CLOCK_SOURCE == HSI)

	// Bit 0 HSION: Internal high-speed clock enable
	setbit(RCC->CR, HSION);

	// Bits 1:0 SW: System clock switch
	// 00: HSI selected as system clock
	RCC->CFGR &= ~(3<<0);

	// wait until internal 8 MHz RC oscillator (HSI) is stable
	while(!readbit(RCC->CR, HSIRDY));

	Sys_clock = HSI;

	// Clock Source is HSE
#elif(SYSTEM_CLOCK_SOURCE == HSE)

	// Bit 16 HSEON: HSE clock enable
	setbit(RCC->CR, HSEON);

	// Bits 1:0 SW: System clock switch
	// 01: HSE selected as system clock
	RCC->CFGR |=(1<<0);
	RCC->CFGR &= ~(1<<1);

	// wait until HSE oscillator is stable
	while(!readbit(RCC->CR, HSERDY));
	/*
	{
		ms_delay(put the time taken for HSE to be ready)
		if(( RCC->CR >> 17) & 1 )== 0)
			return RCC_timeout;
	}
	 */

	Sys_clock = HSE;

	// Clock Source is PLL
#elif(SYSTEM_CLOCK_SOURCE == PLL)

	#if(PLL_ENTRY == HSI_DIVIDED_2)

		// Bit 0 HSION: Internal high-speed clock enable
		setbit(RCC->CR, HSION);


		// Bit 16 PLLSRC: PLL entry clock source
		// 0: HSI oscillator clock / 2 selected as PLL input clock
		clrbit(RCC->CFGR, PLLSRC);


	#elif(PLL_ENTRY == HSE_DIVIDED_2)

		// Bit 16 HSEON: HSE clock enable
		setbit(RCC->CR, HSEON);

		// Bit 17 PLLXTPRE: HSE divider for PLL entry
		// 1: HSE clock divided by 2
		setbit(RCC->CFGR, PLLXTPRE);

		// Bit 16 PLLSRC: PLL entry clock source
		// 1: HSE oscillator clock selected as PLL input clock
		setbit(RCC->CFGR, PLLSRC);


	#elif(PLL_ENTRY == HSE_OSC)
		// Bit 16 HSEON: HSE clock enable
		setbit(RCC->CR, HSEON);

		// Bit 17 PLLXTPRE: HSE divider for PLL entry
		// 0: HSE clock not divided
		clrbit(RCC->CFGR, PLLXTPRE);

		// Bit 16 PLLSRC: PLL entry clock source
		// 1: HSE oscillator clock selected as PLL input clock
		setbit(RCC->CFGR, PLLSRC);
	#endif

		// Bits 21:18 PLLMUL: PLL multiplication factor
		RCC->CFGR &= ( ~(15 << PLLMUL) );
		RCC->CFGR |= ( PLL_MUL_FACTOR << PLLMUL);

		// Bits 1:0 SW: System clock switch
		// 10: PLL selected as system clock
		clrbit(RCC->CFGR, 0);
		setbit(RCC->CFGR, 1);

		// Bit 24 PLLON: PLL enable
		setbit(RCC->CR, PLLON);

		// wait until the PLL is locked
		while(!readbit(RCC->CR, PLLRDY));

		Sys_clock = PLL;


#elif(SYSTEM_CLOCK_SOURCE == HSE_BYPASS)

		// The HSEBYP bit can be written only if the HSE oscillator is disabled.
		clrnit(RCC->CR, HSEON);

		// Bit 18 HSEBYP: External high-speed clock bypass
		// 1: external 4-16 MHz oscillator bypassed with external clock
		setbit(RCC->CR, HSEBYP);

		// Bit 16 HSEON: HSE clock enable
		setnit(RCC->CR, HSEON);

		// Bits 1:0 SW: System clock switch
		// 01: HSE selected as system clock
		setbit(RCC->CFGR, 0);
		clrbit(RCC->CFGR, 1);

		// Bit 16 PLLSRC: PLL entry clock source
		// 1: HSE oscillator clock selected as PLL input clock
		clrnit(RCC->CFGR, PLLSRC);

		// wait until HSE oscillator is stable
		while(!readbit(RCC->CR, HSERDY));

		Sys_clock = HSE_BYPASS;

#endif

	//Bit 19 CSSON: Clock security system enable
#if(CLOCK_SECURITY == CLOCK_SECURITY_ON)

		// 1: Clock detector ON (Clock detector ON if the HSE oscillator is ready , OFF if not)
		setbit(RCC->CR, CSSON);

#elif(CLOCK_SECURITY == CLOCK_SECURITY_OFF)

		// 0: Clock detector OFF
		clrbit(RCC->CR, CSSON);

#endif

		//Set the prescalar for AHB, APB1, APB2

		RCC->CFGR &= ( ~( 15 << HPRE) );
		RCC->CFGR |= ( AHB_PRESCALAR << HPRE );

		RCC->CFGR &= ( ~( 7 << PPRE1) );
		RCC->CFGR |= ( APB1_PRESCALAR << PPRE1 );

		RCC->CFGR &= ( ~( 7 << PPRE2) );
		RCC->CFGR |= ( APB2_PRESCALAR << PPRE2 );
}


void RCC_DEinit()
{
	// Bit 0 HSION: Internal high-speed clock enable
	setbit(RCC->CR, HSION);

	// wait until internal 8 MHz RC oscillator (HSI) is stable
	while(!readbit(RCC->CR, HSIRDY));

	// Internal high-speed clock trimming
	// The default value is 16, which, when added to the HSICAL value, should trim the HSI to 8 MHz ± 1%.
	// mask HSITRIM bits [3-7]
	RCC->CR &= ~(63 >> 2);
	// set value 16 to HSITRIM bits
	RCC->CR |= ( 16 <<3 );

	// reset CFGR register
	clear_reg(RCC->CFGR);

	// wait till clock switch is read "SWS" bits
	while( ( ( RCC->CFGR >> 2) & 3) != 0 );

	// clear PLLON bit
	clrbit(RCC->CR, PLLON);

	/* Wait till PLL is disabled */
	while(readbit(RCC->CR, PLLRDY));

	/* Reset HSEON & CSSON bits */
	clrbit(RCC->CR, HSEON);
	clrbit(RCC->CR, CSSON);

	  /* Wait till HSE is disabled */
	while(readbit(RCC->CR, HSERDY));

	 /* Reset HSEBYP bit */
	clrbit(RCC->CR, HSEBYP);

	/* Disable all interrupts */
	clear_reg(RCC->CIR);

	/* Reset all CSR flags */
	setbit(RCC->CSR, RMVF);

	Sys_clock = HSI;
}


uint8_t RCC_MCO(uint8_t MCO_Source)
{
	// The configuration registers of the corresponding GPIO port must be programmed in alternate function mode push pull

	GPIO_PinConfig_t MCO_PinConfig;
	MCO_PinConfig.PIN_Number = RCC_MCO_PIN;
	MCO_PinConfig.GPIO_Mode = GPIO_MODE_AFIO_PP;
	MCO_PinConfig.GPIO_Speed = GPIO_SPEED_2M;

	MCAL_GPIO_InitPin(GPIO_PORT_A, &MCO_PinConfig);

	if( RCC_Get_SYS_Freq() <= MCO_MAX)
	{
		RCC->CFGR &= ( ~(7 << MCO) );
		RCC->CFGR |= ( MCO_Source << MCO );
		return MCO_OK;
	}
	else
	{
		return MCO_ERROR;
	}
}


void RCC_Periperhal_Enable(uint8_t Bus, uint8_t peripheral)
{
	switch(Bus)
	{
		// the peripheral located on AHB Bus
	case AHB_BUS:
		setbit(RCC->AHBENR, peripheral);
		break;

		// the peripheral located on APB1 Bus
	case APB1_BUS:
		setbit(RCC->APB1ENR, peripheral);
		break;

		// the peripheral located on APB2 Bus
	case APB2_BUS:
		setbit(RCC->APB2ENR, peripheral);
		break;
	}
}


void RCC_Periperhal_Disable(uint8_t Bus, uint8_t peripheral)
{
	switch(Bus)
	{
	case AHB_BUS:
		clrbit(RCC->AHBENR, peripheral);
		break;

	case APB1_BUS:
		clrbit(RCC->APB1ENR, peripheral);
		break;

	case APB2_BUS:
		clrbit(RCC->APB2ENR, peripheral);
		break;
	}
}


void RCC_Periperhal_Reset(uint8_t Bus, uint8_t peripheral)
{
	switch(Bus)
	{
	case APB1_BUS:
		setbit(RCC->APB1RSTR, peripheral);
		clrbit(RCC->APB1RSTR, peripheral);
		break;

	case APB2_BUS:
		setbit(RCC->APB2RSTR, peripheral);
		clrbit(RCC->APB2RSTR, peripheral);
		break;
	}
}


uint8_t RCC_Get_SYS_Source()
{
    return Sys_clock;
}


uint8_t RCC_Get_SYS_Freq()
{
	uint8_t sysFreq = 0;
	// declare variable in clock init () and clock deinit() contain the clock source after initializing
	if(Sys_clock == HSI)
	{
		sysFreq = HSI_Value;
	}
	else if(Sys_clock == HSE)
	{
		sysFreq = HSE_Value;
	}
	else if(Sys_clock == PLL)
	{
		switch(PLL_ENTRY)
		{
		case HSI_DIVIDED_2:
			sysFreq = ( (HSI_Value / 2) * (PLL_MUL_FACTOR + 2) );
			break;

		case HSE_DIVIDED_2:
			sysFreq = ( (HSE_Value / 2) * (PLL_MUL_FACTOR + 2) );
			break;

		case HSE_OSC:
			sysFreq = ( HSI_Value * (PLL_MUL_FACTOR + 2) );
			break;
		}
	}
	return sysFreq;
}


void delay_ms(int ms)
{
	for (int i=0; i<ms; i++)
		for (int j=0 ; j<250; j++);
}
