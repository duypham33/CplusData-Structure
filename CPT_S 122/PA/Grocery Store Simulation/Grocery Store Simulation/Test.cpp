
/*

	This file is to establish the definitions for all programmer-defined functions of test Class, aside from main ()

*/

#include "Test.h"


//Function definitions


//The test case that executes enqueue() operation on an empty queue
void Test::testEnqueueOnEmpty()
{
	//Allocate a pointer to an empty queue, and we will deallocate after testing
	Queue* pQueue = new Queue;
	//Create data used to enqueue
	Data* pData = new Data(1, 0, 2);    //And we will also deallocate after testing	

	//Enqueue
	bool success = pQueue->enqueue(*pData);   //Add the indirect value of the pointer to the queue
	bool check = false;
	if (success)
	{
		if (!pQueue->isEmpty())
		{  
			//Check the content of the head with the new data
			if (pQueue->getHeadPtr()->getData().getCustomerNumber() == pData->getCustomerNumber())
				if (pQueue->getHeadPtr()->getData().getServiceTime() == pData->getServiceTime())
					if (pQueue->getHeadPtr()->getData().getTotalTime() == pData->getTotalTime())
						check = true;
		}

		if (check)
			cout << "The test case for enqueue() operation on an empty queue passed!" << endl;
		else
			cout << "The test case for enqueue() operation on an empty queue failed!" << endl;
	}
	
	//Free up the space
	delete pQueue;
	delete pData;
	pQueue = nullptr;
	pData = nullptr;
}



//The test case that executes enqueue() operation with one node in the queue
void Test::testEnqueueOneNode()
{
	bool check = false;
	//Allocate a pointer to an empty queue, and we will deallocate after testing
	Queue* pQueue = new Queue;
	//Create data to make the queue have one node first
	Data* pData1 = new Data;    //And we will also deallocate after testing	
	bool success = pQueue->enqueue(*pData1);   //Add the indirect value of the pointer to the queue

	if (success)  
	{
		//Create a data to enqueue
		Data* pNewData = new Data(1, 0, 2);
		success = pQueue->enqueue(*pNewData);   //Add the indirect value of the pointer to the queue

		if (success)  
		{
			if (pQueue->getTailPtr())   //Check the content of the tail with the new data
			{
				if (pQueue->getTailPtr()->getData().getCustomerNumber() == pNewData->getCustomerNumber())
					if (pQueue->getTailPtr()->getData().getServiceTime() == pNewData->getServiceTime())
						if (pQueue->getTailPtr()->getData().getTotalTime() == pNewData->getTotalTime())
							check = true;
			}			
		}

		delete pNewData;   //Free space
		pNewData = nullptr;
	}

	if (check)
		cout << "The test case for enqueue() operation with one node in the queue passed!" << endl;
	else
		cout << "The test case for enqueue() operation with one node in the queue failed!" << endl;

	//Free up the space
	delete pQueue;
	delete pData1;
	pQueue = nullptr;
	pData1 = nullptr;
}



//The test case that executes dequeue() operation on a queue with one node
void Test::testDequeueOneNode()
{
	bool check = false;
	//Allocate a pointer to an empty queue, and we will deallocate after testing
	Queue* pQueue = new Queue;
	//Create data to make the queue have one node first
	Data* pData = new Data;    //And we will also deallocate after testing	
	bool success = pQueue->enqueue(*pData);   //Add the indirect value of the pointer to the queue

	if (success)
	{
		pQueue->dequeue();
		if (pQueue->isEmpty())   //If the queue is empty after dequeue, which is true
			check = true;
	}

	if (check)
		cout << "The test case for dequeue() operation on a queue with one node passed!" << endl;
	else
		cout << "The test case for dequeue() operation on a queue with one node failed!" << endl;

	//Free up the space
	delete pQueue;
	delete pData;
	pQueue = nullptr;
	pData = nullptr;
}



//The test case that executes dequeue() operation on a queue with two nodes
void Test::testDequeueTwoNodes()
{
	bool check = false;
	//Allocate a pointer to an empty queue, and we will deallocate after testing
	Queue* pQueue = new Queue;
	//Create data to make the queue have one node first
	Data* pData1 = new Data(1, 0, 2);    //And we will also deallocate after testing	
	Data* pData2 = new Data(2, 5, 2);    

	bool success = pQueue->enqueue(*pData1);   //Add the indirect value of the pointer to the queue
	if (success)
	{
		success = pQueue->enqueue(*pData2);   //Add the indirect value of the pointer to the queue
		if (success)
		{
			pQueue->dequeue();
			if (pQueue->getHeadPtr())   //Check the content of the head with the data 2
			{
				if (pQueue->getHeadPtr()->getData().getCustomerNumber() == pData2->getCustomerNumber())
					if (pQueue->getHeadPtr()->getData().getServiceTime() == pData2->getServiceTime())
						if (pQueue->getHeadPtr()->getData().getTotalTime() == pData2->getTotalTime())
							check = true;
			}
		}
	}

	if (check)
		cout << "The test case for dequeue() operation on a queue with two nodes passed!" << endl;
	else
		cout << "The test case for dequeue() operation on a queue with two nodes failed!" << endl;

	//Free up the space
	delete pQueue;
	delete pData1;
	delete pData2;
	pQueue = nullptr;
	pData1 = nullptr;
	pData2 = nullptr;
}




//The test case that runs simulation for 24 hours
void Test::test_24HoursSimulation()
{
	//Allocate space for a pointer to the simulation
	GrocerySimulation* pGSimulation = new GrocerySimulation();

	//Run the simulation for 24 hours, plus 10 minutes to make sure there is at least one new customer arrives into the both lanes, so we can check their ID
	pGSimulation->simulation(DAY + 10, false);   //We do not need to run simulation slowly by Sleep()

	bool check = false;    
	//Prompt the user for whether the customer numbers have been reset after 24 hours
	char ans = '\0';
	cout << endl << "**************************************************************************************" << endl;
	while(ans != 'y' && ans != 'n')
	{
		cout << " Have the customer numbers been reset after 24 hours('y' / 'n') ?    ";
		cin >> ans;

		if (ans != 'y' && ans != 'n')  //Check for invalid input
			cout << " Your answer is invalid! Please, try again!" << endl << endl;
	}

	if (ans == 'y')   //If the user view the process correctly, and answer 'y' for yes, then the test passes
		check = true;

	cout << endl;
	if (check)
		cout << "The test case that runs simulation for 24 hours passed!" << endl;
	else
		cout << "The test case that runs simulation for 24 hours failed!" << endl;

	//Free up the memory after finishing the simulation
	delete pGSimulation;
}


//This function to run the all the test cases
void Test::runTests()
{
	Sleep(1500);
	this->testEnqueueOnEmpty();  //Case 1
	Sleep(1500);
	cout << endl;
	this->testEnqueueOneNode();  //Case 2
	Sleep(1500);
	cout << endl;
	this->testDequeueOneNode();  //Case 3
	Sleep(1500);
	cout << endl;
	this->testDequeueTwoNodes();  //Case 4

	cout << endl << endl << "Please, hit ENTER key to run the simulation for around 24 hours!";
	_getch();
	system("cls");   //Clear the screen to run the simulation
	this->test_24HoursSimulation();    //Case 5
}