#ifndef _DFGAME_H_
#define _DFGAME_H_

#include "platform.h"
#include "globals.h"
#include "player.h"

class DFGame
{
private:
	bool init_GL();
	bool valid;
	SDL_Event event;
	Player *player;
public:
	DFGame();
	~DFGame();
	int MainLoop();
	bool IsValid();
};

#endif
