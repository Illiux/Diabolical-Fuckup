#ifndef _DFGAME_H_
#define _DFGAME_H_

#include "platform.h"
#include "globals.h"
#include "player.h"
#include "level.h"
#include "ui.h"
#include "items/door.h"

class DFGame
{
private:
	bool init_GL();
	bool valid;
	SDL_Event event;
	UI *ui;
	Level *level;
public:
	DFGame();
	~DFGame();
	int MainLoop();
	bool IsValid();
	void setLevel(Level*);
};

extern DFGame* game;
extern Player* player;

#endif
