/*
William Francis
Corrigan Farley
Randy Tobias
*/

#include "ui.h"
#include "globals.h"

UI::UI()
{
    for (int i = 0; i<10; i++)
    {
	slot_area[i][0] = i * SLOT_WIDTH; //min x
	slot_area[i][1] = SCREEN_HEIGHT - SLOT_HEIGHT; //min y
	slot_area[i][2] = i * SLOT_WIDTH + SLOT_WIDTH; //max x
	slot_area[i][3] = SCREEN_HEIGHT; //max y
	slot_obj[i] = NULL; //ID of obj in slot i
    }
}

void UI::setSlotArea(int id, float xmin, float ymin, float xmax, float ymax)
{
	slot_area[id][0] = xmin;
	slot_area[id][1] = ymin;
	slot_area[id][2] = xmax;
	slot_area[id][3] = ymax;
}

float UI::getSlotMinX(int id)
{
	return slot_area[id][0];
}

float UI::getSlotMinY(int id)
{
	return slot_area[id][1];
}

float UI::getSlotMaxX(int id)
{
	return slot_area[id][2];
}

float UI::getSlotMaxY(int id)
{
	return slot_area[id][3];
}

//return -1 if mouse wasn't in a slot
int UI::getSlotNum(float mouseX, float mouseY)
{
    for (int i=0; i<10; i++)
    {
	if (mouseX >= slot_area[i][0] && mouseX <= slot_area[i][2] && mouseY >= slot_area[i][1] && mouseY <= slot_area[i][3]) 
	    return i;
    }
    
    return -1;
}

GameObject* UI::getSlotObj(int id)
{
	return slot_obj[id];
}

void UI::setSlotObj(int id, GameObject *obj)
{
	slot_obj[id] = obj;
}
/*
	void setSlot(int, float, float, float, float);
	float getSlotMinX(int);
	float getSlotMinY(int);
	float getSlotMaxX(int);
	float getSlotMaxY(int);
	int getSlotNum();
	int getSlotObjID(int);
	void setSlotObjID(int, int)
*/