/*
 * DIOh.h
 *
 * Created: 12/1/2024 2:33:27 AM
 *  Author: Ammar
 */ 


#ifndef DIOH_H_
#define DIOH_H_





#endif /* DIOH_H_ */

void set_pindir(unsigned char port, unsigned char pin, const char *direction);
void DIO_Write(unsigned char port, unsigned char pin, const char *val);
void Dio_toggle(unsigned char port , unsigned char pin);
char Dio_read(unsigned char port , unsigned char pin);
void Dio_SetPort_Direction(unsigned char port , const char *direction);
void Dio_Write_Port(unsigned char port , const char *vall);