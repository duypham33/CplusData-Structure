

/*

  This is the header file that stores standard library includes, #defined and function prototypes of SDLCommonFunc namespace

*/


#ifndef COMMON_FUNCTIONS_H_   //Guard code
#define COMMON_FUNCTIONS_H_

#include<iostream>
#include<Windows.h>      //Open the window
#include<SDL.h>          //SDL library
#include <SDL_image.h>   //Work with images
#include <SDL_mixer.h>   //Work with audio
#include <SDL_ttf.h>     //Work with font
#include <string>    

#undef main     //This is vital, cannot run the program without it



static SDL_Surface* screen = NULL;        //Global surface for screen 
static SDL_Surface* bkground = NULL;      //Global surface for background
static SDL_Surface* g_menu = NULL;        //Global surface for the game menu
static SDL_Event g_even;                  //Global event to keep track of the whole game events


const int SCREEN_WIDTH = 1000;    //The width of the main screen
const int SCREEN_HEIGHT = 750;    //The height of the main screen
const int SCREEN_BPP = 32;

static int MOUSE_X;    //Get x-posion of the mouse 
static int MOUSE_Y;    //Get y-posion of the mouse 


//These are commmon functions used during the program
namespace SDLCommonFunc    //Create a seperated namespace to avoid duplication
{
	//This function loads an image from a file path, and also apply Color Key to remove background of the image if needed
	SDL_Surface* LoadImage(std::string filepath, bool removeBMP, int redVal);
	//This function apply a source surface to a destination surface
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	//This function apply a source surface to a destination surface with a clip of multiple frames
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y);
	//This function cleans the screen
	void CleanUp(SDL_Surface* screen, SDL_Surface* bkground);
	//This function checks collisions between different objects
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}





#endif