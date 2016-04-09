#include "Player.h"
#include "Display.h"
#include "Video.h"
#include "playerShip.h"
#include "ADC.h"

static Player me;
extern uint8_t gameOver;

void initPlayer(void) 
{
	setPlayerPosition(ADC0_In());
	me.lives = 2;
}

void setPlayerPosition(uint32_t ADCRead)
{
	me.xPos = (ADCRead*68)/4095;
}

uint32_t getPlayerPosition(void)
{
	return me.xPos;
}

void drawPlayer(void)
{
	drawElement(me.xPos, SCREEN_HEIGHT-8, SHIP_WIDTH, playerShip);
}

void shootPlayer(void)
{
	shoot((me.xPos + (SHIP_WIDTH/2)), (SCREEN_HEIGHT - 8), PLAYER);
}

void killPlayer(void)
{
	if(!me.lives) {
		clearBuffer();
		printString(8,20, "GAME OVER");
		displayBuffer();
		gameOver = 1;
	} else
		me.lives --;
}
