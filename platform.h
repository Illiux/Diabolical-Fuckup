#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include "dfgame.h"

class Platform {
private:
	Platform();
	float x;
	float y;
	int		width;
	int		height;
	GLuint	texture;
public:
	Platform(float x, float y, int width, int height)
	void Move(float x, float y);
	bool Collides(Player);
	void Draw();
	void SetPosition(float x, float y);
	float GetX();
	float GetY();
};

#endif
