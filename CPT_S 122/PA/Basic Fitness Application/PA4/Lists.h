
/*

  This is the header file that stores #defined and function prototypes of ListNode and List classes

*/


#ifndef LISTS_H  //guard code

#define LISTS_H


#include "DietPlan.h"
#include "ExercisePlan.h"


/*
    We implement two different linked lists for storing the two plan types.
	ListNode class is for DietPlan type
	List class is for ExercisePlan type

	Because inserting at the end of a linked list (with only a head pointer) requires linear time. 
	The plans require all the insertion at the end of the list, 
	hence we will implement these two linked list with AN ADDITIONAL TAIL POINTER to improve insert-after method.
*/



//////////////////List for weekly diet plan\\\\\\\\\\\\\\\\\\\\\\\\\\

//Struct node
struct dietNode
{
	DietPlan plan;
	dietNode* pNext;
	dietNode(const DietPlan& newPlan)   //Constructor-like a makeNode() function
	{
		plan = newPlan;
		pNext = NULL;
	}
};

class ListNode
{
public:
	//Constructor
	ListNode(dietNode* const newHeadPtr = NULL, dietNode* const newTailPtr = NULL);

	//Destructor
	~ListNode();

	//Getters
	dietNode* getHeadPtr() const;    //Only need to get headPtr for display all the list, not neccessary to get tailPtr

	//Operators

	//This function inserts a new node of the given plan at the end of the list. 
	//Returns true if the new node is successfully allocated, otherwise is false.
	bool insertAfter(const DietPlan& newPlan);   

private:
	//Data members
	dietNode* mpHead;    //The head pointer of the linked list
	dietNode* mpTail;    //The additional tail pointer to improve insertion at the end, which is the main operation for the task
};





///////////////////List for weekly exercise plan\\\\\\\\\\\\\\\\\\\\\\\\\\

//Struct node
struct exerciseNode
{
	ExercisePlan plan;
	exerciseNode* pNext;
	exerciseNode(const ExercisePlan& newPlan)    //Constructor-like a makeNode() function
	{
		plan = newPlan;
		pNext = NULL;
	}
};

class List
{
public:
	//Constructor
	List(exerciseNode* const newHeadPtr = NULL, exerciseNode* const newTailPtr = NULL);

	//Destructor
	~List();

	//Getters
	exerciseNode* getHeadPtr() const;      //Only need to get headPtr for display all the list, not neccessary to get tailPtr

	//Operators

	//This function inserts a new node of the given plan at the end of the list. 
	//Returns true if the new node is successfully allocated, otherwise is false.
	bool insertAfter(const ExercisePlan& newPlan);

private:
	//Data members
	exerciseNode* mpHead;    //The head pointer of the linked list
	exerciseNode* mpTail;    //The additional tail pointer to improve insertion at the end, which is the main operation for the task
};






#endif


