/*
 * CFile1.c
 *
 * Created: 3/11/2025 7:52:05 AM
 *  Author: Ammar
 */ 
#include "DIO.h"

void led_initialize(unsigned char port , unsigned char bin_numb)
{
	Dio_VSet_pin_Dir(port , bin_numb, "OUTPUT");
	return 0;
}

void led_on(unsigned char port , unsigned char bin_numb)
{
	DIO_vwrite(port,bin_numb,"HIGH");
}

void led_off(unsigned char port , unsigned char bin_numb)
{
	DIO_vwrite(port,bin_numb,"LOW");
}
void led_toggle(unsigned char port , unsigned char bin_numb)
{
	DIO_vToggle(port,bin_numb);
}