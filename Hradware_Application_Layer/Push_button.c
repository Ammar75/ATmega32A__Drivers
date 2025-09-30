/*
 * Push_button.c
 *
 * Created: 3/29/2025 4:04:32 PM
 *  Author: Ammar
 */ 

void pushButton_Intialize_V8(unsigned char port , unsigned char pin_numb)
{
	Dio_VSet_pin_Dir(port , pin_numb , "INPUT");
}

unsigned char PushButton_read_state(unsigned char port , unsigned char pin_numb)
{
	return DIO_u8Read_pin(port , pin_numb);
}