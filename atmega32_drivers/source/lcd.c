/*
 * lcd.c
 *
 * Created: Sun, 7, 4, 2021 4:27:47 AM
 *  Author: Eslam
 */ 


/*================================================================================================
 											Includes
  ================================================================================================ */
#include "lcd.h"
#include <util/delay.h>

/* ---------------------------------- End of Includes Section ----------------------------------- */


void lcd_Fire()
{
	GPIO_Pin_Set(LCD_CTRL, E, ENABLE);
	_delay_ms(2);
	GPIO_Pin_Set(LCD_CTRL, E, DISABLE);
}


void lcd_Write_Command(u8 command)
{	
	lcd_Busy();
	GPIO_Pin_Set(LCD_CTRL, RS, INSTRUCTION);
	GPIO_Pin_Set(LCD_CTRL, RW, WRITE);
	GPIO_Port_Set(LCD_DATA, command);
	lcd_Fire();
}

void lcd_Write_character(u8 character)
{	
	lcd_Busy();
	GPIO_Pin_Set(LCD_CTRL, RS, DATA);
	GPIO_Pin_Set(LCD_CTRL, RW, WRITE);
	GPIO_Port_Set(LCD_DATA, character);
	lcd_Fire();
}

void lcd_Init()
{
	GPIO_Port_Init(LCD_DATA, 0xFF);
	GPIO_Pin_Init(LCD_CTRL, RS, OUTPUT);
	GPIO_Pin_Init(LCD_CTRL, RW, OUTPUT);
	GPIO_Pin_Init(LCD_CTRL, E, OUTPUT);
	
	//#ifdef EIGHT_MODE
		_delay_ms(40);
		lcd_Write_Command(0x38);
		_delay_ms(1);
		lcd_Write_Command(0x0F);
		_delay_ms(1);
		lcd_Clear();
		lcd_Write_Command(0x06);		
	//#endif
	/*
	#ifdef FOUR_MODE
		_delay_ms(20);
		lcd_Write_Command(0x02);
		lcd_Write_Command(1000);
		_delay_ms(10);
		lcd_Clear();
		_delay_ms(10);
		lcd_Write_Command(0x00);
		lcd_Write_Command(0b0110);	
	#endif*/
}


void lcd_Clear(void)
{
	lcd_Write_Command(LCD_CLEAR_DISPLAY);	
	_delay_ms(2);
}

void lcd_Home()
{
	lcd_Write_Command(0x02);
	_delay_ms(2);
}

void lcd_display_ON()
{
	lcd_Write_Command(0b00001110);
	_delay_ms(1);
}


void lcd_display_OFF()
{
	lcd_Write_Command(0b00001000);
	_delay_ms(1);
}

void lcd_goto(u8 line, u8 position)
{
	if(line == 1)
	{
		// we can do two if conditions for first 16 location and one for another locations and make shift in this case
		lcd_Write_Command(LINE1 + position);
		_delay_ms(1);
	}
	else if(line == 2)
	{
		lcd_Write_Command(LINE2 + position);
		_delay_ms(1);
	}
}

void lcd_Busy()
{
	GPIO_Port_Init(LCD_DATA, 0x00);
	GPIO_Pin_Init(LCD_CTRL, RS, INSTRUCTION);
	GPIO_Pin_Init(LCD_CTRL, RW, READ);
	GPIO_Pin_Init(LCD_CTRL, E, ENABLE);

	while (readbit(LCD_DATA, PIN7));
	
	GPIO_Port_Init(LCD_DATA, 0xFF);
	GPIO_Pin_Init(LCD_CTRL, RS, DATA);
}

void lcd_Write_String(char *data)
{
	while(*data != '\0')
	{		
		lcd_Write_character(*data++);
	}
	
}

void lcd_Write_integer(u32 num)
{
	char string[16];
	itoa(num,string,10);
	lcd_Write_String(string);		
}

void lcd_Write_Float(f32 num)
{
	char  string[16];
	char *tmpSign = (num < 0) ? "-" : "";
	float tmpVal = (num < 0) ? -num : num;

	int tmpInt1 = tmpVal;                  
	float tmpFrac = tmpVal - tmpInt1;      
	int tmpInt2 = tmpFrac * 10000;  

	sprintf (string, "%s%d.%04d", tmpSign, tmpInt1, tmpInt2);

	lcd_Write_String(string) ;
}


void lcd_cursor_shift(u8 direction)
{
	lcd_Write_Command((direction<<2) | 0b00010000);
	_delay_ms(1);
}

void lcd_display_shift(u8 direction)
{
	lcd_Write_Command((direction<<2) | 0b00011000);	
	_delay_ms(1);
}

void lcd_special_char(u8 symbol[8], u8 block_num, u8 line, u8 postion)
{
	//	position * 8 as every character need 8 CGRAM loactions, so the 1st symbol location is 0x40, 2nd is 0x48
	lcd_Write_Command(0x40 + (block_num*8));
	_delay_ms(1);
	for (u8 i=0; i<8; i++)
	{
		lcd_Write_character(symbol[i]);
	}
	lcd_goto(line,postion);
	lcd_Write_character(postion);
}