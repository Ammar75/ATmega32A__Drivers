/*
 * LED.h
 *
 * Created: 3/11/2025 7:54:58 AM
 *  Author: Ammar
 */ 


#ifndef LED_H_
#define LED_H_


void led_initialize(unsigned char port , unsigned char bin_numb);
void led_on(unsigned char port , unsigned char bin_numb);
void led_off(unsigned char port , unsigned char bin_numb);
void led_toggle(unsigned char port , unsigned char bin_numb);

#endif /* LED_H_ */