/*
 * EEprom_I2c.h
 *
 * Created: 7/27/2025 3:43:53 AM
 *  Author: Ammar
 */ 


#ifndef EEPROM_I2C_H_
#define EEPROM_I2C_H_

void EEprom_I2c_write_byte(unsigned char device_address , unsigned char data_address , unsigned char data);
unsigned char EEprom_I2c_Read_byte(unsigned char device_address , unsigned char data_address);

void EEprom_I2c_write_Nbyte(unsigned char device_address , unsigned char data_address , unsigned char Bytes,unsigned char *data);
void EEprom_I2c_Read_Nbyte(unsigned char device_address, unsigned char data_address, unsigned char length, unsigned char *buffer);
void EEprom_I2c_Erase_All(unsigned char device_address);
#endif /* EEPROM_I2C_H_ */