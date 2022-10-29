

/*

	This file is to establish the definitions for all programmer-defined functions of Threat class, aside from main ()

*/

#include "ThreatObject.h"

//Constructor
ThreatObject::ThreatObject(const int& threat_object_width, const int& threat_object_height, const double& speed, const int& HP)
{
	//Data members for the size of apply surface
	this->rect.x = 0;
	this->rect.y = 0;
	this->rect.w = threat_object_width;
	this->rect.h = threat_object_height;
	this->objectPtr = NULL;
	//Data members for image frame
	this->curFrame = 0;

	for (int i = 0; i < 4; i++)
	{
		this->clip[i].x = threat_object_width * i;
		this->clip[i].y = 0;
		this->clip[i].w = threat_object_width;
		this->clip[i].h = threat_object_height;
	}
	//Data members for movement
	this->x_val = 0.0;
	this->y_val = 0.0;
	this->dir_x = 0;
	this->dir_y = 1;
	this->speed = speed;
	this->random_move = false;
	this->countX = 0;
	this->countY = 0;
	//Data members for bullet
	this->pBul = new Bullet;
	this->rechargeTime = 0;
	//Data members for HP
	this->HP = HP;
}


//Destructor
ThreatObject::~ThreatObject()
{
	//Delete the bullet pointer
	delete this->pBul;
	this->pBul = NULL;
}




//Function for showing threats frame by frame
void ThreatObject::Show(SDL_Surface* des, TTF_Font* font, const int& fpcl)   //Override Show() function of the parent class(BaseObject)
{
	//One clip is going to be formed by multiples frames, in order to make the movement not so quick.
	//And the number of frames for each clip, is calculated based on the speed of the threat type.
	//The more high speed is, the more less the number of frames is.
	int frameNums = (this->rect.h < 150) ? (32 * (1.0 / this->speed)) : 400;
	if (this->curFrame >= frameNums)
		this->curFrame = 0;
	SDLCommonFunc::ApplySurfaceClip(this->objectPtr, des, &(this->clip[this->curFrame / (frameNums / 4)]), this->rect.x, this->rect.y);

	this->curFrame++;
}



//Functions for movements

void ThreatObject::moveSteps()
{
	if (dir_x != 0)
	{
		if (this->x_val >= 1.0 || this->x_val <= -1.0)
			this->x_val = 0.0;
		this->x_val += dir_x * this->speed;
		if (this->x_val <= -1.0)
			this->x_val = -1.0;
	}

	if (dir_y != 0)
	{
		if (this->y_val >= 1.0 || this->y_val <= -1.0)
			this->y_val = 0.0;
		this->y_val += dir_y * this->speed;
		if (this->y_val <= -1.0)
			this->y_val = -1.0;
	}
}

//Override HandleMove() function of the parent class(BaseObject)
void ThreatObject::HandleMove(const int& x_border, const int& y_border)
{
	if (!this->random_move)
	{
		if (x_val * x_val >= 1.0)
			this->rect.x += this->x_val;
		this->rect.y += this->y_val;

		if (this->rect.y + this->rect.h >= y_border)
		{
			this->dir_y = 0;
			this->y_val = 0.0;
			this->dir_x = (this->rect.x <= SCREEN_WIDTH / 2) ? 1 : -1;
			this->rect.y = y_border - this->rect.h - 5;
		}

		if (this->rect.x + this->rect.w >= x_border || this->rect.x <= 0)
		{
			if (this->rect.x <= 0)
				this->rect.x += 5;
			else
				this->rect.x = x_border - this->rect.w - 2;
			this->x_val = 0.0;
			this->dir_x *= -1;
			this->random_move = true;
			this->dir_y = -1;
			this->y_val = 0.0;
			this->countX = rand() % 100 + 400;
			this->countY = rand() % 100 + 200;
		}
	}

	else
		this->moveRandomly(x_border, y_border);
}



void ThreatObject::moveRandomly(const int& x_border, const int& y_border)
{
	if (x_val * x_val >= 1.0)
	{
		this->rect.x += this->x_val;
		this->countX--;

		if (this->countX <= 0)
		{
			this->countX = rand() % 100 + 400;
			this->dir_x *= -1;
		}
	}

	if (y_val * y_val >= 1.0)
	{
		this->rect.y += this->y_val;
		this->countY--;

		if (this->countY <= 0)
		{
			this->countY = rand() % 100 + 200;
			this->dir_y *= -1;
		}
	}

	if (this->rect.x + this->rect.w >= x_border || this->rect.x <= 0)
	{
		if (this->rect.x + this->rect.w >= x_border)
			this->rect.x = x_border - this->rect.w - 5;
		if (this->rect.x <= 0)
			this->rect.x += 5;
		this->dir_x *= -1;
	}


	if (this->rect.y + this->rect.h >= y_border || this->rect.y <= 0)
	{
		if (this->rect.y + this->rect.h >= y_border)
			this->rect.y = y_border - this->rect.h - 5;
		if (this->rect.y <= 0)
			this->rect.y += 5;
		this->dir_y *= -1;
	}
}


//Getter
Bullet* const ThreatObject::getBulletPtr()
{
	return this->pBul;
}

//Setter 
void ThreatObject::setBulletPtr(Bullet* const newBulletPtr)
{
	this->pBul = newBulletPtr;
}

//Make bullet
void ThreatObject::InitBullet(const int bullet_width, const int bullet_height)
{
	bool ret = false;
	if (this->rect.w == THREAT_WIDTH)
		ret = this->pBul->LoadImg("egg1.png", true, 0);
	else if (this->rect.w == THREAT2_WIDTH)
		ret = this->pBul->LoadImg("green laser.png", true, 255);
	else
		ret = this->pBul->LoadImg("blue laser.png", true, 0);

	if (ret)
	{
		Bullet* bulPtr = this->pBul;
		this->pBul->setWidthHeight(bullet_width, bullet_height);
		this->pBul->SetRect(this->rect.x + this->rect.w / 2, this->rect.y + 2);
		this->rechargeTime = rand() % 5000 + 1000;
	}
}


void ThreatObject::rechargeBullet()
{
	this->rechargeTime--;
}


void ThreatObject::bulletMove(const int& trans_x, const int& trans_y, const int& x_border, const int& y_border, const int& rechargeTime)
{
	if (this->pBul->getIsMove())
		this->pBul->HandleMove(trans_x, -trans_y, x_border, y_border);

	else
	{
		this->rechargeBullet();
		if (this->rechargeTime <= 0)
		{
			this->pBul->setIsMove(true);
			this->pBul->SetRect(this->rect.x + this->rect.w / 2, this->rect.y + this->rect.h + 2);
			this->rechargeTime = rechargeTime;
		}
	}
}


//Remove(Delete) the bullet when it has hit the main object, and then reset it if the threat is still alive
void ThreatObject::resetBullet()
{
	//Delete the bullet pointer
	delete this->pBul;
	this->pBul = NULL;
}

//Decrease and check the HP when the threat has been hit by main's bullets
bool ThreatObject::isAlive(const int& attackLevel)
{
	//Decrease the HP as the threat has been hit by main's bullets
	this->HP -= attackLevel;
	return (this->HP > 0);   //Return true if the threat still has HP
}