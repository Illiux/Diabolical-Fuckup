#include "item.h"

bool Item::mouseOver(float x, float y)
{
	if ((y > getY()) && (y < ( getY() + getHeight())))
		if ((x > getX()) && (y < ( getY() + getWidth())))
			return true;
	return false;
}

float Item::getWidth()
{
	return ITEM_WIDTH;
}

float Item::getHeight()
{
	return ITEM_HEIGHT;
}

float Item::getX()
{
	return x;
}

float Item::getY()
{
	return y;
}

void Item::move(float x, float y)
{
	this->x += x;
	this->y += y;
}

void Item::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Item::draw() {
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
		glTexCoord2f( (float)ITEM_WIDTH/texture->getWidth(),0 );
		glVertex3f(ITEM_WIDTH,0,0);
		glTexCoord2f( (float)ITEM_WIDTH/texture->getWidth(),(float)ITEM_HEIGHT/texture->getHeight() );
		glVertex3f(ITEM_WIDTH,ITEM_HEIGHT,0);
		glTexCoord2f( 0,(float)ITEM_HEIGHT/texture->getHeight() );
		glVertex3f(0,ITEM_HEIGHT,0);
	glEnd();

	// Reset original translate
	glTranslatef(-x,-y,1.0);
}
