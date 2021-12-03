/*
 * keypad.h
 *
 * Created: Tue, 6, 29, 2021 6:05:57 PM
 *  Author: Eslam
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "gpio.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */


/*================================================================================================
 						KEYPAD Configuration Options "SET BY USER APPLICATION"
  ================================================================================================ */
#define keypad_port					PD

//  set based on @ref KEYPAD_SIZE_define
#define KEYPAD_SIZE					KEYPAD_SIZE_4x4

// set based on @ref KEYPAD_BORDERS_define
#define ROWS_init					ROWS_init_4x4	
#define ROWS_end					ROWS_end_4x4
#define COLS_init					COLS_init_4x4
#define COLS_end					COLS_end_4x4

/* ----------------------- End of KEYPAD Configuration Options Section --------------------------- */


/*================================================================================================
 									Macros Configuration References
  ================================================================================================ */

/* ---------------------------------------------------------------------
*	 @ref KEYPAD_SIZE_define
 ---------------------------------------------------------------------*/
#define KEYPAD_SIZE_3x4				0
#define KEYPAD_SIZE_4x4				1


/* ---------------------------------------------------------------------
*	 @ref KEYPAD_BORDERS_define
 ---------------------------------------------------------------------*/
#define ROWS_init_4x4				0
#define ROWS_end_4x4				4
#define COLS_init_4x4				4
#define COLS_end_4x4				8

#define ROWS_init_3x4				0
#define ROWS_end_3x4				4
#define COLS_init_3x4				4
#define COLS_end_3x4				7

/*================================================================================================
 							 APIs Prototypes Supported by "HAL KEYPAD DRIVER"
  ================================================================================================ */
u8 keypad(void);
//u32 KeyPad_4x4_Get_Key(u32 key_value);
//u8 KeyPad_3x4_Get_Key(u8 key_value);

/* ---------------- End of APIs Prototypes Supported by "HAL KEYPAD DRIVER" Section -------------- */


#endif /* KEYPAD_H_ */