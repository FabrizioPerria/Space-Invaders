#ifndef __PLAYER_H
#	define __PLAYER_H

#include <stdint.h>
#include "Weapon.h"

#define SHIP_WIDTH 12

typedef struct {
	uint8_t xPos;
	uint8_t lives;
}Player;

void initPlayer(void);
void setPlayerPosition(uint32_t ADCRead);
uint32_t getPlayerPosition(void);
void drawPlayer(void);
void killPlayer(void);
void shootPlayer(void);

#endif
