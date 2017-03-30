/***********************************************************************
 * FILE:      niosii_pwm.h                                             *
 * CLASS:     CE-2811                                                  *
 * DATE:      2016=2-15                                                *
 * AUTHOR:    Reid Rumack                                              *
 * CPU:       NIOS II                                                  *
 * SYSTEM:    DE-0                                                     *
 *                                                                     *
 *  This file is an API for the MSOE expantion  board PWM              *
 **********************************************************************/

#ifndef NIOSII_PWM_H_
#define NIOSII_PWM_H_
#include <inttypes.h>

void niosii_pwm_1a(float percent_duty);

void niosii_pwm_1b(float percent_duty);

#endif /* NIOSII_PWM_H_ */
