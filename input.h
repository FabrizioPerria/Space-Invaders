#ifndef __INPUT_H
#	define __INPUT_H

#include <stdint.h>

/* 
	 Input is a layer that allows to abstract the ADC driver and the switch driver
   ad see them as "Input devices". In this way we can initialize them and poll their 
	 status using one function (instead of N functions where N is the number of devices). 
*/

#	include "ADC.h"
#	include "Button.h"
#	include "Systick.h"

/* The initialization takes the following array to initialize all the input devices */
	typedef void (*InputInitFuncPtr)(void);

	static InputInitFuncPtr const initInputList[] = {
		initADC0, 
		initButton,
		initSystick
	};

/* The reading operation takes the following array to read data from all the input devices */
	typedef uint32_t (*InputReadFuncPtr)(void);

	static InputReadFuncPtr const readList[] = {
		ADC0_In,
		Button_In
	};

/* The outcome of the loop of the reads will be a data structure that includes all the results */
	typedef struct {
		uint16_t ADC_data;
		uint8_t Button_data;
	}InputData;

//------------initInputs------------
// Initialize all the input devices using the functions defined in the initList array
// Input: none
// Output: none
	void initInputs(void);

//------------readInputs------------
// Poll all the devices to get the current state. 
// Input: none
// Output: data structure containing the states of all the devices
	InputData readInputs(void);

#endif
