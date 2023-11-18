/*
 * fsm_manual.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#include "fsm_manual.h"


void mode2(){
	if(isButtonPressed(1) == 1){
		time_dur++;
		if(time_dur > 99) time_dur = 1;
	}
	if(isButtonPressed(2) == 1){
		RED_timer = time_dur;
	}
	if(timer_flag[4] == 1){
		switch (counter){
		case 0:
			display7SEG_en(0);
			display7SEG(0);
			break;
		case 1:
			display7SEG_en(1);
			display7SEG(2);
			break;
		case 2:
			display7SEG_en(2);
			display7SEG(time_dur/10);//time_dur = time duration
			break;
		case 3:
			display7SEG_en(3);
			display7SEG(time_dur%10);
			break;
		default:
			break;
		}
		counter++;
		if(counter > 3) counter = 0;
		setTimer(4,10);
	}
	if(timer_flag[5] == 1){
		HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
		HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
		setTimer(5,50);
	}
}

void mode3(){
	if(isButtonPressed(1) == 1){
		time_dur++;
		if(time_dur > 99) time_dur = 1;
	}
	if(isButtonPressed(2) == 1){
		YELLOW_timer = time_dur;
	}
	if(timer_flag[6] == 1){
		switch (counter){
		case 0:
			display7SEG_en(0);
			display7SEG(0);
			break;
		case 1:
			display7SEG_en(1);
			display7SEG(3);
			break;
		case 2:
			display7SEG_en(2);
			display7SEG(time_dur/10);
			break;
		case 3:
			display7SEG_en(3);
			display7SEG(time_dur%10);
			break;
		default:
			break;
		}
		counter++;
		if(counter > 3) counter = 0;
		setTimer(6,10);
	}
	if(timer_flag[7] == 1){
		HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
		HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
		setTimer(7,50);
	}
}

void mode4(){
	if(isButtonPressed(1) == 1){
		time_dur++;
		if(time_dur > 99) time_dur = 1;
	}
	if(isButtonPressed(2) == 1){
		GREEN_timer = time_dur;
	}
	if(timer_flag[8] == 1){
		switch (counter){
		case 0:
			display7SEG_en(0);
			display7SEG(0);
			break;
		case 1:
			display7SEG_en(1);
			display7SEG(4);
			break;
		case 2:
			display7SEG_en(2);
			display7SEG(time_dur/10);
			break;
		case 3:
			display7SEG_en(3);
			display7SEG(time_dur%10);
			break;
		default:
			break;
		}
		counter++;
		if(counter > 3) counter = 0;
		setTimer(8,10);
	}
	if(timer_flag[9] == 1){
		HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
		HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
		setTimer(9,50);
	}
}

void check_time(){
	if(RED_timer > (GREEN_timer + YELLOW_timer)){
		int t = RED_timer - (GREEN_timer + YELLOW_timer);
		if (RED_timer > 5){
			if(YELLOW_timer < 3) {
				if(t >= (3 - YELLOW_timer)){
					t = t - (3 - YELLOW_timer);
					YELLOW_timer = 3;
				}
				else {
					YELLOW_timer += t;
					t = 0;
				}
			}
		}
		GREEN_timer += t;
	}
	if(RED_timer < (GREEN_timer + YELLOW_timer)){
		int t = (GREEN_timer + YELLOW_timer) - RED_timer;
		RED_timer += t;
	}
}

void fsm_manual_run(){
	switch (modeStatus){
	case MODE2:
		mode2();
		if(timer_flag[0] == 1){
			modeStatus = MODE1;
			counter = 0;
			autoStatus1 = LED_INIT;
			autoStatus2 = LED_INIT;
			setTimer(0, 1000);
			setTimer(1,10);
			setTimer(2,50);
			clear();
		}
		if(isButtonPressed(0) == 1){
			modeStatus = MODE3;
			time_dur = YELLOW_timer;
			setTimer(0, 1000);
			setTimer(6,10);
			setTimer(7,50);
			counter = 0;
			clear();
		}
		break;
	case MODE3:
		mode3();
		if(timer_flag[0] == 1){
			modeStatus = MODE1;
			counter = 0;
			autoStatus1 = LED_INIT;
			autoStatus2 = LED_INIT;
			setTimer(0, 1000);
			setTimer(1,10);
			setTimer(2,50);
			clear();
		}
		if(isButtonPressed(0) == 1){
			modeStatus = MODE4;
			time_dur = GREEN_timer;
			setTimer(0, 1000);
			setTimer(8,10);
			setTimer(9,50);
			counter = 0;
			clear();
		}
		break;
	case MODE4:
		mode4();
		if(isButtonPressed(0) == 1 || timer_flag[0] == 1){
			check_time(); //dieu chinh lai thoi gian
			modeStatus = MODE1;
			counter = 0;
			autoStatus1 = LED_INIT;
			autoStatus2 = LED_INIT;
			setTimer(0, 1000);
			setTimer(1,10);
			setTimer(2,50);
			clear();
		}
		break;
	default:
		break;
	}
}
