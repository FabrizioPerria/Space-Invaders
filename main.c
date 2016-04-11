#include "PLL.h"
#include "input.h"
#include "Sound.h"
#include "Video.h"

void DisableInterrupts(void);
void EnableInterrupts(void);

extern uint8_t semaphore; // 0 means don't draw
													// 1 means draw
extern uint8_t gameOver;
extern uint8_t reset;

int main (void)
{
	DisableInterrupts();
	initPLL();			//set the bus clock to 80 MHz
	initInputs();
	initSound();
	initVideo();
	clearBuffer();
	semaphore = 1;
	EnableInterrupts();
	while(1){
		//draw the framebuffer to screen
		if (gameOver) {
			printString(0,SCREEN_HEIGHT-16,"Press Fire to Play");
			displayBuffer();
			while(gameOver);
		} else {
			clearBuffer();
			if(reset){
				initVideo();
				reset = 0;
			}
			while (!semaphore);
			drawShots();
			if(gameOver)
				continue;
			drawBunker();
			moveEnemies();
			if(gameOver)
				continue;
			drawPlayer();
		}
		displayBuffer();
		semaphore = 0;
	}
}
