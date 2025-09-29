/*
 * Motors.c
 *
 * Created: 6/30/2025 3:49:47 AM
 *  Author: Ammar
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "std_macros.h"
#include "TIMER.h"
#define F_CPU 8000000UL
#include "util/delay.h"
int main(void)
{

    while(1)
    {
		
		for (int i = 0 ; i <= 180 ; i++)
		{
			Servo_motor_set_position(i);
			_delay_ms(10);  
		}
		for (int i = 180 ; i >= 0; i--)
		{
			Servo_motor_set_position(i);
			_delay_ms(10);
		}		

    }
}