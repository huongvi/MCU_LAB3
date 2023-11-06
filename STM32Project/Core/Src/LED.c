/*
 * LED.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#include "LED.h"

void displayLED1(int ledStatus1){
	switch (ledStatus1){
	case LED_INIT:
		  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 0);
		  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 0);
		  break;
	case RED:
		  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 0);
		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
		  break;
	case YELLOW:
		  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 0);
		  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 1);
		  break;
	case GREEN:
		  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, 0);
		  break;
	default:
		break;
	}
}

void displayLED2(int ledStatus2){
	switch (ledStatus2){
	case LED_INIT:
		  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
		  HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 0);
		  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 0);
		  break;
	case RED:
		  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 0);
		  HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1);
		  break;
	case YELLOW:
		  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 0);
		  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 1);
		  break;
	case GREEN:
		  HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, 1);
		  HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, 1);
		  HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, 0);
		  break;
	default:
		break;
	}
}

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

