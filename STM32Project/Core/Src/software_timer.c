/*
 * software_timer.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */


#include "software_timer.h"

int timer_counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int timer_flag[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setTimer(int timer_index, int duration){
	timer_counter[timer_index] = duration;
	timer_flag[timer_index] = 0;
}

void timerRun(int timer_index){
	if(timer_counter[timer_index] > 0){
		timer_counter[timer_index]--;
		if(timer_counter[timer_index] <= 0){
			timer_flag[timer_index] = 1;
		}
	}
}
