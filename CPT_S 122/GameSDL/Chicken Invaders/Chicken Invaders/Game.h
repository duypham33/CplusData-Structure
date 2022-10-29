
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Game class

*/

#ifndef GAME_H_   //Guard code
#define GAME_H_

#include "MainObject.h"
#include "ThreatObject.h"
#include "Clips.h"
#include "TextObject.h" 


//This class is for wrapping the whole game process.
class Game
{
public:
	//Default constructor
	Game();

	//Destructor
	~Game();

	//This function runs the whole a game
	int run();

private:
	//Data members
	MainObject* ship;    //The main object of the game (Space ship)  

	//////////////////////////////////////// Private Function \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	
	// Initialize SDL modes (library SDL, Window Screen Mode, font text mode, and audio mode)
	bool Init();

	//This function displays game menu and return a menu option got from the user
	int showMenu(SDL_Surface* des, TTF_Font* font);

	//This function displays the exhaust for the ship (main object)
	void makeExhaust(Clip* exhaust, int& frameExh);

	//This function makes the bullet for the ship (main object)
	void makeBullet();

	//This function handles threats move and collision with the main object and bullets
	void threatsActions(vector<ThreatObject*>& pThreats, int& Round, bool& isDamaged, TextObject*& pMainHP, int& numsDie, int& score,
		TextObject*& pScore, bool& isExplo, Clip*& explo, int& skillMoment, Bullet*& skillGift_ptr, int& newBulletMomt, Bullet*& bulGift_ptr);

	//This function displays the explosion as some threat dies
	void makeThreatExplo(Clip* explo, bool& isExplo, int& frameExplo);

	//This function displays the explosion as the main object lost
	void makeMainExplo(Clip* mExplo, bool& isMExplo, int& frameMExplo);

	//This function displays the main object being damaged as hit some threats or their bullets
	void damagedShip(bool& isDamaged, int& frameDam);

	//This function displays the skill gift
	void skillGift(Bullet* skillGift_ptr, bool& tookSkill);

	//This function displays the new bullet gift
	void bulletGift(Bullet* bulGift_ptr, bool& newBullet, bool& tookSkill);

	//This function checks for the hp gift and displays the hp gift
	void hpGift(Bullet* hp_ptr, bool& hpFlag, TextObject* pMainHP, const int& p);

	//This function creates user directions of how to play
	int tutorial(SDL_Surface* des);

	//This function resets necessary static variables for one game (Because we have a loop for game, so it is needed to reset them every loop)
	bool reset(bool& displayResult, bool& win);

	//This function displays the game result
	void result(bool& displayResult, int& Round, bool& win, Clip* mExplo, bool& isMExplo, int& score, TextObject*& resultText,
		       TextObject*& scoreText, TextObject*& returnText, TTF_Font* font1, TTF_Font* font2);
};




#endif