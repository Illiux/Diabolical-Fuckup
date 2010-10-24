/*
William Francis
Corrigan Farley
Randy Tobias
*/

#include "player.h"

Player::Player()
{
    x = 0.0;
    y = 0.0;
    speed = 0.0;
    health = 100.0;
}

void Player::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Player::setX(float x)
{
    this->x = x;
}

void Player::setY(float y)
{	
    this->y = y;
}

float Player::getX()
{
    return x;
}

float Player::getY()
{
    return y;
}

float Player::getSpeed()
{
    return speed;
}

void Player::setSpeed(float speed)
{
    this->speed = speed;
}

float Player::getHealth()
{
    return health;
}

void Player::setHealth(float health)
{
    this->health = health;
}

void Player::draw()
{
    
}
/*
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
*/	