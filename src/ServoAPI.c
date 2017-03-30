/*
 * ServoAPI.c
 *
 *  Created on: Mar 22, 2017
 *      Author: rumackr
 */
 #include "niosii_pwm.h"
#include "msoeIoAdresses.h"

#define OFF_SET 1000
const float OCR_PER_DEGREE = 5.5556;
const int16_t CENTER_POS = 1500;


void initServo(void); // Set up OCRA and OCRB to move the servos to their center positions

void pan(int col); // Used to provide an absolute x-axis servo position. The number provided
// is to be a zznumber between 0 and 175. This corresponds to the horizontal
// resolution of the camera. These values should cause a full range of travel
// from far left to far right.
void tilt(int row); // Used to provide an absolute y-axis servo position. The number provided
		     // is to be a number between 0 and 144. This corresponds to the vertical
		     // resolution of the camera. These values should cause a full range of travel
		     // from top to bottom

void initServo(void){
	*PWM_OCRA1A = CENTER_POS;
	*PWM_OCRA1B = CENTER_POS;
} // Set up OCRA and OCRB to move the servos to their center positions

void pan(int col){
	if(col>=0&&col<=175){
		uint16_t pwm_value =OCR_PER_DEGREE*col+OFF_SET;
		*PWM_OCRA1A = pwm_value;
	}
	// Used to provide an absolute x-axis servo position. The number provided
}
// is to be a number between 0 and 175. This corresponds to the horizontal
// resolution of the camera. These values should cause a full range of travel
// from far left to far right.
void tilt(int row){
	if(row>=0&&row<=144){
		uint16_t pwm_value =OCR_PER_DEGREE*row+OFF_SET;
		*PWM_OCRA1B = pwm_value;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	}// Used to provide an absolute y-axis servo position. The number provided
}
		     // is to be a number between 0 and 144. This corresponds to the vertical
		     // resolution of the camera. These values should cause a full range of travel
		     // from top to bottom
