#include "input.h"

//------------initInputs------------
// Initialize all the input devices using the functions defined in the initList array
// Input: none
// Output: none
void initInputs(void)
{
	int numDevices = sizeof(initInputList) / sizeof(void*);
	int i = 0;
	
	for (i = 0; i < numDevices; ++i ) {
		initInputList[i]();
	}
}

//------------readInputs------------
// Poll all the devices to get the current state. 
// Input: none
// Output: data structure containing the states of all the devices
InputData readInputs(void)
{
	InputData data;
	data.ADC_data = ADC0_In();
	data.Button_data = Button_In();
	
	return data;
}
