/*
 * Keypad.c
 *
 * Created: 4/19/2025 12:33:31 AM
 *  Author: Ammar
 */ 

#include "lcd.h"
#include "Keypad_driver.h"
#include <avr/io.h>
#include "util/delay.h"
int main(void)
{	Lcd_Initialize();
	keypad_intialize('d');
	unsigned char var = 0;
    while(1)
    {
        //TODO:: Please write your application code 
		Lcd_Set_cursor(1,1);
		var = Keypad_Pressed_value8u();
		Lcd_Send_char(var);
		
    }
}