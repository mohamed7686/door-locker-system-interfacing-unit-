/*
 * passwords.h
 *
 *  Created on: Oct 10, 2019
 *      Author: The Master
 */

#ifndef PASSWORDS_H_
#define PASSWORDS_H_

#include "lcd.h"
#include "keypad.h"
#include "usart.h"





uint8 entering_password(void);
void initial_password(void);
//static void catch_password(uint8 *arr);

#endif /* PASSWORDS_H_ */
