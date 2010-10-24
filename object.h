#ifndef _OBJECT_H_
#define _OBJECT_H_

class GameObject {
public:
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual float getWidth() = 0;
	virtual float getHeight() = 0;
	virtual void move(float, float) = 0;
	virtual void  draw() = 0;
	virtual void setPosition(float, float) = 0;
};

#endif
