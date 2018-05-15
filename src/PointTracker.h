/*******************************************************************************
 *@AUTHOR:   Reid Rumack                                                        *
 *@FILE:     Dot_Tracking_Camera.h                                              *
 *Currnent Milestone : Week 2                                                   *
 *@DATE:     March 15, 2017                                                     *
 *@PROVIDES: Header file for the main/Runable file                              *
 *******************************************************************************/

#ifndef POINTTRACKER_H_
#define POINTTRACKER_H_
#include <stdint.h>

int main(void);
struct Point findXmidPoint();
struct Point calcDiff(struct Point objCenter);



#endif /* POINTTRACKER_H_ */
