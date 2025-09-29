/*
 * LCD_Project.c
 *
 * Created: 4/16/2025 8:50:10 PM
 *  Author: Ammar
 */ 



#include <avr/io.h>

#include "util/delay.h"

#include "lcd.h"
int main(void)
{	LCD_vInit();
	LCD_clearscreen(); // Start defining CGRAM at address 0
	char count = 0;

	
	while(1)
    {	
		LCD_movecursor(1,1);
		LCD_vSend_string("Ammar");
		LCD_vSend_char(count);
		count++;
		//TODO:: Please write your application code 
    }
}