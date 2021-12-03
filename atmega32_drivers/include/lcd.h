/*
* lcd.h
*
* Created: Sun, 7, 4, 2021 4:27:38 AM
*  Author: Eslam
*/


#ifndef LCD_H_
#define LCD_H_

/*================================================================================================
 											Includes
  ================================================================================================ */
#include "gpio.h"

/* ---------------------------------- End of Includes Section ----------------------------------- */


/*================================================================================================
 						LCD Configuration Options "SET BY USER APPLICATION"
  ================================================================================================ */
#define LCD_DATA		PA
#define LCD_CTRL		PB

#define RS				PIN0
#define RW				PIN1
#define E				PIN2
#define BUSY_FLAG		PIN7

//#define FOUR_MODE
#define EIGHT_MODE

/* ----------------------- End of LCD Configuration Options Section --------------------------- */


/*================================================================================================
 									Macros Configuration References
  ================================================================================================ */

/* ---------------------------------------------------------------------
* LCD Macros 
 ---------------------------------------------------------------------*/
#define INSTRUCTION			LOW
#define DATA				HIGH

#define WRITE				LOW
#define READ				HIGH

#define ENABLE				HIGH
#define DISABLE				LOW

#define RIGHT				1
#define LEFT				0

#define LCD_CLEAR_DISPLAY	0x01

#define LINE1				0x80
#define LINE2				0xC0

/* --------------------------- End of Macros Configuration Section ------------------------------- */


/*================================================================================================
 							 APIs Prototypes Supported by "HAL LCD DRIVER"
  ================================================================================================ */
void lcd_Init(void);
void lcd_Write_Command(u8 command);
void lcd_Write_character(u8 character);
void lcd_Write_String(char *data);
void lcd_Write_integer(u32 num);
void lcd_Write_Float(f32 num);
void lcd_Fire(void);
void lcd_Clear(void);
void lcd_Home();
void lcd_display_ON();
void lcd_display_OFF();
void lcd_goto(u8 line, u8 position);
void lcd_Busy();
void lcd_cursor_shift(u8 direction);
void lcd_display_shift(u8 direction);
void lcd_special_char(u8 symbol[8], u8 block_num, u8 line, u8 postion);

/* ---------------- End of APIs Prototypes Supported by "HAL LCD DRIVER" Section -------------- */

#endif /* LCD_H_ */