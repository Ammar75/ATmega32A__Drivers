#include <avr/io.h>
#define F_CPU 8000000UL
#include "util/delay.h"

#include "SPI.h"
#include "two_wire_c.h"
#include "lcd.h"
int main(void)
{
		I2C_slave_address(0b111000,1);
		char data[20];
		LCD_vInit();
		LCD_clearscreen();
	
		while (1)
		{
			LCD_movecursor(1,1);
			I2C_Slave_Transmit_Char('a');
			_delay_ms(1000);
			
		}
}
