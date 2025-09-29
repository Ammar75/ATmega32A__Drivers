/*
 * TIMER.c
 *
 * Created: 6/24/2025 2:02:27 AM
 *  Author: Ammar
 */ 

#include "std_macros.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#define F_CPU 8000000UL
#include "TIMER.h"

void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}



void timer0_CTC_Wave_NonPWM_init(unsigned char compare_value )
{
	/* select CTC mode*/
	SET_BIT(TCCR0_,WGM01);
	CLEAR_BIT(TCCR0_,WGM00);
	/* select 1024 prescaler */
	SET_BIT(TCCR0_,CS00);
	SET_BIT(TCCR0_,CS02);
	CLEAR_BIT(TCCR0_,CS01);
	/* Toggle mode*/
	SET_BIT(TCCR0 , COM00);
	CLEAR_BIT(TCCR0 , COM01);
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
}


void Timer0_fastPwm_init(void)
{
	/* select fast pwm mode */
	SET_BIT(TCCR0_,WGM01);
	SET_BIT(TCCR0_,WGM00);
	
	/* select 1 prescaler */
	SET_BIT(TCCR0_,CS00);
	CLEAR_BIT(TCCR0_,CS02);
	CLEAR_BIT(TCCR0_,CS01);
	
	/* select non_inverting mode */
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
}

void Timer0_wave_generate(unsigned char compare_value)
{
	/* load value in ocr0*/
	OCR0_ = compare_value;
	
}

void Timer0_PhaseCorrect_init(void)
{
	/* select phase correct pwm mode */
	CLEAR_BIT(TCCR0_,WGM01);
	SET_BIT(TCCR0_,WGM00);
	
	/* select 1 prescaler */
	SET_BIT(TCCR0_,CS00);
	CLEAR_BIT(TCCR0_,CS02);
	CLEAR_BIT(TCCR0_,CS01);
	
	/* select functionality mode */
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
}





PWM_Info Timer1_input_capture_unit(unsigned int prescaler)
{
	unsigned short a = 0, b = 0, c = 0;
	unsigned short T_on = 0, period = 0;
	PWM_Info result;
	
	
	
	/* clock select With 1 prescaler*/
 TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));

 switch (prescaler)
	{
	 case 1:
	 TCCR1B |= (1 << CS10); // 001
	 TCCR1B &= ~(1 << CS11); 
	 TCCR1B &= ~(1 << CS12); 
	 break;
	 case 8:
	 TCCR1B |= (1 << CS11); // 010
	 break;
	 case 64:
	 TCCR1B |= (1 << CS11) | (1 << CS10); // 011
	 break;
	 case 256:
	 TCCR1B |= (1 << CS12); // 100
	 break;
	 case 1024:
	 TCCR1B |= (1 << CS12) | (1 << CS10); // 101
	 break;
	 case 0: // No clock source (Timer stopped)
	 // all bits already cleared
	 break;
	 case 6: // External clock on falling edge
	 TCCR1B |= (1 << CS12) | (1 << CS11); // 110
	 break;
	 case 7: // External clock on rising edge
	 TCCR1B |= (1 << CS12) | (1 << CS11) | (1 << CS10); // 111
	 break;
	 default:
	 // Invalid prescaler value, optionally handle error
	 break;
	}
	// detect first rising edge 
	SET_BIT(TIFR,ICF1);
	
	SET_BIT(TCCR1B,ICNC1);
	SET_BIT(TCCR1B,ICES1);
	while(READ_BIT(TIFR,ICF1) == 0);
	a = ICR1;
	
	
	// detect first falling edge
	CLEAR_BIT(TCCR1B,ICES1);
	SET_BIT(TIFR,ICF1);
	while(READ_BIT(TIFR,ICF1) == 0);
	b = ICR1;
	
	
	// detect second rising edge
	
	SET_BIT(TCCR1B,ICES1);
	SET_BIT(TIFR,ICF1);
	while(READ_BIT(TIFR,ICF1) == 0);
	c = ICR1;
	SET_BIT(TIFR,ICF1);
	// stop the timer1
	TCCR1B = 0;

	T_on = b - a;
	period = c - a ;
	
	result.duty_cycle= ((float)T_on / period) * 100 ;
	result.frequency = F_CPU / (period * (unsigned long)prescaler);
	return result;
}	