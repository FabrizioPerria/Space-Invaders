#include "Sound.h"

#define NUM_SAMPLES 2000

static char *currentSound;
static unsigned long currentIndex = 0;

//------------initSound------------
// Initialize all the sound elements using the functions defined in the initList array
// Input: none
// Output: none
void initSound(void)
{
	int numElements = sizeof(initSoundList) / sizeof(void*);
	int i = 0;
	
	for (i = 0; i < numElements; ++i ) {
		initSoundList[i]();
	}
}

void TIMER2A_Handler(void)
{
	DAC_Out(currentSound[currentIndex++]);
	if (currentIndex == NUM_SAMPLES) {
		TIMER2_IMR = 0x0;
	}
	TIMER2_ICR = 0x1;
}

//------------playSound------------
// Set the correct sound in the buffer basing on the event and arm the Timer2A Interrupt
// Input: event happened
// Output: none
void playSound(int event)
{
	//set the current sound to something
	currentSound = sounds[event];
	currentIndex = 0;
	TIMER2_IMR = 0x1;
}
