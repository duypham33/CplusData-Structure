
/*

  This is the header file that stores standard library includes, #defined and function prototypes of test Class

*/


#ifndef TEST_H //guard code

#define TEST_H

#include "GrocerySimulation.h"
#include <conio.h>     //Neccessary to use _getch() function 



//This class is to test some cases for the application
class Test
{
public:
	//The test case that executes enqueue() operation on an empty queue
	void testEnqueueOnEmpty();

	//The test case that executes enqueue() operation with one node in the queue
	void testEnqueueOneNode();

	//The test case that executes dequeue() operation on a queue with one node
	void testDequeueOneNode();

	//The test case that executes dequeue() operation on a queue with two nodes
	void testDequeueTwoNodes();

	//The test case that runs simulation for 24 hours
	void test_24HoursSimulation();

	//This function to run the all the test cases
	void runTests();
};


#endif