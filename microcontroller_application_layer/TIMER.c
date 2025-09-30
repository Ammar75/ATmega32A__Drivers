/*
 * TIMER.c
 *
 * Created: 6/24/2025 2:02:27 AM
 *  Author: Ammar
 */ 

#include "std_macros.h"
#include "avr/io.h"
#include "avr/interrupt.h"
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