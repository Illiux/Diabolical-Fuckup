#include "platform.h"

void Platform::draw() {
	glTranslatef(x,y,-1.0);

	if (texture->isValid()) {
		glEnable( GL_TEXTURE_2D );
	} else {
		glDisable( GL_TEXTURE_2D );
	}

	texture->bind();
	glBegin(GL_QUADS);
		glColor4f(1.0,1.0,1.0,1.0);

		glTexCoord2f( 0,0 );
		glVertex3f(0,0,0);
		glTexCoord2f( (float)width/texture->getWidth(),0 );
		glVertex3f(width,0,0);
		glTexCoord2f( (float)width/texture->getWidth(),(float)height/texture->getHeight() );
		glVertex3f(width,height,0);
		glTexCoord2f( 0,(float)height/texture->getHeight() );
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

Platform::Platform(float x, float y, int width, int height, Texture* texture){
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
	texture = new Texture();
}

float Platform::getWidth() {
	return width;
}

float Platform::getHeight() {
	return height;
}
