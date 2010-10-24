#include "door.h"

void Door::use()
{
	player->setPosition(x,y);
	game->setLevel(dest);
}

void Door::look()
{
// Shit goes here
}

void Door::pickup()
{
	return;
}

void Door::place()
{
	return;
}

void Door::link(Door* otherDoor)
{
	otherDoor->setLink(this);
	linkedDoor = otherDoor;
}

void Door::setLink(Door* otherDoor)
{
	linkedDoor = otherDoor;
}

Door::Door(float x, float y)
{
	this->x = x;
	this->y = y;
	texture = new Texture();
}

Door::Door(float x, float y, Texture* open,Texture* closed)
{
	this->x = x;
	this->y = y;
	this->open = open;
	this->texture = closed;
}

void Door::draw()
{
	glTranslatef(x,y,0);
	
	if (texture->isValid()) {
		glEnable(GL_TEXTURE_2D);
	} else {
		glDisable(GL_TEXTURE_2D);
	}

	texture->bind();

	glBegin(GL_QUADS);
		glColor4f(1.0,1.0,1.0,1.0);

		glTexCoord2i( 0,0 );
		glVertex3f(0,0,0);
		glTexCoord2i( 1,0 );
		glVertex3f(100,0,0);
		glTexCoord2i( 1,1 );
		glVertex3f(100,100,0);
		glTexCoord2i( 0,1 );
		glVertex3f(0,100,0);
	glEnd();

	//Reset original translate
	glTranslatef(-x,-y,0);
}
