#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include "globals.h"
#include "object.h"
#include "texture.h"

class Platform: public GameObject {
private:
	Platform();
	float x;
	float y;
	float	width;
	float	height;
	Texture	*texture;
public:
	Platform(float x, float y, int width, int height);
	Platform(float x, float y, int width, int height, Texture* texture);
	virtual void move(float x, float y);
	virtual void draw();
	virtual void setPosition(float x, float y);
	virtual float getX();
	virtual float getY();
	virtual float getHeight();
	virtual float getWidth();
};

#endif
