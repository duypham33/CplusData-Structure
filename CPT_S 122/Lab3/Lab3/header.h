

#ifndef HEADER_H //guard code

#define HEADER_H


#define _CRT_SECURE_NO_WARNINGS //ignore the error about scanf()


#include<stdio.h>    //necessary to use printf() and scanf()

#include<stdlib.h>   //necessary to use malloc() and free()



typedef struct stackNode
{
	double data;
	struct stackNode* pNext;
} StackNode;


typedef enum boolean
{
	False = 0, True
} Boolean;


//A predicate function which checks to see if the stack is empty; returns true if the stack is empty; false otherwise
Boolean isEmpty(StackNode* pTop);


// Inserts a node, with a double precision value,
//to the top of the stack; the node is allocated dynamically; the double precision value should be passed in as an argument, 
//along with a double pointer to the top of the stack
Boolean push(StackNode** pTop, double newData);



//Deletes a node from the top of the stack; 
//accepts a double pointer to the top of the stack; does not return a value; this function should only be called after isEmpty ( ) is called
void pop(StackNode** pTop);

//Returns the data in the node at the top of the stack; not modify the stack
double peek(StackNode* pTop);





#endif
