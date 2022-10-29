
/*

    This file is to establish the definitions for all programmer-defined functions of Data Class, aside from main ()

*/


#include "Data.h"


//Function definitions

//Default Constructor
Data::Data()
{
    //All integer data members should be initialized to 0
    this->customerNumber = 0;
    this->serviceTime = 0;
    this->totalTime = 0;
    //The item list is automatically intialized as an empty list
    pItemList = new ItemList;
}



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
Data::Data(const int& newCustomerNumber, const int& currentTotalTime, const int& serviceSpeed)
{
    if (newCustomerNumber < 0)     //The customer number should be >= 0
        this->customerNumber = 0;
    else
        this->customerNumber = newCustomerNumber;

    pItemList = new ItemList;   //Allocate the space for the list
    this->pItemList->generateList();   //Generate the grocery item list for the new customer

    //serviceTime = ceil( (double)totalItems / serviceSpeed )
    int n = this->pItemList->getNumberItems();
    this->serviceTime = ceil((double)n / serviceSpeed);

    //totalTime = serviceTime + sum of serviceTimes of customers in line before(this is the current total time, which is updated during the simulation)
    this->totalTime = this->serviceTime + currentTotalTime;
}



//Destructor
Data::~Data()
{
    //No resource to delete, they should be removed at once the simulation finishes.
}


//Display the item list, service time and the total time when the customer checks out
//The parameter is a width value to set a field width when printing the information, since we print two lanes, so should set a field width between them.
void Data::printCK(int w_value)
{
    //Display the shortcut of item list
    this->pItemList->printList();    //Call the printList() function of the ItemList class
    //Display service time and total time
    int srvT = this->serviceTime, tlT = this->totalTime;
    cout << "," << endl << std::setw(w_value) << srvT << " service minute" << ((srvT == 1) ? "" : "s");    //1 min without 's', > 1 has 's'
    cout << ", and " << tlT << " total minute" << ((tlT == 1) ? "\n" : "s\n");          //1 min without 's', > 1 has 's'
}


void Data::setCustomerNumber(const int& newCustomerNumber)
{
    this->customerNumber = newCustomerNumber;
}

void Data::setServiceTime(const int& newServiceTime)
{
    this->serviceTime = newServiceTime;
}

void Data::setTotalTime(const int& newTotalTime)
{
    this->totalTime = newTotalTime;
}


int Data::getCustomerNumber() const
{
    return this->customerNumber;
}

int Data::getServiceTime() const
{
    return this->serviceTime;
}

int Data::getTotalTime() const
{
    return this->totalTime;
}
