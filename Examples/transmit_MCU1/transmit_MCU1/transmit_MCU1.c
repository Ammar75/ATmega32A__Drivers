#include <avr/io.h>
#define F_CPU 8000000UL
#include "util/delay.h"
#include "SPI.h"
#include "two_wire_c.h"
int main(void)
{
	I2C_master_vinit(50000);
	unsigned char i = 0;
	_delay_ms(500);
			LCD_vInit();
			LCD_clearscreen();

	while (1)
	{
		i = I2C_Master_Recieve_Char(0b111000);
		LCD_movecursor(1,1);
		LCD_vSend_char(i);
		_delay_ms(1000);
	}
}
