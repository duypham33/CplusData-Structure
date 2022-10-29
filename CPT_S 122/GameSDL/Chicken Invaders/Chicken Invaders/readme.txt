
========================== Intro ==========================
* Programmer: Duy Pham
  Teammate: Guangbei

* Class: CptS 122, Fall 2021; Section 01; Lab Section 06

* Programming Assignment:    PA 9: A Graphical Game or Application

* Programming Language:   C++ with SDL 1.2

* Date:  Nov 30, 2021

* Game: Chicken Invaders

* Demonstration Video: https://drive.google.com/file/d/1EynygJKP-qJ1QsVuI7RxM95M0nyJcvLc/view?usp=sharing


========================== Description ==========================
This program builds Chicken Invaders game with SDL 1.2. 
It applies SDL_image, SDL_mixer, and SDL_ttf for graphic, sound, font, ...
It applies inheritance and polymorphism to implement classes. 
The base class is BaseOject class. It has some basic properties of loading an object image in the game.
And the derived classes are Clips class, MainObject class, Bullet class, ThreatObject class, and TextObject class.
Each of them have different properties and methods of loading image, movement, and others.				 
Besides, we also implement a Game class for wrapping the whole game process. 

The player is going to control a space ship by mouse motion. Fight and destroy many types of chicken
by shooting bullet to them. Besides, there are some gifts during the game for the ship.
In total, there are three rounds in the game, the difficult level is increased over rounds.

I hope you enjoy the game!