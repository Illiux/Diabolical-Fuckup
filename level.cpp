#include "level.h"

void Level::addPlatform(GameObject *obj)
{
	platforms.push_back(obj);
}

void Level::addObject(GameObject *obj)
{
	objects.push_back(obj);
}

void Level::draw()
{
	std::vector<GameObject *>::iterator i;
	for (i=objects.begin(); i<objects.end(); i++) {
		(*i)->draw();
	}
	for (i=platforms.begin(); i<platforms.end(); i++) {
		(*i)->draw();
	}
}

std::vector<GameObject *>* Level::getPlatforms() {
	return &platforms;
}
