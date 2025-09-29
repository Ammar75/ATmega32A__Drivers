/*
 * DIO.c
 *
 * Created: 12/1/2024 2:32:58 AM
 *  Author: Ammar
 */ 
#include <avr/io.h>
#define  MY_DDRA    *((unsigned char *)(0x3A))
#define  MY_PORTA  *((volatile unsigned char *)(0x3B))
#define  MY_PINA    *((unsigned char *)(0x39))

#define  MY_DDRB    *((unsigned char *)(0x37))
#define  MY_PORTB  *((volatile unsigned char *)(0x38))
#define  MY_PINB    *((unsigned char *)(0x36))

#define  MY_DDRC    *((unsigned char *)(0x34))
#define  MY_PORTC  *((volatile unsigned char *)(0x35))
#define  MY_PINC    *((unsigned char *)(0x33))




void set_pindir(unsigned char port, unsigned char pin, const char *direction)
{
	// Validate pin range
	unsigned char dir = 0;
	if ((strcmp(direction, "output") == 0) | (strcmp(direction, "OUTPUT") == 0))
	dir = 1;
	else if ((strcmp(direction, "input") == 0) | (strcmp(direction, "INPUT") == 0))
	dir = 0;
	
	if (pin > 7) return;

	switch (port)
	{
		case 'a':
		case 'A':
		if (dir == 1)
		MY_DDRA |= (1 << pin); // Set pin direction to output
		else
		MY_DDRA &= ~(1 << pin); // Set pin direction to input
		break;

		case 'b':
		case 'B':
		if (dir == 1)
		MY_DDRB |= (1 << pin);
		else
		MY_DDRB &= ~(1 << pin);
		break;

		case 'c':
		case 'C':
		if (dir == 1)
		MY_DDRC |= (1 << pin);
		else
		MY_DDRC &= ~(1 << pin);
		break;

		default:
		// Invalid port
		break;
	}
}



void DIO_Write(unsigned char port, unsigned char pin, const char *val)
{
	// Validate pin range
	unsigned char vall = 0;
	if ((strcmp(val, "HIGH") == 0) | (strcmp(val, "high") == 0))
	vall = 1;
	else if ((strcmp(val, "LOW") == 0) | (strcmp(val, "low") == 0))
	vall = 0;
	
	if (pin > 7) return;

	switch (port)
	{
		case 'a':
		case 'A':
		if (vall == 1)
		MY_PORTA |= (1 << pin); // Set pin direction to output
		else
		MY_PORTA &= ~(1 << pin); // Set pin direction to input
		break;

		case 'b':
		case 'B':
		if (vall == 1)
		MY_PORTB |= (1 << pin);
		else
		MY_PORTB &= ~(1 << pin);
		break;

		case 'c':
		case 'C':
		if (vall == 1)
		MY_PORTC |= (1 << pin);
		else
		MY_PORTC &= ~(1 << pin);
		break;

		default:
		// Invalid port
		break;
	}
}

void Dio_toggle(unsigned char port , unsigned char pin)
{
	switch(port)
	{
	case 'A':
	case 'a':
	MY_PORTA ^= (1<<pin);
	break;
	case 'b':
	case 'B':
	MY_PORTB ^= (1<<pin);
	break;
	case 'c':
	case 'C':
	MY_PORTC ^= (1<<pin);
	break;

	default:		// Invalid port
	break;
		}
}

char Dio_read(unsigned char port , unsigned char pin)
{
	unsigned char data = 0;
	switch(port)
	{
		case 'A':
		case 'a':
		data = ((MY_PORTA&(1<<pin))>>pin);
		break;
		case 'b':
		case 'B':
		data = ((MY_PORTB&(1<<pin))>>pin);
		break;
		case 'c':
		case 'C':
		data = ((MY_PORTC&(1<<pin))>>pin);
		break;

		default:
		break;
	}
	return data;
	
}

void Dio_SetPort_Direction(unsigned char port , const char *direction)
{	
	unsigned char dir =0;
	if ((strcmp(direction,"OUTPUT") == 0)| (strcmp(direction,"output") == 0))
	{dir = 1;}
	else if ((strcmp(direction,"INPUT") == 0)| (strcmp(direction,"INPUT") == 0))
	{dir = 0;}
	switch(port)
	{
		case 'A':
		case 'a':
		if (dir == 1)
		MY_PORTA = 0xff;
		else
		MY_PORTA=0;
		break;
		case 'B':
		case 'b':
		if (dir == 1)
		MY_PORTB = 0xff;
		else
		MY_PORTB=0;
		break;
		case 'C':
		case 'c':
		if (dir == 1)
		MY_PORTC = 0xff;
		else
		MY_PORTC=0;
		break;
		default:
		break;
	}
		
}


void Dio_Write_Port(unsigned char port , const char *vall)
{
	unsigned char val =0;
	if ((strcmp(vall,"HIGH") == 0)| (strcmp(vall,"high") == 0))
{val = 1;}
	else if ((strcmp(vall,"LOW") == 0)| (strcmp(vall,"low") == 0))
{val = 0;}
	switch(port)
	{
		case 'A':
		case 'a':
		if (val == 1)
		MY_PORTA = 0xff;
		else
		MY_PORTA=0;
		break;
		case 'B':
		case 'b':
		if (val == 1)
		MY_PORTB = 0xff;
		else
		MY_PORTB=0;
		break;
		case 'C':
		case 'c':
		if (val == 1)
		MY_PORTC = 0xff;
		else
		MY_PORTC=0;
		break;
		default:
		break;
	}
	
}




















// toggle specific pins on a register
/*
void toggle_port(unsigned char port,unsigned char *pins)
{
unsigned char *list_pins ={0,1,2,3,4,5,6,7};
int i,j;
switch(port)
{
	case'A':
	for (j = 0; j<8 ; j++)
	{
		for (i = j ; i < 8; i++)
		{
			if (pins[j] == i)
			*((unsigned char *)(0x3A)) ^= (1<<pins[j]);
		}
	}
	break;
	default:
	break;
}
}
*/