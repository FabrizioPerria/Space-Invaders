#ifndef __TIMER2A_H
#	define __TIMER2A_H

#	define TIMER2_CURRENT		(*((volatile unsigned long *) 0x40032048))
#	define TIMER2_CTL				(*((volatile unsigned long *) 0x4003200C))
#	define TIMER2_CFG				(*((volatile unsigned long *) 0x40032000))
#	define TIMER2_TAMR			(*((volatile unsigned long *) 0x40032004))
#	define TIMER2_TAILR			(*((volatile unsigned long *) 0x40032028))
#	define TIMER2_TAPR			(*((volatile unsigned long *) 0x40032038))
#	define TIMER2_ICR				(*((volatile unsigned long *) 0x40032024))
#	define TIMER2_IMR				(*((volatile unsigned long *) 0x40032018))
#	define NVIC_PRI5				(*((volatile unsigned long *) 0xE000E414))
#	define NVIC_EN0					(*((volatile unsigned long *) 0xE000E100))

#	define SYSCTL_RCGC1_TIMER2A	0x40000
#	define TIMER_ENABLE					0x01
#	define TIMER_32BIT					0x0
#	define TIMER_PERIODIC_POLL	0x2
#	define TIMER_RES_SYSCLK		0x0
# define TIMER_ISR_PRIORITY		0x80000000
#	define TIMER_IRQ_EN					(0x1 << 23)
	
#	define PERIOD_TIMER_2A	7271				//((80MHz) / (11 KHz)) -1

void initTimer2A(void);

#endif
