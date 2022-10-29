
/*

    This file is to establish the definitions for all programmer-defined functions of ExercisePlan Class, aside from main ()

*/


#include "ExercisePlan.h"


//Constructor
ExercisePlan::ExercisePlan(const int& newGoalSteps, const string& newPlanName, const string& newPlanDate)
{
    if (newGoalSteps < 0)        //The goal should be equal or greater than 0
        this->mGoalSteps = 0;
    else
        this->mGoalSteps = newGoalSteps;

    this->mPlanName = newPlanName;
    this->mPlanDate = newPlanDate;
}



//Destructor
ExercisePlan::~ExercisePlan()
{
    // No resources to clean up in this case
  //  cout << "\nInside of ExercisePlan's destructor!\n\n";
}


//Copy constructor - invoked when a ExercisePlan object is passed by value
ExercisePlan::ExercisePlan(ExercisePlan& copy)
{
    this->mGoalSteps = copy.mGoalSteps;
    this->mPlanName = copy.mPlanName;
    this->mPlanDate = copy.mPlanDate;
}



//Setters
void ExercisePlan::setGoalSteps(const int& newGoalSteps)
{
    this->mGoalSteps = newGoalSteps;
}

void ExercisePlan::setPlanName(const string& newPlanName)
{
    this->mPlanName = newPlanName;
}

void ExercisePlan::setPlanDate(const string& newPlanDate)
{
    this->mPlanDate = newPlanDate;
}


//Getters
int ExercisePlan::getGoalSteps() const
{
    return mGoalSteps;
}

string ExercisePlan::getPlanName() const
{
    return mPlanName;
}

string ExercisePlan::getPlanDate() const
{
    return mPlanDate;
}



//Prompt the user for a new goal, and display the edited plan to the screen
void ExercisePlan::editGoal()
{
    //Prompt the user for a new goal
    int goal = 0;
    do
    {
        cout << "Please, enter a new steps goal: ";
        cin >> goal;

        if (goal < 0)
            cout << "Your steps goal should be equal or greater than zero! Please, try again!" << endl;
        else
            this->mGoalSteps = goal;
    } while (goal < 0);

    //Display the new plan to the screen
    cout << endl << endl << "The plan after editing:" << endl;
    cout << (*this) << endl;
}




//Non-member functions

  //The overloaded stream insertion (<<) for displaying a plan to the screen
ostream& operator << (ostream& lhs, const ExercisePlan& rhs)
{
    lhs << "Plan name: " << rhs.getPlanName() << endl << "   Goal steps: " << rhs.getGoalSteps() << endl
        << "   Plan date: " << rhs.getPlanDate() << endl << endl;

    return lhs;
}



//The overloaded stream insertion (<<) for writing a plan to a file
fstream& operator << (fstream& lhs, const ExercisePlan& rhs)
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
    ((ofstream&) (lhs)) << rhs.getPlanName() << endl << rhs.getGoalSteps() << endl << rhs.getPlanDate() << endl;
    return lhs;
}



//The overloaded stream extraction (>>) operator for reading a plan from a file
fstream& operator >> (fstream& lhs, ExercisePlan& rhs)
{
    string planName;
    int goal;
    string date;

    //Read the plan name from the file
    std::getline(lhs, planName);
    rhs.setPlanName(planName);   //Set plan name for the object's plan name

    //Read the goal steps
    lhs >> goal;
    if (goal < 0)    //Set goal steps for the object's goal steps
        rhs.setGoalSteps(0);
    else
        rhs.setGoalSteps(goal);
    lhs.ignore();    //Ignore '\n' after the integer goal steps before reading the string plan date


    //Read the plan date
    std::getline(lhs, date);
    rhs.setPlanDate(date);    //Set plan date for the object's plan date

    return lhs;
}