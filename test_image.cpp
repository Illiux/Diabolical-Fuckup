#include "SDL.h"

int main(int argc, char* args){

	//The Images.
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;

	//start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//set up screen
	screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);

	//load image
	hello = SDL_LoadBMP("porn.bmp");

	//apply image
	SDL_BlitSurface(hello,NULL,screen,NULL);

	//update screen
	SDL_Flip(screen);

	//pause
	SDL_Delay(5000);

	//free allocated memory
	SDL_FreeSurface(hello);

	//quit
	SDL_Quit();

	return 0;
}
