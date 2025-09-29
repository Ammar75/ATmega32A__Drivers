/*
 * Keypad_driver.c
 *
 * Created: 4/19/2025 12:35:23 AM
 *  Author: Ammar
 */ 
#include "DIO.h"
#include "std_macros.h"
#include "util/delay.h"
#define Keypad_port 'd' 
#define Keypad_pin PIND_
#define HIGH  "HIGH"
#define LOW "LOW"

void keypad_intialize(unsigned char port)
{
	Dio_VSet_pin_Dir(port , 0,"OUTPUT");
	Dio_VSet_pin_Dir(port, 1,"OUTPUT");
	Dio_VSet_pin_Dir(port, 2,"OUTPUT");
	Dio_VSet_pin_Dir(port, 3,"OUTPUT");
	Dio_VSet_pin_Dir(port, 4,"INTPUT");
	Dio_VSet_pin_Dir(port, 5,"INTPUT");
	Dio_VSet_pin_Dir(port, 6,"INTPUT");
	Dio_VSet_pin_Dir(port, 7,"INTPUT");
	
	Dio_connect_pullup(port, 4 , 1);
	Dio_connect_pullup(port, 5 , 1);
	Dio_connect_pullup(port, 6 , 1);
	Dio_connect_pullup(port, 7 , 1);
}



unsigned char Keypad_Pressed_value8u(void)
{
	// First row
	DIO_vwrite(Keypad_port,0,LOW);
	DIO_vwrite(Keypad_port,1,HIGH);
	DIO_vwrite(Keypad_port,2,HIGH);
	DIO_vwrite(Keypad_port,3,HIGH);
	_delay_ms(10);  // small delay for settling
	if (!READ_BIT(Keypad_pin,4)) return '7';
	if (!READ_BIT(Keypad_pin,5)) return '8';
	if (!READ_BIT(Keypad_pin,6)) return '9';
	if (!READ_BIT(Keypad_pin,7)) return 'A';
	
	// Second row
	DIO_vwrite(Keypad_port,0,HIGH);
	DIO_vwrite(Keypad_port,1,LOW);
	DIO_vwrite(Keypad_port,2,HIGH);
	DIO_vwrite(Keypad_port,3,HIGH);
	_delay_ms(10);
	if (!READ_BIT(Keypad_pin,4)) return '4';
	if (!READ_BIT(Keypad_pin,5)) return '5';
	if (!READ_BIT(Keypad_pin,6)) return '6';
	if (!READ_BIT(Keypad_pin,7)) return 'B';
	
	// Third row
	DIO_vwrite(Keypad_port,0,HIGH);
	DIO_vwrite(Keypad_port,1,HIGH);
	DIO_vwrite(Keypad_port,2,LOW);
	DIO_vwrite(Keypad_port,3,HIGH);
	_delay_ms(10);
	if (!READ_BIT(Keypad_pin,4)) return '1';
	if (!READ_BIT(Keypad_pin,5)) return '2';
	if (!READ_BIT(Keypad_pin,6)) return '3';
	if (!READ_BIT(Keypad_pin,7)) return 'C';
	
	// Fourth row
	DIO_vwrite(Keypad_port,0,HIGH);
	DIO_vwrite(Keypad_port,1,HIGH);
	DIO_vwrite(Keypad_port,2,HIGH);
	DIO_vwrite(Keypad_port,3,LOW);
	_delay_ms(10);
	if (!READ_BIT(Keypad_pin,4)) return '*';
	if (!READ_BIT(Keypad_pin,5)) return '0';
	if (!READ_BIT(Keypad_pin,6)) return '#';
	if (!READ_BIT(Keypad_pin,7)) return 'D';
	
	return '\0';  // No key pressed
}

unsigned char keypad_u8check_press(void)
{
	unsigned char arr[4][4] = {
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'A','0','=','+'}
	};

	unsigned char row, column;

	for (row = 0; row < 4; row++)
	{
		// Set all rows HIGH first (only once per row scan)
		for (unsigned char r = 0; r < 4; r++)
		DIO_vwrite(Keypad_port, r, HIGH);

		// Set current row LOW
		DIO_vwrite(Keypad_port, row, LOW);
		
		for (column = 0; column < 4; column++)
		{
			if (READ_BIT(Keypad_pin, column + 4) == 0)
			{
				_delay_ms(20); // debounce
				if (READ_BIT(Keypad_pin, column + 4) == 0)
				{
					// Wait until key is released (optional but cleaner)
					while (READ_BIT(Keypad_pin, column + 4) == 0);
					return arr[row][column];
				}
			}
		}
	}
	
	return 0xFF; // no key pressed
}
