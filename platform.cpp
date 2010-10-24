#include "platform.h"

void Platform::draw() {
    
	glTranslatef(x,y,-1.0);

	glBegin(GL_QUADS);
		glColor4f(1.0,1.0,1.0,1.0);

		glVertex3f(0,0,0);
		glVertex3f(width,0,0);
		glVertex3f(width,height,0);
		glVertex3f(0,height,0);
	glEnd();

	// Reset original translate
	glTranslatef(-x,-y,1.0);}

float Platform::getX() {
	return x;
}

float Platform::getY() {
	return y;
}

void Platform::move(float x, float y)
{
	this->x += x;
	this->y += y;
}

void Platform::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

Platform::Platform(float x, float y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

float Platform::getWidth() {
	return width;
}

float Platform::getHeight() {
	return height;
}
