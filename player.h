#ifndef _DFGAME_PLAYER_H_
#define _DFGAME_PLAYER_H_

#include "object.h"
#include "stdio.h"
#include "platform.h"
#include "globals.h"

#define PLAYER_WIDTH	50
#define PLAYER_HEIGHT 	80

class Player: public GameObject {
private:
	float x;
	float y;
	float speed;
	float health;
	Vect2D	accel;
	Vect2D	v;
	Platform *floor;
	bool	collides();
public:
	void setFloor(Platform *);
	void doMovement(float);
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
	void	stopX();
};

#endif

