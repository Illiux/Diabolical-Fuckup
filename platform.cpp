#include "platform.h"

void Platform::draw() {
	glTranslatef(x,y,-1.0);

	if (texture!=-1) {
		glEnable( GL_TEXTURE_2D );
	} else {
		glDisable( GL_TEXTURE_2D );
	}

	glBegin(GL_QUADS);
		glColor4f(1.0,1.0,1.0,1.0);

		glBindTexture( GL_TEXTURE_2D, texture );
		glTexCoord2i( 0,0 );
		glVertex3f(0,0,0);
		glTexCoord2i( 1,0 );
		glVertex3f(width,0,0);
		glTexCoord2i( 1,1 );
		glVertex3f(width,height,0);
		glTexCoord2i( 0,1 );
		glVertex3f(0,height,0);
	glEnd();

	// Reset original translate
	glTranslatef(-x,-y,1.0);
}

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

Platform::Platform(float x, float y, int width, int height, GLuint texture){
	this->texture = texture;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
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
