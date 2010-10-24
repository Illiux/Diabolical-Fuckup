#include <SDL/SDL.h>
#include <stdlib.h>

bool wait_for_events ()
{
  SDL_Event event;
  int status;
  char *key;
  bool quit = false;

  printf("waiting for events, press 'q' or 'ESC' to quit\n");
  while ( !quit ) {				
    status = SDL_WaitEvent(&event);	//wait indefinitely for an event to occur
					//event will be removed from event queue
    if ( !status ) {			//Error has occurred while waiting
	printf("SDL_WaitEvent error: %s\n", SDL_GetError());
	return false;
    }
    switch (event.type) {		//check the event type
      case SDL_KEYDOWN:			//if a key has been pressed
	key = SDL_GetKeyName(event.key.keysym.sym);
    	printf("The %s key was pressed!\n", key );
	if ( event.key.keysym.sym == SDLK_ESCAPE )	//quit if 'ESC' pressed
	  quit = true;
    	else if ( key[0] == 'q'  )	//quit if 'q'  pressed
	  quit = true;			//same as "if ( event.key.keysym.sym == SDLK_q )"
    	break;
       case SDL_MOUSEMOTION:             //mouse moved
        printf("Mouse motion x:%d, y:%d\n", event.motion.x, event.motion.y );
        break;
      case SDL_MOUSEBUTTONUP:           //mouse button pressed
        printf("Mouse pressed x:%d, y:%d\n", event.button.x, event.button.y );
        break; 
     case SDL_QUIT:			//'x' of Window clicked
	  exit ( 1 );
    	break;
    }
  } //while
  return true;
}

int main()
{   
  //The Images.
SDL_Surface* hello = NULL;
SDL_Surface* screen = NULL;

//start SDL
SDL_Init(SDL_INIT_EVERYTHING);

//set up screen
screen = SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);

//load image
hello = SDL_LoadBMP("porn.bmp");

//apply image
SDL_BlitSurface(hello,NULL,screen,NULL);

//update screen
SDL_Flip(screen);

//pause
//SDL_Delay(5000);

//free allocated memory
SDL_FreeSurface(hello);
  
    
 // SDL_Surface *screen;

  //initialize the event subsystem along with video system
  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
        exit(1);
  }
  //ensure SDL_Quit is called when the program exits
  atexit(SDL_Quit);
   
  //set video mode of 640 x 480 with 16-bit pixels
  //screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE);
  if ( screen == NULL ) {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        exit(1);
  }
  
  wait_for_events();
  
  return 0;
}