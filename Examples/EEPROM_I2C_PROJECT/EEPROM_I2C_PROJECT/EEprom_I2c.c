/*
 * EEprom_I2c.c
 *
 * Created: 7/27/2025 3:43:45 AM
 *  Author: Ammar
 */ 

#include "two_wire_c.h"
#include "util/delay.h"
void EEprom_I2c_write_byte(unsigned char device_address , unsigned char data_address , unsigned char data)
{
	I2C_Start();
	I2C_Write_address(device_address,0);
	I2C_Write_data(data_address);
	I2C_Write_data(data);
	I2C_stop();
}


void EEprom_I2c_write_Nbyte(unsigned char device_address , unsigned char data_address , unsigned char Bytes,unsigned char *data)
{
	I2C_Start();
	I2C_Write_address(device_address, 0);
	I2C_Write_data(data_address);
	for (int i = 0; i < Bytes; i++)
	{
		I2C_Write_data(data[i]);
		_delay_ms(6);
	}
	I2C_stop();
	_delay_ms(6);  // Only here
}

unsigned char EEprom_I2c_Read_byte(unsigned char device_address , unsigned char data_address)
{
	unsigned char ret_data= 0;
	I2C_Start();
	I2C_Write_address(device_address,0);
	I2C_Write_data(data_address);
	I2C_Start();
	I2C_Write_address(device_address,1);
	ret_data = I2C_slave_read_Nack();
	I2C_stop();
	return ret_data ;
}

void EEprom_I2c_Read_Nbyte(uint8_t device_address, uint8_t data_address, uint8_t length, uint8_t *buffer) 
{
	I2C_Start();
	I2C_Write_address(device_address, 0);
	I2C_Write_data(data_address);
	I2C_Start();
	I2C_Write_address(device_address, 1);
	
	for (int i = 0; i < length; i++) {
		if (i == (length - 1)) {
			buffer[i] = I2C_slave_read_Nack();
		} else {
			buffer[i] = I2C_slave_read();
		}
	}
	
	I2C_stop();
}


void EEprom_I2c_Erase_All(unsigned char device_address)
{
	for (int page = 0; page < 128; page++)  // 128 pages for AT24C16
	{
		unsigned char blank[16];  // each page = 16 bytes
		for (int i = 0; i < 16; i++)
		blank[i] = 0xFF;

		EEprom_I2c_write_Nbyte(device_address, page * 16, 16, blank);
		_delay_ms(10);
	}
}