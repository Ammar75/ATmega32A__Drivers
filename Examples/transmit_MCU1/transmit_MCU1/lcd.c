/*
 * LCD.c
 *
 * Created: 2/23/2018 4:38:26 PM
 *  Author: Mohamed Zaghlol
 */ 
#include "LCD.h"
#define F_CPU 8000000UL 
#include <util/delay.h>

void LCD_vInit(void)
{
	_delay_ms(200);
	
#if defined eight_bits_mode
	Dio_VSet_pin_Dir(LCD_Data_port, 0, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 1, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 2, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 3, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 4, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 5, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 6, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 7, "OUTPUT");

	Dio_VSet_pin_Dir(LCD_control_port, EN, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_control_port, RW, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_control_port, RS, "OUTPUT");

	DIO_vwrite(LCD_control_port, RW, "LOW");
	LCD_vSend_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON); //display on cursor on
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN); //clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1); 

#elif defined four_bits_mode
	Dio_VSet_pin_Dir(LCD_Data_port, 4, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 5, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 6, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_Data_port, 7, "OUTPUT");

	Dio_VSet_pin_Dir(LCD_control_port, EN, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_control_port, RW, "OUTPUT");
	Dio_VSet_pin_Dir(LCD_control_port, RS, "OUTPUT");

	DIO_vwrite(LCD_control_port, RW, "LOW");
	LCD_vSend_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_vSend_cmd(FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_vSend_cmd(CURSOR_ON_DISPLAN_ON); //display on cursor on
	_delay_ms(1);
	LCD_vSend_cmd(CLR_SCREEN); //clear the screen
	_delay_ms(10);
	LCD_vSend_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
#endif
}

static void send_falling_edge(void)
{
	DIO_vwrite(LCD_control_port, EN, "high");
	_delay_ms(2);
	DIO_vwrite(LCD_control_port, EN, "LOW");
	_delay_ms(2);
}

void LCD_vSend_cmd(char cmd)
{
#if defined eight_bits_mode
	DIO_VWrite_port(LCD_Data_port, cmd);
	DIO_vwrite(LCD_control_port, RS, "LOW");
	send_falling_edge();

#elif defined four_bits_mode
	Dio_Write_highNibble(LCD_Data_port, cmd >> 4);
	DIO_vwrite(LCD_control_port, RS, "LOW");
	send_falling_edge();

	Dio_Write_highNibble(LCD_Data_port, cmd);
	DIO_vwrite(LCD_control_port, RS, "LOW");
	send_falling_edge();
#endif
	_delay_ms(1);
}

void LCD_vSend_char(char data)
{
#if defined eight_bits_mode
	DIO_VWrite_port(LCD_Data_port, data);
	DIO_vwrite(LCD_control_port, RS, "high");
	send_falling_edge();

#elif defined four_bits_mode
	Dio_Write_highNibble(LCD_Data_port, data >> 4);
	DIO_vwrite(LCD_control_port, RS, "high");
	send_falling_edge();

	Dio_Write_highNibble(LCD_Data_port, data);
	DIO_vwrite(LCD_control_port, RS, "high");
	send_falling_edge();
#endif
	_delay_ms(1);
}

void LCD_vSend_string(char *data)
{
	while((*data) != '\0')
	{
		LCD_vSend_char(*data);
		data++;
	}
}

void LCD_clearscreen(void)
{
	LCD_vSend_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_movecursor(char row, char coloumn)
{
	char data;
	if (row > 2 || row < 1 || coloumn > 16 || coloumn < 1)
	{
		data = 0x80;
	}
	else if (row == 1)
	{
		data = 0x80 + coloumn - 1;
	}
	else if (row == 2)
	{
		data = 0xC0 + coloumn - 1;
	}
	LCD_vSend_cmd(data);
	_delay_ms(1);
}
