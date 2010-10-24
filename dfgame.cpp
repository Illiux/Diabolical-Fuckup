/*
William Francis
Corrigan Farley
Randy Tobias
*/

#include "dfgame.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_opengl.h"

#define SCREEN_WIDTH			800
#define SCREEN_HEIGHT			600
#define SCREEN_BPP				32
#define Floor_HEIGHT			50
#define Floor_WIDTH				800
#define fps						60

SDL_Event event;

int main(int argc, char** argv){
	bool quit = false;

	if(init() == false){
		return 1;
	}
	Floor Floor;
	while (quit == false){
		//fps.start();
		//While there are events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle key presses
            Floor.handle_input();
            
            //Handle user quit
            if( event.type == SDL_QUIT )
            {
                quit = true;
            }
        }
	    
        //Move the Floor
        Floor.move();
	    
        //Clear the screen
        glClear( GL_COLOR_BUFFER_BIT );
	    
        //Show the Floor
        Floor.show();
	    
        //Update screen
        SDL_GL_SwapBuffers();
	    /*
        //Cap the frame rate
        if( fps.get_ticks() < 1000 / fps )
        {
            SDL_Delay( ( 1000 / fps ) - fps.get_ticks() );
        }
		*/
    }

	return 0;
}

bool init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        return false;    
    }
    
    //Create Window
    if( SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_OPENGL ) == NULL )
    {
        return false;
    }
    
    //Initialize OpenGL
    if( init_GL() == false )
    {
        return false;    
    }
    
    //Set caption
    SDL_WM_SetCaption( "Diabolical Fuckup", NULL );
    
    return true;    
}

bool init_GL(){
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

void Floor::show(){
	//move to offset

	glTranslatef(x,y,0);

	//start Quad
	glBegin(GL_QUADS);
		glColor4f(1.0,1.0,1.0,1.0);

		glVertex3f(0,0,0);
		glVertex3f(Floor_WIDTH,0,0);
		glVertex3f(Floor_WIDTH,Floor_HEIGHT,0);
		glVertex3f(0,Floor_HEIGHT,0);
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
void clean_up(){
	SDL_Quit();
}

