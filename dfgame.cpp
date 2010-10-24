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
	
	if (!IsValid()) {
		return 1;
	}

	float dTime=0.0;
	int thisTime=0;
	int lastTime=0;

	while (quit == false){
		thisTime = SDL_GetTicks();
		dTime = (float)(thisTime - lastTime) / 1000;
		lastTime = thisTime;

		player->doMovement(dTime);

		//printf("%f %f\n",player->getX(),player->getY());

		while( SDL_PollEvent( &event ) )
		{
			switch (event.type) {		//check the event type
			case SDL_KEYDOWN:			//if a key has been pressed
			    key = SDL_GetKeyName(event.key.keysym.sym);
			  switch ( event.key.keysym.sym)
			    {
				case SDLK_ESCAPE: 	//quit if 'ESC' pressed
				    quit = true;
				    break;
				case 'a':	 	//move player left if 'a'  pressed
				    player->moveLeft();
				    break;
				case 'd': 		//move player right if 'd' is pressed
				    player->moveRight();
				    break;
				case 'w':		// move player up if 'w' is pressed
				    player->moveUp();
				    break;
				case 's':	 	// move player down if 's' is pressed
				    player->moveDown();
				    break;
			    }
			    break;
			case SDL_KEYUP:
			  key = SDL_GetKeyName(event.key.keysym.sym);
			  switch ( event.key.keysym.sym)
			    {
						case 'a':
						player->stopLeft();
						break;
						case 'd':
						player->stopRight();
						break;
					}
				break;
			case SDL_MOUSEMOTION:             //mouse moved
			    //printf("Mouse motion x:%d, y:%d\n", event.motion.x, event.motion.y );
			    break;
			case SDL_MOUSEBUTTONUP:           //mouse button pressed
			    printf("Mouse pressed x:%d, y:%d\n", event.button.x, event.button.y );
			    printf("Slot %d was clicked\n", ui->getSlotNum(event.motion.x, event.motion.y));
			    break; 
			case SDL_QUIT:			//'x' of Window clicked
			    exit ( 1 );
			    break;
			}
		}	
		glClear( GL_COLOR_BUFFER_BIT );

		level->draw();
		ui->draw();
		
		SDL_GL_SwapBuffers();
		SDL_Delay(1);
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

		ui = new UI();

		// Initialize a texture
		Texture *front = new Texture("images/Tesla.png");
		Texture *left = new Texture("images/Tesla_left.png");
		Texture *right = new Texture("images/Tesla_right.png");
		Texture *tex = new Texture("images/greybrick.png");
	
		player = new Player(left,right,front);
		
		// Initialize some platforms
		Platform *floor = new Platform(0,450,FLOOR_WIDTH,FLOOR_HEIGHT,tex);
		Platform *thing = new Platform(500,250,FLOOR_WIDTH/3,FLOOR_HEIGHT,tex);

		// Create a level and add everything
		level = new Level();
		level->addPlatform(floor);
		level->addPlatform(thing);
		level->addObject(player);

		// Set level on player
		player->setLevel(level);
}

bool DFGame::init_GL(){
	glEnable( GL_TEXTURE_2D );
	//clear color
	glClearColor(0,0,0,0);

	//set projection
	glMatrixMode( GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,SCREEN_WIDTH,SCREEN_HEIGHT,0,-1,1);

	glClear( GL_COLOR_BUFFER_BIT );

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

