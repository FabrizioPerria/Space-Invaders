#ifndef __DISPLAY_H
#	define __DISPLAY_H

/*
DISPLAY CONNECTION

3.3V ----------------  Vcc
       |   200 ohm
       |--/\/\/------  BACKLIGHT (optional)  

PA7  ----------------  RST

PA6  ----------------  DC (data/cmd)

PA5  ----------------  DIN

PA3  ----------------  CE 

PA2  ----------------  CLK
		 
GND  ----------------  GND

*/

#	define SCREEN_WIDTH	  84
#	define SCREEN_HEIGHT  48

#	define 	GPIO_PORTA_DATA			(*((volatile unsigned long *)0x400043FC))
# define  GPIO_PORTA_LOCK 		(*((volatile unsigned long *)0x40004520))
# define 	GPIO_PORTA_CR 			(*((volatile unsigned long *)0x40004524))
# define 	GPIO_PORTA_AMSEL 		(*((volatile unsigned long *)0x40004528))
# define 	GPIO_PORTA_AFSEL 		(*((volatile unsigned long *)0x40004420))
# define 	GPIO_PORTA_PCTL 		(*((volatile unsigned long *)0x4000452C))
# define 	GPIO_PORTA_DIR 			(*((volatile unsigned long *)0x40004400))
# define 	GPIO_PORTA_DEN 			(*((volatile unsigned long *)0x4000451C))
	
#	define 	SSI0_CR0						(*((volatile unsigned long *)0x40008000))
#	define 	SSI0_CR1						(*((volatile unsigned long *)0x40008004))
#	define 	SSI0_CC							(*((volatile unsigned long *)0x40008FC8))
#	define 	SSI0_CPSR						(*((volatile unsigned long *)0x40008010))
#	define 	SSI0_ISR						(*((volatile unsigned long *)0x4000800C))
#	define 	SSI0_IDR						(*((volatile unsigned long *)0x40008008))

#	define 	SYSCTL_RCGC2_SSI0			0x10
#	define 	SYSCTL_RCGC2_GPIOA		0x01
#	define 	GPIOA_PINS	0xC0				//pins 6 and 7 
#	define	SSI0_PINS		0x2C				//pins 2,3,5
#	define	SSI0_FUNCTION 0x202200	//pins 2, 3 and 5 will get alternate function 2

#	define 	SSI0_ENABLE			0x2
#	define 	SSI0_SLAVE_MODE	0x4
#	define 	SSI0_REF_CLK_SYS	0x0
# define 	SSI0_CLK_DIV			0x18

#	define	PIN_RESET 7
#	define	PIN_DATA_CMD 6
#	define	IS_DATA						(0x1 << PIN_DATA_CMD)
#	define 	RESET_SCREEN			(0x1 << PIN_RESET)

//------------initDisplay------------
// Initialization Sequence of the Nokia 5110 Display. 
// Input: none
// Output: data structure containing the states of all the devices
void initDisplay(void);

//------------sendCMD------------
// Send a command to Nokia 5110 module 
// Input: ID of the comman to send (see the datasheet for the set of possible commands)
// Output: none
void sendCMD(unsigned char cmd);

//------------sendDATA------------
// Send data to Nokia 5110 module 
// Input: data to send
// Output: none
void sendDATA(unsigned char data);

#endif
