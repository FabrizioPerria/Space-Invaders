// Button.h
// Runs on TM4C123
// Shoot Button for space invaders

#ifndef __BUTTON_H
#	define __BUTTON_H

#include <stdint.h>

/*
BUTTON CONNECTION

3.3V--------|
             /
            |
						|
PD0---------|
            |
            \
						/  200 ohm
						\
						|
						-
					 GND
					 
*/

#	define 	GPIO_PORTD_DATA				(*((volatile unsigned long *)0x400073FC))
# define	GPIO_PORTD_LOCK				(*((volatile unsigned long *)0x40007520))
#	define	GPIO_PORTD_CR					(*((volatile unsigned long *)0x40007524))
#	define	GPIO_PORTD_AMSEL			(*((volatile unsigned long *)0x40007528))
#	define	GPIO_PORTD_AFSEL			(*((volatile unsigned long *)0x40007420))
#	define	GPIO_PORTD_PCTL				(*((volatile unsigned long *)0x4000752C))
#	define	GPIO_PORTD_DIR				(*((volatile unsigned long *)0x40007400))
#	define	GPIO_PORTD_DEN				(*((volatile unsigned long *)0x4000751C))
#	define	GPIO_PORTD_PUR				(*((volatile unsigned long *)0x40007510))

#	define SYSCTL_RCGC2_GPIOD 0x08		// enable clock on bit 4 for PORT D
#	define BUTTON_BIT					0x01

// **************initButton*********************
// Initialize the shoot button connected to PD0
// Input: none
// Output: none
	void initButton(void); 
  

// **************Button_In*********************
// Input from shoot button
// Input: none 
// Output: 0 (not pressed) or 1 pressed)

	uint32_t Button_In(void);

#endif
