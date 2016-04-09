#ifndef __WEAPON_H
#	define __WEAPON_H

#include <stdint.h>
#include "laser.h"

#define SPEED_SHOT 25
#define SPEED_EXPLOSION 60

typedef enum {
	PLAYER,
	ENEMY
}SENDER;

typedef enum {
	OVER,
	HIT,
	ACTIVE
}WEAPON_STATUS;

typedef enum {
	DEAD = 0,
	ALIVE
} LIFE;
	
typedef struct Weapon{
	uint8_t xPos;
	uint8_t yPos;
	SENDER sentBy;
	WEAPON_STATUS active;
	unsigned char const *image;
	uint8_t cnt;
}Weapon;

static unsigned char const *typeWeapon[] = {
	laser,laser
};

void drawShots(void);
void shoot(uint8_t xPos, uint8_t yPos, SENDER sender);

#endif
