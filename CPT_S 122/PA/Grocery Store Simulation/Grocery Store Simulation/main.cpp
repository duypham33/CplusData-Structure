
/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:    PA 5: Grocery Store Simulation

      * Date:    October 16th, 2021

      * Description: This program simulates two lines in a grocery store by queue data structure. 
                     Queue node contains data including customer number (start from 1, and reset to 1 every 24 hours), a list of grocery items 
                     that the customer bought (this is a singly linked list), a service time that is computed proportionally the number of grocery items,
                     and the total time that is sum of the customer's service time and sum of the total time of customers before.
                     We will implement two queues representing two lanes(normal and express lanes):
                     The normal lane has customers arriving every 3 to 8 minutes. Meanwhile, it is quicker for the express lane, customers arrives 
                     every 1 - 5 minutes. However, the service speed of the express lane is faster than the normal one's, in order to process 
                     a high number of customers as customers arrive constantly and quickly.
*/


#include "Test.h"    // "Test.h" already included all the other files

int main(void)
{
    //Allocate space for a pointer to the test suite, and we will free it up when finishing the program
    Test* pTestSuite = new Test;
   
    //Allocate space for a pointer to the main simulation, and we will free it up when finishing the program
    GrocerySimulation* pGSimulation = new GrocerySimulation();

    //Display the option menu of Testing and Running simulation
    cout << "           MENU" << endl;
    cout << " 1. Test the application" << endl;
    cout << " 2. Run the simulation" << endl;

    //Prompt the user for an option
    int opt = 0;
    while (opt != 1 && opt != 2)
    {
        cout << endl << "Please, enter your option shown in the menu (1 or 2): ";
        cin >> opt;

        if (opt != 1 && opt != 2)  //Check whether the option is invalid
            cout << endl << "Your input option is invalid! Please, try again!";
        else
            system("cls");   //Clear the screen before running option
    }

    if (opt == 1)
    {
        //Run the test cases
        pTestSuite->runTests();

        cout << endl << "**************************************************************************************" << endl;
        cout << " Please, hit ENTER key to run the real simulation!";
        _getch();
        system("cls");   //Clear the screen to run the real simulation
    }

    //Run the simulation
    pGSimulation->run();
    
    //Free up the memory after finishing the simulation
    delete pTestSuite;
    delete pGSimulation;
  
    return 0;    //The program was successful
}