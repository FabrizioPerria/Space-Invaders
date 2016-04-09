#include "Bunker.h"
#include "Video.h"
#include <stdint.h>

#define START_BUNKER_POS 16
#define BUNKER_SPACE 16
#define END_BUNKER_POS (START_BUNKER_POS + BUNKER_SIZE + BUNKER_SPACE + BUNKER_SIZE)

static uint8_t bunkerBuffer[SCREEN_WIDTH] = {0};

void initBunker(void)
{
	uint8_t i;
	for(i = 0; i < SCREEN_WIDTH; ++i) {
		if (i < START_BUNKER_POS || i >=
			END_BUNKER_POS) {
			continue;
		} else if (i < (START_BUNKER_POS + BUNKER_SIZE)){
			//first bunker
			bunkerBuffer[i] = bunker[(i - START_BUNKER_POS)];
		} else if(i == (START_BUNKER_POS + BUNKER_SIZE)) {
			// leave the space between bunkers
			i+= (BUNKER_SPACE - 2);
		} else if(i >= (START_BUNKER_POS + BUNKER_SIZE + BUNKER_SPACE)) {
			//second bunker
			bunkerBuffer[i] = bunker[(i - (END_BUNKER_POS - BUNKER_SIZE))];
		} 
	}
}

void drawBunker(void)
{
	drawElement(0, (SCREEN_HEIGHT - 16), SCREEN_WIDTH, bunkerBuffer);
}

static void digBunker(uint8_t x)
{
	bunkerBuffer[x] >>= 1;
}

uint8_t checkBunker(uint8_t x)
{
	if (bunkerBuffer[x] != 0) {
		digBunker(x);
		return 1; //TODO: enum for return type......1 may mean bunker hit
	} else {
		return 0; //TODO: enum for return type......0 may mean no bunker hit
	}
}
