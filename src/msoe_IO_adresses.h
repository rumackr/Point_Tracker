/*****************************************************************************
 * FILENAME:     msoe_IO_adresses.h                                          *
 * DATE:         11 Dec 2015                                                 *
 * AUTHOR:       rumackr@msoe.edu <Reid Rumack>                              *
 * PROVIDES: - defines register base addresses for the CE2800 DE0            *
 ****************************************************************************/
#include <inttypes.h>

#ifndef MSOE_IO_ADRESSES_H_
#define MSOE_IO_ADRESSES_H_

extern volatile uint32_t*  LEDs;
extern volatile uint32_t*  HEX_7;
extern volatile uint32_t*  BUZZER;
extern volatile uint32_t*  SLDR;
extern volatile uint32_t*  PUSH_BTN;
extern volatile uint32_t*  J4_EXPAN;
                           
extern volatile uint32_t*  TIMER_0;
extern volatile uint32_t*  TIMER_0_STAT;
extern volatile uint32_t*  TIMER_0_CTRL;
extern volatile uint32_t*  TIMER_0_LOW;
extern volatile uint32_t*  TIMER_0_HIGH;
                           
extern volatile uint32_t*  TIMER_1;
extern volatile uint32_t*  TIMER_1_STAT;
extern volatile uint32_t*  TIMER_1_CTRL;
extern volatile uint32_t*  TIMER_1_LOW;
extern volatile uint32_t*  TIMER_1_HIGH;
                           
extern volatile uint32_t*  TIMER_2;
extern volatile uint32_t*  TIMER_2_STAT;
extern volatile uint32_t*  TIMER_2_CTRL;
extern volatile uint32_t*  TIMER_2_LOW;
extern volatile uint32_t*  TIMER_2_HIGH;
                           
extern volatile uint32_t*  LCD_DATA;
extern volatile uint32_t*  LCD_DATA_DIR;
extern volatile uint32_t*  LCD_CTRL;
extern volatile uint32_t*  LCD_CTRL_DIR;
                           
extern volatile uint32_t*  PWM_OCRA1A;
extern volatile uint32_t*  PWM_OCRA1B ;
extern volatile uint32_t*  PWM_TCNT;
                           
extern volatile uint32_t*  BufferedOut;
                           
extern volatile uint32_t*  ADC_CH0_UPDATE;
extern volatile uint32_t*  ADC_CH1_AUTO_UPDATE;
extern volatile uint32_t*  ADC_CH2_SCLK_COUNTER;
extern volatile uint32_t*  ADC_CH3;
extern volatile uint32_t*  ADC_CH4;
extern volatile uint32_t*  ADC_CH5;
extern volatile uint32_t*  ADC_CH6;
extern volatile uint32_t*  ADC_CH7;

extern volatile uint8_t*   UART_BASE;
extern volatile uint8_t*   UART_RECV;
extern volatile uint8_t*   UART_SEND;
extern volatile uint8_t*   UART_STAT;
extern volatile uint8_t*   UART_CTRL;

#endif /* MSOE_IO_ADRESSES_H_ */
