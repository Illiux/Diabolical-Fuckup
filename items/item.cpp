#include "item.h"

bool Item::mouseOver(float x, float y)
{
	if ((y > getY()) && (y < ( getY() + getHeight())))
		if ((x > getX()) && (y < ( getY() + getWidth())))
			return true;
	return false;
}
