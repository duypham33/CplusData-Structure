
/*

  This is the header file that stores standard library includes, #defined and function prototypes of FitnessAppWrapper Class

*/


#ifndef FITNESS_APP_WRAPPER_H    //guard code

#define FITNESS_APP_WRAPPER_H


// Lists.h included "DietPlan.h" and ExercisePlan.h"
#include "Lists.h"     
#include <conio.h>   //For use _getch() function


/*
   We implement FitnessAppWrapper class used to “wrap” the application. This class contains two lists of weekly (7 days) plans: 
   one diet and one exercise weekly plan. It also contains two fstream objects (input/utput file streams). 
   Besides, it also contains member functions to run the fitness application with displaying main menu, loading plans, displaying plans,
   storing plans, and editing plans.
*/



class FitnessAppWrapper
{
public:
	//Default constructor
	FitnessAppWrapper();

	//Destructor
	~FitnessAppWrapper();

	//Operations
	void displayMenu();    //This function displays the main menu of the application

	//Two following functions will call the private loadWeeklyPlan() functions, to load weekly plans for diet and exercise plans
	void loadWeeklyDietPlan();  
	void loadWeeklyExercisePlan();

	//Two following functions will call the private displayWeeklyPlan() functions, to display weekly plans to the screen
	void displayWeeklyDietPlan();
	void displayWeeklyExercisePlan();


	//Two following functions will call the private storeWeeklyPlan() functions, to store weekly plans to the file
	void storeWeeklyDietPlan();
	void storeWeeklyExercisePlan();

	//Two following functions will prompt the user for the name of the plan to edit its goal, then display the new plan to the screen
	//This will call editGoal() functions in DietPlan and ExercisePlan classes
	void editDietPlan();
	void editExercisePlan();

	//The function is for running all the application
	void runApp();


private:   
	//Data members
	ListNode* mpDietList;     //The pointer to list of diet weekly plans
	List* mpExerciseList;     //The pointer to list of exercise weekly plans
	fstream mDietStr;        //The file stream (input/output) associated with “dietPlans.txt”
	fstream mExerciseStr;    //The file stream (input/output) associated with “exercisePlans.txt”


	/////////////////////  Private helper/utility functions  \\\\\\\\\\\\\\\\\\\\\\\\

	//Two loadDailyPlan() functions. Reads one record from the given stream. Precondition: The file is already open!
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);       
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);

	//Two loadWeeklyPlan() functions. Calls loadDailyPlan() functions to read all seven daily plans from the given stream. 
    //Precondition: The file is already open!
	void loadWeeklyPlan(fstream& fileStream, ListNode* pDietList);
	void loadWeeklyPlan(fstream& fileStream, List* pExerciseList);

	//Two displayDailyPlan() functions. Apply the overloaded stream insertion operator to write a daily plan to the screen
	void displayDailyPlan(const DietPlan& plan);
	void displayDailyPlan(const ExercisePlan& plan);

	//Two displayWeeklyPlan() functions. Calls displayWeeklyPlan() functions to write a weekly plan to the screen
	void displayWeeklyPlan(ListNode* pDietList);
	void displayWeeklyPlan(List* pExerciseList);

	//Two storeDailyPlan() functions. Apply the overloaded stream insertion operator to write a daily plan to a file
	void storeDailyPlan(fstream& fileStream, DietPlan& plan);
	void storeDailyPlan(fstream& fileStream, ExercisePlan& plan);

	//Two storeWeeklyPlan() functions. Calls storeDailyPlan() functions to write a weekly plan to a file
	void storeWeeklyPlan(fstream& fileStream, ListNode* pDietList);
	void storeWeeklyPlan(fstream& fileStream, List* pExerciseList);
};









#endif


