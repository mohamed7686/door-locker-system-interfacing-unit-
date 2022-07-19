/*
 * interfacing.c
 *
 *  Created on: Oct 6, 2019
 *      Author: The Master
 */


#include "passwords.h"


int main (void){
uint8 t;


LCD_init();
UART_init();
SREG |=(1<<7);

initial_password();

while(1){

do{
	LCD_displayString("1: to open door");
	LCD_goToRowColumn(1,0);
	LCD_displayString("2:to change pass");
	t = KeyPad_getPressedKey();
	UART_sendByte(t);
}
while(t !=1 && t!=2);
LCD_clearScreen();
if(t==1){
	if(entering_password()==2){
		LCD_displayString("failed");
		UART_recieveByte();
		LCD_clearScreen();
	}
	else{LCD_displayString("door opening");
	     UART_recieveByte();
	     LCD_clearScreen();
       	 LCD_displayString("door closing");
		 UART_recieveByte();

	LCD_clearScreen();}
}
else {
	if(entering_password()==2){
		LCD_displayString("failed");
				UART_recieveByte();
				LCD_clearScreen();
	continue;}
	else{
		initial_password();
	}

}
}

}

