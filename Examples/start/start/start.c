/*
 * start.c
 *
 * Created: 2/27/2025 11:57:00 AM
 *  Author: Ammar
 */ 

#define F_CPU 8000000ul
//#include <avr/io.h>
#include "std_macros.h"
#include "DIO.h"
#include <util/delay.h>   
#define F_CPU 8000000UL
#include "LED.h"

int main(void)
{	
	led_initialize('A',0);
    while(1)
    {
		
		led_on('a',0);
		_delay_ms(500);
		led_off('a',0);
		_delay_ms(500); 
		
		
		/*
		
		DIO_VWrite_port('a',0xff);
		_delay_ms(500);
		DIO_VWrite_port('a' , 0x0000);
		_delay_ms(500);
		
        //TODO:: Please write your application code 
		char vall;
		const char *sign;
		DIO_vToggle('A',0);
		vall = DIO_u8Read_pin('a',1);
		sign = (vall == 0) ? "LOW" : "HIGH";
		DIO_vwrite('a' , 2 , sign);
		_delay_ms(500);
	*/
		

    }
}


