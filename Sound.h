#ifndef __SOUND_H
#	define __SOUND_h

/* 
	 Sound is a layer that allows to abstract the DAC driver and the Sample Timer driver
   ad see them as "Sound device". In this way we can initialize them and play the sounds 
	 transparently. 
*/

#include "DAC.h"
#include "Timer2A.h"

/* The initialization takes the following array to initialize all the input devices */
typedef void (*SoundInitFuncPtr)(void);

static SoundInitFuncPtr initSoundList[] = {
	initDAC,
	initTimer2A
};

enum Events {
	FIRE = 0,
	DESTROY,
	DIED
};

typedef char* SoundWave;

static SoundWave sounds[] ;//= { };


//------------initSound------------
// Initialize all the sound elements using the functions defined in the initList array
// Input: none
// Output: none
void initSound(void);

//------------playSound------------
// Set the correct sound in the buffer basing on the event and arm the Timer2A Interrupt
// Input: event happened
// Output: none
void playSound(int event);


#endif
