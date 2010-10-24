#ifndef _DFGAME_H_
#define _DFGAME_H_

#include "platform.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"
#include "globals.h"

class DFGame
{
private:
	bool init_GL();
	bool valid;
	SDL_Event event;
public:
	DFGame();
	~DFGame();
	int MainLoop();
	bool IsValid();
};

#endif
