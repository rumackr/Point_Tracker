/*
 * cameraAPI.c
 *
 *  Created on: Mar 30, 2017
 *      Author: rumackr
 */
#include <stdint.h>
#include "msoeIoAdresses.h"
#include "niosii_I2C.h"
#include "CameraAPI.h"
#include "niosii_vga.h"

#define CAMERA_WR_ADDR 0xC0
#define CAMERA_RD_ADDR 0xC1
#define CAMERA_mfg_id_numb1 0x1c
#define CAMERA_mfg_id_numb2 0x1d
#define BLK_MAX 0x10
#define WHT_MAX 0xF0
#define COL_BUFF  7
#define ROW_BUFF  11
#define NUMB_VGA_COLS 80
#define NUMB_VGA_ROWS 60
#define NUMB_COLS 175
#define NUMB_ROWS 143
#define COMC_ADDR 0x14
#define COMH_ADDR 0x28
#define VSYNC_MASK 0x4
#define HREF_MASK 0x2
#define PCLK_MASK 0x1


uint8_t cameraDetect(){
	uint8_t val0, val1, detected = 0;
	val0 = cameraRead(CAMERA_mfg_id_numb1);
	val1 = cameraRead(CAMERA_mfg_id_numb2);

	((val0 == 0x7F)&&(val1 == 0xA2 ))?  (detected = 1): (detected = 0);
	(detected==1)?  (printf("\n Camera Detected \n")): (printf("\n Camera NOT Detected \n"));
	return detected;
}

void cameraInit(){
	if (cameraDetect()){
		//initializes the camera into QCIF mode by
		cameraWrite(0x20,COMC_ADDR);
		cameraWrite(0x41,COMH_ADDR);
	}
}

uint8_t cameraRead(uint8_t subaddress){
	uint8_t readValue = 0;
	readValue = I2C_read(CAMERA_RD_ADDR, subaddress);
	return readValue;
}

void cameraWrite(uint8_t value,uint8_t subaddress){
	I2C_write(CAMERA_WR_ADDR, subaddress, value);
}


void cameraDisplayVGA(){
	int rowCamera,rowVga;
	uint8_t * currentPixel;
	rowCamera=0;
	while(!((*CAM_CTRL)&VSYNC_MASK));
	while((*CAM_CTRL)&VSYNC_MASK);
	for(rowVga = NUMB_VGA_ROWS; rowVga >= 0 ; rowVga--){
		while(!((*CAM_CTRL)&HREF_MASK)); // Check for rising edge HREF
        if(rowCamera >= ROW_BUFF && rowCamera <= 132 && rowCamera%2 == 0){ //check for offsets, then do even numbers
            int colCamera, colVga;
            colCamera = 0;
            for(colVga = NUMB_VGA_COLS; colVga >= 0 ; colVga--){ // 80 columns in vga

            	while(!((*CAM_CTRL)&PCLK_MASK)); // Check for rising edge pclk

                if(colCamera >= COL_BUFF && colCamera <= 169 && colCamera%2 == 0){
                	*currentPixel=*PIXEL_PORT;
                     currentPixel++;   //function to write pixels to x and y coordinates
                } else {
	                colVga ++;              // decrement column
                }
                while(((*CAM_CTRL)&PCLK_MASK)); // Check for falling edge pclk
                colCamera++;       // increment column
            }
			currentPixel = (uint8_t *)(VGA + (rowVga << 7));
       } else {
            rowVga++;
       }
       while(((*CAM_CTRL)&HREF_MASK)); // Check for falling edge HREF
       rowCamera++;
 }

}


