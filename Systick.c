#include "Systick.h"
#include "input.h"

//------------initSystick------------
// Initialize the systick and define the reload value
// Input: none
// Output: none
void initSystick(void)
{
	NVIC_ST_CTRL = 0;							//turn off the systick device
	NVIC_ST_RELOAD = TICK_PERIOD; //set the wanted period
	NVIC_ST_CURRENT = 0;
	NVIC_PRI3 = SYSTICK_PRIORITY;	//set the priority of the ISR
	NVIC_ST_CTRL = NVIC_ST_CTRL_EN_INT;
}


//------------Systick_Handler------------
// Interrupt Service Routine executed at each tick (30Hz is the rate)
// Input: none
// Output: none
void SysTick_Handler(void)
{
	InputData data = readInputs();

	//if ADC is different (over a threshold)
	//	move my ship in the framebuffer
	
	//if the button is pressed
	//  draw missile
	//  start to play missile sound (arm timer2A)
	
	//move sprites in the framebuffer
}
