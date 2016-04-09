#include "Timer2A.h"
#include "shared_registers.h"

void initTimer2A(void)
{
	int delay;
	// Enable clock for Timer2
	SYSCTL_RCGC1 |= SYSCTL_RCGC1_TIMER2A;
	//dummy loop
	delay = SYSCTL_RCGC1;
	(void) delay;
	
	//Disable Timer2 while initialization
	TIMER2_CTL &= ~(TIMER_ENABLE);
	
	// set the 32-bit mode for Timer2A
	TIMER2_CFG = TIMER_32BIT;
	
	// Set polling mode on RIS flag
	TIMER2_TAMR = TIMER_PERIODIC_POLL;
	
	//set the frequency for the Timer (11KHz)
	TIMER2_TAILR = PERIOD_TIMER_2A;
	
	//use system clock resoution
	TIMER2_TAPR = TIMER_RES_SYSCLK;
	
	//clear interrupt flag and arm the interrupt
	TIMER2_ICR = 0x1;
//	TIMER2_IMR = 0x1;
	
	//set priority for Timer2A ISR
	NVIC_PRI5 |= TIMER_ISR_PRIORITY;
	
	//enable IRQ23 (timer2A)
	NVIC_EN0 |= TIMER_IRQ_EN;
	
	//the setup is over so.....let's enable the timer
	TIMER2_CTL |= (TIMER_ENABLE);
}
