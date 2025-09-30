/*
 * Servo_Motor.c
 *
 * Created: 6/30/2025 5:41:14 AM
 *  Author: Ammar
 */ 

#include "std_macros.h"
#include "avr/io.h"
#define F_CPU 1000000UL

 Servo_motor_set_position(unsigned char angle)
{
	float pulse_width_ms = 0 ;
	/* setup timer 2 */
	/* select mode 14*/
	SET_BIT(TCCR1A,WGM11);
	CLEAR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	
	/* select prescaler = 1 */
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);
	
	/* select output mode functionality (non_inverting) */
	SET_BIT(TCCR1A,COM1A1);
	CLEAR_BIT(TCCR1A,COM1A0);
	
	/* load ocr1 */
	ICR1 = 19999;
	
	// convert angle to ms
	 if (angle > 180) angle = 180;
	 pulse_width_ms = 1.0 + angle / 180.0 ;
	
	/* control the on time */
	OCR1A = (unsigned short)(pulse_width_ms * 19999) / 20.0 ;
	SET_BIT(DDRD, 5);
	
	
}