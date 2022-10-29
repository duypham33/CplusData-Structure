/*
      * Programmer: Duy Pham

      * Class: CptS 122, Fall 2021; Section 01; Lab Section 06

      * Programming Assignment:    PA 4:  Basic Fitness Application in C++

      * Date:    October 1st, 2021

      * Description:   This program is a basic fitness application that allows the user of the application to manually edit “diet” and “exercise” plans.
                There are DietPlan and ExercisePlan classes that represent diet and exercise plans. Their attributes are goals, plan name, and intended date 
                Besides, there are ListNode and List classes, which are linked lists used to store weekly diet and exercise plans.
                Finally, FitnessAppWrapper class is for the whole application. This class contains two lists of weekly (7 days) plans: 
                         One diet and one exercise weekly plan. It also contains two fstream objects (input/utput file streams). 
                Besides, it also contains member functions to run the fitness application with displaying main menu, loading plans, displaying plans,
                storing plans, and editing plans.
*/


#include "FitnessAppWrapper.h"


int main(void)
{
    //Allocate a poiter to the main application, so we would free the memory up right after the application is finished
    FitnessAppWrapper* pApp = new FitnessAppWrapper();

    //Run the application
    pApp->runApp();
   
    //Free up the memory
    delete pApp;

	return 0;   //The program was successfull
}