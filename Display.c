#include "Display.h"
#include "shared_registers.h"

static void configScreen(void)
{
	int delay;
	GPIO_PORTA_DATA &= ~RESET_SCREEN;
	delay = GPIO_PORTA_DATA;
	(void)delay;
	GPIO_PORTA_DATA |= RESET_SCREEN;
	
	sendCMD(0x21);
	sendCMD(0xB9);		//contrast
	sendCMD(0x04);		//temperature coefficient
	sendCMD(0x14);		//Bias mode
	sendCMD(0x20);		//normal instrution set
	sendCMD(0x0C);		//normal display mode
}

void initDisplay(void)
{
	int delay;
	SYSCTL_RCGC1 |= SYSCTL_RCGC2_SSI0;			//Activate SSI0 clock
	SYSCTL_RCGC2 |= SYSCTL_RCGC2_GPIOA; 		//Activate GPIO A clock
	delay = SYSCTL_RCGC2;
	(void)delay;
	GPIO_PORTA_LOCK = MAGIC_NUM;						// unlock port A
	GPIO_PORTA_DIR |= GPIOA_PINS;						//pin6 and pin7 are gpio output
	GPIO_PORTA_DIR &= ~(SSI0_PINS);					// the SSI pins are input
	
	GPIO_PORTA_AFSEL |= SSI0_PINS;						//pin2, pin3 and pin5 are SSI pins
	GPIO_PORTA_AFSEL &= ~(GPIOA_PINS);				//pin6 and pin7 are gpio output....so no alternate function
	
	GPIO_PORTA_DEN |= (GPIOA_PINS | SSI0_PINS);	//all the pins will be on digital mode
	
	// enable SSI0 alternate function to pin2,3,5 and enable GPIO for pin 6 and 7.
	GPIO_PORTA_PCTL = (GPIO_PORTA_PCTL & 0x000F00FF) + SSI0_FUNCTION;
	
	GPIO_PORTA_AMSEL |= (GPIOA_PINS | SSI0_PINS);	//all the pins will be on digital mode
	
	//Disable SSI0 during setup
	SSI0_CR1 &= ~SSI0_ENABLE;
	
	//Launchpad will be the master
	SSI0_CR1 &= ~SSI0_SLAVE_MODE;
	
	//Take the system clock as a reference for the SSI clock
	SSI0_CC = SSI0_REF_CLK_SYS;
	
	//set the clock divider....with this the clock will be 3,33MHz
	SSI0_CPSR = (SSI0_CPSR & ~(0xFF)) + SSI0_CLK_DIV;
	
	//set frame format, SCR, sync option
	SSI0_CR0 &= ~(0xFFF0);
	
	//the data frame will bit 8-bit
	SSI0_CR0 |= 0x7;
	
	//enable SSI0
	SSI0_CR1 |= SSI0_ENABLE;
		
	configScreen();	
}

void sendCMD(unsigned char cmd)
{
	while(SSI0_ISR >> 4);		//wait until SSI becomes available
	GPIO_PORTA_DATA &= ~IS_DATA;
	SSI0_IDR = cmd;
	while(SSI0_ISR >> 4);		// wait until is processed
}

void sendDATA(unsigned char data)
{
	while(SSI0_ISR >> 4);		//wait until SSI becomes available
	GPIO_PORTA_DATA |= IS_DATA;
	SSI0_IDR = data;
}
