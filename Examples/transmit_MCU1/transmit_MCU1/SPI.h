/*
 * SPI.h
 *
 * Created: 7/13/2025 1:49:24 AM
 *  Author: Ammar
 */ 


#ifndef SPI_H_
#define SPI_H_
// =================== Master Functions ===================
void SPI_MasterInit(void);
unsigned char SPI_MasterTransmit(unsigned char data);
void SPI_MasterSendString(const char *str);
void SPI_MasterReceiveString(char *buffer);

// =================== Slave Functions ===================
void SPI_SlaveInit(void);
unsigned char SPI_SlaveTransmit(unsigned char data);
void SPI_SlaveReceiveString(char *buffer);
void SPI_SlaveSendString(const char *str);

#endif /* SPI_H_ */