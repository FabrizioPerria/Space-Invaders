// DAC.c
// Runs on TM4C123, 
// Implementation of the 6-bit digital to analog converter

// Port B bits 5-0 have the 6-bit DAC

#include "DAC.h"
#include "shared_registers.h"

// **************initDAC*********************
// Initialize 6-bit DAC 
// Input: none
// Output: none
void initDAC(void){
	unsigned int delay;
	SYSCTL_RCGC2 |= SYSCTL_RCGC2_GPIOB;
	delay = SYSCTL_RCGC2;
	(void)delay;
	GPIO_PORTB_LOCK = MAGIC_NUM;
	GPIO_PORTB_CR |= DAC_BITS;
	GPIO_PORTB_AMSEL &= ~DAC_BITS;
	GPIO_PORTB_AFSEL &= ~DAC_BITS;
	GPIO_PORTB_PCTL = 0;
	GPIO_PORTB_DIR |= DAC_BITS;
	GPIO_PORTB_DR8R |= DAC_BITS;
	GPIO_PORTB_DEN |= DAC_BITS;
}


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(unsigned long data){
  GPIO_PORTB_DATA = data & 0xF;
}
