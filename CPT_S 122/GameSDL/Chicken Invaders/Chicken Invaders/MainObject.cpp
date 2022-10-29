

/*

	This file is to establish the definitions for all programmer-defined functions of MainObject class, aside from main ()

*/

#include "MainObject.h"


//Constructor
MainObject::MainObject(const int& main_object_width, const int& main_object_height)
{
	//Data members for the size of apply surface
	this->rect.x = 0;
	this->rect.y = 0;
	this->rect.w = main_object_width;
	this->rect.h = main_object_height;

	this->objectPtr = NULL;

	//Data members for image frame
	this->curFrame = 0;

	for (int i = 0; i < 4; i++)
	{
		this->clip[i].x = MAIN_OBJECT_WIDTH * i;
		this->clip[i].y = 0;
		this->clip[i].w = MAIN_OBJECT_WIDTH;
		this->clip[i].h = MAIN_OBJECT_HEIGHT;
	}

	
	//Data member for HP
	this->HP = 100;
}

//Destructor
MainObject::~MainObject()
{
	//Nothing
}



//Setters
void MainObject::setFrame(const int& newFrame)
{
	this->curFrame = newFrame;
}

void MainObject::setHP(const int& newHP)
{
	this->HP = newHP;
}

//Getter 
int MainObject::getHP() const
{
	return this->HP;
}


//Function for showing the explosion frame by frame
void MainObject::Show(SDL_Surface* des, TTF_Font* font, const int& fpcl)   //Override Show() function of the parent class(BaseObject)
{
	if (this->curFrame > 90)
		this->curFrame = 0;

	int clipIndex = 0;
	if (this->curFrame > 0 && this->curFrame < 91)
		clipIndex = this->curFrame / 31 + 1;
	SDLCommonFunc::ApplySurfaceClip(this->objectPtr, des, &(this->clip[clipIndex]), this->rect.x, this->rect.y);
}


//Override HandleMove() function of the parent class(BaseObject)
void MainObject::HandleMove(SDL_Event events)
{
	if (events.type == SDL_MOUSEMOTION)   //The mouse motion 
	{
		int x = events.motion.x;
		int y = events.motion.y;

		int speedX = (abs(x - this->rect.x) / 50 > 1) ? abs(x - this->rect.x) / 50 : 1;
		int speedY = (abs(y - this->rect.y) / 50 > 1) ? abs(y - this->rect.y) / 50 : 1;
		int newX = (abs(x - this->rect.x) < 50) ? (x - this->rect.x) : 50;
		int newY = (abs(y - this->rect.y) < 50) ? (y - this->rect.y) : 50;

		if (x > MOUSE_X)
		{
			if (x < this->rect.x + this->rect.w / 2 || this->rect.x + this->rect.w >= SCREEN_WIDTH)
				this->rect.x += 0;
			else
				this->rect.x += abs(x - this->rect.x) / 30 + 1;
		}

		else if (x < MOUSE_X)
		{
			if (x > this->rect.x + this->rect.w / 2 || this->rect.x <= 0)
				this->rect.x -= 0;
			else
				this->rect.x -= abs(x - this->rect.x) / 30 + 1;
		}

		if (y > MOUSE_Y)
		{
			if (y < this->rect.y || this->rect.y + this->rect.h > SCREEN_HEIGHT - 5)
				this->rect.y += 0;
			else
				this->rect.y += abs(x - this->rect.y) / 30 + 1;
		}

		else if (y < MOUSE_Y)
		{
			if (y > this->rect.y || this->rect.y <= 0)
				this->rect.y -= 0;
			else
				this->rect.y -= abs(x - this->rect.y) / 30 + 1;
		}

		MOUSE_X = x;
		MOUSE_Y = y;
	}
}



//Update the HP of the main object
void MainObject::updateHP(const int& change)
{
	this->HP += change;
	if (this->HP < 0)
		this->HP = 0;
}
