// ADC.c
// Runs on TM4C123
// Provide functions that initialize ADC0 SS3 to be triggered by
// software and trigger a conversion, wait for it to finish,
// and return the result. 

#include "ADC.h"
#include "shared_registers.h"

// This initialization function sets up the ADC 
// Max sample rate: <=125,000 samples/second
// SS3 triggering event: software trigger
// SS3 1st sample source:  channel 1
// SS3 interrupts: enabled but not promoted to controller
void initADC0(void){ 
	int delay = 0;
	SYSCTL_RCGC2 |= SYSCTL_RCGC2_GPIOE;			//enable clock on port E
	delay = SYSCTL_RCGC2;			// dummy loop
	(void)delay;
	PORTE_LOCK = MAGIC_NUM;	// unlock port E
	PORTE_CR |= ADC_BIT;			// allow changes on PE2
	PORTE_DIR &= ~ADC_BIT;		// set PE2 as input
	PORTE_AFSEL |= ADC_BIT;		// PE2 will not be a GPIO
	PORTE_DEN &= ~ADC_BIT;		// PE2 will not be a digital pin...
	PORTE_AMSEL |= ADC_BIT;		// ...but instead will be analog (AIN1)
	
	SYSCTL_RCGC0 |= SYSCTL_RCGC0_ADC0_CK;	// Enable clock for ADC0
	delay = SYSCTL_RCGC0;			// dummy loop
	
	SYSCTL_RCGC0 &= ~SYSCTL_RCGC0_ADC0_SPD;		// set speed to 125Ksamples/sec
	ADC0_SSPRI = ADC0_SSPRI_PRIORITY0;	// set priority 0 to sequencer 3...
	ADC0_ACTSS &= ~SEQUENCER3;// ...and shut it down during its setup
	ADC0_EMUX &= ~ADC0_EMUX_POLL;		// the sampling will be made through polling (software triggered)
	ADC0_SSMUX3 &= ~0xF;			// reset sequencer
	ADC0_SSMUX3 = AIN1;				// link sequencer 3 to AIN1
	ADC0_SSCTL3 = ADC0_SSCTL3_RIS_FLAG;				// after each sample set a flag in RIS	
	ADC0_ACTSS |= SEQUENCER3;			//enable the sequencer 3
}


//------------ADC0_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
unsigned long ADC0_In(void){  
	unsigned int tmp = 0;
	ADC_PSSI |= SEQUENCER3;
	while (!(ADC_RIS & SEQUENCER3));	//wait for RIS set (means data ready)
	tmp = (ADC_DATA & 0xFFF);			// only 12 bits
	ADC_ISC |= SEQUENCER3;
	
	return tmp;
}
