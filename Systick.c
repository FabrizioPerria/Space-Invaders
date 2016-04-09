#include "Systick.h"
#include "input.h"
#include "Sound.h"
#include "Video.h"

static uint32_t speedEnemies;
uint8_t semaphore;
uint8_t reset = 0;
extern uint8_t gameOver;

/* 
Calculate the absolute value of a number 
Needed to detect slider changes over a threshold
*/
static int16_t abs(int16_t val)
{
	if (val < 0) 
		val = -val;
	return val;
}

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
	static uint32_t prevADCVal = ADC_THRESHOLD+1;
	static uint8_t prevBtnVal = 0;
	InputData data = readInputs();
	//if ADC is different (over a threshold)
	//	set a new current position
	if(abs(data.ADC_data - prevADCVal) > ADC_THRESHOLD){
		setPlayerPosition(data.ADC_data);
		prevADCVal = data.ADC_data;
	}
	
	//if the button is pressed
	if(data.Button_data && !prevBtnVal) {	//react on press
		//  draw missile
		if(!gameOver) {
			shootPlayer();
		} else {
			gameOver = 0;
			prevBtnVal = data.Button_data;
			semaphore = 1;
			reset = 1;
			return;
		}
		//  start to play missile sound (arm timer2A)
	}
	prevBtnVal = data.Button_data;
	
		
	//play sounds
	if(!gameOver){
		//move sprites in the data structure
		if (!speedEnemies){
			setEnemiesPosition(1);
			speedEnemies = getRemainingEnemies() * 100;
		} else {
			--speedEnemies;
		}

		semaphore = 1;
		
	}
}
