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
    printf("Player moves LEFT \n");
}

void Player::moveRight()
{
    printf("Player moves RIGHT \n");
}

void Player::moveUp()
{
    printf("Player moves UP \n");
}

void Player::moveDown()
{
    printf("Player moves DOWN \n");
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
void Player::setFloor(Platform *floor) {
	this->floor = floor;
}

bool Player::collides() {
	if ((y + PLAYER_HEIGHT) < floor->getY()) return false;
	if ((x + PLAYER_WIDTH) < floor->getX()) return false;
	if ((floor->getY() + floor->getHeight()) < y) return false;
	if ((floor->getX() + floor->getWidth()) < x) return false;
	return true;
}

void Player::doMovement(float dT)
{
	accel.y -= dT*-9.8;
	printf("%f\n",accel.y);
	v.x += accel.x*dT;
	v.y += accel.y*dT;

	x += v.x*dT;
	y += v.y*dT;

	if (collides()) {
		x -= v.x;
		y -= v.y;
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
