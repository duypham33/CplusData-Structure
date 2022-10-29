
/*

    This file is to establish the definitions for all programmer-defined functions of DietPlan Class, aside from main ()

*/


#include "DietPlan.h"


//Constructor
DietPlan::DietPlan(const int& newGoalCalories, const string& newPlanName, const string& newPlanDate)
{
    if (newGoalCalories < 0)   //The goal should be equal or greater than 0
        this->mGoalCalories = 0;
    else
        this->mGoalCalories = newGoalCalories;

    this->mPlanName = newPlanName;
    this->mPlanDate = newPlanDate;
}



//Destructor
DietPlan::~DietPlan()
{
    // No resources to clean up in this case
  //  cout << "\nInside of DietPlan's destructor!\n\n";
}


//Copy constructor - invoked when a DietPlan object is passed by value
DietPlan::DietPlan(DietPlan& copy)
{
    this->mGoalCalories = copy.mGoalCalories;
    this->mPlanName = copy.mPlanName;
    this->mPlanDate = copy.mPlanDate;
}



//Setters
void DietPlan::setGoalCalories(const int& newGoalCalories)
{
    this->mGoalCalories = newGoalCalories;
}

void DietPlan::setPlanName(const string& newPlanName)
{
    this->mPlanName = newPlanName;
}

void DietPlan::setPlanDate(const string& newPlanDate)
{
    this->mPlanDate = newPlanDate;
}


//Getters
int DietPlan::getGoalCalories() const
{
    return mGoalCalories;
}

string DietPlan::getPlanName() const
{
    return mPlanName;
}

string DietPlan::getPlanDate() const
{
    return mPlanDate;
}



//Prompt the user for a new goal, and display the edited plan to the screen
void DietPlan::editGoal()
{
    //Prompt the user for a new goal
    int goal = 0;
    do
    {
        cout << "Please, enter a new calories goal: ";
        cin >> goal;

        if (goal < 0)
            cout << "Your calories goal should be equal or greater than zero! Please, try again!" << endl;
        else
            this->mGoalCalories = goal;
    } while (goal < 0);

    //Display the new plan to the screen
    cout << endl << endl << "The plan after editing:" << endl;
    cout << (*this) << endl;
}



//Non-member functions

  //The overloaded stream insertion (<<) for displaying a plan to the screen
ostream& operator << (ostream& lhs, const DietPlan& rhs)
{
    lhs << "Plan name: " << rhs.getPlanName() << endl << "   Goal calories: " << rhs.getGoalCalories() << endl
        << "   Plan date: " << rhs.getPlanDate() << endl << endl;

    return lhs;
}



//The overloaded stream insertion (<<) for writing a plan to a file
fstream& operator << (fstream& lhs, const DietPlan& rhs)
{
    /*
     Write information to the file in the following format:
        Plan name
        Goal
        Date in the form mm/dd/yyyy
        (blank line)
        Plan name
        Goal
        Date in the form mm/dd/yyyy
        (blank line)
        ...
    */

    //Cast lhs to ofstream
    ((ofstream&) (lhs)) << rhs.getPlanName() << endl << rhs.getGoalCalories() << endl << rhs.getPlanDate() << endl;
    return lhs;
}



//The overloaded stream extraction (>>) operator for reading a plan from a file
fstream& operator >> (fstream& lhs, DietPlan& rhs)
{
    string planName;
    int goal;
    string date;

    //Read the plan name from the file
    std::getline(lhs, planName);
    rhs.setPlanName(planName);   //Set plan name for the object's plan name

    //Read the goal calories
    lhs >> goal;
    if (goal < 0)    //Set goal calories for the object's goal calories
        rhs.setGoalCalories(0);
    else
        rhs.setGoalCalories(goal);
    lhs.ignore();    //Ignore '\n' after the integer goal calories before reading the string plan date


    //Read the plan date
    std::getline(lhs, date);
    rhs.setPlanDate(date);    //Set plan date for the object's plan date

    return lhs;
}