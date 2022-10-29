
/*

  This is the header file that stores standard library includes, #defined and function prototypes and definitions of BSTNode Class

*/


#ifndef BST_NODE_H   //guard code

#define BST_NODE_H


#include <iostream>  //Neccessary to print out the screen 

using std::cin;
using std::cout;
using std::endl;



//This is a template class for BST node. It contains two different data types representing an English text character 
// and the corresponding Morse code characters for it. Besides, there are also two child pointers left and right.
template <typename T1, typename T2>
class BSTNode
{
public:
	//Default constructor
	BSTNode();

	//Constructor
	BSTNode(const T1& newSymbol, const T2& newMorseCode);

	//Destructor
	~BSTNode();    

	//Setters
	void setData(const T1& newSymbol, const T2& newMorseCode);
	void setLeftPtr(BSTNode<T1, T2>* const newLeftPtr);
	void setRightPtr(BSTNode<T1, T2>* const newRightPtr);

	//Getters
	T1 getSymbol() const;
	T2 getMorseCode() const;
	BSTNode<T1, T2>* getLeftPtr() const;
	BSTNode<T1, T2>* getRightPtr() const;

private:
	T1 mSymbol;
	T2 mMorseCode;
	BSTNode<T1, T2>* mpLeft;
	BSTNode<T1, T2>* mpRight;
};



//Member functions definitions

//Default constructor
template <typename T1, typename T2>
BSTNode<T1, T2>::BSTNode()
{
	this->mpLeft = NULL;
	this->mpRight = NULL;
}


//Constructor
template <typename T1, typename T2>
BSTNode<T1, T2>::BSTNode(const T1& newSymbol, const T2& newMorseCode)
{
	this->mSymbol = newSymbol;
	this->mMorseCode = newMorseCode;
	this->mpLeft = NULL;
	this->mpRight = NULL;
}


//Destructor
template <typename T1, typename T2>
BSTNode<T1, T2>::~BSTNode()
{
	//All the nodes would be destroyed when destructor of BST class is invoked!
}




//Setters
template <typename T1, typename T2>
void BSTNode<T1, T2>::setData(const T1& newSymbol, const T2& newMorseCode)
{
	this->mSymbol = newSymbol;
	this->mMorseCode = newMorseCode;
}

template <typename T1, typename T2>
void BSTNode<T1, T2>::setLeftPtr(BSTNode<T1, T2>* const newLeftPtr)
{
	this->mpLeft = newLeftPtr;
}

template <typename T1, typename T2>
void BSTNode<T1, T2>::setRightPtr(BSTNode<T1, T2>* const newRightPtr)
{
	this->mpRight = newRightPtr;
}



//Getters
template <typename T1, typename T2>
T1 BSTNode<T1, T2>::getSymbol() const
{
	return this->mSymbol;
}

template <typename T1, typename T2>
T2 BSTNode<T1, T2>::getMorseCode() const
{
	return this->mMorseCode;
}

template <typename T1, typename T2>
BSTNode<T1, T2>* BSTNode<T1, T2>::getLeftPtr() const
{
	return this->mpLeft;
}

template <typename T1, typename T2>
BSTNode<T1, T2>* BSTNode<T1, T2>::getRightPtr() const
{
	return this->mpRight;
}





#endif