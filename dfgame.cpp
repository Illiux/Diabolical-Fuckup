/*
William Francis
Corrigan Farley
Randy Tobias
*/

#include "dfgame.h"

Player* player;

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
						case 'e':
						
						break;
					}
				break;
			case SDL_MOUSEMOTION:             //mouse moved
			    //printf("Mouse motion x:%d, y:%d\n", event.motion.x, event.motion.y );
			    break;
			case SDL_MOUSEBUTTONUP:{           //mouse button pressed
			    printf("Mouse pressed x:%d, y:%d\n", event.button.x, event.button.y );
			    printf("Slot %d was clicked\n", ui->getSlotNum(event.motion.x, event.motion.y));
			    
			    //check for player collision to activate door
			    std::vector<Item*>* objects = level->getObjects();
			    std::vector<Item*>::iterator i;
			    for (i=(*objects).begin();i<(*objects).end();i++) {
			    if ((*i)->mouseOver(event.button.x,event.button.y)){ 
				if (player->singleCollide(*i)){
				    (*i)->use();
				}
			    }
			    }
			};
			    break; 
			case SDL_QUIT:			//'x' of Window clicked
			    exit ( 1 );
			    break;
			}
		}	
		glClear( GL_COLOR_BUFFER_BIT );

		level->draw();
		ui->draw();
		player->draw();
		
		SDL_GL_SwapBuffers();
		SDL_Delay(1);
	}

	return 0;

}

void DFGame::setLevel(Level* level)
{
	this->level = level;
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

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
    
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
		Texture *doorclosed = new 
Texture("images/door_closed.png");
		Texture *dooropen = new Texture("images/door_open.png");
		
		player = new Player(left,right,front);
		
		// Initialize some platforms
		Platform *floor = new Platform(0,450,FLOOR_WIDTH,FLOOR_HEIGHT,tex);
		Platform *thing = new Platform(500,250,FLOOR_WIDTH/3,FLOOR_HEIGHT,tex);

		// Door?
		Door *door1 = new Door(700,350,dooropen,doorclosed);
		Door *door2 = new Door(0,350,dooropen,doorclosed);
		door1->link(door2);

		// Create a level and add everything
		level = new Level();
		level->addPlatform(floor);
		level->addPlatform(thing);
		level->addObject(door1);

		Level *level2 = new Level();
		level2->addPlatform(floor);
		level2->addObject(door2);

		door2->setDest(level);
		door1->setDest(level2);

		// Set level on player
		player->setLevel(level);
}

bool DFGame::init_GL(){
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

	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//else
	return true;
}

bool DFGame::IsValid() {
	return valid;
}

