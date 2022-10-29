
/*

    This file is to establish the definitions for all programmer-defined functions of Node Class, aside from main ()

*/

#include "Node.h"

//Function definitions

//Constructor
Node::Node(const string& newData)
{
    this->mData = newData;
    this->mpLeft = NULL;
    this->mpRight = NULL;
}


//Virtual destructor
Node::~Node()
{
    //When the BST is destroyed, all the nodes are deleted! 
}



//Setters
void Node::setData(const string& newData)
{
    this->mData = newData;
}

void Node::setLeftPtr(Node* const newLeftPtr)
{
    this->mpLeft = newLeftPtr;
}

void Node::setRightPtr(Node* const newRightPtr)
{
    this->mpRight = newRightPtr;
}


//Getters
string Node::getData() const
{
    return this->mData;
}

//Returns a reference to the pointers
Node*& Node::getLeftPtr() 
{
    return this->mpLeft;
}

Node*& Node::getRightPtr()
{
    return this->mpRight;
}
