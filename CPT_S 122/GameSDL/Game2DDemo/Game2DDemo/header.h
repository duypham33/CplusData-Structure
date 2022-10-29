
#ifndef HEADER_H_   //Guard code
#define HEADER_H_

#include<Windows.h>
#include <string>
#include<SDL.h>
#include <SDL_image.h>
#include<vector>


#include "AmoObject.h"
#include "BaseObject.h"

#undef main 



const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;


const int HUMAN_OBJECT_WIDTH = 64;
const int HUMAN_OBJECT_HEIGHT = 91;

const int PLANE_OBJECT_WIDTH = 80;
const int PLANE_OBJECT_HEIGHT = 46;



static SDL_Surface* screen = NULL;
static SDL_Surface* bkground = NULL;
static SDL_Event g_even;




namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string filepath);
	void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void CleanUp(SDL_Surface* screen, SDL_Surface* bkground);
}






//Main object Class(Inheritant Class)
class MainObject : public BaseObject
{
public:
	MainObject(int main_object_width, int main_object_height);
	~MainObject();

	void HandleInputAction(SDL_Event events);
	void HandleMove();

	void setAmoList(std::vector<AmoObject*> amo_list)
	{
		amo_list_ = amo_list;
	}
	std::vector<AmoObject*> getAmoList () const
	{
		return amo_list_;
	}

	void makeAmo();

private:
	int x_val;
	int y_val;

	std::vector<AmoObject*> amo_list_;
};








#endif 



