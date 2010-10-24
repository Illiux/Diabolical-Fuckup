#ifndef _DFGAME_PLAYER_H_
#define _DFGAME_PLAYER_H_

#include "object.h"
#include "stdio.h"

#define PLAYER_WIDTH	50
#define PLAYER_HEIGHT 	100

class Player: public GameObject {
private:
	float x;
	float y;
	float speed;
	float health;
public:
	Player();
	virtual void 	setPosition(float, float);
  void 	setX(float);
	void 	setY(float);
	virtual void	move(float, float);
	virtual float 	getX();
	virtual float 	getY();
	float 	getSpeed();
	void 	setSpeed(float);
	float	getHealth();
	void 	setHealth(float);
	virtual void	draw();
	void 	moveLeft();
	void 	moveRight();
	void 	moveUp();
	void	moveDown();
	void	jump();
};

#endif

