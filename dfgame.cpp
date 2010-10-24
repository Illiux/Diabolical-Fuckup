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
	
	Platform floor(0,450,FLOOR_WIDTH,FLOOR_HEIGHT);

	if (!IsValid()) {
		return 1;
	}

	while (quit == false){
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_QUIT )
			{
				quit = true;
			}
		}


		glClear( GL_COLOR_BUFFER_BIT );

		floor.Draw();

		SDL_GL_SwapBuffers();

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

