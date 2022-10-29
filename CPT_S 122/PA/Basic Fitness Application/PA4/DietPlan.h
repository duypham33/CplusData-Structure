/*

  This is the header file that stores standard library includes, #defined and prototype of Diet Plan Class

*/


#ifndef DIET_PLAN_H //guard code

#define DIET_PLAN_H

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


//The class DietPlan is used to represent a daily diet plan
class DietPlan
{
public:
	//Constructor
	DietPlan(const int& newGoalCalories = 0, const string& newPlanName = "", const string& newPlanDate = "");

	//Destructor
	~DietPlan();

	//Copy constructor - invoked when a DietPlan object is passed by value
	DietPlan(DietPlan& copy);

	//Member functions
	//Setters
	void setGoalCalories(const int& newGoalCalories);
	void setPlanName(const string& newPlanName);
	void setPlanDate(const string& newPlanDate);

	//Getters
	int getGoalCalories() const;
	string getPlanName() const;
	string getPlanDate() const;

	//Prompt the user for a new goal, and display the edited plan to the screen
	void editGoal();


private:  //Data members
	int mGoalCalories;    //An integer representing the maximum intake of calories for a day
	string mPlanName;     //The name of the diet plan
	string mPlanDate;     //The date for which the plan is intended
};



//Non-member functions

  //The overloaded stream insertion (<<) for displaying a plan to the screen
ostream& operator << (ostream& lhs, const DietPlan& rhs);

//The overloaded stream insertion (<<) for writing a plan to a file
fstream& operator << (fstream& lhs, const DietPlan& rhs);

//The overloaded stream extraction (>>) operator for reading a plan from a file
fstream& operator >> (fstream& lhs, DietPlan& rhs);









#endif


