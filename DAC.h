// DAC.h
// Runs on TM4C123, 
// Header file for the 6-bit digital to analog converter

#ifndef __DAC_H
#	define __DAC_H

#	define 	GPIO_PORTB_DATA			(*((volatile unsigned long *)0x400053FC))
# define  GPIO_PORTB_LOCK 		(*((volatile unsigned long *)0x40005520))
# define 	GPIO_PORTB_CR 			(*((volatile unsigned long *)0x40005524))
# define 	GPIO_PORTB_AMSEL 		(*((volatile unsigned long *)0x40005528))
# define 	GPIO_PORTB_AFSEL 		(*((volatile unsigned long *)0x40005420))
# define 	GPIO_PORTB_PCTL 		(*((volatile unsigned long *)0x4000552C))
# define 	GPIO_PORTB_DIR 			(*((volatile unsigned long *)0x40005400))
# define 	GPIO_PORTB_DR8R 		(*((volatile unsigned long *)0x40005508))
# define 	GPIO_PORTB_DEN 			(*((volatile unsigned long *)0x4000551C))

#	define DAC_BITS 						0x3F			//00111111b
#	define SYSCTL_RCGC2_GPIOB		0x02			// enable clock on bit 2 for PORT B

// **************DAC_Init*********************
// Initialize 6-bit DAC 
// Input: none
// Output: none
	void initDAC(void);


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
	void DAC_Out(unsigned long data);
  
#endif

