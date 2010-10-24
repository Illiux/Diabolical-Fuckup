#ifndef _DOOR_H_
#define _DOOR_H_

#include "item.h"
#include "../globals.h"
#include "../level.h"
#include "../dfgame.h"

class Door: public Item
{
private:
	Level *dest;
	Door	*linkedDoor;
	Texture* open;
public:
	Door(float,float);
	Door(float,float,Texture*,Texture*);
	virtual void use();
	virtual void pickup();
	virtual void place();
	virtual void look();
	void	setDest(Level*);
	void	link(Door*);
	void	setLink(Door*);
	virtual void	draw();
};

#endif
