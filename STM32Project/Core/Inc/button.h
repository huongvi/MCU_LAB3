/*
 * button.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 1
#define PRESSED_STATE 0

void getKeyInput();
int isButtonPressed(int button_index);

#endif /* INC_BUTTON_H_ */
