/*******************************************************************************
*@AUTHOR:   Reid Rumack                                                        *
*@FILE:     CameraCmdParser.c                                                  *
*Currnent Milestone : Week 2                                                   *
*@DATE:     March 15, 2017                                                     *
*@PROVIDES: fuctions to both read and write to memory using the system console.*
*******************************************************************************/

/****   INCLUDES  ****/
#include "CameraCmdParser.h"
#include "ServoAPI.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_COUNT 16
#define MIN_COUNT 1
#define READ_CMD "RD"
#define WRITE_CMD "WR"
#define PAN_CMD "P"
#define TILT_CMD "T"

#define IS_A_MATCH 0
#define FALSE 0
#define VALID 1
#define INVALID 0






struct readcmd{
    uint32_t *addr;
    uint32_t  count;
};

struct writecmd{
    uint32_t *addr;
    uint8_t  data;
};
typedef struct readcmd ReadCmd;
typedef struct writecmd WriteCmd;

/**** PROTO-TYPES ****/
void memWriter(uint32_t* address, uint8_t data);
uint8_t* memReader(uint32_t* address, uint32_t count);
uint8_t memRead(uint32_t* address);
void memPrinter(uint32_t* staringAddr, uint32_t numToRead, uint8_t* rdData);
uint8_t cameraCmdSystem(void);
ReadCmd rdPaser(char* command);
WriteCmd wrPaser(char* command);

/**** IMPLIMENTED FUNCTIONS  ****/

void memWriter(uint32_t* address, uint8_t data){
        *address = data;
}

uint8_t* memReader(uint32_t* address, uint32_t count){
    uint8_t* readData;
    uint8_t i;
        for(i= 0; i<count;i++){
            *(readData+i) = *(address+i);
        }
    return readData;
}

uint8_t memRead(uint32_t* address){
    return (uint8_t)*address;
}

void memPrinter(uint32_t* staringAddr, uint32_t numToRead, uint8_t* rdData){;
	uint32_t numbPrinted, toPrint,numbInLine;
	numbPrinted = 0;
	while((numToRead-numbPrinted)>0){
		toPrint=numToRead-numbPrinted;
	    uint32_t i;

		if(toPrint>MAX_COUNT){
			numbInLine = MAX_COUNT;
		}else{
			numbInLine = toPrint;
		}

		printf("\n          ");

		for(i = 0; i < numbInLine; i++){
			printf(" +%-2u", i);
		}

		printf("\n0x%08X:",staringAddr+numbPrinted);

		for(i = 0; i < numbInLine; i++){
			printf(" %02X ",(rdData+numbPrinted+i));
		}
		numbPrinted += i;
		printf("\n");
	}
}


uint8_t cameraCmdSystem(){
    uint8_t isValid = INVALID;
    char cmd[32];
    char* op;
    char* cmdPrompt = "\n Please enter a command.\n RD address\n RD address count(max of 16)\n WR address data\n";
    printf(cmdPrompt);
    if(fgets(cmd, sizeof(cmd), stdin) != NULL){
        char* newLine = strchr(cmd,'\n');
        if(newLine != NULL){
            *newLine = '\n';
        }
    }
    sscanf(cmd,"%s",op);
    if (strcmp(op,READ_CMD) == IS_A_MATCH) {
    	ReadCmd rdCmd = rdPaser(cmd);
        uint8_t* memData = memReader(rdCmd.addr,rdCmd.count);
        memPrinter(rdCmd.addr,rdCmd.count, memData);

    } else if (strcmp(op,WRITE_CMD) == IS_A_MATCH) {
    	WriteCmd wrCmd = wrPaser(cmd);
        memWriter(wrCmd.addr,wrCmd.data);

    } else if(strcmp(op,PAN_CMD) == IS_A_MATCH) {
    	int col=0;
    	sscanf(cmd,"%*s %d", &col);
    	pan(col);
    }else if(strcmp(op,TILT_CMD) == IS_A_MATCH) {
    	int row=0;
    	sscanf(cmd,"%*s %d", &row);
    	tilt(row);
    }
    return isValid;
}

ReadCmd rdPaser(char* command){
    ReadCmd toReturn;
    uint32_t count = 0;
    sscanf(command,"%*s %x %u", &toReturn.addr, &count);
    (count == 0)?(toReturn.count = MIN_COUNT):(toReturn.count = count);
    return toReturn;
}

WriteCmd wrPaser(char* command){
    WriteCmd toReturn;
    sscanf(command,"%*s %x %x", &toReturn.addr, &toReturn.data);
    return toReturn;
}




