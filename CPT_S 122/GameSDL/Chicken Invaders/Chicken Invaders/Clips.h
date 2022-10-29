
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Clips class

*/


#ifndef CLIPS_H_   //Guard code
#define CLIPS_H_

#include "BaseObject.h"

const int EXPLO_WIDTH = 153;         //The width of explosion image
const int EXPLO_HEIGHT = 153;        //The height of explosion image
const int THREAT_EXPLO_NUMS = 56;    //The number of frames in the explosion image

const int MAIN_EXPLO_SIZE = 200;     //The size of main-explosion image
const int MAIN_EXPLO_NUMS = 9;       //The number of frames in the main-explosion image

const int EXHAUST_WIDTH = 100;       //The width of exhaust image
const int EXHAUST_HEIGHT = 64;       //The height of exhaust image
const int EXHAUST_CLIPS_NUMS = 8;    //The number of frames in the exhaust image

static Mix_Chunk* EXPLO_SOUND;       //A Mix_Chunk variable for the sound of explosion


//This class is to load an object with multiple frames (Used to load exhaust object, explosion object,...)

//Clip Class(An inheritant class from BaseOject class)
class Clip : public BaseObject
{
public:
	enum DIR    //The direction of loading image
	{
		VERTICAL = 0,
		HORIZONTAL
	};

	//Constructor 
	Clip(const int& objectWidth, const int& objectHeight, const int& clipNums, DIR direction = HORIZONTAL)
	{
		this->curFrame = 0;

		this->clipNums = clipNums;
		this->clip = new SDL_Rect[this->clipNums];

		int xval = 1, yval = 0;
		if (direction == VERTICAL)
			xval = 0, yval = 1;
		for (int i = 0; i < clipNums; i++)
		{
			this->clip[i].x = objectWidth * (i * xval);
			this->clip[i].y = objectHeight * (i * yval);
			this->clip[i].w = objectWidth;
			this->clip[i].h = objectHeight;
		}
	}

	//Destructor
	~Clip()
	{
		//Free up memory
		delete[]this->clip;
	}

	//Setter
	void setFrame(const int& newFrame)
	{
		this->curFrame = newFrame;
	}

	//Function for showing the object frame by frame
	void Show(SDL_Surface* des, TTF_Font* font = nullptr, const int& fpcl = 1)   //Override Show() function of the parent class(BaseObject)
	{
		if (this->curFrame >= this->clipNums * fpcl)
			this->curFrame = 0;
		SDLCommonFunc::ApplySurfaceClip(this->objectPtr, des, &(this->clip[this->curFrame / fpcl]), this->rect.x, this->rect.y);
	}

private:
	int curFrame;     //The current frame
	SDL_Rect* clip;   //An array of frames
	int clipNums;     //The number of frames
};


#endif