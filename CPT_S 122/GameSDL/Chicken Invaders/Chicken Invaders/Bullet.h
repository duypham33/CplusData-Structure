
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Bullet class

*/

#ifndef BULLET_H_   //Guard code
#define BULLET_H_

#include "BaseObject.h"

const int BULLET_WIDTH = 18;     //The width of bullet image
const int BULLET_HEIGHT = 18;    //The width of height image

const int BULLET_SPHERE_WIDTH = 10;    //The width of sphere-bullet image
const int BULLET_SPHERE_HEIGHT = 10;   //The width of sphere-bullet image

const int SKILL1_SIZE = 57;    //The size of skill gift

static Mix_Chunk* BULLET_SOUND;  //For sound of shooting a bullet


//Bullet Class(An inheritant class from BaseOject class)
class Bullet : public BaseObject
{
public:
	enum BulletDir   //The direction of bullet
	{
		LEFT = 0,
		STRAIGHT,
		RIGHT
	};

	//Constructor
	Bullet(BulletDir dir = STRAIGHT);

	//Destructor
	~Bullet();

	//Override Show() function of the parent class(BaseObject)
	void Show(SDL_Surface* des, TTF_Font* font = nullptr, const int& fpcl = 1);

	//Override HandleMove() function of the parent class(BaseObject)
	void HandleMove(const int& trans_x, const int& trans_y, const int& x_border, const int& y_border, const int& n = 0);

	//Setters and Getters
	void setIsMove(bool is_move);
	bool getIsMove() const;
	void setWidthHeight(const int& bullet_width, const int& bullet_height);

private:
	int x_val;
	int y_val;
	bool is_move;
	BulletDir bullet_dir;
};


#endif