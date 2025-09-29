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
	/* load a value in OCR0 */
	OCR0=80;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei();
	SET_BIT(TIMSK,OCIE0);
}