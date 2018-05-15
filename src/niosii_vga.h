/*
 * niosii_vga.h
 *
 *  Created on: Apr 6, 2017
 *      Author: rumackr
 */

#ifndef NIOSII_VGA_H_
#define NIOSII_VGA_H_
#include <stdint.h>
/**
 * Used to test VGA
 */
void niosii_vga_write();
/**
 * niosii_vga_read_pixel
 * Reads the data of a given pixel the VGA monitor.
 * @param x: X-coordinate of the requested Pixel
 * @param y: Y-coordinate of the requested Pixel
 * @return pixel value
 */
uint8_t niosii_vga_read_pixel(uint8_t x, uint8_t y);


#endif /* NIOSII_VGA_H_ */
