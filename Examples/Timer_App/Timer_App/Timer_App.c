/*
 * Timer_App.c
 *
 * Created: 6/23/2025 12:16:25 AM
 *  Author: Ammar
 */ 


#include <avr/io.h>
#include "avr/interrupt.h"
#include "std_macros.h"
#include "DIO.h"
#include "TIMER.h"
#include "util/delay.h"
int main(void)
{	
			Timer0_fastPwm_init();
			Timer0_wave_generate(255);
    
	while(1)
    {	

	}
}
