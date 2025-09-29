/*
 * std_macros.h
 *
 * Created: 3/5/2025 4:47:39 PM
 *  Author: Ammar
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_





#endif /* STD_MACROS_H_ */

#define PORTA_ *((volatile  unsigned char *)(0x3B))
#define DDRA_  *((volatile  unsigned char *)(0x3A))
#define PINA_  *((volatile  unsigned char *)(0x39))

#define PORTB_ *((volatile  unsigned char *)(0x38))
#define DDRB_  *((volatile  unsigned char *)(0x37))
#define PINB_  *((volatile  unsigned char *)(0x36))

#define PORTC_ *((volatile  unsigned char *)(0x35))
#define DDRC_  *((volatile  unsigned char *)(0x34))
#define PINC_  *((volatile  unsigned char *)(0x33))

#define PORTD_ *((volatile  unsigned char *)(0x32))
#define DDRD_  *((volatile  unsigned char *)(0x31))
#define PIND_  *((volatile  unsigned char *)(0x30))

#define SFIOR_ *((volatile  unsigned char *)(0x50))
//EEPROM
#define EEARH_ *((volatile unsigned char *)(0x3F))
#define EEARL_ *((volatile unsigned char *)(0x3E))
#define EEDR_  *((volatile unsigned char *)(0x3D))
#define EECR_  *((volatile unsigned char *)(0x3c))


//ADC
#define ADCSRA_  *((volatile unsigned char *)(0x26))
#define ADMUX_  *((volatile unsigned char *)(0x27))

#define ADCH_  *((volatile unsigned char *)(0x25))
#define ADCL_  *((volatile unsigned char *)(0x24))


#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg |= (1<<bit)
#define CLEAR_BIT(reg,bit)  reg &= (~(1<<bit))
#define TOG_BIT(reg, bit)   reg ^= (1<<bit)
#define READ_BIT(reg,bit)   ((reg&(1<<bit))>>bit)
 
// Timers
#define TCCR0_  *((volatile unsigned char *)(0x53))
#define TCNT0_  *((volatile unsigned char *)(0x52))
#define TIFR_  *((volatile unsigned char *)(0x58))
#define TIMSK_  *((volatile unsigned char *)(0x59))
#define OCR0_  *((volatile unsigned char *)(0x5c))
