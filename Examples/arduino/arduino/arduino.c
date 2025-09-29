/*
 * arduino.c
 *
 * Created: 4/12/2025 10:53:01 PM
 *  Author: Ammar
 */ 
#define F_CPU 16000000UL  // Define CPU frequency as 16 MHz
#include <avr/io.h>
#include <util/delay.h>
#include "avr/interrupt.h"
#include <avr/io.h>
#include "std_macros.h"

#include "lcd.h"
int main(void)
{	CLEAR_BIT(MCUCR,4);
	
	Lcd_Initialize();
	keypad_intialize('D');
	char x = 0;
	unsigned char counter=0;
	while(1)
	{
		x=keypad_u8check_press();
		if (x != 0 && x != 0xFF)  // Check for both possible "no key" values
		{
			Lcd_Set_cursor(1,1);
			Lcd_Send_char(x);  // Changed from Lcd_send_string
		}

		_delay_ms(200);
		
	}

}

