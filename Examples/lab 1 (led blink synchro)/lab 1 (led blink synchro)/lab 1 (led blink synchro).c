/*
 * lab_1__led_blink_synchro_.c
 *
 * Created: 3/29/2025 4:34:22 AM
 *  Author: Ammar
 */ 

#include "std_macros.h"
#include <avr/io.h>
#include "LED.h"
#define F_CPU 8000000UL  // Set CPU clock frequency (e.g., 8 MHz)
#include "Push_button.h"
#include <util/delay.h>


int main(void)

{	// first lab
	/*
	signed char i =0;
	for (i=0;i<8;i++)
	{
		led_initialize('A',i);
	}
	while(1)
    {
		for (i = 0 ; i < 8 ; i++)
		{
			led_on('A',i);
			_delay_ms(100);
		}
		
		for (i = 7 ;  i >= 0 ; i--)
		{
			led_off('A',i);
			_delay_ms(100);
		}
		
		
    }*/
	
	// second lab
	unsigned char state , flag =0;
	led_initialize('a',0);
	led_initialize('a',1);
	pushButton_Intialize_V8('c',0);
	Dio_connect_pullup('C',0,1);
	while(1)
	{	
		/*
		led_toggle('A',0);
		_delay_ms(500);
		led_toggle('A',0);
		_delay_ms(500);
		led_toggle('a',1);
		led_toggle('A',0);
		_delay_ms(500);
		led_toggle('a',1);
		led_toggle('A',0);
		_delay_ms(500);
	*/
		/*
		unsigned char state;
		state = PushButton_read_state('c',0);
		if (state == 1)
		{led_on('A',0);}
		else
		{led_off('A',0);}*/
			
	// internal pull up

	// toggle only once
	/*
	1- 
	Dio_connect_pullup('C',0,1);
	state = PushButton_read_state('c',0);
	if (state == 0)
	{ _delay_ms(10); // debounce solution
		state = PushButton_read_state('C',0);
		if (state == 0)
		{
		led_toggle('A',0);
		while(PushButton_read_state('C',0) == 0);
		}
	}	*/
	/*
	2- 
	state = PushButton_read_state('c',0);
	while(!state)
	{
		state = PushButton_read_state('C',0);
		if (state)
		{
			led_toggle('A',0);
		}
		_delay_ms(100);
	}
	3-
	static uint8_t prev_state = 1;  // Start with button not pressed

	uint8_t current_state = PushButton_read_state('C', 0);
	if ((prev_state == 1) && (current_state == 0))  // Falling edge (press)
	{
		_delay_ms(10);  // Debounce
		if (PushButton_read_state('C', 0) == 0)  // Still pressed
		{
			led_toggle('A', 0);
		}
	}
	prev_state = current_state;  // Update state for next check
	4-
	*/
	state = PushButton_read_state('c',0);
	if (state == 0 && flag == 0)
	{
		led_toggle('a',0);
		flag = 1;
	}
	else if (state == 1)
	{
		flag = 0;
	}
}
}
