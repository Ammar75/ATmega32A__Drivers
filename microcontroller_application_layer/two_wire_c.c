/*
 * two_wire.c
 *
 * Created: 7/21/2025
 * Author : Ammar
 */

#include "two_wire_c.h"
#include "std_macros.h"
#include <util/delay.h>

//=========================== I2C Initialization (Master) =============================
void I2C_master_vinit(unsigned long clock)
{
    // Set prescaler bits
    switch (PRESCALER)
    {
        case 1:  TWSR = 0; break;
        case 4:  TWSR = 1; break;
        case 16: TWSR = 2; break;
        case 64: TWSR = 3; break;
        default: TWSR = 0; break;
    }

    // Set bit rate
    TWBR = (uint8_t)(((F_CPU / clock) - 16) / (2 * PRESCALER));
}

//=========================== Error Handler =============================
void I2C_Error()
{
    SET_BIT(ERR_DDR, 3);     // Set PC3 as output
    TOG_BIT(ERR_PORT, 3);    // Toggle PC3 to indicate error
}

//=========================== Start Condition =============================
void I2C_Start()
{
    TWCR = (1 << TWSTA) | (1 << TWEN);
    SET_BIT(TWCR, TWINT);
    while (READ_BIT(TWCR, TWINT) == 0);

    if ((TWSR & 0xF8) != 0x08)  // START transmitted
        I2C_Error();
}

//=========================== Send Address =============================
void I2C_Write_address(uint8_t address, uint8_t direction)
{
    TWDR = (address << 1) | (direction & 0x01);
    TWCR = (1 << TWEN);
    TWSR = 0;
    SET_BIT(TWCR, TWINT);
    while (READ_BIT(TWCR, TWINT) == 0);

    if ((direction == 0 && (TWSR & 0xF8) != 0x18) || (direction == 1 && (TWSR & 0xF8) != 0x40))
        I2C_Error();
}

//=========================== Write Data =============================
void I2C_Write_data(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWEN);
    TWSR = 0;
    SET_BIT(TWCR, TWINT);
    while (READ_BIT(TWCR, TWINT) == 0);

    if ((TWSR & 0xF8) != 0x28)
        I2C_Error();
}

//=========================== Stop Condition =============================
void I2C_stop()
{
    TWCR = (1 << TWEN) | (1 << TWSTO);
    SET_BIT(TWCR, TWINT);
}

//=========================== Slave Address Setup =============================
void I2C_slave_address(uint8_t address, uint8_t general_call)
{
    TWAR = (address << 1) | (general_call & 0x01);
}

//=========================== Slave Read One Byte =============================
uint8_t I2C_slave_read()
{
    TWCR = (1 << TWEN) | (1 << TWEA);
    SET_BIT(TWCR, TWINT);
    while (READ_BIT(TWCR, TWINT) == 0);
    if ((TWSR & 0xF8) != 0x60)
        I2C_Error();

    TWCR = (1 << TWEN) | (1 << TWEA);
    SET_BIT(TWCR, TWINT);
    while (READ_BIT(TWCR, TWINT) == 0);
    if ((TWSR & 0xF8) != 0x60)
        I2C_Error();

    return TWDR;
}

//=========================== Master Transmit String =============================
void I2C_Master_Transmit_String(uint8_t slave_address, const char *str)
{
    I2C_Start();
    I2C_Write_address(slave_address, 0);  // Write operation

    while (*str)
        I2C_Write_data(*str++);

    I2C_stop();
}
//=========================== Master Transmit char =============================
void I2C_Master_Transmit_Char(uint8_t slave_address, char data)
{
	I2C_Start();
	I2C_Write_address(slave_address, 0);  // Write operation
	I2C_Write_data(data);
	I2C_stop();
}
//=========================== Slave Transmit char =============================
void I2C_Slave_Transmit_Char(char data)
{	
	
	
	TWCR = (1 << TWEN) | (1 << TWEA);
	SET_BIT(TWCR, TWINT);
	while (READ_BIT(TWCR, TWINT) == 0);	
	
	
    TWDR = data;
    TWCR = (1 << TWEN) | (1 << TWEA);;
    TWSR = 0;
    SET_BIT(TWCR, TWINT);
    while (READ_BIT(TWCR, TWINT) == 0);
	
	
}



//=========================== Master Recieve char =============================
unsigned char I2C_Master_Recieve_Char(uint8_t slave_address)
{
	
	I2C_Start();
	I2C_Write_address(slave_address, 1);  // Read operation
	TWCR = (1 << TWEN) | (1 << TWEA);
	SET_BIT(TWCR, TWINT);
	while (READ_BIT(TWCR, TWINT) == 0);
	if ((TWSR & 0xF8) != 0x60)
	I2C_Error();
	I2C_stop();
	
	return TWDR;
}



//=========================== Slave Receive String =============================
void I2C_Slave_Receive_String(char *buffer, uint8_t max_length)
{
    uint8_t index = 0;

    // Wait for SLA+W
    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x60)
        I2C_Error();

    while (index < (max_length - 1))
    {
        TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
        while (!(TWCR & (1 << TWINT)));

        if ((TWSR & 0xF8) == 0x80)
        {
            buffer[index++] = TWDR;
        }
        else if ((TWSR & 0xF8) == 0xA0)
        {
            break;
        }
        else
        {
            I2C_Error();
        }
    }

    buffer[index] = '\0';
}
