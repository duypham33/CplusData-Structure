
#ifndef AMO_OBJECT_H_   //Guard code
#define AMO_OBJECT_H_

#include "header.h"
#include "BaseObject.h"

const int AMO_LASER_WIDTH = 35;
const int AMO_LASER_HEIGHT = 5;

const int AMO_SPHERE_WIDTH = 10;
const int AMO_SPHERE_HEIGHT = 10;




//Amo object Class(Inheritant Class)
class AmoObject : public BaseObject
{
public:
	enum AmoType
	{
		NONE = 0,
		LASER,
		SPHERE
	};

	AmoObject();
	~AmoObject();

	//void HandleInputAction(SDL_Event events);
	void HandleMove(const int trans_x, const int trans_y, const int x_border, const int y_border);



	void setAmoType(unsigned int amo_type)
	{
		this->amo_type = amo_type;
	}
	unsigned int getAmoType() const
	{
		return amo_type;
	}

	void setIsMove(bool is_move)
	{
		this->is_move = is_move;
	}
	bool getIsMove() const
	{
		return is_move;
	}

	void setWidthHeight(const int amo_width, const int amo_height)
	{
		rect_.w = amo_width;
		rect_.h = amo_height;
	}

private:
	int x_val;
	int y_val;
	bool is_move;
	unsigned int amo_type;
};






#endif
