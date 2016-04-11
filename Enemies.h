#ifndef __ENEMIES_H
#define __ENEMIES_H

#include <stdint.h>
#include "enemy10PT.h"
#include "enemy15Pt.h"
#include "enemy20Pt.h"
#include "enemy40Pt.h"
#include "enemy50Pt.h"
#include "Weapon.h"

#define N_ENEMIES 10
#define MAX_SHOOT_ENEMY 4
#define ENEMY_WIDTH 12
#define ENEMY_HEIGHT 8
#define ENEMY_SPACE (ENEMY_WIDTH / 3)
#define ENEMIES_PER_ROW 5

typedef struct enemy {
	unsigned char const *image;
	uint8_t loadWeapon;
	LIFE life;
	uint8_t xPos;
	uint8_t yPos;
}Enemy;

static unsigned char const *invaders[] = {
	enemy10Pt,
	enemy15Pt,
	enemy20Pt,
	enemy40Pt,
	enemy50Pt
};

void initEnemies(void);
void moveEnemies(void);
void setEnemiesPosition(uint8_t step);
uint8_t getRemainingEnemies(void);
void setRemainingEnemies(uint8_t n);

#endif
