/*
 * CameraAPI.h
 *
 *  Created on: Mar 30, 2017
 *      Author: rumackr
 */

#ifndef CAMERAAPI_H_
#define CAMERAAPI_H_

#include <stdint.h>

uint8_t cameraDetect();
void cameraInit();
void cameraWrite(uint8_t value, uint8_t subaddress);
uint8_t cameraRead(uint8_t subaddress);
void cameraDisplayVGA();
#endif /* CAMERAAPI_H_ */
