
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:    PA 9: A Graphical Game or Application

      * Date:  Nov 30, 2021

      * Description: This program builds Chicken Invaders game with SDL 1.2. We apply SDL for graphic, sound, font, ...
	                 We apply inheritance and polymorphism to implement classes. The base class is BaseOject class. 
					 And the derived classes are Clips class, MainObject class, Bullet class, ThreatObject class, and TextObject class.
					 Besides, we also implement a Game class for wrapping the whole game process. 
*/


#include "Game.h"

int main(int arc, char* argv[])
{
	//Allocate space for the game (It costs only 4 bytes)
    Game* pGame = new Game;

	//Run the whole game
	if (!pGame->run())
		return 0;

	//Free up the space
	delete pGame;
	pGame = NULL;

	return 1;     //The program was successful
}