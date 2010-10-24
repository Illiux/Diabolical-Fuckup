#ifndef _DFGAME_PLAYER_H_
#define _DFGAME_PLAYER_H_

#include "stdlib.h"

#define PLAYER_WIDTH	50
#define PLAYER_HEIGHT 	100

class Player{
private:
	float x;
	float y;
	float speed;
	float health;
public:
	Player();
	void 	setPosition(float, float);
	void 	setX(float);
	void 	setY(float);
	float 	getX();
	float 	getY();
	float 	getSpeed();
	void 	setSpeed(float);
	float	getHealth();
	void 	setHealth(float);
	void	draw();
	void 	moveLeft();
	void 	moveRight();
	void 	moveUp();
	void	moveDown();
	void	jump();
};

#endif

