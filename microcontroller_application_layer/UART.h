/*
 * UART.h
 *
 * Created: 7/7/2025 3:50:59 AM
 *  Author: Ammar
 */ 


#ifndef UART_H_
#define UART_H_


void UART_vinit(unsigned long baud);
void UART_SendChar(unsigned char data);
unsigned char UART_u8Recieve_data(void);
void UART_SendString(const char* str);





#endif /* UART_H_ */