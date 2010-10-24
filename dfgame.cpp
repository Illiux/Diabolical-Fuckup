/*
William Francis
Corrigan Farley
Randy Tobias
*/

#include "dfgame.h"

DFGame::~DFGame() {
	SDL_Quit();
}

int DFGame::MainLoop() {
	bool quit = false;
	char *key;
	bool draw_player = false;
	
	Platform floor(0,450,FLOOR_WIDTH,FLOOR_HEIGHT);

	if (!IsValid()) {
		return 1;
	}

	while (quit == false){
		while( SDL_PollEvent( &event ) )
		{
			switch (event.type) {		//check the event type
			case SDL_KEYDOWN:			//if a key has been pressed
			    key = SDL_GetKeyName(event.key.keysym.sym);
			    //printf("The %s key was pressed!\n", key );
			    if ( event.key.keysym.sym == SDLK_ESCAPE )	//quit if 'ESC' pressed
				quit = true;
			    else if ( key[0] == 'a' )	//move player left if 'a'  pressed
				player->moveLeft();
			    else if ( key[0] == 'd' ) 	//move player right if 'd' is pressed
				player->moveRight();
			    else if ( key[0] == 'w' )	// move player up if 'w' is pressed
				player->moveUp();
			    else if ( key[0] == 's' ) 	// move player down if 's' is pressed
				player->moveDown();
			    else if ( key[0] == 'm' ) 	// set draw player = true pressed
				draw_player = true;

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


		glClear( GL_COLOR_BUFFER_BIT );

		floor.draw();
		if (draw_player)
		   player->draw();

		SDL_GL_SwapBuffers();
		}
	}

	return 0;

}

DFGame::DFGame()
{
    valid = true;


    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        valid = false;
				return;
    }
    
    Player *player = new Player();
    
    //Create Window
    if( SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_OPENGL ) == NULL )
    {
				valid = false;
        return;
    }
    
    //Initialize OpenGL
    if( init_GL() == false )
    {
				valid = false;
        return;   
    }
    
    //Set caption
    SDL_WM_SetCaption( "Diabolical Fuckup", NULL );
    
    return;    
}

bool DFGame::init_GL(){
	//clear color
	glClearColor(0,0,0,0);

	//set projection
	glMatrixMode( GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,SCREEN_WIDTH,SCREEN_HEIGHT,0,-1,1);

	//innitialize modelview
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	//check for errors
	if (glGetError() != GL_NO_ERROR){
		return false;
	}
	//else
	return true;
}

bool DFGame::IsValid() {
	return valid;
}

