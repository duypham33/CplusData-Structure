
/*

	This file is to establish the definitions for all programmer-defined functions of GrocerySimulation Class, aside from main ()

*/

#include "GrocerySimulation.h"

//Function definitions

//Constructor
GrocerySimulation::GrocerySimulation()
{
	//The two queues are initialized as empty queues
}


//Destructor
GrocerySimulation::~GrocerySimulation()
{
	//Destroy queues
	while (!this->normalLane.isEmpty() || !this->expressLane.isEmpty())
	{
		//Dequeues until the queues are empty
		this->normalLane.dequeue();     //If it is already empty, nothing changes
		this->expressLane.dequeue();    //If it is already empty, nothing changes
	}
}


//This function displays minutes based on day
void GrocerySimulation::printMin(int curTime)
{
	//Display minutes elapsed with more detail of the day
	int min = curTime % DAY;
	int day = (curTime / DAY) + 1;
	
	cout << "Minute " << curTime;
	if (curTime >= DAY)
		cout << " (minute " << min << " day " << day << ")";
}


//This function prompts the user for the number of minutes for the simulation to run
int GrocerySimulation::getNumberMinutes()
{
	int totalTime = 0;
	do   //The loop for prompting the user until getting a valid input
	{
		//Prompts the user for the number of minutes for the simulation to run
		cout << " Please, enter the number of minutes that you would like to run for the simulation(a positive integer): ";
		cin >> totalTime;

		if (totalTime < 1)  //Invalid input
			cout << "\nYour inputted number is invalid! Please, try again!\n\n";
		
	} while (totalTime < 1);

	return totalTime;
}



//This function is the key fucntion. It simulates the process. The parameter is the number of minutes for the simulation to run.
void GrocerySimulation::simulation(int totalTime, bool displayWait)
{
	srand(unsigned int(time(NULL)));   //Neccessary to generate random numbers for multiple times

	//Two pointer to data, that keeps track of new customers arriving into the two lanes, helping enqueue. They will be freed up after finishing the process
	Data* pNormalData = NULL;
	Data* pExpressData = NULL;
	//The customer numbers of the two lanes. Unique identifier; starts at 1; after 24 hours should be reset to 1
	int normalCusNum = 0, expressCusNum = 0;
	//The integer variable represents one minute of time elapsing.
	int elapsedTime = 0;
	//The two arrival time of a new customer in two lanes. They keep track of the arrival time during the process
	int normalArvTime = elapsedTime + rand() % 6 + 3;   //Generate the arrival time for the first customer in normal lane. It is random from 3 to 8 minutes
	int expressArvTime = elapsedTime + rand() % 5 + 1;  //Generate the arrival time for the first customer in express lane. It is random from 1 to 5 minutes
	//The two checkout time of the head customer in the two lanes. Initializes them to 0 at the beginning.
	int nmCheckoutTime = 0, expCheckoutTime = 0;

	//The two total service time in the two lanes. These are very important to keep track of the totalTime of customers. 
	//It is updated every minute. Simply, it is a total time from the current minute to when all the current customers done service
	//It helps to maintain totalTime = serviceTime + sum of serviceTimes of customers in line before
	int nmTotalTime = 0, expTotalTime = 0;   //Initializes to 0s at the beginning

	//The main loop of the simulation. The incrementing represent one minute of time elapsing
	for (elapsedTime = 1; elapsedTime < totalTime + 1; elapsedTime++)   
	{   
		if (elapsedTime % 60 == 0)    //Clear the screen after every 60 minutes
		{
			system("cls");  //Clear the screen
			if (elapsedTime % DAY == 0)   //After every 24 hours, reset customerNumber to 1
			{
				cout << "\n\t\t\t\t\t\t\t\tFINISH THE WORKING DAY, RESET CUSTOMER NUMBER!\n\n";
				//Reset customerNumber to 0, then it will be 1 after increment later
				normalCusNum = 0;
				expressCusNum = 0;
			}
			cout << "\t\t    NORMAL LANE" << std::setw(93) << "EXPRESS LANE" << endl;
			if (displayWait)   //Sleep 1s, if displayWait = true
				Sleep(1000);
		}


		/////////////////////////////////////////  NORMAL LANE  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

		if (elapsedTime == normalArvTime)   //A new customer arrives into the normal lane
		{			
			//Update the customerNumber, then allocate the space with related data used compute serviceTime and totalTime 			
			pNormalData = new Data(++normalCusNum, nmTotalTime, NORMAL_SERVICE_SPEED);
			this->normalLane.enqueue(*pNormalData);   //Insert the indirect value of the pointer, which is the new customer joining the lane
			nmTotalTime = pNormalData->getTotalTime();  //Update mnTotalTime after computing totalTime for the new customer

			//Print out a message indicating in which line each customer arrives, along with the overall corresponding arrival time and customer number
			printMin(elapsedTime);
			cout << ": Customer " << normalCusNum << " arrives the normal lane" << endl;

			//Update checkout time for this customer IN CASE this customer arrives when the lane is currently empty. 
			//This is when this is the first customer in the process, or all previous customers finished services before he/she arrives
			if (elapsedTime > nmCheckoutTime)    //If the current time is greater than the latest checkout time, it is THE MENTIONED CASE
				nmCheckoutTime = normalArvTime + pNormalData->getServiceTime();//So the checkout time for him/her equals his/her arrival time plus the service time 
			
			//Generates the next arrive time for the new customer. It is random from 3 to 8 minutes for the normal lane.
			normalArvTime += rand() % 6 + 3;
			if (displayWait)   //Sleep 1s, if displayWait = true
				Sleep(1000);
		}
		//Update the toal time, which is very important. The total time always elapses every minute unless it is already 0 (when previous customers done)
		if (nmTotalTime > 0)
			nmTotalTime--;     //Elapses if the lane still has customers.

		if (elapsedTime == nmCheckoutTime)   //This is the checkout time. So the customer at the head of lane, checks out.
		{
			//Print out a message indicating which line the customer was in, along the corresponding customer number and totalTime in the line.
			printMin(elapsedTime);
			cout << ": Customer " << this->normalLane.top().getCustomerNumber() << " checkouts the normal lane with ";	//The top() function is called		    
			this->normalLane.top().printCK(0);
			this->normalLane.dequeue();    //Dequeue, representing a customer checking out

			//Update the next checkout time for the next customer IN CASE the lane still has customers
			if (!this->normalLane.isEmpty())
				nmCheckoutTime += this->normalLane.top().getServiceTime();  //The next check time = the current one + the head customer's service time

			if (displayWait)   //Sleep 1s, if displayWait = true
				Sleep(1000);
		}
		

		/////////////////////////////////////////  EXPRESS LANE  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

		if (elapsedTime == expressArvTime)   //A new customer arrives into the express lane
		{
			//Update the customerNumber, then allocate the space with related data used compute serviceTime and totalTime 		
			pExpressData = new Data(++expressCusNum, expTotalTime, EXPRESS_SERVICE_SPEED);
			this->expressLane.enqueue(*pExpressData);   //Insert the indirect value of the pointer, which is the new customer joining the lane
			expTotalTime = pExpressData->getTotalTime();  //Update expTotalTime after computing totalTime for the new customer

			//Print out a message indicating in which line each customer arrives, along with the overall corresponding arrival time and customer number
			cout << std::setw(100); printMin(elapsedTime);
			cout << ": Customer " << expressCusNum << " arrives the express lane" << endl;

			//Update checkout time for this customer IN CASE this customer arrives when the lane is currently empty. 
			//This is when this is the first customer in the process, or all previous customers finished services before he/she arrives
			if (elapsedTime > expCheckoutTime)    //If the current time is greater than the latest checkout time, it is THE MENTIONED CASE
				expCheckoutTime = expressArvTime + pExpressData->getServiceTime();  //So the checkout time for him/her equals his/her arrival time plus the service time 

			//Generates the next arrive time for the new customer. It is random from 1 to 5 minutes for the express lane.
			expressArvTime += rand() % 5 + 1;
			if (displayWait)   //Sleep 1s, if displayWait = true
				Sleep(1000);
		}

		//Update the toal time, which is very important. The total time always elapses every minute unless it is already 0 (when previous customers done)
		if (expTotalTime > 0)
			expTotalTime--;     //Elapses if the lane still has customers.

		if (elapsedTime == expCheckoutTime)   //This is the checkout time. So the customer at the head of lane, checks out.
		{
			//Print out a message indicating which line the customer was in, along the corresponding customer number and totalTime in the line.
			cout << std::setw(100); printMin(elapsedTime);
			cout << ": Customer " << this->expressLane.top().getCustomerNumber()     //The top() function is called
				<< " checkouts the express lane with "; this->expressLane.top().printCK(105);
			
			this->expressLane.dequeue();    //Dequeue, representing a customer checking out

			//Update the next checkout time for the next customer IN CASE the lane still has customers
			if (!this->expressLane.isEmpty())
				expCheckoutTime += this->expressLane.top().getServiceTime();  //The next check time = the current one + the head customer's service time

			if (displayWait)   //Sleep 1s, if displayWait = true
				Sleep(1000);
		}
		


		//For every 10 minutes, print out the entire queue for each line
		if (elapsedTime % 10 == 0)
		{
			//Display normal lane
			cout << endl << endl; printMin(elapsedTime); cout << endl << "\t\tNormal Lane\n";
			if (!this->normalLane.isEmpty())
				this->normalLane.printQueue(0);   //The normal lane is not set a field width, which is in the left of the screen
			
			else
				cout << "\t The normal line is empty!" << endl << endl;
			
			//Display express lane
			cout << endl << std::setw(100); printMin(elapsedTime); cout << endl << std:: setw(125) << "Express Lane\n";
			if (!this->expressLane.isEmpty())
				this->expressLane.printQueue(107);  //The express lane is set a field width, which is in the right of the screen
			
			else
				cout << std::setw(120) << "\t\tThe express line is empty!" << endl << endl;

			if (displayWait)   //Sleep 1.5s, if displayWait = true
				Sleep(1500);
		}
	}

	//Free up the memory after finishing the simulation
	delete pNormalData;
	delete pExpressData;
}





//This function runs the simulation
void GrocerySimulation::run()
{
	cout << "\t\t\tWelcome to Grocery Store Simulation\n";
	//Prompts the user for the number of minutes for the simulation to run
	int totalTime = getNumberMinutes();

	system("cls");  //Clear the screen
	cout << "\t\t    NORMAL LANE" << std::setw(93) << "EXPRESS LANE" << endl;
	this->simulation(totalTime, true);  //Call the key private function
}