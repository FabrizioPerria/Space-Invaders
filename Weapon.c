#include "Weapon.h"
#include "exploded.h"
#include "Enemies.h"
#include "Video.h"
#include "Bunker.h"
#include "Sound.h"

#define MAX_BULLETS 40
#define N_ROWS (N_ENEMIES / ENEMIES_PER_ROW)

extern Enemy enemies[N_ENEMIES];
extern uint8_t leftMost;
extern uint8_t rightMost;
static Weapon bullets[MAX_BULLETS] = {0};
static uint8_t index = 0;
uint8_t gameOver = 1;

static void killEnemy(int8_t index) 
{
	enemies[index].life = DEAD;
	if(index == leftMost) {
		while(enemies[index].life == DEAD && index < N_ENEMIES){
			if(index >= ENEMIES_PER_ROW) {
				index-= ENEMIES_PER_ROW;
			} else {
				index++;
				index += ((N_ROWS - 1) * ENEMIES_PER_ROW);
			}
		}
		if(index < N_ENEMIES){
			if (rightMost == leftMost)
				leftMost = rightMost = index;
			else
				leftMost = index;
		}
	} else if (index == rightMost) {
		while(enemies[index].life == DEAD && index >= 0) {
			if(index >= ENEMIES_PER_ROW) {
				index-= ENEMIES_PER_ROW;
			} else {
				index--;
				index += ((N_ROWS - 1) * ENEMIES_PER_ROW);
			}
		}
		if(index >= 0){
			if (rightMost == leftMost)
				leftMost = rightMost = index;
			else
				rightMost = index;
		}
	}
	setRemainingEnemies(getRemainingEnemies() - 1);
}

static void findNextFreeIndex(void)
{
	index = 0;
	while(bullets[index].active && index < MAX_BULLETS)
		index++;
}

void shoot(uint8_t xPos, uint8_t yPos, SENDER sender)
{
	findNextFreeIndex();
	if(index < MAX_BULLETS) {
		//draw missile
		bullets[index].xPos = xPos;
		bullets[index].yPos = yPos;
		bullets[index].sentBy = sender;
		bullets[index].active = ACTIVE;
		bullets[index].image = typeWeapon[sender];
		bullets[index].cnt = SPEED_SHOT;
		//sound missile
		if(sender == PLAYER)
			playSound(FIRE);
	} /*else {
		while(1);
	}*/
}

static WEAPON_STATUS hitEnemy(uint8_t xPosShot, uint8_t yPosShot)
{
	uint8_t i;
	//check if the bunker is hit
	if(yPosShot >= (SCREEN_HEIGHT - 16) && checkBunker(xPosShot))
		return OVER;
	for (i = 0; i < N_ENEMIES; ++i) {
		if ((enemies[i].life != DEAD) &&
		 (xPosShot >= (enemies[i].xPos)) && (xPosShot < (enemies[i].xPos + ENEMY_WIDTH)) && 
		 (yPosShot > enemies[i].yPos - ENEMY_HEIGHT) && (yPosShot < enemies[i].yPos + ENEMY_HEIGHT)) {
				killEnemy(i);
				if(getRemainingEnemies() == 0) {
					clearBuffer();
					printString(12,20, "YOU WIN!");
					displayBuffer();
					gameOver = 1;
				}
				return HIT;
		}
	}
	return ACTIVE;
}

static WEAPON_STATUS hitPlayer(uint8_t xPosShot, uint8_t yPosShot)
{
	uint8_t playerPos = getPlayerPosition();
	//check if the bunker is hit
	if(yPosShot >= (SCREEN_HEIGHT - 16) && checkBunker(xPosShot))
		return OVER;
	if ((xPosShot >= (playerPos)) && (xPosShot < (playerPos + SHIP_WIDTH)) && 
	 (yPosShot > (SCREEN_HEIGHT - 8)) && (yPosShot < (SCREEN_HEIGHT))) {
			playSound(DESTROY);
			killPlayer();
			return HIT;
	}
	return ACTIVE;
}

static WEAPON_STATUS hit(uint8_t xPosShot, uint8_t yPosShot, SENDER sender)
{
	if(sender == PLAYER)
		return hitEnemy(xPosShot, yPosShot);
	else
		return hitPlayer(xPosShot, yPosShot);
}

static void moveShot(uint8_t nBullet)
{
	uint8_t res;
	if(bullets[nBullet].active == ACTIVE) {
		if(bullets[nBullet].yPos > 0) {
			if(bullets[nBullet].sentBy == PLAYER)
				bullets[nBullet].yPos--;
			else if (bullets[nBullet].sentBy == ENEMY)
				bullets[nBullet].yPos++;
			res = hit(bullets[nBullet].xPos, bullets[nBullet].yPos, bullets[nBullet].sentBy);
			if(res == HIT) {
				bullets[nBullet].active = HIT;
				bullets[nBullet].image = exploded;
				bullets[nBullet].cnt = SPEED_EXPLOSION;
			} else if(res == OVER) {
				bullets[nBullet].active = OVER;
			}
		} else {
			bullets[nBullet].active = OVER;
		}		
	}
}


void drawShots(void)
{
	uint8_t i;
	
	for(i = 0; i < MAX_BULLETS; ++i) {
		if(bullets[i].active == ACTIVE) {
			//move laser
			if(!bullets[i].cnt) {
				bullets[i].cnt = SPEED_SHOT;
				moveShot(i);	
				if(gameOver){
					return;
				}
			} else {
				--bullets[i].cnt;
			}
			drawElement(bullets[i].xPos, bullets[i].yPos, 2, bullets[i].image);
		} else if(bullets[i].active == HIT && getRemainingEnemies()) {
			if (bullets[i].cnt--)
				//draw the explosion
				drawElement(bullets[i].xPos, bullets[i].yPos, 12, bullets[i].image);
			else
				bullets[i].active = OVER;
		}
	}
}
