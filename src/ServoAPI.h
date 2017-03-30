/*
 * ServoAPI.h
 *
 *  Created on: Mar 22, 2017
 *      Author: rumackr
 */

#ifndef SERVOAPI_H_
#define SERVOAPI_H_

void initServo(void); // Set up OCRA and OCRB to move the servos to their center positions

void pan(int col); // Used to provide an absolute x-axis servo position. The number provided
// is to be a number between 0 and 175. This corresponds to the horizontal
// resolution of the camera. These values should cause a full range of travel
// from far left to far right.
void tilt(int row); // Used to provide an absolute y-axis servo position. The number provided
		     // is to be a number between 0 and 144. This corresponds to the vertical
		     // resolution of the camera. These values should cause a full range of travel
		     // from top to bottom


#endif /* SERVOAPI_H_ */
