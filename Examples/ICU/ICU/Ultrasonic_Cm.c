/*
 * Ultrasonic_Cm.c
 *
 * Created: 6/29/2025 7:18:57 PM
 *  Author: Ammar
 */ 
#include "DIO.h"
#include "util/delay.h"
#include "std_macros.h"
#define F_CPU 8000000UL
#include "avr/io.h"
unsigned char Distance_measure_U8(unsigned char port,unsigned char trigger)
{
	unsigned short a = 0 , b = 0 , T_on =0 ;
	unsigned char distance ;

	
	DIO_vwrite(port , trigger , "HIGH");
	_delay_us(50);
	DIO_vwrite(port , trigger , "LOW");
	// Timer1 Setup
	TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));  // Clear all
	// set pre_scaler to 1
	CLEAR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS12);
	//SELECT ICU MODE
	
	SET_BIT(TCCR1B,ICNC1);
	SET_BIT(TCCR1B,ICES1);
	SET_BIT(TIFR,ICF1);
	
	while(READ_BIT(TIFR,ICF1) == 0);
	a = ICR1;
	// detect first falling edge
	CLEAR_BIT(TCCR1B,ICES1);
	SET_BIT(TIFR,ICF1);
	while(READ_BIT(TIFR,ICF1) == 0);
	b = ICR1;
	TCCR1B = 0;
	SET_BIT(TIFR,ICF1);
	
	T_on = (b-a); 
	distance = (T_on * 34600) / (F_CPU * 2) ;
	return distance;
}