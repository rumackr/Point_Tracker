/*
 * niosii_vga.c
 *
 *  Created on: Apr 6, 2017
 *      Author: rumackr
 */


#include "niosii_vga.h"
#include "msoeIoAdresses.h"

uint8_t niosii_vga_read_pixel(uint8_t x, uint8_t y){
	uint8_t pixelVal;
	uint32_t pixelAddr;
	pixelAddr = (y << 7);
	pixelAddr += x;
	pixelVal = *(VGA + pixelAddr);
	return pixelVal;
}



void niosii_vga_write(){
	uint8_t row =  0;
	uint8_t* memPtr;

	memPtr = (uint8_t*)(VGA + (row << 7));
	for (row = 59 ; row > 0; --row){
		uint8_t col = 0;
		for(col = 79; col > 0; --col){
			if((col>(60-4))&&(col<(60+4))&&(row>(30-4))&&(row<(30+4))){
				*memPtr = 0x10;

			}else{
			  *memPtr = 0xF0;

			}
			memPtr++;
		}
		memPtr = (uint8_t*)(VGA + (row << 7));
	}
}
