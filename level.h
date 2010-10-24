#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <vector>
#include "object.h"

class Level
{
private:
	std::vector<GameObject*> objects;
	std::vector<GameObject*> platforms;
public:
	void addObject(GameObject *);
	void addPlatform(GameObject *);
	void draw();
	std::vector<GameObject*>* getPlatforms();
	std::vector<GameObject*>* getObjects();
};

#endif
