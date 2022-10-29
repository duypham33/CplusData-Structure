

#include "header.h"

#include "AmoObject.h"




SDL_Surface* SDLCommonFunc::LoadImage(std::string filepath)
{
	SDL_Surface* load_image = NULL;
	SDL_Surface* optimize_image = NULL;

	load_image = IMG_Load(filepath.c_str());

	if (load_image != NULL)
	{
		optimize_image = SDL_DisplayFormat(load_image);
		SDL_FreeSurface(load_image);
	}

	return optimize_image;
}



void SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(src, NULL, des, &offset);
}



void SDLCommonFunc::CleanUp(SDL_Surface* screen, SDL_Surface* bkground)
{
	SDL_FreeSurface(screen);
	SDL_FreeSurface(bkground);
}







//Base object 

BaseObject::BaseObject()
{
	rect_.x = 0;
	rect_.y = 0;
	object_ptr_ = NULL;
}


BaseObject::~BaseObject()
{
	;
}



bool BaseObject::LoadImg(const char* file_name)
{
	object_ptr_ = SDLCommonFunc::LoadImageW(file_name);

	if (object_ptr_ == NULL)
	{
		return false;
	}

	else
	{
		return true;
	}
}


void BaseObject::Show(SDL_Surface* des)
{
	if (object_ptr_ != NULL)
	{
		SDLCommonFunc::ApplySurface(object_ptr_, des, rect_.x, rect_.y);
	}
}




//Main object
MainObject::MainObject(int main_object_width, int main_object_height)
{
	rect_.x = 0;
	rect_.y = 0;
	rect_.w = main_object_width;
	rect_.h = main_object_height;

	object_ptr_ = NULL;

	x_val = 0;
	y_val = 0;
}


MainObject::~MainObject()
{
	;
}



void MainObject::HandleInputAction(SDL_Event events)
{
	if (events.type == SDL_KEYDOWN)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			//y_val -= rect_.h / 10;
			y_val -= 1;
			break;
		case SDLK_DOWN:
			//y_val += rect_.h / 10;
			y_val += 1;
			break;
		case SDLK_LEFT:
			//x_val -= rect_.w / 10;
			x_val -= 1;
			break;
		case SDLK_RIGHT:
			//x_val += rect_.w / 10;
			x_val += 1;
			break;

		default: break;
		}
	}

	else if (events.type == SDL_KEYUP)
	{
		switch (events.key.keysym.sym)
		{
		case SDLK_UP:
			//y_val += rect_.h / 3;
			y_val = 0;
			break;
		case SDLK_DOWN:
			//y_val -= rect_.h / 3;
			y_val = 0;
			break;
		case SDLK_LEFT:
			//x_val += rect_.w / 3;
			x_val = 0;
			break;
		case SDLK_RIGHT:
			//x_val -= rect_.w / 3;
			x_val = 0;
			break;
		default: break;
		}
	}

	else if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		AmoObject* amo_ptr = new AmoObject();

		if (events.type == SDL_BUTTON_LEFT)
		{
			amo_ptr->LoadImg("laser.png");
			amo_ptr->setWidthHeight(AMO_LASER_WIDTH, AMO_LASER_HEIGHT);
			amo_ptr->setAmoType(AmoObject::LASER);
		}

		else if (events.type == SDL_BUTTON_RIGHT)
		{
			amo_ptr->LoadImg("sphere.png");
			amo_ptr->setWidthHeight(AMO_SPHERE_WIDTH, AMO_SPHERE_HEIGHT);
			amo_ptr->setAmoType(AmoObject::SPHERE);
		}

		amo_ptr->SetRect(this->rect_.x + this->rect_.w, this->rect_.y + (this->rect_.h) / 2);
		amo_ptr->setIsMove(true);

		amo_list_.push_back(amo_ptr);
	}

	else if (events.type == SDL_MOUSEBUTTONUP)
	{
		
	}

	else
	{
		;
	}

}



void MainObject::HandleMove()
{
	rect_.x += x_val;
	if (rect_.x < 0 || rect_.x + rect_.w > SCREEN_WIDTH)
	{
		rect_.x -= x_val;
	}

	rect_.y += y_val;
	if (rect_.y < 0 || rect_.y + rect_.h > SCREEN_HEIGHT - 200)
	{
		rect_.y -= y_val;
	}
}




void MainObject::makeAmo()
{
	for (int i = 0; i < amo_list_.size(); ++i)
	{
		AmoObject* amo_ptr = amo_list_.at(i);

		if (amo_ptr != NULL)
		{
			if (amo_ptr->getIsMove() == true)
			{
				amo_ptr->Show(screen);
				amo_ptr->HandleMove(20, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			}

			else    //amo_ptr->getIsMove() == false
			{
				amo_list_.erase(amo_list_.begin() + i);

				delete amo_ptr;
				amo_ptr = NULL;
			}

		}
	}
}






//Amo Object
AmoObject::AmoObject()
{
	rect_.x = 0;
	rect_.y = 0;

	object_ptr_ = NULL;

	x_val = 0;
	y_val = 0;
	is_move = false;
	amo_type = NONE;
}


AmoObject::~AmoObject()
{
	;
}




void AmoObject::HandleMove(const int trans_x, const int trans_y, const int x_border, const int y_border)
{
	x_val = trans_x;
	y_val = trans_y;

	rect_.x += x_val;
	rect_.y += y_val;

	if (rect_.x > x_border || rect_.y > y_border)
	{
		is_move = false;
	}
}


