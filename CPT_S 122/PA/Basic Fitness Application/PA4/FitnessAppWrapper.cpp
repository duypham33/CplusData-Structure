
/*

    This file is to establish the definitions for all programmer-defined functions of FitnessAppWrapper Class, aside from main ()

*/


#include "FitnessAppWrapper.h"

//Default constructor
FitnessAppWrapper::FitnessAppWrapper()
{
    //Allocate memory for the two lists, which initializes two empty lists
    this->mpDietList = new ListNode();
    this->mpExerciseList = new List();
}


//Destructor
FitnessAppWrapper::~FitnessAppWrapper()
{
    //Free up memory of the two lists
    delete mpDietList;
    delete mpExerciseList;
    cout << "Inside FitnessAppWrapper's destructor!" << endl;
}


//Operations

//This function displays the main menu of the application
void FitnessAppWrapper::displayMenu()
{
    cout << "    MENU" << endl;
    cout << "1. Load weekly diet plan from file" << endl;
    cout << "2. Load weekly exercise plan from file" << endl;
    cout << "3. Store weekly diet plan to file" << endl;
    cout << "4. Store weekly exercise plan to file" << endl;
    cout << "5. Display weekly diet plan to screen" << endl;
    cout << "6. Display weekly exercise plan to screen" << endl;
    cout << "7. Edit daily diet plan" << endl;
    cout << "8. Edit daily exercise plan" << endl;
    cout << "9. Exit" << endl << endl;
}



//Two following functions will call the private loadWeeklyPlan() functions, to load weekly plans for diet and exercise plans
void FitnessAppWrapper::loadWeeklyDietPlan()
{
    // We want to start reading from the beginning of the "dietPlan.txt" file
    // We will close the stream associated with the file if it's open!
    if (this->mDietStr.is_open()) // is_open () returns true if file open, false otherwise
        this->mDietStr.close();   // close it so we can start from the beginning of the file

    this->mDietStr.open("dietPlans.txt");  //Opens in input/output mode by default with fstream object
    //We will read the first line and check whether the list is empty
    string firstLine = "";
    std::getline(this->mDietStr, firstLine);  //Read the first line
    //Check whether the list is empty, because if the initial empty plan is stored in the file, it will write "The diet list is empty!" to the file
    if (firstLine != "The diet list is empty!")
    {
        this->mDietStr.seekg(std::ios::beg);  // Set the file pointer to the file beginning, in order to read the plans since the list is not empty
        this->loadWeeklyPlan(this->mDietStr, this->mpDietList);   //Call the private function associated with diet plans
    }

    this->mDietStr.close();  //Close the file
}


void FitnessAppWrapper::loadWeeklyExercisePlan()
{
    // We want to start reading from the beginning of the "exercisePlan.txt" file
    // We will close the stream associated with the file if it's open!
    if (this->mExerciseStr.is_open()) // is_open () returns true if file open, false otherwise
        this->mExerciseStr.close();   // close it so we can start from the beginning of the file

    this->mExerciseStr.open("exercisePlans.txt");  //Opens in input/output mode by default with fstream object
    //We will read the first line and check whether the list is empty
    string firstLine = "";
    std::getline(this->mExerciseStr, firstLine);  //Read the first line
    //Check whether the list is empty, because if the initial empty plan is stored in the file, it will write "The exercise list is empty!" to the file
    if (firstLine != "The exercise list is empty!")
    {
        this->mExerciseStr.seekg(std::ios::beg);  // Set the file pointer to the file beginning, in order to read the plans since the list is not empty
        this->loadWeeklyPlan(this->mExerciseStr, this->mpExerciseList);   //Call the private function associated with diet plans
    }

    this->mExerciseStr.close();  //Close the file
}




//Two following functions will call the private displayWeeklyPlan() functions, to display weekly plans to the screen
void FitnessAppWrapper::displayWeeklyDietPlan()
{
    if (this->mpDietList->getHeadPtr() == NULL)   //The list is empty
        cout << " The diet list is empty!" << endl << endl;
    else
        this->displayWeeklyPlan(this->mpDietList);   //Display a weekly diet plan to the screen
}


void FitnessAppWrapper::displayWeeklyExercisePlan()
{
    if (this->mpExerciseList->getHeadPtr() == NULL)   //The list is empty
        cout << " The exercise list is empty!" << endl << endl;
    else
        this->displayWeeklyPlan(this->mpExerciseList);   //Display a weekly exercise plan to the screen
}




//Two following functions will call the private storeWeeklyPlan() functions, to store weekly plans to the file
void FitnessAppWrapper::storeWeeklyDietPlan()
{
    // We want to start overwriting from the beginning of the "dietPlan.txt" file
    // We will close the stream associated with the file if it's open!
    if (this->mDietStr.is_open()) // is_open () returns true if file open, false otherwise
        this->mDietStr.close();   // close it so we can start from the beginning of the file

    this->mDietStr.open("dietPlans.txt", std::ios::out);  //Opens in output mode

    if (this->mpDietList->getHeadPtr() == NULL)    //The list is empty
        this->mDietStr << "The diet list is empty!" << endl;
    else
        this->storeWeeklyPlan(this->mDietStr, this->mpDietList);   //Call the private function associated with diet plans
    this->mDietStr.close();  //Close the file
}


void FitnessAppWrapper::storeWeeklyExercisePlan()
{
    // We want to start overwritting from the beginning of the "exercisePlan.txt" file
    // We will close the stream associated with the file if it's open!
    if (this->mExerciseStr.is_open()) // is_open () returns true if file open, false otherwise
        this->mExerciseStr.close();   // close it so we can start from the beginning of the file

    this->mExerciseStr.open("exercisePlans.txt", std::ios::out);  //Opens in output mode 

    if (this->mpExerciseList->getHeadPtr() == NULL)    //The list is empty
        this->mExerciseStr << "The exercise list is empty!" << endl;
    else
        this->storeWeeklyPlan(this->mExerciseStr, this->mpExerciseList);   //Call the private function associated with exercise plans
    this->mExerciseStr.close();  //Close the file
}



//Two following functions will prompt the user for the name of the plan to edit its goal, then display the new plan to the screen
//This will call editGoal() functions in DietPlan and ExercisePlan classes
void FitnessAppWrapper::editDietPlan()
{
    //First, display the weekly plan to the screen for the user to view
    displayWeeklyDietPlan();
    cout << endl << "****************************************************************" << endl;

    bool found = false;   //To check whether the input name is found
    cin.ignore();  //Ignore next character in stream
    do
    {
        //Prompt the user for the name of the plan to edit its goal
        cout << "Please, enter one name of a plan that you would like to edit: ";      
        string name = "";
        std::getline(cin, name);   //Get string input
      
        //Search the corresponding node in the list
        dietNode* pCur = this->mpDietList->getHeadPtr();
        while (pCur != NULL)
        {
            if (pCur->plan.getPlanName() == name)
            {
                found = true;
                break;    //Break the loop
            }
            pCur = pCur->pNext;
        }

        if (found == true)   //Found
        {   //Clear the screen and display the current plan before editing
            system("cls");
            cout << pCur->plan << endl << endl;

            pCur->plan.editGoal();
            break;    //Break the loop
        }

        else   //The plan name does not exist 
        {
            cout << endl << "Your plan name does not exist in the list! Please try again!" << endl;
        }
    } while (found == false);
}



void FitnessAppWrapper::editExercisePlan()
{
    //First, display the weekly plan to the screen for the user to view
    displayWeeklyExercisePlan();
    cout << endl << "****************************************************************" << endl;

    bool found = false;   //To check whether the input name is found
    cin.ignore();  //Ignore next character in stream
    do
    {
        //Prompt the user for the name of the plan to edit its goal
        cout << "Please, enter one name of a plan that you would like to edit: ";
        string name = "";
        std::getline(cin, name);

        //Search the corresponding node in the list
        exerciseNode* pCur = this->mpExerciseList->getHeadPtr();
        while (pCur != NULL)
        {
            if (pCur->plan.getPlanName() == name)
            {
                found = true;
                break;    //Break the loop
            }
            pCur = pCur->pNext;
        }

        if (found == true)   //Found
        {   //Clear the screen and display the current plan before editing
            system("cls");
            cout << pCur->plan << endl << endl;

            pCur->plan.editGoal();
            break;    //Break the loop
        }

        else   //The plan name does not exist 
        {
            cout << endl << "Your plan name does not exist in the list! Please try again!" << endl;
        }
    } while (found == false);
}






//The function is for running all the application
void FitnessAppWrapper::runApp()
{
    int opt = 0; //Option of the user

    do   //The main loop during the application is running
    {
        //Display the main menu
        this->displayMenu();

        //Prompt the user for an option of feature
        cout << " Please, enter your option of feature (1-9): ";
        cin >> opt;

        system("cls");  //Clear the screen before demonstrating the chosen feature
        if (opt == 1)   //Load weekly diet plans from file
        {
            this->loadWeeklyDietPlan();
            cout << " The weekly diet plan has been loaded!" << endl;
        }

        else if (opt == 2)   //Load weekly exercise plans from file
        {
            this->loadWeeklyExercisePlan();
            cout << " The weekly exercise plan has been loaded!" << endl;
        }


        else if (opt == 3)   //Store weekly diet plan to file
        {
            this->storeWeeklyDietPlan();
            cout << " The weekly diet plan has been stored to the file!" << endl;
        }

        else if (opt == 4)   //Store weekly exercise plan to file
        {
            this->storeWeeklyExercisePlan();
            cout << " The weekly exercise plan has been stored to the file!" << endl;
        }

        else if (opt == 5)  //Display weekly diet plans to screen
            this->displayWeeklyDietPlan();

        else if (opt == 6)  //Display weekly exercise plans to screen
            this->displayWeeklyExercisePlan();


        else if (opt == 7)  //Edit diet plan
        {
            if (this->mpDietList->getHeadPtr() == NULL)
                cout << " The weekly diet plan is empty, no plan to edit!" << endl;
            else
                this->editDietPlan();
        }
            

        else if (opt == 8)   //Edit exercise plan
        {
            if (this->mpExerciseList->getHeadPtr() == NULL)
                cout << " The weekly exercise plan is empty, no plan to edit!" << endl;
            else
                this->editExercisePlan();
        }
            
        

        else if (opt == 9)   //Write the most recent weekly plans to the corresponding files,  and then exit the application
        {
            this->storeWeeklyDietPlan();
            this->storeWeeklyExercisePlan();
            cout << " The most recent weekly plans have been stored to the corresponding files!" << endl;
        }


        else   // Invalid option
        {
            cout << " Your option is invalid! Please, try again!" << endl;
        }

        if (opt != 9)  //If the user did not choose Exit, then prompt to return the main menu
        {
            cout << "\n Please, hit the ENTER key to return the main menu!";
            _getch();
            system("cls");    //Clear the screen before returnning back the main menu
        }

    } while (opt != 9);  //Only break the loop when the user choose option 9 as Exit
}










/////////////////////  Private helper/utility functions  \\\\\\\\\\\\\\\\\\\\\\\\

//Two loadDailyPlan() functions. Reads one record from the given stream. Precondition: The file is already open!
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan)
{
    fileStream >> plan;   // Use overloaded file stream extraction operator
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan)
{
    fileStream >> plan;   // Use overloaded file stream extraction operator
}




//Two loadWeeklyPlan() functions. Calls loadDailyPlan() functions to read all seven daily plans from the given stream. 
//Precondition: The file is already open!
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ListNode* pDietList)
{
    DietPlan newPlan;
    while (!fileStream.eof())
    {
        loadDailyPlan(fileStream, newPlan);    //Call the loadDailyPlan() function to read each daily plan
        fileStream.ignore();                   //Ignore '\n' as the blank line between plans in the file

        pDietList->insertAfter(newPlan);       //Insert a new node with the new plan at the end of list
    }
}


void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, List* pExerciseList)
{
    ExercisePlan newPlan;
    while (!fileStream.eof())
    {
        loadDailyPlan(fileStream, newPlan);    //Call the loadDailyPlan() function to read each daily plan
        fileStream.ignore();                   //Ignore '\n' as the blank line between plans in the file

        pExerciseList->insertAfter(newPlan);   //Insert a new node with the new plan at the end of list
    }
}




//Two displayDailyPlan() functions. Apply the overloaded stream insertion operator to write a daily plan to the screen
void FitnessAppWrapper::displayDailyPlan(const DietPlan& plan)
{
    cout << plan;   //Use the overloaded stream insertion operator
}

void FitnessAppWrapper::displayDailyPlan(const ExercisePlan& plan)
{
    cout << plan;   //Use the overloaded stream insertion operator
}


//Two displayWeeklyPlan() functions. Calls displayWeeklyPlan() functions to write a weekly plan to the screen
void FitnessAppWrapper::displayWeeklyPlan(ListNode* pDietList)
{
    int day = 1;
    dietNode* pCur = pDietList->getHeadPtr();
    while (pCur)
    {
        cout << day << ") " << pCur->plan;
        pCur = pCur->pNext;
        day++;
    }
}

void FitnessAppWrapper::displayWeeklyPlan(List* pExerciseList)
{
    int day = 1;
    exerciseNode* pCur = pExerciseList->getHeadPtr();
    while (pCur)
    {
        cout << day << ") " << pCur->plan;
        pCur = pCur->pNext;
        day++;
    }
}




//Two storeDailyPlan() functions. Apply the overloaded stream insertion operator to write a daily plan to a file
void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, DietPlan& plan)
{
    fileStream << plan;   //Use the overloaded stream insertion operator
}


void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, ExercisePlan& plan)
{
    fileStream << plan;   //Use the overloaded stream insertion operator
}



//Two storeWeeklyPlan() functions. Calls storeDailyPlan() functions to write a weekly plan to a file
void FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, ListNode* pDietList)
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
    dietNode* pCur = pDietList->getHeadPtr();
    while (pCur)
    {
        storeDailyPlan(fileStream, pCur->plan);
        pCur = pCur->pNext;
        if(pCur)
            fileStream << endl;    //A blank line betwwen plans
    }
}


void FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, List* pExerciseList)
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
    exerciseNode* pCur = pExerciseList->getHeadPtr();
    while (pCur)
    {
        storeDailyPlan(fileStream, pCur->plan);
        pCur = pCur->pNext;
        if (pCur)
            fileStream << endl;    //A blank line betwwen plans
    }
}





