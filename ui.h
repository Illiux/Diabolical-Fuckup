#ifndef _DFGAME_UI_H_
#define _DFGAME_UI_H_


#include "globals.h"

#define SLOT_WIDTH	50
#define SLOT_HEIGHT 	50


class UI
{
    private:
	int slot; //indicates which slot or zone was clicked
	float slot_area[10][4]; //holds coordinates of each slot_area
	int slot_obj_id[10]; //hold the ID number of onjects in the slot. -1 if slot empty
    public:
	UI();
	void setSlotArea(int, float, float, float, float);
	float getSlotMinX(int);
	float getSlotMinY(int);
	float getSlotMaxX(int);
	float getSlotMaxY(int);
	int getSlotNum();
	int getSlotObjID(int);
	void setSlotObjID(int, int);
};

#endif