/*****************************************************************************
 * FILENAME:     msoe_IO_adresses.c                                          *
 * DATE:         11 Dec 2015                                                 *
 * AUTHOR:       rumackr@msoe.edu <Reid Rumack>                              *
 * PROVIDES:     defines register base addresses for the CE2800 DE0          *
 * To Use:                                                                   *
 *    Incluede the header and source file in the project.                    *
 ****************************************************************************/
#include <inttypes.h>
volatile uint32_t* LEDs                   = (uint32_t*) 0x80802030;
volatile uint32_t* HEX_7                  = (uint32_t*) 0x90000020;
volatile uint32_t* BUZZER                 = (uint32_t*) 0x90800050;
volatile uint32_t* SLDR	                  = (uint32_t*) 0x90000040;
volatile uint32_t* PUSH_BTN               = (uint32_t*) 0x90000050;
volatile uint32_t* J4_EXPAN               = (uint32_t*) 0x90001000;
                                                          
volatile uint32_t* TIMER_0                = (uint32_t*) 0x90002000;
volatile uint32_t* TIMER_0_STAT           = (uint32_t*) 0x90002000;
volatile uint32_t* TIMER_0_CTRL           = (uint32_t*) 0x90002004;
volatile uint32_t* TIMER_0_LOW            = (uint32_t*) 0x90002008;
volatile uint32_t* TIMER_0_HIGH           = (uint32_t*) 0x9000200C;
                                                          
volatile uint32_t* TIMER_1 	              = (uint32_t*) 0x90002020;
volatile uint32_t* TIMER_1_STAT           = (uint32_t*) 0x90002020;
volatile uint32_t* TIMER_1_CTRL           = (uint32_t*) 0x90002024;
volatile uint32_t* TIMER_1_LOW            = (uint32_t*) 0x90002028;
volatile uint32_t* TIMER_1_HIGH           = (uint32_t*) 0x9000202C;
                                                          
volatile uint32_t* TIMER_2                = (uint32_t*) 0x90002040;
volatile uint32_t* TIMER_2_STAT           = (uint32_t*) 0x90002040;
volatile uint32_t* TIMER_2_CTRL           = (uint32_t*) 0x90002044;
volatile uint32_t* TIMER_2_LOW            = (uint32_t*) 0x90002048;
volatile uint32_t* TIMER_2_HIGH           = (uint32_t*) 0x9000204C;

volatile uint32_t* LCD_DATA               = (uint32_t*) 0x80800040;
volatile uint32_t* LCD_DATA_DIR           = (uint32_t*) 0x80800044;
volatile uint32_t* LCD_CTRL               = (uint32_t*) 0x80800030;
volatile uint32_t* LCD_CTRL_DIR           = (uint32_t*) 0x80800034;
                                                          
volatile uint16_t* PWM_OCRA1A             = (uint16_t*) 0x80800028;
volatile uint16_t* PWM_OCRA1B             = (uint16_t*) 0x80800030;
volatile uint16_t* PWM_TCNT               = (uint16_t*) 0x80800034;
                                                          
volatile uint8_t*  BufferedOut            = (uint8_t* ) 0x80800010;

volatile uint32_t* ADC_CH0_UPDATE         = (uint32_t*) 0x90002060;
volatile uint32_t* ADC_CH1_AUTO_UPDATE    = (uint32_t*) 0x90002064;
volatile uint32_t* ADC_CH2_SCLK_COUNTER   = (uint32_t*) 0x90002068;
volatile uint32_t* ADC_CH3                = (uint32_t*) 0x9000206C;
volatile uint32_t* ADC_CH4                = (uint32_t*) 0x90002070;
volatile uint32_t* ADC_CH5                = (uint32_t*) 0x90002074;
volatile uint32_t* ADC_CH6                = (uint32_t*) 0x90002078;
volatile uint32_t* ADC_CH7                = (uint32_t*) 0x9000207C;

volatile uint8_t*  UART_BASE              = (uint8_t* ) 0x80800020;
volatile uint8_t*  UART_RECV              = (uint8_t* ) 0x80800020;
volatile uint8_t*  UART_SEND              = (uint8_t* ) 0x80800020;
volatile uint8_t*  UART_STAT              = (uint8_t* ) 0x80800021;
volatile uint8_t*  UART_CTRL              = (uint8_t* ) 0x80800022;



