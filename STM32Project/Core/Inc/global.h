/*
 * global.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "LED7seg.h"
#include "LED.h"

#define INIT	0
#define AUTO_RED	1
#define AUTO_YELLOW 2
#define AUTO_GREEN	3

#define MODE1 	11
#define MODE2	12
#define MODE3	13
#define MODE4 	14

#define RED	4
#define YELLOW	5
#define GREEN	6
#define LED_INIT	7

extern int modeStatus;
extern int autoStatus1;
extern int autoStatus2;

extern int ledStatus1;
extern int ledStatus2;

extern int time_dur;
extern int INIT_timer;
extern int RED_timer;
extern int YELLOW_timer;
extern int GREEN_timer;

extern int counter;
extern int count1;
extern int count2;
extern int flag;

void clear();

#endif /* INC_GLOBAL_H_ */
