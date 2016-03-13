// Button.c
// Runs on TM4C123

// Port D bit 0 has the shoot button

#include "Button.h"
#include "shared_registers.h"

// **************initButton*********************
// Initialize the shoot button connected to PD0
// Input: none
// Output: none

void initButton(void){ 
 	unsigned int delay;
	SYSCTL_RCGC2 |= SYSCTL_RCGC2_GPIOD;
	delay = SYSCTL_RCGC2;
	(void)delay;
	GPIO_PORTD_LOCK = MAGIC_NUM;
	GPIO_PORTD_CR |= BUTTON_BIT;
	GPIO_PORTD_AMSEL &= ~BUTTON_BIT;
	GPIO_PORTD_AFSEL &= ~BUTTON_BIT;
	GPIO_PORTD_PCTL = 0;
	GPIO_PORTD_PUR &= ~BUTTON_BIT;
	GPIO_PORTD_DIR &= ~BUTTON_BIT;
	GPIO_PORTD_DEN |= BUTTON_BIT;
}

// **************Button_In*********************
// Input from shoot button
// Input: none 
// Output: 0 (not pressed) or 1 pressed)

unsigned long Button_In(void){
	return (GPIO_PORTD_DATA & BUTTON_BIT);
}
