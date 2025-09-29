/*
 * ADC.c
 *
 * Created: 5/28/2025 4:42:39 AM
 *  Author: Ammar
 */ 
#include "std_macros.h"

void Adc_intialize()
{
	// enable adc
	SET_BIT(ADCSRA_,7);
	// set reference to AVC
	CLEAR_BIT(ADMUX_,6);
	CLEAR_BIT(ADMUX_,7);
	// set frequency factor by 
	SET_BIT(ADCSRA_,2);
	CLEAR_BIT(ADCSRA_,1);
	CLEAR_BIT(ADCSRA_,0);

	
}



unsigned short adc_read_u16(unsigned char channel)
{
	unsigned short ADC_data = 0;

	// select channel
	ADMUX_ = (ADMUX_ & 0xF0) | (channel & 0x0F);
	// start Conversion
	SET_BIT(ADCSRA_,6);
	while (READ_BIT(ADCSRA_,6) == 1);
	// must read low bit first
	ADC_data = ADCL_;
	ADC_data |= (ADCH_<< 8);


	SET_BIT(ADCSRA_,4);
	return ADC_data;
}
