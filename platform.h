#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include "dfgame.h"
#include "player.h"
#include "object.h"

class Platform: public GameObject {
private:
	Platform();
	float x;
	float y;
	int		width;
	int		height;
	//GLuint	texture;
public:
	Platform(float x, float y, int width, int height);
	virtual void move(float x, float y);
	bool collides(Player);
	virtual void draw();
	virtual void setPosition(float x, float y);
	virtual float getX();
	virtual float getY();
};

#endif
