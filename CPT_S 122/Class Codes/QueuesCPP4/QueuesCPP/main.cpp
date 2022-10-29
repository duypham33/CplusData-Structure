// This example illustrates how to implement and apply queues in C++.

// History: 3/5 - Implemented a destructor for Queue. Discussed a namespace
//                called Tests. Created an incomplete test function
//                called testEnqueueOnEmpty () in class TestQueue.
//          3/3 - Implemented enqueue () and dequeue () for a Queue. Also,
//                added a constructor, some getters () and setters () to the
//                Node class. We have yet to test our functions and complete
//                the application.
//          3/1 - Declared aspects of class Node and class Queue. We are
//                not done!!! Implemented a constructor with default arguments
//                for the Queue class. Started working on enqueue ().

#include "Queue.h"
#include "TestQueue.h"

int main(void)
{
	Queue printJobContainer;
	Tests::TestQueue testQueue;

	testQueue.testEnqueueOnEmpty();

	printJobContainer.enqueue("pj1");
	printJobContainer.enqueue("pj2");
	std::cout << printJobContainer.dequeue() << std::endl;
	std::cout << printJobContainer.dequeue() << std::endl;

	return 0;
}