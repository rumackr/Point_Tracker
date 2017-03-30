/***********************************************************************
 * FILE:      niosii_pwm.c                                             *
 * CLASS:     CE-2811                                                  *
 * DATE:      2016=2-15                                                *
 * AUTHOR:    Reid Rumack                                              *
 * CPU:       NIOS II                                                  *
 * SYSTEM:    DE-0                                                     *
 *                                                                     *
 *  This file is an API for the MSOE expantion  board PWM              *
 **********************************************************************/
#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>
#include "niosii_pwm.h"
#include "msoeIoAdresses.h"

void niosii_pwm_1a(float percent_duty);

void niosii_pwm_1b(float percent_duty);


/**
 * niosii_pwm_1a
 *
 * controles the duty cycle of pwm 1A.
 *
 * @param percent_duty: percent duty
 */
void niosii_pwm_1a(float percent_duty){

	if(percent_duty < 0){
    	percent_duty*= -1;
	}
    uint16_t pwm_value = 0;

	if(percent_duty != 0.0){
		pwm_value = 20000 * percent_duty;
	}
	else{
		pwm_value = 0;
	}

	*PWM_OCRA1A = pwm_value;
}

/**
 * niosii_pwm_1b
 *
 * controles the duty cycle of pwm 1b.
 *
 * @param percent_duty: percent duty
 */
void niosii_pwm_1b(float percent_duty){
    if(percent_duty < 0)
    	percent_duty*= -1;

    uint16_t pwm_value = 0;

	if(percent_duty != 0.0){
		pwm_value = 20000 * percent_duty;
	}
	else{
		pwm_value = 0;
	}
	*PWM_OCRA1B = pwm_value;

}


