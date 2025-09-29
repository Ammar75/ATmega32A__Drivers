/*
 * std_macros.h
 *
 * Created: 3/5/2025 4:47:39 PM
 *  Author: Ammar
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_





#endif /* STD_MACROS_H_ */


#define PORTA_ *((volatile  unsigned char *)(0x25))
#define DDRA_  *((volatile  unsigned char *)(0x24))
#define PINA_  *((volatile  unsigned char *)(0x23))

#define PORTB_ *((volatile  unsigned char *)(0x25))
#define DDRB_  *((volatile  unsigned char *)(0x24))
#define PINB_  *((volatile  unsigned char *)(0x23))

#define PORTC_ *((volatile  unsigned char *)(0x28))
#define DDRC_  *((volatile  unsigned char *)(0x27))
#define PINC_  *((volatile  unsigned char *)(0x26))

#define PORTD_ *((volatile  unsigned char *)(0x2B))
#define DDRD_  *((volatile  unsigned char *)(0x2A))
#define PIND_  *((volatile  unsigned char *)(0x29))


#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)    reg |= (1<<bit)
#define CLEAR_BIT(reg,bit)  reg &= (~(1<<bit))
#define TOG_BIT(reg, bit)   reg ^= (1<<bit)
#define READ_BIT(reg,bit)   ((reg&(1<<bit))>>bit)
 