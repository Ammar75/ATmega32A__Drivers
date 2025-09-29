/*
 * Real_time_clock.c
 *
 * Created: 6/26/2025 10:06:25 PM
 *  Author: Ammar
 */ 


#include <avr/io.h>
#include "Seven_segment.h"
#include "avr/interrupt.h"
#include "TIMER.h"
#include "std_macros.h"
#include "Keypad_driver.h"
#include "lcd.h"

void Update_Time(void);
void Enable_mux_7seg(unsigned char pin);
volatile unsigned char counter = 0;
volatile unsigned char flag = 0;

volatile unsigned char hours =0;
volatile unsigned char minutes =0;
volatile unsigned char seconds = 0;
#define F_CPU 8000000UL
#include "util/delay.h"
int main(void)
{	
	timer2_OVF_init_int();
	timer0_OVF_interrupt();
	
	for (int i = 0 ; i <= 5 ; i++)
	{
		Dio_VSet_pin_Dir('c',i,"OUTPUT");
	}
	Seven_Segment_vintit('b');
	keypad_intialize('d');
	Lcd_Initialize();

	Lcd_Set_cursor(1,1);
	Lcd_send_string("Press 1 to Edit time");
	
    while(1)
    {	

		Update_Time();
		if (keypad_u8check_press() == '1')
		Edit_Timev();
		else if (keypad_u8check_press() != 0xFF )
		{
			Lcd_Clear_Screen();
			Lcd_Set_cursor(1,1);
			Lcd_send_string("Wrong choice");
			_delay_ms(500);
			Lcd_Clear_Screen();
			Lcd_Set_cursor(1,1);
			Lcd_send_string("Press 1 to Edit time");	
		}
		switch(flag)
        {
	        // tens hours
	        case 0 :
	        Enable_mux_7seg(0);
	        Seven_segment_write_by_numb('b',hours / 10);
	        break;
	        // ones hours
	        case 1:
	        Enable_mux_7seg(1);
	        Seven_segment_write_by_numb('b',hours % 10);
	        break;
	        // tens minutes
	        case 2:
	        Enable_mux_7seg(2);
	        Seven_segment_write_by_numb('b',minutes / 10);
	        break;
	        // ones minutes
	        case 3:
	        Enable_mux_7seg(3);
	        Seven_segment_write_by_numb('b',minutes % 10);
	        break;
	        // tens seconds
	        case 4:
	        Enable_mux_7seg(4);
	        Seven_segment_write_by_numb('b',seconds / 10);
	        break;
	        // ones seconds
	        case 5:
	        Enable_mux_7seg(5);
	        Seven_segment_write_by_numb('b',seconds % 10);
	        break;
	        default:
	        flag = 0;
	        break;
	                
        }
    }
}

ISR(TIMER2_OVF_vect)
{
	
	counter++;
}

ISR(TIMER0_OVF_vect)
{
	
	flag++;
	if (flag > 5)
	flag =0;
}
void Enable_mux_7seg(unsigned char pin)
{
	PORTC |= 0b00111111;          
	CLEAR_BIT(PORTC, pin);        
}


void Update_Time(void)
{
	seconds = counter;
	if (seconds == 60)
	{
		minutes++;
		counter = 0;
	}
	if (minutes == 60)
	{
		minutes = 0;
		(hours)++;
	}
	if (hours == 24)
	{
		hours = 0;
		
	}
}

void Edit_Timev(void)
{	cli();
	unsigned char hours_ones = 0, hours_tens = 0;
	unsigned char minutes_ones = 0, minutes_tens = 0;
	unsigned char seconds_ones = 0, seconds_tens = 0;

	Lcd_Clear_Screen();
	Lcd_Set_cursor(1,1);
	Lcd_send_string("Hours = ");
	_delay_ms(500);
	
	do {
		hours_tens = keypad_u8check_press();
	} while (hours_tens < '0' || hours_tens > '9');
	Lcd_Send_char(hours_tens);
	_delay_ms(200);
	hours_tens -= '0';

	do {
		hours_ones = keypad_u8check_press();
	} while (hours_ones < '0' || hours_ones > '9');
	Lcd_Send_char(hours_ones);
	_delay_ms(200);
	hours_ones -= '0';

	hours = (hours_tens * 10) + hours_ones;
	if (hours > 23) hours = 0;

	Lcd_Clear_Screen();
	Lcd_Set_cursor(1,1);
	Lcd_send_string("Minutes = ");

	do {
		minutes_tens = keypad_u8check_press();
	} while (minutes_tens < '0' || minutes_tens > '9');
	Lcd_Send_char(minutes_tens);
	_delay_ms(200);
	minutes_tens -= '0';

	do {
		minutes_ones = keypad_u8check_press();
	} while (minutes_ones < '0' || minutes_ones > '9');
	Lcd_Send_char(minutes_ones);
	_delay_ms(200);
	minutes_ones -= '0';

	minutes = (minutes_tens * 10) + minutes_ones;
	if (minutes > 59) minutes = 0;

	Lcd_Clear_Screen();
	Lcd_Set_cursor(1,1);
	Lcd_send_string("Seconds = ");

	do {
		seconds_tens = keypad_u8check_press();
	} while (seconds_tens < '0' || seconds_tens > '9');
	Lcd_Send_char(seconds_tens);
	_delay_ms(200);
	seconds_tens -= '0';

	do {
		seconds_ones = keypad_u8check_press();
	} while (seconds_ones < '0' || seconds_ones > '9');
	Lcd_Send_char(seconds_ones);
	_delay_ms(200);
	seconds_ones -= '0';

	counter = (seconds_tens * 10) + seconds_ones;
	if (counter > 59) counter = 0;


	Lcd_Clear_Screen();
	Lcd_Set_cursor(1,1);
	Lcd_send_string("Time Updated");
	_delay_ms(1000);
	sei();

	Lcd_Set_cursor(1,1);
	Lcd_send_string("Press 1 to Edit time");
}
