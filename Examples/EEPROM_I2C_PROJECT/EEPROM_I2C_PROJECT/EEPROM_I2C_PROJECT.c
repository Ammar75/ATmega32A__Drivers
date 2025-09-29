/*
 * EEPROM_I2C_PROJECT.c
 *
 * Created: 7/27/2025 3:42:37 AM
 *  Author: Ammar
 */ 


#include <avr/io.h>
#include "EEprom_I2c.h"
#include "lcd.h"
#include "util/delay.h"

int main(void)
{
	
	
	I2C_master_vinit(50000);
	LCD_vInit();
	_delay_ms(500);
	char transmit_buffer[8] = {48,49,50,51,52,53};
	EEprom_I2c_write_Nbyte(0b1010000,0b00000000,8,transmit_buffer);
	unsigned char data = 0 ;
	_delay_ms(500);

	char rec_buffer[8];

	EEprom_I2c_Read_Nbyte(0b1010000,0b00000000,8 , rec_buffer);
	_delay_ms(100);
	LCD_movecursor(1,1);


	for (int i = 0; i < 8; i++) {
		LCD_movecursor(1, i+1);
		LCD_vSend_char(rec_buffer[i]);
	}
	while(1)
	{
		

	}
}