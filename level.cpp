#include "level.h"

void Level::addPlatform(GameObject *obj)
{
	platforms.push_back(obj);
}

void Level::addObject(Item *obj)
{
	objects.push_back(obj);
}

void Level::draw()
{
	std::vector<GameObject *>::iterator i;
	std::vector<Item *>::iterator j;
	for (j=objects.begin(); j<objects.end(); j++) {
		(*j)->draw();
	}
	for (i=platforms.begin(); i<platforms.end(); i++) {
		(*i)->draw();
	}
}

std::vector<GameObject *>* Level::getPlatforms() {
	return &platforms;
}

std::vector<Item *>* Level::getObjects() {
	return &objects;
}
