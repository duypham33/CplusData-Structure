/*

  This is the header file that stores standard library includes, #defined and function prototypes of Data Class

*/


#ifndef DATA_H //guard code

#define DATA_H


#include "ItemList.h"
#include <iomanip>      //Neccessary to use std::setw() function, to set a field width when printing


//This class is for service information of each customer
class Data
{
public:
	//Default Constructor
	Data();

	/*
	This is a more special contructor. It will set a new customerNumber (the first parameter), 
	and then it will call generateList() function of the itemList, in order to randomly generate the grocery item list for the new customer.

	Based on the number of items, it compute service time proportinally.
	We suppose in the normal line, every two items costs 1 minute in service time, and one item does too. 
	So for example: only one item costs 1 service minute, 6 items costs 3 service minutes, and 5 items also costs 3, but 7 items costs 4.
	So serviceTime = ceil( (double)totalItems / 2 ). However, the express line should have a quicker service speed since customers arrive every 1-5 minutes
	That is why we need the third parameter - serviceSpeed, we suppose serviceTime = ceil( (double)totalItems / 4 ) in the express line.
	 So serviceSpeed will be 2 for the normal lane and 4 for the express one.	

	Finally, totalTime = serviceTime + sum of serviceTimes of customers in line before(this is the current total time - the second parameter).
	*/
	Data(const int& newCustomerNumber, const int& currentTotalTime, const int& serviceSpeed);

	//Destructor
	~Data();

	//Display the item list, service time and the total time when the customer checks out
	//The parameter is a width value to set a field width when printing the information, since we print two lanes, so should set a field width between them.
	void printCK(int w_value);

	//Setters
	void setCustomerNumber(const int& newCustomerNumber);
	void setServiceTime(const int& newServiceTime);
	void setTotalTime(const int& newTotalTime);

	//Getters
	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime() const;

private:
	int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	ItemList* pItemList;  //The linked list consisting of grocery items corresponding to one customer (STORED TO THE HEAP INSTEAD OF STACK) 
	int serviceTime;   //The service time, which is proportional to the number of items that customer bought; units in minutes
	int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
};



#endif