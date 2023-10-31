/*
 * button.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#include "button.h"

int ButtonPin[3] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};
int keyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int keyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int keyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int button_flag[3] = {0, 0, 0};
int timeForKeyPress = 50;

int isButtonPressed(int button_index){
	if(button_flag[button_index] == 1){
		button_flag[button_index] = 0;
		return 1;
	}
	else return 0;
}

void subKeyProcess(int button_index){
	button_flag[button_index] = 1;
}

void getKeyInput(int button_index){
	keyReg0[button_index] = keyReg1[button_index];
	keyReg1[button_index] = keyReg2[button_index];
	keyReg2[button_index] = HAL_GPIO_ReadPin(GPIOB, ButtonPin[button_index]);
	if((keyReg0[button_index] == keyReg1[button_index]) && (keyReg1[button_index] == keyReg2[button_index])){
		if(keyReg2[button_index] != keyReg3[button_index]){
			keyReg3[button_index] = keyReg2[button_index];
			if(keyReg2[button_index] == PRESSED_STATE){
				subKeyProcess(button_index);
				timeForKeyPress = 50;
			}
		}
		else {
			timeForKeyPress--;
			if(timeForKeyPress <= 0){
				keyReg3[button_index] = NORMAL_STATE;
			}
		}
	}
}
