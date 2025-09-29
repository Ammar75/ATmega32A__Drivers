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
		
		var = keypad_u8check_press();
		if (var){
		Lcd_Set_cursor(1,1);
		Lcd_Send_char(var);}
		_delay_ms(100);

		
    }
}