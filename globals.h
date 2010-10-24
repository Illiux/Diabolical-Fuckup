#ifndef _DFGAME_GLOBALS_H_
#define _DFGAME_GLOBALS_H_

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"
#include "object.h"
#include <iostream>

#define SCREEN_WIDTH	800
#define SCREEN_HEIGHT 600
#define SCREEN_BPP		32
#define FLOOR_HEIGHT	50
#define FLOOR_WIDTH		800
#define FPS						60
#define SCALE_FACTOR  50
#define ITEM_WIDTH		50
#define	ITEM_HEIGHT		50

typedef struct {
	float x;
	float y;
} Vect2D;

#endif
