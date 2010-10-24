#include "texture.h"

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
	// This surface will tell us the details of the image
	SDL_Surface *surface;	
	GLenum texture_format;
	GLint  nOfColors;
 
if ( (surface = loadImage(filename.c_str())) ) { 
 
	// Check that the image's width is a power of 2
	if ( (surface->w & (surface->w - 1)) != 0 ) {
		std::cout << "warning: " << filename << "'s width is not a power of 2\n";
	}
	
	// Also check if the height is a power of 2
	if ( (surface->h & (surface->h - 1)) != 0 ) {
		std::cout << "warning: " << filename << "'s height is not a power of 2\n";
	}
 
        // get the number of channels in the SDL surface
        nOfColors = surface->format->BytesPerPixel;
        if (nOfColors == 4)     // contains an alpha channel
        {
                if (surface->format->Rmask == 0x000000ff)
                        texture_format = GL_RGBA;
                else
                        texture_format = GL_BGRA;
        } else if (nOfColors == 3)     // no alpha channel
        {
                if (surface->format->Rmask == 0x000000ff)
                        texture_format = GL_RGB;
                else
                        texture_format = GL_BGR;
        } else {
                std::cout << "warning: the image is not truecolor..  this will probably break\n";
                // this error should not go unhandled
        }
        
	// Have OpenGL generate a texture object handle for us
	glGenTextures( 1, &texture );
 
	// Bind the texture object
	glBindTexture( GL_TEXTURE_2D, texture );
 
	// Set the texture's stretching properties
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
 
	// Edit the texture object's image data using the information SDL_Surface gives us
	glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0,
                      texture_format, GL_UNSIGNED_BYTE, surface->pixels );
	height = surface->h;
	width = surface->w;
} 
else {
	std::cout << "SDL could not load " << filename << ": " << SDL_GetError() << std::endl;
	glDeleteTextures( 1, &texture );
	texture = -1;
}    
 
// Free the SDL_Surface only if it was successfully created
if ( surface ) { 
	SDL_FreeSurface( surface );
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