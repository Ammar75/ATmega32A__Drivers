/*
 * project_2_timer_with_two_7segments.c
 *
 * Created: 6/24/2025 4:01:09 PM
 *  Author: Ammar
 */ 


#include <avr/io.h>
#include "avr/interrupt.h"
#include "util/delay.h"

volatile unsigned short counter = 0;
volatile unsigned char  seconds = 0;
volatile unsigned char display_flag = 0;
int main(void)
{	
	
	Seven_Segment_vintit('d');
	Dio_VSet_pin_Dir('a',0,"OUTPUT");
	Dio_VSet_pin_Dir('a',1,"OUTPUT");
    timer_CTC_init_interrupt();
	
	while(1)
    {
		if ( display_flag == 0 )
		{
			DIO_vwrite('a',0,"LOW");
			DIO_vwrite('a',1,"HIGH");
			Seven_segment_write_by_numb('d',seconds / 10);
		}
		else
		{
			DIO_vwrite('a',1,"LOW");
			DIO_vwrite('a',0,"HIGH");
			Seven_segment_write_by_numb('d',seconds % 10);	
		}
		if (counter == 100)
		{
			seconds++;
			counter = 0;
		}
		if (seconds > 60)
		seconds = 0; 
		
	}
}


ISR(TIMER0_COMP_vect)
{
	counter++;
	 display_flag ^= 1;

}