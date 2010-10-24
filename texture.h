#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include "globals.h"

class Texture
{
private:
	SDL_Surface* loadImage(std::string);
	GLuint	texture;
	int			width;
	int			height;
public:
	Texture();
	Texture(std::string);
	int getWidth();
	int getHeight();
	bool isValid();
	void	bind();
};

#endif
