/*
 * _7_segment.c
 *
 * Created: 4/3/2025 5:24:28 PM
 *  Author: Ammar
 */ 

#include "std_macros.h"
#include "DIO.h"
#define comman_cathod

void Seven_Segment_vintit(unsigned char port)
{
	DIO_VSet_port_Direction(port,"output");
}

void Seven_segment_write_by_numb(unsigned char port , unsigned char numb)
{  
	#ifdef comman_cathod
		unsigned char arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	#else
		unsigned char arr[10]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f};
	#endif
	DIO_VWrite_port(port , arr[numb]);
}


void Seven_segment_vinit_BCD(unsigned char port , const char *nibble)
{
	if ((strcmp(nibble , "LOW") == 0) || (strcmp(nibble , "low") == 0))
	{
		Dio_VSet_pin_Dir(port,0,"OUTPUT");
		Dio_VSet_pin_Dir(port,1,"OUTPUT");
		Dio_VSet_pin_Dir(port,2,"OUTPUT");
		Dio_VSet_pin_Dir(port,3,"OUTPUT");
	}
	else if  ((strcmp(nibble,  "HIGH") == 0) || (strcmp(nibble , "high") == 0))
	{
		Dio_VSet_pin_Dir(port,4,"OUTPUT");
		Dio_VSet_pin_Dir(port,5,"OUTPUT");
		Dio_VSet_pin_Dir(port,6,"OUTPUT");
		Dio_VSet_pin_Dir(port,7,"OUTPUT");
	}
}

void Seven_segment_vWrite_BCD(unsigned char port , unsigned char val , const char *nibble)
{
	if ((strcmp(nibble,"LOW") == 0 ) || (strcmp(nibble,"low") == 0))
	{
		Dio_Write_lowNibble(port , val);
	}
	else if  ((strcmp(nibble,"HIGH") == 0) || (strcmp(nibble,"high") == 0))
	{
		Dio_Write_highNibble(port , val);
	}
}

