/*****************************************************************************
 * FILENAME:     msoeIoAdresses.h                                            *
 * DATE:         11 Dec 2015                                                 *
 * AUTHOR:       rumackr@msoe.edu <Reid Rumack>                              *
 * PROVIDES:     defines register base addresses for the CE2800 DE0          *
 * To Use:                                                                   *
 *    Incluede the header and source file in the project.                    *
 ****************************************************************************/
#include <inttypes.h>
volatile uint32_t* LEDs                   = (uint32_t*) 0x80802030;

volatile uint16_t* PWM_OCRA1A             = (uint16_t*) 0x80802028;
volatile uint16_t* PWM_OCRA1B             = (uint16_t*) 0x8080202A;
volatile uint16_t* PWM_TCNT               = (uint16_t*) 0x8080202E;

volatile uint8_t*  VGA                    = (uint8_t* ) 0x80800000;

volatile uint8_t* I2C_LO                 = (uint8_t*) 0x80802020;
volatile uint8_t* I2C_HI                 = (uint8_t*) 0x80802021;
volatile uint8_t* I2C_CTRL               = (uint8_t*) 0x80802022;
volatile uint8_t* I2C_TRANSMIT           = (uint8_t*) 0x80802023;
volatile uint8_t* I2C_RECEIVE            = (uint8_t*) 0x80802023;
volatile uint8_t* I2C_CMD                = (uint8_t*) 0x80802024;
volatile uint8_t* I2C_STAT               = (uint8_t*) 0x80802024;

volatile uint8_t* CAM_CTRL               = (uint8_t*) 0x80802000;
volatile uint8_t* PIXEL_PORT             = (uint8_t*) 0x80802010;


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
