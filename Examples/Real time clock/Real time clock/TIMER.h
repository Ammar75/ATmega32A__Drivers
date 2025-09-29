/*
 * TIMER.h
 *
 * Created: 6/24/2025 2:03:23 AM
 *  Author: Ammar
 */ 


#ifndef TIMER_H_
#define TIMER_H_
void timer0_OVF_interrupt(void);
void timer0_CTC_init_interrupt(void);
void timer0_CTC_Wave_NonPWM_init(unsigned char compare_value );
void Timer0_fastPwm_init(void);
void Timer0_wave_generate(unsigned char compare_value);
void Timer0_PhaseCorrect_init(void);
void timer2_OVF_init_int(void);
#endif /* TIMER_H_ */