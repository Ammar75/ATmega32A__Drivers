/*
 * Interrupt.c
 *
 * Created: 4/12/2025 1:18:40 AM
 *  Author: Ammar
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "Push_button.h"
#include "std_macros.h"
#include "avr/interrupt.h"
#include "LED.h"
#include "util/delay.h"
unsigned char counter = 0;
unsigned char counter1 = 0;
unsigned char counter2 = 0;
int main(void)
{
    pushButton_Intialize_V8('D',2);
	pushButton_Intialize_V8('D',3);
	pushButton_Intialize_V8('b',2);
	led_initialize('A',0);
	led_initialize('a',1);
	led_initialize('a',2);
	led_initialize('a',3);
	sei();
	SET_BIT(GICR,5);
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);
	
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	
	SET_BIT(MCUCSR,2);
	
	
	while(1)
    {
        //TODO:: Please write your application code 
		led_off('a',0);
		led_off('a',1);
		led_off('a',2);
		led_toggle('a',3);
		_delay_ms(1000);
    }
}


void __vector_1(void)__attribute__((signal,__INTR_ATTRS));
void __vector_1(void)
{
	led_on('a',0);
	_delay_ms(2000);

}