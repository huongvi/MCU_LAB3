/*
 * software_timer.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];

void setTimer(int timer_index, int duration);
void timerRun(int timer_index);

#endif /* INC_SOFTWARE_TIMER_H_ */
