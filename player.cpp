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

void Player::move(float x, float y)
{
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

void Player::moveLeft()
{
	v.x-=2.5;
}

void Player::moveRight()
{
	v.x+=2.5;
}

void Player::moveUp()
{
	y += 0.01;
	if (collides())
		v.y = -10;
}

void Player::moveDown()
{
}

void Player::draw()
{
    glTranslatef(x,y,-1.0);

    glBegin(GL_QUADS);
	glColor4f(1.0,1.0,1.0,1.0);

	glVertex3f(0,0,0);
	glVertex3f(PLAYER_WIDTH,0,0);
	glVertex3f(PLAYER_WIDTH,PLAYER_HEIGHT,0);
	glVertex3f(0,PLAYER_HEIGHT,0);
    glEnd();

    // Reset original translate
    glTranslatef(-x,-y,1.0);
}

//temporary
void Player::setLevel(Level *level) {
	this->level = level;
}

float Player::getHeight() {
	return PLAYER_HEIGHT;
}

float Player::getWidth() {
	return PLAYER_WIDTH;
}

bool Player::singleCollide(GameObject *obj) {
	if ((y + PLAYER_HEIGHT) < obj->getY()) return false;
	if ((obj->getY() + obj->getHeight()) < y) return false;
	if ((x + PLAYER_WIDTH) < obj->getX()) return false;
	if ((obj->getX() + obj->getWidth()) < x) return false;
	return true;
}

bool Player::collides() {
	std::vector<GameObject*>* objects = level->getPlatforms();
	std::vector<GameObject*>::iterator i;
	for (i=objects->begin();i<objects->end();i++) {
		if (singleCollide(*i)) return true;
	}
	return false;
}

void Player::doMovement(float dT)
{
	accel.y = 9.8;
	v.x += accel.x*dT;
	v.y += accel.y*dT;


	y += v.y*dT*SCALE_FACTOR;
	if (collides()) {
		y -= v.y*dT*SCALE_FACTOR;
		accel.y = 0.0;
		v.y = 0.0;
	}
	x += v.x*dT*SCALE_FACTOR;
	if (collides()) {
		x -= v.x*dT*SCALE_FACTOR;
		accel.x = 0.0;
		v.x = 0.0;
	}
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
