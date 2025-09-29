/*
 * _7_SEGMENTS.c
 *
 * Created: 4/3/2025 5:19:22 PM
 *  Author: Ammar
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "Push_button.h"
#define comman_cathod
#include "Seven_segment.h"
#define F_CPU 8000000UL

int main(void)
{	
	Seven_Segment_vintit('C');
	pushButton_Intialize_V8('A',0);
	Dio_connect_pullup('a',0,1);
	Seven_Segment_vintit('B');
	unsigned char push = 0;
	unsigned char state = 0;
	Seven_segment_vinit_BCD('D',"LOW");

    while(1)
    {	/*
		push = PushButton_read_state('a',0);
		
		if (!push)
		{
			_delay_ms(50); 
			if (!PushButton_read_state('a',0))
			{
				state++; 
				
				if (state == 10) 
				{
					state = 0;
				}
				
				// Wait until the button is released
				while (!PushButton_read_state('a',0));
			}
		}
		Seven_segment_write_by_numb('c', state);
	*/
	
	// two seven segments
	
	/*
	for (int i =0 ; i < 10 ; i++ )
	{
		Seven_segment_write_by_numb('C',i);
		for ( int j = 0 ; j < 10 ; j++)
		{
			Seven_segment_write_by_numb('B',j);
			_delay_ms(3000);
		}
	}
	
	*/
	/*
	count from 0 to 20 ;;;;
	
	push = PushButton_read_state('a',0);
	
	if (!push)
	{
		_delay_ms(50);
		if (!PushButton_read_state('a',0))
		{
			state++;
			
			if (state == 20)
			{
				state = 0;
			}
			
			// Wait until the button is released
			while (!PushButton_read_state('a',0));
		}
	}
	Seven_segment_write_by_numb('c', (unsigned int)(state / 10));
	Seven_segment_write_by_numb('b', (unsigned int)(state % 10));
	*/
	
	
	// using BCD ;;;;;

	for (int i = 0 ; i < 10 ; i++)
	{
		Seven_segment_vWrite_BCD('D',i,"low");
		_delay_ms(5000);
	}
	
	
	}	
}
