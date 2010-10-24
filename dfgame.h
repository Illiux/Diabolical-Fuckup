
void clean_up();
bool init();
bool init_GL();

class Floor{
private:
	//location
	float x;
	float y;

public:
	//initialize
	Floor();
	//handle keypresses
	void handle_input();
	//moves the Floor
	void move();
	//show the Floor on the screen
	void show();
};
/*
class Timer{
private:
	int startTicks;
	int pausedTicks;
	bool paused;
	bool stated;
public:
	Timer();
	void start();
	void stop();
	void pause();
	void unpause();
	int get_ticks();
	bool is_started();
	bool is_paused();
};
*/