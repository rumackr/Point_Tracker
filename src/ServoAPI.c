/*
 * ServoAPI.c
 *
 *  Created on: Mar 22, 2017
 *      Author: rumackr
 */
#include "niosii_pwm.h"
#include "msoeIoAdresses.h"

#define OFF_SET 1000
#define pwCenterValue 1500
const int OCR_INC_PAN = 6;
const int OCR_INCA_TILT = 8;
//
//struct cameraPosition{
//	uint16_t panPwmVal = 1500
//};
const int16_t panServoPos = 1500;



void initServo(void); // Set up OCRA and OCRB to move the servos to their center positions

uint16_t pan(int col,uint16_t currentPwmValue); // Used to provide an absolute x-axis servo position. The number provided
// is to be a zznumber between 0 and 175. This corresponds to the horizontal
// resolution of the camera. These values should cause a full range of travel
// from far left to far right.
uint16_t tilt(int row,uint16_t currentPwmValue); // Used to provide an absolute y-axis servo position. The number provided
		     // is to be a number between 0 and 144. This corresponds to the vertical
		     // resolution of the camera. These values should cause a full range of travel
		     // from top to bottom

void initServo(void){
	*PWM_OCRA1A = 1500;
	*PWM_OCRA1B = 1500;
} // Set up OCRA and OCRB6 to move the servos to their center positions

uint16_t pan(int col,uint16_t currentPwmValue){

	uint16_t newPwmValue =(uint16_t)currentPwmValue;
	if(col>-39&&col<39){
		uint16_t pwm_value =(uint16_t)(currentPwmValue-(OCR_INC_PAN*col));
		if(pwm_value>=1000&& pwm_value<=2000){
			*PWM_OCRA1A = pwm_value;
			newPwmValue = pwm_value;

		}
	}
	return newPwmValue;
	// Used to provide an absolute x-axis servo position. The number provided
}
// is to be a number between 0 and 175. This corresponds to the horizontal
// resolution of the camera. These values should cause a full range of travel
// from far left to far right.
uint16_t tilt(int row,uint16_t currentPwmValue){
	uint16_t newPwmValue = (uint16_t)currentPwmValue;
	if(row>-29&&row<29){
		uint16_t pwm_value =(uint16_t)(currentPwmValue-(OCR_INCA_TILT*row));
		if(pwm_value>=1000&& pwm_value<=2000){
			*PWM_OCRA1B = pwm_value;
			newPwmValue = pwm_value;
		}
	}
	return newPwmValue;// Used to provide an absolute y-axis servo position. The number provided
}
		     // is to be a number between 0 and 144. This corresponds to the vertical
		     // resolution of the camera. These values should cause a full range of travel
		     // from top to bottom
