#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include "globals.h"
#include "object.h"
#include "util.h"

class Platform: public GameObject {
private:
	Platform();
	float x;
	float y;
	float	width;
	float	height;
	GLuint	texture;
public:
	Platform(float x, float y, int width, int height);
	Platform(float x, float y, int width, int height, GLuint texture);
	virtual void move(float x, float y);
	virtual void draw();
	virtual void setPosition(float x, float y);
	virtual float getX();
	virtual float getY();
	virtual float getHeight();
	virtual float getWidth();
};

#endif
