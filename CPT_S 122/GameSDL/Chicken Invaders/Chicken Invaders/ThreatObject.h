

/*

  This is the header file that stores standard library includes, #defined and function prototypes of Threat class

*/


#ifndef THREAT_OBJECT_H_   //Guard code
#define THREAT_OBJECT_H_

#include "BaseObject.h"
#include "Bullet.h"


static int NUM_THREATS = 30;    //The number of threats in the first round

const int THREAT_WIDTH = 85;      //The width of threat1 image
const int THREAT_HEIGHT = 72;     //The height of threat2 image
const int THREAT2_WIDTH = 95;     //The width of threat2 image
const int THREAT2_HEIGHT = 84;    //The height of threat2 image
const int BOSS_WIDTH = 280;       //The width of boss image
const int BOSS_HEIGHT = 285;      //The height of boss image
const int XMAS_BOSS_WIDTH = 380;  //The width of xmas boss image
const int XMAS_BOSS_HEIGHT = 296; //The height of xmas boss image

static double SPEED = 0.2;      //The speed of the threats
static int THREAT_HP = 3;       //The HP of the threats
static int THREAT_ATTACK = 1;   //The attack level of the threats

const int EGG_WIDTH = 14;             //The width of threats' bullet
const int EGG_HEIGHT = 18;            //The height of threats' bullet
const int LASER_WIDTH = 30;           //The width of threats' laser bullet
const int LASER_HEIGHT = 58;          //The height of threats' laser bullet
const int BLUE_LASER_WIDTH = 60;      //The width of threats' blue laser bullet
const int BLUE_LASER_HEIGHT = 134;    //The height of threats' blue laser bullet

static int BULLET_SPEED = 1;          //The bullet speed of threats
static int RECHARGE_TIME = 1000;      //The recharging time of bullets

static Mix_Chunk* CHICKEN_SOUND;    //For sound of threats



//Threat Class(An inheritant class from BaseOject class)
class ThreatObject : public BaseObject
{
public:
	//Constructor
	ThreatObject(const int& threat_object_width = THREAT_WIDTH, const int& threat_object_height = THREAT_HEIGHT, const double& speed = SPEED
		, const int& HP = THREAT_HP);

	//Destructor
	~ThreatObject();

	//Function for showing threats frame by frame
	void Show(SDL_Surface* des, TTF_Font* font = nullptr, const int& fpcl = 1);   //Override Show() function of the parent class(BaseObject)

	//Functions for movements
	void moveSteps();
	//Override HandleMove() function of the parent class(BaseObject)
	void HandleMove(const int& x_border, const int& y_border);
	void moveRandomly(const int& x_border, const int& y_border);

	//Getter
	Bullet* const getBulletPtr();
	//Setter 
	void setBulletPtr(Bullet* const newBulletPtr);

	//Make bullet
	void InitBullet(const int bullet_width = EGG_WIDTH, const int bullet_height = EGG_HEIGHT);
	void bulletMove(const int& trans_x, const int& trans_y, const int& x_border, const int& y_border, const int& rechargeTime = RECHARGE_TIME);
	void rechargeBullet();
	//Remove(Delete) the bullet when it has hit the main object, and then reset it if the threat is still alive
	void resetBullet();

	//Decrease and check the HP when the threat has been hit by main's bullets
	bool isAlive(const int& attackLevel = 1);

private:
	//Data members for image frame
	int curFrame;
	SDL_Rect clip[4];
	//Data members for movement
	double x_val;
	double y_val;
	int dir_x;
	int dir_y;
	double speed;
	bool random_move;
	int countX;
	int countY;
	//Data members for bullet
	Bullet* pBul;
	int rechargeTime;
	//Data members for HP
	int HP;
};



#endif