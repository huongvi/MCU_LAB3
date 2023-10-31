/*
 * global.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#include "global.h"

int modeStatus = 11;
int autoStatus1 = 7;
int autoStatus2 = 7;

int time_dur = 0;
int INIT_timer = 1;
int RED_timer = 5;
int YELLOW_timer = 2;
int GREEN_timer = 3;

int counter = 0;
int count1 = 1;
int count2 = 1;
int flag = 0;

void clear(){
	HAL_GPIO_WritePin(GPIOA, a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin|LED_YELLOW1_Pin|LED_GREEN1_Pin, 1);
	HAL_GPIO_WritePin(GPIOB, LED_RED2_Pin|LED_YELLOW2_Pin|LED_GREEN2_Pin, 1);
}
