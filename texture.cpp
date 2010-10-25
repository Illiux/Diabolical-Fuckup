#include "texture.h"
#include "GL/glpng.h"

bool Texture::isValid()
{
	bool valid = true;
	if (texture==-1)
		valid = false;
	return valid;
}

int Texture::getWidth()
{
	return width;
}

int Texture::getHeight()
{
	return height;
}

void Texture::bind()
{
	glBindTexture( GL_TEXTURE_2D, texture);
}

// For creating invalid placeholder textures
Texture::Texture()
{
	height = 0;
	width = 0;
	texture = -1;
}

Texture::Texture(std::string filename)
{
	pngInfo* info = new pngInfo;
	texture = pngBind(filename.c_str(), PNG_NOMIPMAP, PNG_ALPHA, info,GL_REPEAT,GL_LINEAR,GL_LINEAR);
	if (texture==0) {
		texture=-1;
		height=0;
		width=0;
	} else {
		height = info->Height;
		width = info->Width;
	}
}

SDL_Surface *Texture::loadImage(std::string filename){
	SDL_Surface* any_image = NULL;
	
	
	//optimized image that will be used
	SDL_Surface* optimizedimage = NULL;
	//load image
	any_image = IMG_Load(filename.c_str());
	if (any_image != NULL){
		//create an optimized image
		optimizedimage = SDL_DisplayFormat(any_image);

		//free the old image
		SDL_FreeSurface (any_image);
	}
	//optimizedimage = zoomSurface(optimizedimage,.5,.5,.5);
	//return the optimized image
	return optimizedimage;
}
