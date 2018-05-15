/*******************************************************************************
 *@AUTHOR:   Reid Rumack                                                        *
 *@FILE:     PointTracker.c                                                     *
 *@DATE:     March 15, 2017                                                     *
 *@PROVIDES: Runable file for the system. contains Main                         *
 *******************************************************************************/

/****   INCLUDES  ****/
#include "PointTracker.h"
#include "niosii_uart.h"
#include "CameraCmdParser.h"
#include "niosii_pwm.h"
#include "ServoAPI.h"
#include "CameraAPI.h"
#include "niosii_I2C.h"
#include "msoeIoAdresses.h"
#include "niosii_vga.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define maxBLK 0x50
#define minWhite 0xB0


/**** IMPLIMENTED FUNCTIONS  ****/
typedef struct Point {
	int X_cord;
	int Y_cord;
};
/****************************************************************************
 * Starts ands sets up the system. Contains the main program loop
 ***************************************************************************/
int main(void) {
	uint16_t panServoVal, tiltServoVal;
	panServoVal = 1500;
	tiltServoVal = 1500;
	struct Point objCenter;
	objCenter.X_cord = 39;
	objCenter.Y_cord = 29;

	initServo();
	I2C_init();
	cameraInit();
	cameraWrite(0xF, 0x11);
	cameraCmdSystem();

	while (1) {
		struct Point difference;
		cameraDisplayVGA();
		objCenter = findObjCenter();
		difference = calcDiff(objCenter);
		panServoVal = pan(difference.X_cord, panServoVal);
		tiltServoVal = tilt(difference.Y_cord, tiltServoVal);
	}
	return 0;
}

/**
 *findObjCenter
 * Finds the edges of of the black object calculates the center point
 * of the object.
 * @return struct Point: coordinates of the calculated center pixel
 */
struct Point findObjCenter() {
	struct Point dotCenter;
	uint8_t row;

	float leftColSum, rightColSum = 0.0;
	float leftColNum, rightColNum = 0.0;
	float topRowSum, botRowSum = 0.0;
	float topRowNum, botRowNum = 0.0;

	for (row = 58; row > 1; --row) {
		uint8_t col;
		for (col = 78; col > 1; --col) {
			uint8_t pixL, pixR;
			// gets the pixel color next to the center pixel
			pixL = niosii_vga_read_pixel(col - 1, row);
			pixR = niosii_vga_read_pixel(col + 1, row);
			if (pixL >= minWhite && pixR <= maxBLK) {
				leftColSum += col;
				leftColNum++;
				uint8_t pixTop, pixBott;

				pixTop = niosii_vga_read_pixel(col + 1, row - 1);
				pixBott = niosii_vga_read_pixel(col + 1, row + 1);

				if (pixTop >= minWhite && pixBott <= maxBLK) {
					//if top row
					topRowSum += row;
					topRowNum++;
				} else if (pixTop <= maxBLK && pixBott >= minWhite) {
					//bottom row
					botRowSum += row;
					botRowNum++;
				}
			} else if (pixL <= maxBLK && pixR >= minWhite) {
				rightColSum += col;
				rightColNum++;
				uint8_t pixTop, pixBott;

				pixTop = niosii_vga_read_pixel(col - 1, row - 1);
				pixBott = niosii_vga_read_pixel(col - 1, row + 1);
				if (pixTop >= minWhite && pixBott <= maxBLK) {
					topRowSum += row;
					topRowNum++;
				} else if (pixTop <= maxBLK && pixBott >= minWhite) {
					botRowSum += row;
					botRowNum++;
				}
			}
		}
	}
	float leftColAvr, rightColAvr;
	leftColAvr = leftColSum / leftColNum;
	rightColAvr = rightColSum / rightColNum;
	int XCenterPoint = (int) (leftColAvr + rightColAvr) / (2.0);
	(XCenterPoint >= 1 && XCenterPoint <= 78) ?
	    ((dotCenter.X_cord) = (80 - XCenterPoint)) : ((dotCenter.X_cord) = 39);
	float topRowAvr, botRowAvr = 0.0;
	topRowAvr = topRowSum / topRowNum;
	botRowAvr = botRowSum / botRowNum;

	int YCenterPoint = (int) (topRowAvr + botRowAvr) / 2.0;
	(YCenterPoint >= 1 && YCenterPoint <= 58) ? ((dotCenter.Y_cord) =
														(YCenterPoint)) :
												((dotCenter.Y_cord) = 29);

	return dotCenter;
}
/**
 * calculates the difference between the center pixel of the camera and the
 * calculated center of the object
 * @param struct Point calculated center point.
 * @returns struct Point
 */
struct Point calcDiff(struct Point objCenter) {
	struct Point diffrence;
	diffrence.X_cord = 39 - objCenter.X_cord;
	diffrence.Y_cord = 29 - objCenter.Y_cord;
	return diffrence;
}
