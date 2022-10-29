
/*

	This file is to establish the definitions for all programmer-defined functions of TextObject class, aside from main ()

*/


#include "TextObject.h"

//Constructor
TextObject::TextObject(const int& posX, const int& posY, const string& newText)
{
	this->rect.x = posX;
	this->rect.y = posY;
	this->mText = newText;
	this->mColor = { 255, 255, 255 };  //Initialize text color as white
}

//Destructor
TextObject::~TextObject()
{
	//Nothing
}

//Setters
void TextObject::setText(const string& newText)
{
	this->mText = newText;
}

void TextObject::setColor(const int& colorType)
{
	if (colorType == 0)
		this->mColor = { 255,255,255 };
	else if (colorType == 1)
		this->mColor = { 255,0,0 };
	else
		this->mColor = { 0,255,0 };
}


//Override Show() function of the parent class(BaseObject)
void TextObject::Show(SDL_Surface* des, TTF_Font* font, const int& fpcl)
{
	this->objectPtr = TTF_RenderText_Solid(font, this->mText.c_str(), this->mColor);
	if (this->objectPtr)
		this->rect = SDLCommonFunc::ApplySurface(this->objectPtr, des, this->rect.x, this->rect.y);
}