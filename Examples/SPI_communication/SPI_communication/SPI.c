/*
 * SPI.c
 * Updated: 7/14/2025
 * Author: Ammar
 */

#include <avr/io.h>
#include "util/delay.h"

// ================= Pin Definitions =================
#define SS   PB4
#define MOSI PB5
#define MISO PB6
#define SCK  PB7

// ================= MASTER =================
void SPI_MasterInit(void) {
    // Set MOSI, SCK, and SS as outputs
    DDRB |= (1 << MOSI) | (1 << SCK) | (1 << SS);
    // Enable SPI in Master mode, fosc/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	PORTB |= (1 << SS);  // Deselect slave initially

}

unsigned char SPI_MasterTransmit(unsigned char data) {
	PORTB &= ~(1 << SS);
    SPDR = data;  // Load data
    while (!(SPSR & (1 << SPIF)));  // Wait for completion
    return SPDR;  // Return received byte
}

void SPI_MasterSendString(const char *str) {
    PORTB &= ~(1 << SS);  // Select slave (SS low)

    while (*str) {
        SPI_MasterTransmit(*str++);
 // Optional delay for simulation/debug
    }
    SPI_MasterTransmit('\0');  // Send null terminator

    PORTB |= (1 << SS);  // Deselect slave
}

void SPI_MasterReceiveString(char *buffer) {
    PORTB &= ~(1 << SS);  // Select slave (SS low)

    uint8_t i = 0;
    char received;
    do {
        received = SPI_MasterTransmit(0xFF);  // Send dummy to read
        buffer[i++] = received;
    } while (received != '\0');
}



// ================= SLAVE =================
void SPI_SlaveInit(void) {
	SPCR = (1 << SPE);    // Enable SPI (slave mode)
    DDRB |= (1 << MISO);  // Set MISO as output
    

}

unsigned char SPI_SlaveTransmit(unsigned char data) {
    SPDR = data;  // Load data to send
    while (!(SPSR & (1 << SPIF)));  // Wait for transmission
    return SPDR;  // Return received byte
}

void SPI_SlaveReceiveString(char *buffer) {
    uint8_t i = 0;
    char received;
    do {
        received = SPI_SlaveTransmit(0xFF);  // Send dummy, receive data
        buffer[i++] = received;
    } while (received != '\0');
}

void SPI_SlaveSendString(const char *str) {
    while (*str) {
        SPI_SlaveTransmit(*str++);
         // Optional delay for sync/debug
    }
    SPI_SlaveTransmit('\0');  // Send null terminator
}
