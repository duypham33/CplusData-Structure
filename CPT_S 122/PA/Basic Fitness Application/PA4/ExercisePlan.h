/*

  This is the header file that stores standard library includes, #defined and prototype of Exercise Plan Class

*/


#ifndef EXERCISE_PLAN_H //guard code

#define EXERCISE_PLAN_H

#include<iostream>  //cout, cin, endl, <<, >>
#include<fstream>   //operations to work with fstream, ifstream, and ofstream
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ofstream;
using std::ostream;


//The class ExercisePlan is used to represent a daily exercise plan
class ExercisePlan
{
public:
	//Constructor
	ExercisePlan(const int& newGoalSteps = 0, const string& newPlanName = "", const string& newPlanDate = "");

	//Destructor
	~ExercisePlan();

	//Copy constructor - invoked when a ExercisePlan object is passed by value
	ExercisePlan(ExercisePlan& copy);

	//Member functions
	//Setters
	void setGoalSteps(const int& newGoalSteps);
	void setPlanName(const string& newPlanName);
	void setPlanDate(const string& newPlanDate);

	//Getters
	int getGoalSteps() const;
	string getPlanName() const;
	string getPlanDate() const;

	//Prompt the user for a new goal, and display the edited plan to the screen
	void editGoal();


private:  //Data members
	int mGoalSteps;       //An integer representing the number of desired steps for a day
	string mPlanName;     //The name of the exercise plan
	string mPlanDate;     //The date for which the plan is intended
};



//Non-member functions

  //The overloaded stream insertion (<<) for displaying a plan to the screen
ostream& operator << (ostream& lhs, const ExercisePlan& rhs);

//The overloaded stream insertion (<<) for writing a plan to a file
fstream& operator << (fstream& lhs, const ExercisePlan& rhs);

//The overloaded stream extraction (>>) operator for reading a plan from a file
fstream& operator >> (fstream& lhs, ExercisePlan& rhs);




#endif


