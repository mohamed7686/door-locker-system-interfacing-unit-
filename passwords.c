/*
 * passwords.c
 *
 *  Created on: Oct 10, 2019
 *      Author: The Master
 */

#include "passwords.h"



/////////////////////////////////////////function to catch pass in an array/////////////////////////////////////

static void catch_password(void){
	uint8 t;
	LCD_goToRowColumn(1,0);
	do{
	t=KeyPad_getPressedKey();
	UART_sendByte(t);
	LCD_displayCharacter('*');
	_delay_ms(300);
	}
	while(t !=42);

}



////////////////////// function to change pass ///////////////////////////////////////

void initial_password(void){
	LCD_displayString("enter new pass");
		catch_password();
		LCD_clearScreen();
		LCD_displayString("enter pass again");
		catch_password();
		LCD_clearScreen();
	while(!(UART_recieveByte())){
		LCD_displayString("wrong pass");
		_delay_ms(300);
					LCD_clearScreen();
		LCD_displayString("enter new pass");
	catch_password();
	LCD_clearScreen();
	LCD_displayString("enter pass again");
	catch_password();
	LCD_clearScreen();
	}
	LCD_displayString("done");
			_delay_ms(300);
			LCD_clearScreen();
}

////////////////// function used to ask you enter a pass //////////////////////////////////////
/*
 * ask you for a pass if wrong it gives you a 3 trials
 * it returns the number of wrong trials
 */

uint8 entering_password(void){

	uint8 i;
	LCD_displayString("enter password");
			catch_password();
			LCD_clearScreen();
		for( i=0;i<2 && !(UART_recieveByte());i++){
			LCD_displayString("wrong pass");
			_delay_ms(300);
			LCD_clearScreen();
		LCD_displayString("rapeat a pass");
		catch_password();
		LCD_clearScreen();
		}
		return i ;

}
