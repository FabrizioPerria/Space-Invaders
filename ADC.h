// ADC.h
// Runs on TM4C123
// Provide functions that initialize ADC0 SS3 to be triggered by
// software and trigger a conversion, wait for it to finish,
// and return the result. 
#ifndef __ADC_H
#	define __ADC_H

#include <stdint.h>

/* 
	The potentiometer has 3 pins:
		1 - GND
		2 - PE2
		3 - Vcc (3.3V)
		                   |-----------------------------|
GND--------------------|  1                        3 |------3.3V
                       |     SLIDE POTENTIOMETER     |
PE2--------------------|  2                          |
                       |-----------------------------|  
		
 */

#	define PORTE_AFSEL					(*((volatile unsigned long *)0x40024420))
#	define PORTE_AMSEL					(*((volatile unsigned long *)0x40024528))
#	define PORTE_LOCK						(*((volatile unsigned long *)0x40024520))
#	define PORTE_CR							(*((volatile unsigned long *)0x40024524))
#	define PORTE_DIR						(*((volatile unsigned long *)0x40024400))
#	define PORTE_DEN						(*((volatile unsigned long *)0x4002451C))
	
#	define ADC0_SSPRI						(*((volatile unsigned long *)0x40038020))
#	define ADC0_ACTSS						(*((volatile unsigned long *)0x40038000))
#	define ADC0_EMUX						(*((volatile unsigned long *)0x40038014))
#	define ADC0_SSMUX3					(*((volatile unsigned long *)0x400380A0))
#	define ADC0_SSCTL3					(*((volatile unsigned long *)0x400380A4))

#	define ADC_PSSI							(*((volatile unsigned long *)0x40038028))
#	define ADC_RIS							(*((volatile unsigned long *)0x40038004))
#	define ADC_ISC							(*((volatile unsigned long *)0x4003800C))
#	define ADC_DATA							(*((volatile unsigned long *)0x400380A8))   //SSFIFO3

#	define ADC_PIN 							2
#	define ADC_BIT							(0x1 << ADC_PIN)

#	define SEQUENCER3						(0x1 << 3)

#	define SYSCTL_RCGC2_GPIOE 	0x10		// enable clock on bit 5 for PORT E
#	define SYSCTL_RCGC0_ADC0_CK 0x10000
#	define SYSCTL_RCGC0_ADC0_SPD 0x300
#	define ADC0_SSPRI_PRIORITY0 0x0123
#	define ADC0_EMUX_POLL 			0xF0000
# define AIN1									0x01
#	define ADC0_SSCTL3_RIS_FLAG 0x6

#	define ADC_THRESHOLD 5
// This initialization function sets up the ADC 
// Max sample rate: <=125,000 samples/second
// SS3 triggering event: software trigger
// SS3 1st sample source: channel 1
// SS3 interrupts: enabled but not promoted to controller
	void initADC0(void);

//------------ADC0_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
	uint32_t ADC0_In(void);

#endif
