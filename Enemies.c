#include "Enemies.h"
#include "Display.h"
#include "Video.h"
#include "Weapon.h"
#include <stdlib.h>

#define DELAY_LOAD_WEAPON 100

static uint8_t remainingEnemies = N_ENEMIES;
extern uint8_t gameOver;
Enemy enemies[N_ENEMIES] = { 0 };
uint8_t leftMost;
uint8_t rightMost;

typedef enum {
	RIGHT,
	LEFT
}DIRECTION;

static uint8_t direction;

void initEnemies(void)
{
	int8_t i = 0;
	remainingEnemies = N_ENEMIES;
	
	for(i = 0; i < N_ENEMIES; ++i) {
		enemies[i].image = invaders[rand() % 5];
		enemies[i].life = ALIVE;
		enemies[i].xPos = (ENEMY_WIDTH + ENEMY_SPACE) * (i % ENEMIES_PER_ROW);
		enemies[i].yPos = (i/ENEMIES_PER_ROW) * ENEMY_HEIGHT;
		enemies[i].loadWeapon = 0;	//can shoot without waiting
		drawElement(enemies[i].xPos, enemies[i].yPos, ENEMY_WIDTH, enemies[i].image);
	}

	leftMost = N_ENEMIES - ENEMIES_PER_ROW;
	rightMost = N_ENEMIES - 1;
	direction = RIGHT;
}

static void updateEnemy(unsigned int id, LIFE life, int xPos, int yPos) 
{
	enemies[id].xPos = xPos;
	enemies[id].yPos = yPos;
	enemies[id].life = life;
}

void setEnemiesPosition(uint8_t step)
{
	int i = 0;
	if (direction == RIGHT) {
		if((enemies[rightMost].xPos + step) > SCREEN_WIDTH - ENEMY_WIDTH){
			for (i = 0; i < N_ENEMIES; ++i) {
				if(enemies[i].life == ALIVE){
					updateEnemy(i,ALIVE, enemies[i].xPos, enemies[i].yPos + 1);
					if(enemies[i].yPos == SCREEN_HEIGHT - 7) {
						gameOver = 1;
						clearBuffer();
						printString(8,20, "GAME OVER");
						displayBuffer();
					}
				}
			}
			direction = LEFT;
		} else {
			for (i = 0; i < N_ENEMIES; ++i) {
				if(enemies[i].life == ALIVE) {
					updateEnemy(i,ALIVE, enemies[i].xPos + step, enemies[i].yPos);
				}
			}
		}
	} else if (direction == LEFT) {
		if((enemies[leftMost].xPos - step) < 0){
			for (i = 0; i < N_ENEMIES; ++i) {
				if(enemies[i].life == ALIVE){
					updateEnemy(i,ALIVE, enemies[i].xPos, enemies[i].yPos + 1);
					if(enemies[i].yPos == SCREEN_HEIGHT - 7) {
						gameOver = 1;
						clearBuffer();
						printString(8,20, "GAME OVER");
						displayBuffer();
					}
				}
			}
			direction = RIGHT;
		} else {
			for (i = 0; i < N_ENEMIES; ++i) {
				if(enemies[i].life == ALIVE){
					updateEnemy(i,ALIVE, enemies[i].xPos - step, enemies[i].yPos);
				}					
			}
		}
	}
}
	
void moveEnemies(void)
{
	uint8_t i;
	for (i = 0; i < N_ENEMIES; ++i) {
		if(enemies[i].life == ALIVE){
			drawElement(enemies[i].xPos, enemies[i].yPos, ENEMY_WIDTH, enemies[i].image);
			// random to see if he's gonna shot
			if((!enemies[i].loadWeapon--) && ((rand() % 3) == 1)) {
				shoot((enemies[i].xPos + (ENEMY_WIDTH / 2)), enemies[i].yPos + 8, ENEMY);
				enemies[i].loadWeapon = DELAY_LOAD_WEAPON;
			}
		}
	}
}

uint8_t getRemainingEnemies(void)
{
	return remainingEnemies;
}

void setRemainingEnemies(uint8_t n)
{
	if(n < N_ENEMIES)
		remainingEnemies = n;
}
