/*
 * ADC_PROJECT.c
 *
 * Created: 5/28/2025 4:42:00 AM
 *  Author: Ammar
 */ 
#include "std_macros.h"
#include "ADC.h"
#include "lcd.h"
#include "DIO.h"
#include <avr/io.h>
#include "util/delay.h"
void send_degreesToLcd(unsigned char degrees);


int main(void)
{	Lcd_Initialize();
	Adc_intialize();
	Dio_VSet_pin_Dir('a',0,"INPUT");
	uint16_t read_data;
	unsigned char temp;
    unsigned int mv ;

	while(1)
    {	//read data from adc
		read_data = adc_read_u16(0);
		// convert binary data to equivalent mvolt
		mv = (read_data * 5000UL) / 1024;  
		// convert volt to temp as 1c = 10mv
		temp = (mv/10);
		
		send_degreesToLcd(temp);
		 _delay_ms(100);
    }
}



void send_degreesToLcd(unsigned char degrees)
{
	
	char buffer[11];  
	buffer[0] = 'T';
	buffer[1] = 'M';
	buffer[2] = 'P';
	buffer[3] = ':';

	buffer[4] = (degrees / 100) + '0';
	buffer[5] = ((degrees / 10) % 10) + '0';
	buffer[6] = (degrees % 10) + '0';

	buffer[7] = ' ';     
	buffer[8] = 0xDF;     
	buffer[9] = 'C';        
	buffer[10] = '\0';    
	
	Lcd_Set_cursor(0, 0);
	Lcd_send_string(buffer);
}