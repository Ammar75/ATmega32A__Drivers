/*
 * GccApplication3.c
 *
 * Created: 11/29/2024 1:43:40 AM
 *  Author: Ammar
 */ 
#include <stdio.h>
#include "DIOh.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{	set_pindir('A' ,0,"output");
	unsigned char data = 0;

	while(1)
    { 
		Dio_toggle('a',0);
		_delay_ms(1000);
		data = Dio_read('A',0);
		printf("data is %c",data);

        //TODO:: Please write your application code 
    }
}