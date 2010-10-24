#include "platform.h"

void Platform::Draw() {
	glTranslatef(x,y,-1.0);

	glBegin(GL_QUADS);
		glColor4f(1.0,1.0,1.0,1.0);

		glVertex3f(0,0,0);
		glVertex3f(width,0,0);
		glVertex3f(width,height,0);
		glVertex3f(0,height,0);
	glEnd();

	// Reset original translate
	glTranslatef(-x,-y,1.0);
}

float Platform::GetX() {
	return x;
}

float Platform::GetY() {
	return y;
}

void Platform::Move(float x, float y)
{
	this.x += x;
	this.y += y;
}

void Platform::SetPosition(float x, float y)
{
	this.x = x;
	this.y = y;
}

Platform::Platform(float x, float y, int width, int height)
{
	this.x = x;
	this.y = y;
	this.width = width;
	this.height = height;
}

bool Platform::Collides(Player player) {
}
