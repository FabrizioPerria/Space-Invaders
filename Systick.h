#ifndef __SYSTICK_H
#	define __SYSTICK_H

#define NVIC_ST_CTRL			(*((volatile unsigned long*)0xE000E010))
#define NVIC_ST_RELOAD		(*((volatile unsigned long*)0xE000E014))
#define NVIC_ST_CURRENT		(*((volatile unsigned long*)0xE000E018))
#define NVIC_PRI3					(*((volatile unsigned long*)0xE000E40C))

#define TICK_PERIOD 			7271;//2666665							// @30Hz---------> ((80 Mhz)/(30 Hz))-1
#define SYSTICK_PRIORITY	(0x2 << 29)
#define NVIC_ST_CTRL_EN_INT 0x07

//------------initSystick------------
// Initialize the systick and define the reload value
// Input: none
// Output: none
void initSystick(void);

//------------Systick_Handler------------
// Interrupt Service Routine executed at each tick (30Hz is the rate)
// Input: none
// Output: none
void SysTick_Handler(void);

#endif
