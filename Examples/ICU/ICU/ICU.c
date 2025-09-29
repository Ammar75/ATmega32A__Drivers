/*
 * ICU.c
 *
 * Created: 6/29/2025 3:36:26 PM
 *  Author: Ammar
 */ 


#include <avr/io.h>
#include "TIMER.h"
#include "lcd.h"
#include "Ultrasonic_Cm.h"
#include "util/delay.h"
int main(void)
{
	/*
    PWM_Info signal;
    Lcd_Initialize();
    signal = Timer1_input_capture_unit(1024);
    Lcd_Set_cursor(1,1);
    Lcd_send_string("Duty = ");
    Lcd_Send_char((signal.duty_cycle/10) + 48 );
    Lcd_Send_char((signal.duty_cycle%10) + 48 );
	Lcd_Send_char('%');
	Lcd_Set_cursor(2,1);
	Lcd_send_string("freq:");
	Lcd_Send_char((signal.frequency/1000)+48);
	Lcd_Send_char(((signal.frequency/100)%10)+48);
	Lcd_Send_char(((signal.frequency/10)%10)+48);
	Lcd_Send_char((signal.frequency%10)+48);
	Lcd_send_string("HZ");
	*/
	
	Dio_VSet_pin_Dir('d',5,"OUTPUT");
	Lcd_Initialize();
	unsigned char distance;
	while(1)
    {
	Lcd_Set_cursor(1, 1);
	Lcd_send_string("DISTANCE = ");
	distance = Distance_measure_U8('d', 5);
	Lcd_Send_char(((distance / 10) % 10) + 48);
	Lcd_Send_char((distance % 10) + 48);
	Lcd_send_string("cm ");
	_delay_ms(300);
		
    }
}