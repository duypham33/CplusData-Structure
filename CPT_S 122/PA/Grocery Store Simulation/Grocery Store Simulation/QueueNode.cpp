
/*

    This file is to establish the definitions for all programmer-defined functions of QueueNode Class, aside from main ()

*/


#include "QueueNode.h"

//Function definitions

//Constructor
QueueNode::QueueNode(const Data& newData)
{
    //Allocate space for the data pointer
    this->pData = new Data;  //A default constructor, not the special one
    *(this->pData) = newData;

    this->pNext = NULL;
}


//Destructor
QueueNode::~QueueNode()
{
    //Free up the memory
    delete this->pData;
    this->pNext = NULL;
}


//Setters
void QueueNode::setNextPtr(QueueNode* const newNextPtr)
{
    this->pNext = newNextPtr;
}


//Getters
Data QueueNode::getData() const
{
    return *(this->pData);
}


QueueNode* QueueNode::getNextPtr() const
{
    return this->pNext;
}