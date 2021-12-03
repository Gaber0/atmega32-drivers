/*
* keypad.c
*
* Created: Tue, 6, 29, 2021 6:05:44 PM
*  Author: Eslam
*/


/*================================================================================================
 											Includes
  ================================================================================================ */
#include "keypad.h"
#include <util/delay.h>

/* ---------------------------------- End of Includes Section ----------------------------------- */

u32 KeyPad_4x4_Get_Key(u32 key_value);
u8 KeyPad_3x4_Get_Key(u8 key_value);

u8 keypad(void)
{
	u8 keypad_Port_read = 0;
	u8 row, column;
	while (1)
	{
		//	loop for columns
		for(column = COLS_init; column < COLS_end; column++)
		{
			//	make one column to be output one at time --- the rest of all pins are input.
			GPIO_Pin_Init(keypad_port, column, OUTPUT);
			
			//	put high voltage on columns and rows(to activate internal pull up resistor)
			//	then put low in one column at a time
			GPIO_Port_Set(keypad_port, 0xFF);
			GPIO_Pin_Set(keypad_port, column, LOW);
			
			//	loop for rows
			for(row = ROWS_init; row < ROWS_end; row++)
			{
				//	check if a switch is pressed in the row
				if(GPIO_Pin_Read(keypad_port, row) == 0)
				{
					/* This variable hold the value of PINx register then he is passed to function to return 
					the value of pressed key as PINx register's value will changed after left pressing the key  */ 
					keypad_Port_read = GPIO_Port_Read(keypad_port);  
					
					while(GPIO_Pin_Read(keypad_port, row) == 0);		/* Single press */
					
					#if (KEYPAD_SIZE == KEYPAD_SIZE_3x4)
						return KeyPad_3x4_Get_Key(keypad_Port_read);
						
					#elif (KEYPAD_SIZE == KEYPAD_SIZE_4x4)
						return KeyPad_4x4_Get_Key(keypad_Port_read);						
					#endif
				}
			}
			// reset the column as input
			GPIO_Pin_Init(keypad_port, column, INPUT);
		}
	}
}

u8 KeyPad_3x4_Get_Key(u8 key_value)
{
	switch(key_value)
	{
		case 0b11101110:
		return 49;
		break;
		case 0b11101101:
		return 52;
		break;
		case 0b11101011:
		return 55;
		break;
		case 0b11100111:
		return 67;
		break;
		
		// COL 1
		case 0b11011110:
		return 50;
		break;
		case 0b11011101:
		return 53;
		break;
		case 0b11011011:
		return 56;
		break;
		case 0b11010111:
		return 48;
		break;
		
		// COL 2
		case 0b10111110:
		return 51;
		break;
		case 0b10111101:
		return 54;
		break;
		case 0b10111011:
		return 57;
		break;
		case 0b10110111:
		return 61;
		break;
	}
}


/* it return ASCII for the values */
u32 KeyPad_4x4_Get_Key(u32 key_value)
{
	switch(key_value)
	{
		// COLUMN 0, COLUMN 1, COLUMN 2
		default: 
			return KeyPad_3x4_Get_Key(key_value);
			break;
			
		// COLUMN 3
		case 0b01111110:
			return 47;
			break;
		case 0b01111101:
			return 42;
			break;
		case 0b01111011:
			return 45;
			break;
		case 0b01110111:
			return 43; 
			break;			
	}
}

