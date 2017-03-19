/***********************************************************************
 * @file      niosii_uart.h                                            *
 * @class     CE-2811                                                  *
 * @date      2015-14-28                                               *
 * @version   2.0                                                      *
 * @author    rumackr@msoe.edu <Reid Rumack>                           *
 * @cpu       NIOS II                                                  *
 * @system    DE-0                                                     *
 *                                                                     *
 * This file conntains multiple subroutiens                            *
 * that are called by multiple.                                        *
 *                                                                     *
 ***********************************************************************/
#include <inttypes.h>

#ifndef NIOSII_UART_H_
#define NIOSII_UART_H_

  #define UART_STAT_FE           0x01
  #define UART_STAT_OE           0x02
  #define UART_STAT_RDRF         0x40
  #define UART_STAT_TDRE         0x80
  #define UART_CNTR_RIE          0x40
  #define UART_CNTR_TIE          0x80
  #define UART_CNTR_BAUD_MASK    0x07
  #define UART_CNTR_BAUD_38_4K   0x00
  #define UART_CNTR_BAUD_19_2K   0x01
  #define UART_CNTR_BAUD_9600    0x02
  #define UART_CNTR_BAUD_4800    0x03
  #define UART_CNTR_BAUD_2400    0x04
  #define UART_CNTR_BAUD_1200    0x05
  #define UART_CNTR_BAUD_600     0x06
  #define UART_CNTR_BAUD_300     0x07

  void uart_init(void);

  void uart_trasmit_char(const char c);

  void uart_trasmit_stringln(const char *str);

  char uart_get_recived_char();
  uint8_t uart_check_for_recived();


#endif /* NIOSII_UART_H_ */
