/*
 * EXTI.h
 *
 * Created: Wed, 9, 8, 2021 4:43:15 AM
 *  Author: Eslam
 */ 


#ifndef EXTI_H_
#define EXTI_H_


/*================================================================================================
 									Bits of Peripherals' Register
  ================================================================================================ */

/* ----------------------------------------------------------------------------------------------
 * 		Bits of MCUCR Register
 *  --------------------------------------------------------------------------------------------- */
#define ISC00			0
#define ISC01			1
#define ISC10			2
#define ISC11			3
#define SM0				4
#define SM1				5
#define SM2				6
#define SE				7

/* ----------------------------------------------------------------------------------------------
 * 		Bits of MCUCSR Register
 *  --------------------------------------------------------------------------------------------- */
#define PORF			0
#define EXTRF			1
#define BORF			2
#define WDRF			3
#define JTRF			4
#define ISC2			6
#define JTD				7

/* ----------------------------------------------------------------------------------------------
 * 		Bits of GICR Register
 *  --------------------------------------------------------------------------------------------- */
#define IVCE			0
#define IVSEL			1
#define INT2			5
#define INT0			6
#define INT1			7

/* ----------------------------------------------------------------------------------------------
 * 		Bits of GIFR Register
 *  --------------------------------------------------------------------------------------------- */
#define INTF2			5
#define INTF0			6
#define INTF1			7

/* -------------------------- End of Bits of Peripherals' Register Section ------------------------ */


#endif /* EXTI_H_ */