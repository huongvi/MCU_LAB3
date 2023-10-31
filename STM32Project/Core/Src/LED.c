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
