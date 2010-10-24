#ifndef _DFGAME_H_
#define _DFGAME_H_

#include "dfgame.h"
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

class Floor{
private:
	//location
	float x;
	float y;

public:
	//initialize
	Floor();
	//handle keypresses
	void handle_input();
	//moves the Floor
	void move();
	//show the Floor on the screen
	void show();
};
/*
class Timer{
private:
	int startTicks;
	int pausedTicks;
	bool paused;
	bool stated;
public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	int get_ticks();
	bool is_started();
	bool is_paused();
};
*/

#endif
