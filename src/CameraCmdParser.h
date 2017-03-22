/*******************************************************************************
*@AUTHOR:   Reid Rumack                                                        *
*@FILE:     CameraCmdParser.h                                                  *
*Currnent Milestone : Week 2                                                   *
*@DATE:     March 15, 2017                                                     *
*@PROVIDES: fuctions to both read and write to memory using the system console.*
*******************************************************************************/

#ifndef CAMERACMDPARSER_H_
#define CAMERACMDPARSER_H_
#include <stdint.h>

typedef struct readcmd ReadCmd;
typedef struct writecmd WriteCmd;

void memWriter(uint32_t* address, uint8_t data);
uint8_t* memReader(uint32_t* address, uint32_t count);
uint8_t memRead(uint32_t* address);
void memPrinter(uint32_t* staringAddr, uint32_t numToRead, uint8_t* rdData);uint8_t cameraCmdSystem(void);
ReadCmd rdPaser(char* command);
WriteCmd wrPaser(char* command);


#endif /* CAMERACMDPARSER_H_ */
