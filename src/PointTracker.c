/*******************************************************************************
*@AUTHOR:   Reid Rumack                                                        *
*@FILE:     PointTracker.c                                              *
*Currnent Milestone : Week 2                                                   *
*@DATE:     March 15, 2017                                                     *
*@PROVIDES: Runable file for the system. contains Main                         *
*******************************************************************************/

/****   INCLUDES  ****/
#include "PointTracker.h"
#include "niosii_uart.h"
#include "CameraCmdParser.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/**** PROTO-TYPES ****/
int main(void);
/**** IMPLIMENTED FUNCTIONS  ****/


int main(void) {
	while(1){
        cameraCmdSystem();
	}
	return 0;
}
