
/*

  This is the header file that stores standard library includes, #defined and function prototypes of GrocerySimulation Class

*/


#ifndef GROCERY_SIMULATION_H //guard code

#define GROCERY_SIMULATION_H

#include "Queue.h"
#include <Windows.h>     //Neccessary to use Sleep() function

#define DAY (60*24)   //The number of minutes for 24 hours. After every 24 hours(a day), reset customerNumber to 1
#define NORMAL_SERVICE_SPEED 2        //The service speed in the normal lane, one-two items cost 1 minute, used to compute serviceTime
#define EXPRESS_SERVICE_SPEED 4       //The service speed in the express lane, one-four items cost 1 minute, used to compute serviceTime


//This class represents the whole grocery store simulation. This runs the whole process with two lanes (normal and express lanes)
class GrocerySimulation
{
public:
	//Constructor
	GrocerySimulation();

	//Destructor
	~GrocerySimulation();

	//This function displays minutes based on day
	void printMin(int curTime);

	//This function prompts the user for the number of minutes for the simulation to run
	int getNumberMinutes();

	//This function is the key fucntion. It simulates the process. The first parameter is the number of minutes for the simulation to run.
	//The second parameter is a bool flag. If true, then the simulation will be displayed more slowly like as the real waiting lines by using Sleep().
	//False is otherwise. This is because it may not need to display slowly in the test function running the simulation for 24 hours
	void simulation(int totalTime, bool displayWait);

	//This function runs the simulation
	void run();
	
private:
	//Data members are the two main queues, representing normal and express lanes
	Queue normalLane;
	Queue expressLane;
};


#endif
