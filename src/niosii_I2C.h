/*
 * niosii_I2C.h
 *
 *  Created on: Mar 30, 2017
 *      Author: rumackr
 */

#ifndef NIOSII_I2C_C_
#define NIOSII_I2C_C_
#include <stdint.h>

void I2C_init();
uint8_t I2C_action(uint8_t command);
uint8_t I2C_read(uint8_t baseAddr,uint8_t regNumber);
uint8_t I2C_write(uint8_t baseAddr, uint8_t regNumber, uint8_t value);

#endif /* NIOSII_I2C_C_ */
