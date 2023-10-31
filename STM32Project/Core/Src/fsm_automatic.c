/*
 * fsm_automatic.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#include "fsm_automatic.h"

void autoStatusWay1(){
	switch (autoStatus1){
	case LED_INIT:
		autoStatus1 = RED;
		count1 = RED_timer;
		setTimer(3,100);
		break;
	case RED:
		displayLED1(RED);
		if(timer_flag[3] == 1){
			count1 = count1 - 1;
			if(count1 <= 0){
				autoStatus1 = GREEN;
				count1 = GREEN_timer;
			}
			setTimer(3,100);
		}
		break;
	case YELLOW:
		displayLED1(YELLOW);
		if(timer_flag[3] == 1){
			count1 = count1 - 1;
			if(count1 <= 0){
				autoStatus1 = RED;
				count1 = RED_timer;
			}
			setTimer(3,100);
		}
		break;
	case GREEN:
		displayLED1(GREEN);
		if(timer_flag[3] == 1){
			count1 = count1 - 1;
			if(count1 <= 0){
				autoStatus1 = YELLOW;
				count1 = YELLOW_timer;
			}
			setTimer(3,100);
		}
		break;
	default:
		break;
	}
}

void autoStatusWay2(){
	switch (autoStatus2){
	case LED_INIT:
		autoStatus2 = GREEN;
		count2 = GREEN_timer;
		setTimer(2,100);
		break;
	case RED:
		displayLED2(RED);
		if(timer_flag[2] == 1){
			count2 = count2 - 1;
			if(count2 <= 0){
				autoStatus2 = GREEN;
				count2 = GREEN_timer;
			}
			setTimer(2,100);
		}
		break;
	case YELLOW:
		displayLED2(YELLOW);
		if(timer_flag[2] == 1){
			count2 = count2 - 1;
			if(count2 <= 0){
				autoStatus2 = RED;
				count2 = RED_timer;
			}
			setTimer(2,100);
		}
		break;
	case GREEN:
		displayLED2(GREEN);
		if(timer_flag[2] == 1){
			count2 = count2 - 1;
			if(count2 <= 0){
				autoStatus2 = YELLOW;
				count2 = YELLOW_timer;
			}
			setTimer(2,100);
		}
		break;
	default:
		break;
	}
}

void fsm_auto_run(){
		if(modeStatus == MODE1){
			autoStatusWay1();
			autoStatusWay2();
			if(timer_flag[1] == 1){
				switch (counter){
				case 0:
					display7SEG_en(0);
					display7SEG(count1/10);
					break;
				case 1:
					display7SEG_en(1);
					display7SEG(count1%10);
					break;
				case 2:
					display7SEG_en(2);
					display7SEG(count2/10);
					break;
				case 3:
					display7SEG_en(3);
					display7SEG(count2%10);
					break;
				default:
					break;
				}
				counter++;
				if(counter > 3) counter = 0;
				setTimer(1,10);
			}
		}
		if(isButtonPressed(0) == 1){
			modeStatus = MODE2;
			time_dur = RED_timer;
			setTimer(0, 1000);
			setTimer(4,10);
			setTimer(5,50);
			counter = 0;
			clear();
		}
	}
