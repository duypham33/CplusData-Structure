

/*

  This is the header file that stores standard library includes, #defined and function prototypes of BaseObject class

*/

#ifndef BASE_OBJECT_H_   //Guard code
#define BASE_OBJECT_H_

#include "CommonFunctions.h"


//This class has some basic properties of an object in the game

//Base Object Class
class BaseObject
{
public:
	//Default constructor
	BaseObject()
	{
		this->rect.x = 0;
		this->rect.y = 0;
		this->objectPtr = NULL;
	}

	//Destructor
	~BaseObject()
	{
		//Nothing		
	}

	//Load image of the object by calling LoadImage() function from SDLCommonFunc namespace
	bool LoadImg(const char* file_name, bool removeBMP, int redVal)
	{
		this->objectPtr = SDLCommonFunc::LoadImage(file_name, removeBMP, redVal);
		return (this->objectPtr != NULL);
	}

	//Pure virtual Show() function (All derived classes must override it)
	virtual void Show(SDL_Surface* des, TTF_Font* font = nullptr, const int& fpcl = 1) = 0;

	//Virtual HandleMove function (derived classes may override it)
	virtual void HandleMove(const int& trans_x, const int& trans_y, const int& x_border, const int& y_border)
	{		
		if (this->rect.x > 0 && this->rect.x < x_border && this->rect.y > 0 && this->rect.y < y_border)
		{
			this->rect.x -= trans_x;
			this->rect.y -= trans_y;
		}
	}

	//Setter
	void SetRect(const int& x, const int& y)
	{
		this->rect.x = x;
		this->rect.y = y;
	}

	//Getters
	SDL_Rect GetRect() const
	{
		return this->rect;
	}

	SDL_Surface* const GetObject()
	{
		return this->objectPtr;
	}

protected:
	SDL_Rect rect;
	SDL_Surface* objectPtr;
};



#endif