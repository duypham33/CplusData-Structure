#pragma once


#include "Mammal.h"


class Dog : public Mammal
{
public:
	Dog()
	{
		cout << "Dog constructor..." << endl;
	}

	~Dog()
	{
		cout << "Dog destructor..." << endl;
	}

	void Move() const
	{
		cout << "Dog moves a step!" << endl;
	}

	void Speak() const
	{
		cout << "What does a dog speak? Woof!" << endl;
	}
};



class Cat : public Mammal
{
public:
	Cat()
	{
		cout << "Cat constructor..." << endl;
	}

	~Cat()
	{
		cout << "Cat destructor..." << endl;
	}

	void Move() const
	{
		cout << "Cat moves a step!" << endl;
	}

	void Speak() const
	{
		cout << "What does a cat speak? Meowl!" << endl;
	}
};



class Horse : public Mammal
{
public:
	Horse()
	{
		cout << "Horse constructor..." << endl;
	}

	~Horse()
	{
		cout << "Horse destructor..." << endl;
	}

	void Move() const
	{
		cout << "Horse moves a step!" << endl;
	}

	void Speak() const
	{
		cout << "What does a horse speak? Neighl!" << endl;
	}
};


class GuineaPig : public Mammal
{
public:
	GuineaPig()
	{
		cout << "Guinea pig constructor..." << endl;
	}

	~GuineaPig()
	{
		cout << "Guinea pig destructor..." << endl;
	}

	void Move() const
	{
		cout << "Guinea pig moves a step!" << endl;
	}

	void Speak() const
	{
		cout << "What does a guinea pig speak? Weep weep!" << endl;
	}
};