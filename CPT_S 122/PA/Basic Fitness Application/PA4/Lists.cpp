
/*

    This file is to establish the definitions for all programmer-defined functions of ListNode and List classes, aside from main ()

*/

#include "Lists.h"


//List for weekly diet plan

//Constructor
ListNode::ListNode(dietNode* const newHeadPtr, dietNode* const newTailPtr)
{
    this->mpHead = newHeadPtr;
    this->mpTail = newTailPtr;
}


//Destructor
ListNode::~ListNode()
{
    delete mpHead;
    delete mpTail;
}


//Getters
dietNode* ListNode::getHeadPtr() const
{
    return this->mpHead;
}



//This function inserts a new node of the given plan at the end of the list. 
//Returns true if the new node is successfully allocated, otherwise is false.
bool ListNode::insertAfter(const DietPlan& newPlan)
{
    //Allocate memory for the new node
    dietNode* pMem = new dietNode(newPlan);
    bool success = false;

    if (pMem)   //Check whether the allocated memory is available
    {
        success = true;     //Allocated successfully
        if (mpHead == NULL) //The list is empty
            mpHead = mpTail = pMem;   //Update both pHead and pTail
        else
        {
            mpTail->pNext = pMem;
            mpTail = pMem;    //Update pTail
        }
    }

    return success;
}





//List for weekly exercise plan

//Constructor
List::List(exerciseNode* const newHeadPtr, exerciseNode* const newTailPtr)
{
    this->mpHead = newHeadPtr;
    this->mpTail = newTailPtr;
}


//Destructor
List::~List()
{
    delete mpHead;
    delete mpTail;
}


//Getters
exerciseNode* List::getHeadPtr() const
{
    return this->mpHead;
}



//This function inserts a new node of the given plan at the end of the list. 
//Returns true if the new node is successfully allocated, otherwise is false.
bool List::insertAfter(const ExercisePlan& newPlan)
{
    //Allocate memory for the new node
    exerciseNode* pMem = new exerciseNode(newPlan);
    bool success = false;

    if (pMem)   //Check whether the allocated memory is available
    {
        success = true;     //Allocated successfully
        if (mpHead == NULL) //The list is empty
            mpHead = mpTail = pMem;   //Update both pHead and pTail
        else
        {
            mpTail->pNext = pMem;
            mpTail = pMem;    //Update pTail
        }
    }

    return success;
}