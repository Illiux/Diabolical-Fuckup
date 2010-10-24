#ifndef _UTIL_H_
#define _UTIL_H_

#include "globals.h"
#include <string>
#include <iostream>

GLuint LoadTexture(std::string);
SDL_Surface *load_image(std::string filename);
#endif
