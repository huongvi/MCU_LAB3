/*
 * fsm_automatic.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#include "fsm_automatic.h"


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
