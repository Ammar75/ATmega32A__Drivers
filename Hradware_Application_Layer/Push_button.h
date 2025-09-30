/*
 * Push_button.h
 *
 * Created: 3/29/2025 4:05:05 PM
 *  Author: Ammar
 */ 


#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_


void pushButton_Intialize_V8(unsigned char port , unsigned char pin_numb);
unsigned char PushButton_read_state(unsigned char port , unsigned char pin_numb);


#endif /* PUSH_BUTTON_H_ */