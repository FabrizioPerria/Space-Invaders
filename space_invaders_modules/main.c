#include "PLL.h"
#include "input.h"
#include "Sound.h"

void DisableInterrupts(void);
void EnableInterrupts(void);

int main (void)
{
	DisableInterrupts();
	initPLL();			//set the bus clock to 80 MHz
	initInputs();
	initSound();
	EnableInterrupts();
	
	while(1){
		//draw the framebuffer to screen
		
	}
}

	void SleepTest(unsigned long ms)
	{
		unsigned long cnt;
		while (ms > 0) {
			cnt = 13333;			// @ 80Mhz
			while (cnt--);
			ms--;
		}
	}
