#ifndef _ITEM_H_
#define _ITEM_H_

#include "../object.h"
#include "../texture.h"
#include "../globals.h"

class Item: public GameObject
{
private:
	Texture* texture;
public:
	virtual void Pickup();
	virtual void Place();
	virtual void Use();
	virtual void Look();
	bool mouseOver(float,float)
}


#endif
