/*
 * two_wire.h
 *
 * I2C Driver for ATmega32 (Master and Slave support)
 * Created: 7/21/2025
 * Author : Ammar
 */

#ifndef TWO_WIRE_H_
#define TWO_WIRE_H_

#include <avr/io.h>
#include <stdint.h>

//=========================== Configuration Macros =============================
#define F_CPU      8000000UL
#define PRESCALER  1
#define ERR_DDR    DDRC
#define ERR_PORT   PORTC

//=========================== Function Prototypes =============================

/**
 * @brief  Initialize the I2C module in master mode with desired SCL clock.
 * @param  clock: Desired I2C clock frequency in Hz (e.g., 100000 for 100kHz)
 * @retval None
 */
void I2C_master_vinit(unsigned long clock);

/**
 * @brief  Send the START condition on the I2C bus.
 * @retval None
 */
void I2C_Start(void);

/**
 * @brief  Send a slave address along with read/write bit.
 * @param  address: 7-bit I2C slave address
 * @param  direction: 0 for write, 1 for read
 * @retval None
 */
void I2C_Write_address(uint8_t address, uint8_t direction);

/**
 * @brief  Send one byte of data over I2C.
 * @param  data: The byte to transmit
 * @retval None
 */
void I2C_Write_data(uint8_t data);

/**
 * @brief  Send the STOP condition to release the I2C bus.
 * @retval None
 */
void I2C_stop(void);

/**
 * @brief  Set the device's own address in slave mode.
 * @param  address: 7-bit slave address
 * @param  general_call: Set to 1 to respond to general call (0x00), 0 to ignore
 * @retval None
 */
void I2C_slave_address(uint8_t address, uint8_t general_call);

/**
 * @brief  Read a single byte sent from the master to the slave.
 * @retval Received byte from the I2C master
 */
uint8_t I2C_slave_read(void);

/**
 * @brief  Transmit a null-terminated string from the master to a slave.
 * @param  slave_address: 7-bit I2C slave address
 * @param  str: Pointer to null-terminated string to send
 * @retval None
 */
void I2C_Master_Transmit_String(uint8_t slave_address, const char *str);

/**
 * @brief  Receive a string sent from the master and store it in a buffer.
 * @param  buffer: Pointer to character array where data will be stored
 * @param  max_length: Maximum number of characters to store including null terminator
 * @retval None
 */
void I2C_Slave_Receive_String(char *buffer, uint8_t max_length);

/**
 * @brief  Handle an I2C error by toggling an error pin (PC3).
 * @retval None
 */
void I2C_Error(void);

#endif /* TWO_WIRE_H_ */
