
/*

  This is the header file that stores standard library includes, #defined and function prototypes of MainObject class

*/


#ifndef MAIN_OBJECT_H_   //Guard code
#define MAIN_OBJECT_H_

#include "Bullet.h"
#include <vector>    //Neccessary for an array of bullets

using std::vector;

const int MAIN_OBJECT_WIDTH = 100;    //The width of main-object image
const int MAIN_OBJECT_HEIGHT = 100;   //The height of main-object image
const int START_XPOS = (SCREEN_WIDTH - MAIN_OBJECT_WIDTH) / 2;     //The x-position of the starting point for main object
const int START_YPOS = SCREEN_HEIGHT - MAIN_OBJECT_HEIGHT - 10;    //The y-position of the starting point for main object

static int BULLET_MAIN_SPEED = 1;   //The bullet speed of the main object
static int MAIN_ATTACK = 1;         //The attack level of the main object

static Mix_Chunk* DAMAGED_SOUND;    //For sound of being damaged
static Mix_Chunk* VICTORY_SOUND;    //For sound of victory

static vector<Bullet*> BulletList;    //The bullet array of the main object 


//Main object Class(An inheritant class from BaseObject class)
class MainObject : public BaseObject
{
public:
	//Constructor
	MainObject(const int& main_object_width = MAIN_OBJECT_WIDTH, const int& main_object_height = MAIN_OBJECT_HEIGHT);

	//Destructor
	~MainObject();

	//void HandleInputAction2(SDL_Event events);
	//void HandleMove();

	//Setters
	void setFrame(const int& newFrame);
	void setHP(const int& newHP);
	//Getter 
	int getHP() const;

	//Function for showing the explosion frame by frame
	void Show(SDL_Surface* des, TTF_Font* font = nullptr, const int& fpcl = 1);   //Override Show() function of the parent class(BaseObject)

	//Override HandleMove() function of the parent class(BaseObject)
	void HandleMove(SDL_Event events);

	//Update the HP of the main object 
	void updateHP(const int& change);

private:
	//Data members for image frame
	int curFrame;
	SDL_Rect clip[4];
	//Data member for HP
	int HP;
};



#endif