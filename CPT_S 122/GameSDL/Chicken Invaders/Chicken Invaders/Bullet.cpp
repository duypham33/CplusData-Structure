

/*

	This file is to establish the definitions for all programmer-defined functions of Bullet class, aside from main ()

*/

#include "Bullet.h"

//Constructor
Bullet::Bullet(BulletDir dir)
{
	this->rect.x = 0;
	this->rect.y = 0;

	this->objectPtr = NULL;

	this->x_val = 0;
	this->y_val = 0;
	this->is_move = false;
	this->bullet_dir = dir;
}

//Destructor
Bullet::~Bullet()
{
	//Nothing
}


//Override Show() function of the parent class(BaseObject)
void Bullet::Show(SDL_Surface* des, TTF_Font* font, const int& fpcl)
{
	if (this->objectPtr)
		this->rect = SDLCommonFunc::ApplySurface(this->objectPtr, des, this->rect.x, this->rect.y);
}


//Override HandleMove() function of the parent class(BaseObject)
void Bullet::HandleMove(const int& trans_x, const int& trans_y, const int& x_border, const int& y_border, const int& n)
{
	if (this->x_val >= n)
	{
		this->rect.x -= (1 - int(this->bullet_dir)) * trans_x;
		this->x_val = 0;
	}
	else
		this->x_val++;

	this->rect.y -= trans_y;

	if (this->rect.x < 0 || this->rect.x > x_border || this->rect.y < 0 || this->rect.y > y_border)
		this->is_move = false;
}


//Setters and Getters

void Bullet::setIsMove(bool is_move)
{
	this->is_move = is_move;
}

bool Bullet::getIsMove() const
{
	return this->is_move;
}


void Bullet::setWidthHeight(const int& bullet_width, const int& bullet_height)
{
	this->rect.w = bullet_width;
	this->rect.h = bullet_height;
}
