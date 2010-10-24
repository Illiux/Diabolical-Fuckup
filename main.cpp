#include "dfgame.h"

int main(int argc, char** argv){
	DFGame *game = new DFGame();
	int ret = game->MainLoop();

	delete game;
	
	return ret;
}
