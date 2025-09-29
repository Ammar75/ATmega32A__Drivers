/*
 * DIO.c
 *
 * Created: 3/5/2025 4:26:20 PM
 *  Author: Ammar
 */ 
#include "std_macros.h"
#include <string.h>

void Dio_VSet_pin_Dir(unsigned char port, unsigned char reg_numb, const char *dir)
{
	if (((strcmp(dir, "OUTPUT")) == 0) || ((strcmp(dir, "output")) == 0))
	{
		switch (port)
		{
			case 'A':
			case 'a':
				SET_BIT(DDRA_, reg_numb);
				break;
			case 'B':
			case 'b':
				SET_BIT(DDRB_, reg_numb);
				break;
			case 'C':
			case 'c':
				SET_BIT(DDRC_, reg_numb);
				break;
			case 'D':   // Fixed inconsistency
			case 'd':
				SET_BIT(DDRD_, reg_numb);
				break;
			default:
				break;  // Handle unexpected port values
		}
	}
	else if (((strcmp(dir, "INPUT")) == 0) || ((strcmp(dir, "input")) == 0))
	{
		switch (port)
		{
			case 'A':
			case 'a':
			CLEAR_BIT(DDRA_, reg_numb);
			break;
			case 'B':
			case 'b':
			CLEAR_BIT(DDRB_, reg_numb);
			break;
			case 'C':
			case 'c':
			CLEAR_BIT(DDRC_, reg_numb);
			break;
			case 'D':   // Fixed inconsistency
			case 'd':
			CLEAR_BIT(DDRD_, reg_numb);
			break;
			default:
			break;  // Handle unexpected port values
		}
	}
}

void DIO_vwrite(unsigned char port , unsigned char reg_numb, const char *val)
{
	if (((strcmp(val, "HIGH")) == 0) || ((strcmp(val, "high")) == 0))
	{
		switch (port)
		{
			case 'A':
			case 'a':
			SET_BIT(PORTA_, reg_numb);
			break;
			case 'B':
			case 'b':
			SET_BIT(PORTB_, reg_numb);
			break;
			case 'C':
			case 'c':
			SET_BIT(PORTC_, reg_numb);
			break;
			case 'D':   // Fixed inconsistency
			case 'd':
			SET_BIT(PORTD_, reg_numb);
			break;
			default:
			break;  // Handle unexpected port values
		}
	}
	else if (((strcmp(val, "LOW")) == 0) || ((strcmp(val, "low")) == 0))
	{
		switch (port)
		{
			case 'A':
			case 'a':
			CLEAR_BIT(PORTA_, reg_numb);
			break;
			case 'B':
			case 'b':
			CLEAR_BIT(PORTB_, reg_numb);
			break;
			case 'C':
			case 'c':
			CLEAR_BIT(PORTC_, reg_numb);
			break;
			case 'D':   // Fixed inconsistency
			case 'd':
			CLEAR_BIT(PORTD_, reg_numb);
			break;
			default:
			break;  // Handle unexpected port values
		}
	}
	
}

void DIO_vToggle(unsigned char port , unsigned char reg_numb)
{
	switch (port)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA_, reg_numb);
		break;
		case 'B':
		case 'b':
		TOG_BIT(PORTB_, reg_numb);
		break;
		case 'C':
		case 'c':
		TOG_BIT(PORTC_, reg_numb);
		break;
		case 'D':   // Fixed inconsistency
		case 'd':
		TOG_BIT(PORTD_, reg_numb);
		break;
		default:
		break;  // Handle unexpected port values
	}
	
}

unsigned char DIO_u8Read_pin(unsigned char port , unsigned char reg_numb)
{
	
	switch (port)
	{
		case 'A':
		case 'a':
		return READ_BIT(PINA_, reg_numb);
		break;
		case 'B':
		case 'b':
		return READ_BIT(PINB_, reg_numb);
		break;
		case 'C':
		case 'c':
		return READ_BIT(PINC_, reg_numb);
		break;
		case 'D':   // Fixed inconsistency
		case 'd':
		return READ_BIT(PIND_, reg_numb);
		break;
		default:
		break;  // Handle unexpected port values
	}
}


void DIO_VSet_port_Direction(unsigned char port , unsigned char dir)
{
	switch(port)
	{
		case'a':
		case'A':
			DDRA_ = dir;
		break;
		case 'b':
		case 'B':
			DDRB_ = dir;
			break;
		case 'C':
		case 'c':
			DDRC_ = dir;
			break;
		case 'd':
		case 'D':
			DDRD_ = dir;
			break;
	}
}

void DIO_VWrite_port(unsigned char port , unsigned char val)
{
	switch(port)
	{
		case'a':
		case'A':
			PORTA_ = val;
			break;
		case 'b':
		case 'B':
			PORTB_ = val;
			break;
		case 'C':
		case 'c':
			PORTC_ = val;
			break;
		case 'd':
		case 'D':
			PORTD_ = val;
			break;
		default:
			break;
	}
}

unsigned char DIO_U8Read_port(unsigned char port)
{
	switch(port)
	{
		case'a':
		case'A':
			return PINA_ ;
			break;
		case 'b':
		case 'B':
			return PINB_;
			break;
		case 'C':
		case 'c':
			return PINC_;
			break;
		case 'd':
		case 'D':
			return PIND_;
			break;
	}
}


void DIO_VToggle_port(unsigned char port)

{
	switch(port)
	{
		case'a':
		case'A':
			PORTA_ ^= (0xff);
			break;
		case 'b':
		case 'B':
			PORTB_ ^= (0xff);
			break;
		case 'C':
		case 'c':
			PORTC_ ^= (0xff);
			break;
		case 'd':
		case 'D':
			return PORTD_ ^= (0xff);
			break;
	}
}




