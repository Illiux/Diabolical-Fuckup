#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <vector>
#include "object.h"
#include "items/item.h"

class Level
{
private:
	std::vector<Item*> objects;
	std::vector<GameObject*> platforms;
public:
	Level();
	void addObject(Item *);
	void addPlatform(GameObject *);
	void draw();
	std::vector<GameObject*>* getPlatforms();
	std::vector<Item*>* getObjects();
};

#endif
