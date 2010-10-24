#include "dfgame.h"

DFGame *game;

int main(int argc, char** argv){
	game = new DFGame();
	int ret = game->MainLoop();

	delete game;

	return ret;
}
