
/*

    This file is to establish the definitions for all programmer-defined functions of TransactionNode Class, aside from main ()

*/


#include "TransactionNode.h"

//Function definitions

//Constructor - invokes class Node’s constructor
TransactionNode::TransactionNode(const string& newData, const int& newUnits) : Node(newData)
{
    this->mUnits = newUnits;
}

//Destructor
TransactionNode::~TransactionNode()
{
    //When the BST is destroyed, all the nodes are deleted! 
}

//Setter
void TransactionNode::setUnits(const int& newUnits)
{
    this->mUnits = newUnits;
}
//Getter
int TransactionNode::getUnits() const
{
    return this->mUnits;
}

//Overrides the pure virtual printData() function in class Node
void TransactionNode::printData()
{
    cout << "Type: " << this->mData << ", the number of units: " << this->mUnits << endl;
}