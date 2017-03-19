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
#include "msoe_IO_adresses.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/**** PROTO-TYPES ****/
int main(void);
/**** IMPLIMENTED FUNCTIONS  ****/


int main(void) {
	while(1){
	    uart_init();
		*LEDs = 0xAF;
	}
	return 0;
}



