#include <avr/io.h>
#include "std_macros.h"
#include "lcd.h"
#include "Keypad_driver.h"
#include "util/delay.h"
#include "avr/interrupt.h"
volatile unsigned short counter = 0 ;
int main(void)
{	
	Lcd_Initialize();
	keypad_intialize('d');
	unsigned char value = 0;
	unsigned char correct_value = '3';
	timer_CTC_init_interrupt();
	while(1)
	{
		if (counter < 1000 )
		{
			// Display the question
			Lcd_Set_cursor(1,1);
			Lcd_Send_char('5');
			Lcd_Set_cursor(1,2);
			Lcd_Send_char('+');
			Lcd_Set_cursor(1,3);
			Lcd_Send_char('?');
			Lcd_Set_cursor(1,4);
			Lcd_Send_char('=');
			Lcd_Set_cursor(1,5);
			Lcd_Send_char('8');

			// Wait for key press
			value = keypad_u8check_press();

			if (value != '\0') 
			{
				if (value == correct_value)
				{
					Lcd_Clear_Screen();
					Lcd_Set_cursor(1,2);
					Lcd_send_string("correct value");
					while(1);
				}
				else
				{
					Lcd_Clear_Screen();
					Lcd_Set_cursor(1,2);
					Lcd_send_string("wrong answer");
				}

				_delay_ms(5000);
				Lcd_Clear_Screen();
			}

			_delay_ms(200);
		}
		else 
		{
			Lcd_Clear_Screen();
			Lcd_Set_cursor(1,1);
			Lcd_send_string("time out");
			while(1);
		}
		
	}
}


ISR(TIMER0_COMP_vect)
{
	counter++;
}