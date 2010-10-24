#ifndef _ITEM_H_
#define _ITEM_H_

#include "../object.h"
#include "../texture.h"
#include "../globals.h"

class Item: public GameObject
{
protected:
	Texture* texture;
	float x;
	float y;
public:
	virtual void pickup()=0;
	virtual void place()=0;
	virtual void use()=0;
	virtual void look()=0;
	virtual float getWidth();
	virtual float getHeight();
	virtual float getX();
	virtual float getY();
	virtual void	move(float,float);
	virtual void	setPosition(float,float);
	virtual void	draw();
	virtual void Pickup();
	virtual void Place();
	virtual void Use();
	virtual void Look();
	bool mouseOver(float,float);
};


#endif
