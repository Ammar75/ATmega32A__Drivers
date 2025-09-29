/*
 * Keypad_driver.c
 *
 * Created: 4/19/2025 12:35:23 AM
 *  Author: Ammar
 */ 
#include "DIO.h"
#include "std_macros.h"
#include "util/delay.h"
#define Keypad_port 'd' 
#define Keypad_pin PIND_
#define HIGH  "HIGH"
#define LOW "LOW"
#define NOTPRESSED 0xff


void keypad_intialize(unsigned char port)
{
	Dio_VSet_pin_Dir(port ,0,"OUTPUT");
	Dio_VSet_pin_Dir(port, 1,"OUTPUT");
	Dio_VSet_pin_Dir(port, 2,"OUTPUT");
	Dio_VSet_pin_Dir(port, 3,"OUTPUT");
	Dio_VSet_pin_Dir(port, 4,"INPUT");
	Dio_VSet_pin_Dir(port, 5,"INPUT");
	Dio_VSet_pin_Dir(port, 6,"INPUT");
	Dio_VSet_pin_Dir(port, 7,"INPUT");
	
	Dio_connect_pullup(port, 4 , 1);
	Dio_connect_pullup(port, 5 , 1);
	Dio_connect_pullup(port, 6 , 1);
	Dio_connect_pullup(port, 7 , 1);
}



unsigned char Keypad_Pressed_value8u(void)
{	unsigned char x = 0;
	// First row
	DIO_vwrite(Keypad_port,0,LOW);
	DIO_vwrite(Keypad_port,1,HIGH);
	DIO_vwrite(Keypad_port,2,HIGH);
	DIO_vwrite(Keypad_port,3,HIGH);
	_delay_ms(10);  // small delay for settling
	if (!READ_BIT(Keypad_pin,4)) x= '1';
	if (!READ_BIT(Keypad_pin,5)) x= '2';
	if (!READ_BIT(Keypad_pin,6)) x= '3';
	if (!READ_BIT(Keypad_pin,7)) x= 'A';
	
	// Second row
	DIO_vwrite(Keypad_port,0,HIGH);
	DIO_vwrite(Keypad_port,1,LOW);
	DIO_vwrite(Keypad_port,2,HIGH);
	DIO_vwrite(Keypad_port,3,HIGH);
	_delay_ms(10);
	if (!READ_BIT(Keypad_pin,4)) x= '4';
	if (!READ_BIT(Keypad_pin,5)) x= '5';
	if (!READ_BIT(Keypad_pin,6)) x= '6';
	if (!READ_BIT(Keypad_pin,7)) x= 'B';
	
	// Third row
	DIO_vwrite(Keypad_port,0,HIGH);
	DIO_vwrite(Keypad_port,1,HIGH);
	DIO_vwrite(Keypad_port,2,LOW);
	DIO_vwrite(Keypad_port,3,HIGH);
	_delay_ms(10);
	if (!READ_BIT(Keypad_pin,4)) x= '7';
	if (!READ_BIT(Keypad_pin,5)) x= '8';
	if (!READ_BIT(Keypad_pin,6)) x= '9';
	if (!READ_BIT(Keypad_pin,7)) x= 'c';
	
	// Fourth row
	DIO_vwrite(Keypad_port,0,HIGH);
	DIO_vwrite(Keypad_port,1,HIGH);
	DIO_vwrite(Keypad_port,2,HIGH);
	DIO_vwrite(Keypad_port,3,LOW);
	_delay_ms(10);
	if (!READ_BIT(Keypad_pin,4)) x= '*';
	if (!READ_BIT(Keypad_pin,5)) x= '0';
	if (!READ_BIT(Keypad_pin,6)) x= '#';
	if (!READ_BIT(Keypad_pin,7)) x= 'D';
	
	return x;  // No key pressed
}


 unsigned char keypad_u8check_press()
 {
 unsigned char arr[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'A','0','=','+'}};
 unsigned char row = 0;
 unsigned char coloumn=0;
 unsigned char x;
 unsigned char returnval=NOTPRESSED;
 for(row=0;row<4;row++)
 {
	 DIO_vwrite('D',0,HIGH);
	 DIO_vwrite('D',1,HIGH);
	 DIO_vwrite('D',2,HIGH);
	 DIO_vwrite('D',3,HIGH);
	 DIO_vwrite('D',row,LOW);
	 
	 for(coloumn=0;coloumn<4;coloumn++)
	 {
		 x=READ_BIT(Keypad_pin,(coloumn+4));
		 if(x==0)
		 {
			 returnval=arr[row][coloumn];
			 break;
		 }
	 }
	 if(x==0)
	 {
		 break;
	 }
 }
 return returnval ;
 }