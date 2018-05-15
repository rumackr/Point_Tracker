/*
 * niosii_I2C.c
 *
 *  Created on: Mar 30, 2017
 *      Author: rumackr
 */

#include <stdint.h>
#include "niosii_I2C.h"
#include "msoeIoAdresses.h"

// For Command Register
#define START_I2C 0x80
#define STOP_I2C  0x40
#define WRITE_I2C 0x10
#define READ_I2C  0x20
#define ACK_I2C   0x08
// For Status Register
#define TIP    0x02
#define RxACK  0x80
#define BUSY   0x40
//
#define ACK       0
#define NACK      1
#define IS_BUSY   1
#define NOT_BUSY  0


void I2C_init();
// This function is needed by every I2C transfer operation.
// It sets the command needed by the particular I2C
//  transfer, polls TIP for end of transfer and returns the
// RxACK status (0 for success)
uint8_t I2C_action(uint8_t command);

// This function is used to read the contents of any of
// the camera’s registers. It returns the 8-bit contents of the
// specified register.
uint8_t I2C_read(uint8_t slaveAddr,uint8_t regNumber);

// This function takes the value passed in
// and writes it to the specified register. It returns nothing.
uint8_t I2C_write(uint8_t slaveAddr,uint8_t regNumber, uint8_t value);

void I2C_init(){
	*I2C_LO = 0x63;//99
	*I2C_HI = 0x00;
	*I2C_CTRL = 0x80;//Enable

}

uint8_t I2C_action(uint8_t command){
	uint8_t ackOrNack  = 0;

	*I2C_CMD = command;
	//wait for not busy
	while((*I2C_STAT & TIP) == TIP);
	ackOrNack = (*I2C_STAT & RxACK);
	return ackOrNack;
}
uint8_t I2C_read(uint8_t slaveAddr,uint8_t regNumber){
	uint8_t valueRead = 0;
	*I2C_TRANSMIT = 0xC0;
	I2C_action(START_I2C|WRITE_I2C);
	*I2C_TRANSMIT = regNumber;
	I2C_action(WRITE_I2C|STOP_I2C);
	*I2C_TRANSMIT = slaveAddr;
	I2C_action(START_I2C|WRITE_I2C);
	I2C_action(READ_I2C|STOP_I2C|ACK_I2C);
	valueRead = *I2C_RECEIVE;
	return valueRead;
}
uint8_t I2C_write(uint8_t slaveAddr, uint8_t regNumber, uint8_t value){
	uint8_t writen = 0;
	*I2C_TRANSMIT = slaveAddr;
	 I2C_action(START_I2C|WRITE_I2C);
	*I2C_TRANSMIT = regNumber;
	 I2C_action(WRITE_I2C);
	*I2C_TRANSMIT = value;
	 writen = I2C_action(WRITE_I2C|STOP_I2C);
	 return writen;
}
