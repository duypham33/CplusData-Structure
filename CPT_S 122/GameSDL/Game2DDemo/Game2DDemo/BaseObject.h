
#ifndef BASE_OBJECT_H_   //Guard code
#define BASE_OBJECT_H_

#include "header.h"



//Base Object Class
class BaseObject
{
public:
	BaseObject();
	~BaseObject();
	bool LoadImg(const char* file_name);
	void Show(SDL_Surface* des);

	void SetRect(const int& x, const int& y)
	{
		rect_.x = x;
		rect_.y = y;
	}

	SDL_Rect GetRect() const
	{
		return rect_;
	}

	SDL_Surface* GetObject()
	{
		return object_ptr_;
	}



protected:
	SDL_Rect rect_;
	SDL_Surface* object_ptr_;

};








#endif
