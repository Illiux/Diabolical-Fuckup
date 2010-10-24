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
	
	Floor floor;

	if (!IsValid()) {
		return 1;
	}

	while (quit == false){
		while( SDL_PollEvent( &event ) )
		{
			floor.handle_input();

			if( event.type == SDL_QUIT )
			{
				quit = true;
			}
		}

		floor.move();

		glClear( GL_COLOR_BUFFER_BIT );

		floor.show();

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

void Floor::show(){
	//move to offset

	glTranslatef(x,y,0);

	//start Quad
	glBegin(GL_QUADS);
		glColor4f(1.0,1.0,1.0,1.0);

		glVertex3f(0,0,0);
		glVertex3f(FLOOR_WIDTH,0,0);
		glVertex3f(FLOOR_WIDTH,FLOOR_HEIGHT,0);
		glVertex3f(0,FLOOR_HEIGHT,0);
	glEnd();

	glLoadIdentity();
}
Floor::Floor(){
	x = 0;
	y = 450;
}
void Floor::handle_input(){
	/*if (event.type == SDL_KEYDOWN){
		switch(event.key.keysym.sym){
			case SDLK_UP: yVel-= Floor_HEIGHT/2;break;
			case SDLK_DOWN:yVel +=Floor_HEIGHT/2;break;
			case SDLK_RIGHT:xVel += Floor_WIDTH/2;break;
			case SDLK_LEFT: xVel -= Floor_WIDTH/2;break;
		}
	}else if (event.type == SDL_KEYUP){
		switch(event.key.keysym.sym){
			case SDLK_UP: yVel+= Floor_HEIGHT/2;break;
			case SDLK_DOWN:yVel -=Floor_HEIGHT/2;break;
			case SDLK_RIGHT:xVel -= Floor_WIDTH/2;break;
			case SDLK_LEFT: xVel += Floor_WIDTH/2;break;
		}
	}*/
}
void Floor::move(){

}

