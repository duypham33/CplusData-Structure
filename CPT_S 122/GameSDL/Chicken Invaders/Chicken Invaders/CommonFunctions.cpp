
/*

    This file is to establish the definitions for all programmer-defined functions of SDLCommonFunc namespace, aside from main ()

*/

#include "CommonFunctions.h"


//Function definitions


//This function loads an image from a file path, and also apply Color Key to remove background of the image if needed
SDL_Surface* SDLCommonFunc::LoadImage(std::string filepath, bool removeBMP, int redVal)
{
    SDL_Surface* load_image = NULL;
    SDL_Surface* optimize_image = NULL;

    load_image = IMG_Load(filepath.c_str());

    if (load_image != NULL)
    {
        optimize_image = SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);
    }
    if (optimize_image && removeBMP)
    {
        //Using Color Key to remove background of object (The img has a highlight background with white color) 
        UINT32 color_key = SDL_MapRGB(optimize_image->format, redVal, 255, 255);
        SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
    }

    return optimize_image;
}


//This function apply a source surface to a destination surface
SDL_Rect SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);
    return offset;
}


//This function apply a source surface to a destination surface with a clip of multiple frames
void SDLCommonFunc::ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, clip, des, &offset);
}



//This function cleans the screen
void SDLCommonFunc::CleanUp(SDL_Surface* screen, SDL_Surface* bkground)
{
    SDL_FreeSurface(screen);
    SDL_FreeSurface(bkground);
}



//This function checks collisions between different objects
bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
    int left_a = object1.x;
    int right_a = object1.x + object1.w;
    int top_a = object1.y;
    int bottom_a = object1.y + object1.h;

    int left_b = object2.x;
    int right_b = object2.x + object2.w;
    int top_b = object2.y;
    int bottom_b = object2.y + object2.h;

    // Case 1: size object 1 < size object 2
    if (left_a > left_b && left_a < right_b)
        if (top_a > top_b && top_a < bottom_b)
            return true;

    if (left_a > left_b && left_a < right_b)
        if (bottom_a > top_b && bottom_a < bottom_b)
            return true;

    if (right_a > left_b && right_a < right_b)
        if (top_a > top_b && top_a < bottom_b)
            return true;

    if (right_a > left_b && right_a < right_b)
        if (bottom_a > top_b && bottom_a < bottom_b)
            return true;

    // Case 2: size object 1 < size object 2
    if (left_b > left_a && left_b < right_a)
        if (top_b > top_a && top_b < bottom_a)
            return true;

    if (left_b > left_a && left_b < right_a)
        if (bottom_b > top_a && bottom_b < bottom_a)
            return true;

    if (right_b > left_a && right_b < right_a)
        if (top_b > top_a && top_b < bottom_a)
            return true;

    if (right_b > left_a && right_b < right_a)
        if (bottom_b > top_a && bottom_b < bottom_a)
            return true;

    // Case 3: size object 1 = size object 2
    if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
        return true;

    return false;
}
