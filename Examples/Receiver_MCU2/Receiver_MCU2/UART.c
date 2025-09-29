/*
 * UART.c
 *
 * Created: 7/7/2025 3:50:32 AM
 *  Author: Ammar
 */ 
#define F_CPU 8000000UL
#include "avr/io.h"

void UART_vinit(unsigned long baud)
{
	
	// DEFINE THE baud rate
	
	unsigned short UBRR= (F_CPU/ (16UL * baud))-1;
	UBRRH = (unsigned char) (UBRR >> 8);
	UBRRL = (unsigned char) UBRR ;
	
	// enable uart sender and receiver bits
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	// choose to transmit 8 data bit, no parity bits , 1 stop bit
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
}

void UART_SendChar(unsigned char data)
{
	while(!(UCSRA & ( 1 << UDRE)));
	UDR = data;
}

unsigned char UART_u8Recieve_data(void)
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}

void UART_SendString(const char* str) {
	while (*str) {
		UART_SendChar(*str++);
	}
}