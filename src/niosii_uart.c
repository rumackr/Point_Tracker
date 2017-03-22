/***********************************************************************
 * @file      niosii_uart.c                                            *
 * @class     CE-2811                                                  *
 * @date      March
 * @author    rumackr@msoe.edu <Reid Rumack>                           *
 * @cpu       NIOS II Fast                                             *
 * @system    DE-0                                                     *
 *                                                                     *
 ***********************************************************************/
#include <stdio.h>
#include <inttypes.h>
#include "msoeIoAdresses.h"
#include "niosii_uart.h"


/**********************************************************
 * function name: uart_init
 * operation:     initializes the UART
 * inputs:        none
 * returns:       none
 * alters:        UART
 * implemented:   2-22-2016
 *********************************************************/
void uart_init(void);
/**********************************************************
 * function name: uart_trasmit_char
 * operation:     sends a char over the UART
 * inputs:        Char; c
 * returns:       none
 * alters:        UART
 * implemented:   2-22-2016
 *********************************************************/
void uart_trasmit_char(const char c);
/**********************************************************
 * function name: uart_trasmit_stringln
 * operation:     trasmits a String, and then goes
 *		          to another line
 * inputs:        a string of Chars
 * returns:       none
 * alters:        UART
 * implemented:   2-22-2016
 *********************************************************/
void uart_trasmit_stringln(const char *str);
char uart_get_recived_char();
uint8_t uart_check_for_recived();


void uart_init(void){
  *UART_CTRL = UART_CNTR_BAUD_9600;
}


 void uart_trasmit_char(const char c){
	//  disable_interupts();
	  *UART_SEND = c;
	  while(((*UART_STAT) & 0x80)==0)
		  ;
	//  enable_interupts();
  }

  void uart_trasmit_stringln(const char *str){
		while (*str != '\0') {

			uart_trasmit_char(*str);
			str++;
		}
		//carriage return; \cr = 0x0D
		uart_trasmit_char(0x0D);
		//new line; \LF = 0x0A
		uart_trasmit_char(0x0A);
 }

 uint8_t uart_check_for_recived(){
	 uint8_t recived = 0;
	 if((*UART_STAT & UART_STAT_RDRF)!=0){
		 recived = 1;
	 }
	return recived;
 }
 char uart_get_recived_char(){
	char recivedChar = *UART_RECV;
	return recivedChar;
 }
