#ifndef _DFGAME_PLAYER_H_
#define _DFGAME_PLAYER_H_

#include "object.h"
#include "stdio.h"
#include "platform.h"
#include "globals.h"
#include "level.h"

#define PLAYER_WIDTH	100
#define PLAYER_HEIGHT 	100

class Player: public GameObject {
private:
	Texture* texLeft;
	Texture* texRight;
	Texture* texFront;
	Texture* texRightJump;
	Texture* texLeftJump;
	float x;
	float y;
	float speed;
	float health;
	Vect2D	accel;
	Vect2D	v;
  Level *level;
	bool	left;
	bool	right;
	bool	collides();
	bool  colliding;
public:
	bool	singleCollide(GameObject *);
	void setLevel(Level *);
	void doMovement(float);
	Player();
	Player(Texture*,Texture*,Texture*,Texture*,Texture*);
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
	void	stopLeft();
	void	stopRight();
	void	jump();
	void	stopX();
	virtual float getHeight();
	virtual float getWidth();
};

#endif

