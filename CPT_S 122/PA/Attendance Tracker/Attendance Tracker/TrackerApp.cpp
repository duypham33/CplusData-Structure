
/*

    This file is to establish the definitions for all programmer-defined functions of Tracker App class, aside from main ()

*/


#include "TrackerApp.h"


//Function definitions

//Default constructor
TrackerApp::TrackerApp()
{
    //The master list has been initialized as an empty list
}


//Destructor
TrackerApp::~TrackerApp()
{
    //When the destructor has been invoked, the destructor of the master list is also invoked. This would destroy the list.
}


//This function displays the main menu
void TrackerApp::displayMenu()
{
    cout << "\tMAIN MENU" << endl;
    cout << "  1. Import course list" << endl;
    cout << "  2. Load master list" << endl;
    cout << "  3. Store master list" << endl;
    cout << "  4. Mark absences" << endl;
    cout << "  5. Edit absences" << endl;
    cout << "  6. Generate report" << endl;
    cout << "  7. Exit" << endl;

    cout << "  ****************************************************************************" << endl << endl;
}


//This function prompts the user for an option of a feature. Returns the valid option
int TrackerApp::getOption()
{
    int opt = 0;

    do
    {
        cout << " Please, enter your menu option (1-7): ";
        cin >> opt;

        if (opt < 1 || opt > 7)  //Invalid option
            cout << "\n Your option number is invalid! Please, try again!" << endl;
        else
            break;
    } while (true);   //The infinite loop would stop once a valid option has been got.

    return opt;
}




// This function is a helper for import and load features. This reads all records from the file and inserts each record at front of the master list.
bool TrackerApp::read(fstream& fin)
{
    if (!fin.is_open())
        return false;
    //The file is opend!
    //Read the title line 
    string line = "";   //The string used to read the header file
    std::getline(fin, line);
    
    if (line != "The list is empty!")   //Check if the first line is "The list is empty". If so, do nothing.
    {
        while (!fin.eof())
        {
            Data newData;
            //Read record by using overloaded filestream extraction operator
            fin >> newData;

            //Check whether it did meet the empty line at the last line of the file. If so, the record number of the data equals 0.
            if (newData.getRecordNum() == 0)
                break;
            //Insert a node with the new record at the front of the list 
            this->mMasterList.insertFront(newData);
        }
    }

    //Close the file
    fin.close();

    return true;
}


// Import feature: Read record from a file, and OVERWRITES the master list. 
// So the destroyList() function in the List class is used to clear the list before loading new records
bool TrackerApp::importList()
{
    //Open the classList.csv file
    fstream infile;
    infile.open("classList.csv", std::ios::in);

    if (!infile.is_open())
        return false;
    //The file is opend!
    // If the master list is not empty, clear the list before loading new records (OVERWRITE)
    if (!this->mMasterList.isEmpty())
        this->mMasterList.destroyList();

    //Load new records from the file into the master list by calling the read() function
    return this->read(infile);

    //The file is closed within the read() function.
}



// Load feature: Populates the master list with previous records from master.txt file. So it inserts more nodes, not overwrites the list.
bool TrackerApp::load()
{
    //Open the master.txt file
    fstream infile;
    infile.open("master.txt", std::ios::in);

    if (!infile.is_open())
        return false;
    //The file is opend!
    
    //Populates the master list with previous records from master.txt file by calling the read() function
    return this->read(infile);

    //The file is closed within the read() function.
}




// Store feature: Stores the contents of the master list’s nodes to master.txt
bool TrackerApp::store()
{
    //Open the master.txt file, to overwrite the file
    ofstream outfile;
    outfile.open("master.txt", std::ios::out);   //Overwrite mode

    if (!outfile.is_open())
        return false;

    //The file is opened
    Node<Data>* pCur = mMasterList.getHeadPtr();

    if (pCur != NULL)    //The master list is not empty
    {
        //Write the title line first
        outfile << "Record number,ID,Name,Email,Units,Program,Level";

        //Overwrite the data
        int recordNum = 1;
        while (pCur != NULL)
        {
            outfile << endl;
            outfile << (*pCur->getDataPtr());

            pCur = pCur->getNextPtr();
        }
    }

    else
        outfile << "The list is empty!" << endl;

    //Close the file
    outfile.close();

    return true;
}




//Functions for the feature of making absence
//This function gets the current day based on the local time
string TrackerApp::currentDate()
{
    time_t t = time(0);   // get time now
    struct tm* now = localtime(&t);

    //Get the date in string form to push into the stack of absence dates
    string month = std::to_string(now->tm_mon + 1);
    string day = std::to_string(now->tm_mday);
    string year = std::to_string(now->tm_year + 1900);

    string date = month + " / " + day + " / " + year;

    return date;
}



//This function prompts the user for whether the student is absent or not on the current day
void TrackerApp::askAbsence(Node<Data>* pCur)
{
    char answer = '\0';    //'y' for Yes, 'n' for No

    do
    {
        cout << "Was " << pCur->getDataPtr()->getName() << " absent for today? (y/n): ";
        cin >> answer;
        if (answer != 'y' && answer != 'n')  //Check for validiation
            cout << "\nYour input is invalid! Please, enter 'y' (yes) or 'n' (no)!" << endl;
        else
            break;
    } while (true);
    
    if (answer == 'y')     //If yes, update the number and the dates of absences 
    {
        //Increase the number of absent times
        pCur->getDataPtr()->modifyAbsence(1);

        //Push the date into the stack of absent dates
        string date = this->currentDate();
        pCur->getDataPtr()->getpAbsenDates()->push(date);
    }
}


//This function runs through the master list, displays each student's name, and prompts if he/she was absent for the current day.
void TrackerApp::makeAbsence()
{
    if (this->mMasterList.isEmpty())
        cout << "There is no student record in the class!" << endl;
    else
    {
        //Display the class list
        cout << " \t\t    THE CLASS LIST" << endl;
        cout << " ID \t    Name\t     Major\t Level" << endl;
        this->mMasterList.print();
        
        cout << "\n************************************************************\n";
        cout << "   Today(m/d/y): " << this->currentDate() << endl;

        //Runs through the master list, to ask each student
        Node<Data>*  pCur = this->mMasterList.getHeadPtr();

        while (pCur)
        {
            this->askAbsence(pCur);
            pCur = pCur->getNextPtr();
        }
    }
}


//Functions for the feature of edtting absence
//This function searches a node with the record matching with the ID or student name that the user enters.
Node<Data>* TrackerApp::search(string IDorNAME)
{
    bool flag = false;     // true means IDorNAME is an ID, false means it is a student name

    int id = 0;
    if (IDorNAME[0] >= '0' && IDorNAME[0] <= '9')   //If the first character is a number, then the string is an ID
    {
        flag = true;
        id = atoi(IDorNAME.c_str());
    }
    
    Node<Data>* pCur = this->mMasterList.getHeadPtr();
    while (pCur)
    {
        if (flag)
        {
            if (pCur->getDataPtr()->getID() == id)
                break;
        }
        else
            if (pCur->getDataPtr()->getName() == IDorNAME)
                break;

        pCur = pCur->getNextPtr();
    }

    return pCur;
}

//This function prompts the user for a date to remove from absent dates of the student just found!
void TrackerApp::askDate(Node<Data>* pFound)
{
    cout << "All of the absent dates of " << pFound->getDataPtr()->getName() << ":";
    if (pFound->getDataPtr()->getpAbsenDates()->print())  //Display the all the absent dates 
    {
        bool found = false;
        while(!found)
        {
            cout << "\n************************************************************\n";
            cout << " Please, type the date(m / d / y) that you want to remove out of the list:  ";
            string date;
            std::getline(cin, date);

            //Search the input date from the user in the stack to remove it
            found = pFound->getDataPtr()->getpAbsenDates()->remove(date);
            if(!found)
                cout << " This date does not exist in the list or be invalid! Make sure you fill in exact form (m / d / y)! Notice whitespaces!" << endl;
        } 
        
        cout << "\n\n  The chosen date was successfully removed!" << endl;

        //Updating the number of absences field
        pFound->getDataPtr()->modifyAbsence(0);   //Decrease
    }
}



//This function is for the whole feature of editting absence
void TrackerApp::editAbsence()
{
    if (this->mMasterList.isEmpty())
        cout << "There is no student record in the class!" << endl;
    else
    {
        //Display the class list
        cout << " \t\t    THE CLASS LIST" << endl;
        cout << " ID \t    Name\t     Major\t Level" << endl;
        this->mMasterList.print();
        
        char ans = '\0';
        Node<Data>* pSearch = NULL;
        cin.ignore();
        while (true)
        {
            //Prompts the user for an ID or student name
            cout << "\n************************************************************\n";
            cout << "  Please, enter the ID number or the name of the student to edit his/her absent dates: ";
            string IDorNAME = "";
            std::getline(cin, IDorNAME);

            //Call the search() function to search a node with the matching record
            pSearch = this->search(IDorNAME);
            if (!pSearch)  //Input is not matched
            {
                cout << "There is no students matching with your input!" << endl;
                cout << "Do you want to try again, or return the main menu? (enter 'y' to try again, 'n' to return menu): ";
                cin >> ans;
                if (ans == 'n')
                    return;
                else
                    cin.ignore();
            }

            else   //Valid input 
                break;
        }

        cout << "\n************************************************************\n";
        this->askDate(pSearch);  //Call the askDate() function to ask and edit the absent date.
    }
}



//Functions for generating reports
//This function reports version 1: Shows all of the students in the class and 
// the number of times they have been absent, along with the date of the most recent absence (peek ())
bool TrackerApp::reportVer1()
{
    Node<Data>* pCur = mMasterList.getHeadPtr();
    //Open the file for reporting version 1
    ofstream fout;
    fout.open("reportVersion1.txt", std::ios::out);

    if (!fout.is_open())
        return false;
    //The file is opened
    if (!pCur)    //Empty list
    {
        cout << " There is currently no student in the class!" << endl;
        fout << " There is currently no student in the class!" << endl;
    }

    else
    {
        while (pCur)
        {
            int num = pCur->getDataPtr()->getAbsentNum();  //Get the number of absent times

            //Display to screen
            cout << "  " << pCur->getDataPtr()->getName() << " was absent " << num << " time(s)";

            //Write to the .txt file
            fout << pCur->getDataPtr()->getName() << " was absent " << num << " time(s)";
            
            if (num == 0)
            {
                cout << endl;
                fout << endl;
            }

            else  //If there is at least one absent date, show the most recent date.
            {
                cout << " with the most recent date " << pCur->getDataPtr()->getpAbsenDates()->peek() << endl;
                fout << " with the most recent date " << pCur->getDataPtr()->getpAbsenDates()->peek() << endl;
            }

            pCur = pCur->getNextPtr();
        }

        cout << "\n*************************************************************************\n";
        cout << " The report was stored to the file!" << endl;
    }

    return true;    //Time complexity: O(n) (n is the number of nodes in the list)
}


//This function reports version 2: Shows the names of the students absent for those who are absent greater than some threshold set.
bool TrackerApp::reportVer2()
{
    Node<Data>* pCur = mMasterList.getHeadPtr();
    //Open the file for reporting version 2
    ofstream fout;
    fout.open("reportVersion2.txt", std::ios::out);

    if (!fout.is_open())
        return false;
    //The file is opened
    if (!pCur)    //Empty list
    {
        cout << " There is currently no student in the class!" << endl;
        fout << " There is currently no student in the class!" << endl;
    }

    else
    {
        //Prompt a threshold for the number of absences
        cout << " Please, enter a number as threshold for the number of absences: ";
        int threshold = 0;
        cin >> threshold;

        cout << "**************************************************************************\n\n";

        bool found = false;
        while (pCur)
        {
            int num = pCur->getDataPtr()->getAbsentNum();
            if (num > threshold)
            {
                cout << "  " << pCur->getDataPtr()->getName() << " with " << num << " absence(s)" << endl;
                fout << pCur->getDataPtr()->getName() << " with " << num << " absence(s)" << endl;
                found = true;
            }

            pCur = pCur->getNextPtr();
        }

        if (found)
        {
            cout << "\n*************************************************************************\n";
            cout << " The report was stored to the file!" << endl;
        }
        else
        {
            cout << " No student with absences that exceed the threshold\n";
            fout << "No student with absences that exceed the threshold\n";
        }
    }

    return true;   //Time complexity: O(n) (n is the number of nodes in the list)
}


//This function is for the whole report feature
bool TrackerApp::report()
{
    // Print submenu 
    cout << "   TWO VERSIONS" << endl;
    cout << " 1. Display and store all the students with the number of absences and the most recent date" << endl;
    cout << " 2. Display and store all the students who are absent greater than threshold inputted" << endl;

    int opt = 0;
    while(true)
    {
        cout << "\n Please, enter your option (1-2): ";
        cin >> opt;

        if (opt != 1 && opt != 2)
            cout << "\n\n Your option is invalid! Please, try again!";
        else
            break;
    } 

    system("cls");  //Clear the screen
    if (this->mMasterList.isEmpty())
    {
        cout << " There is no students in the class!" << endl;
        return true;
    }
       
    if (opt == 1)
        return this->reportVer1();

    else if (opt == 2)
        return this->reportVer2();

    return false;
}




//This function runs the main application
void TrackerApp::runApp()
{
    int opt = 0;
    do
    {
        //Dusplay menu
        this->displayMenu();
        //Prompt the user for a feature option
        opt = this->getOption();

        //Clear the screen before showing feature
        system("cls");

        switch (opt)
        {
        case 1:  //Import feature
            if (this->importList())
                cout << "Import the class file successfully!" << endl;
            else
                cout << "Failed to import the class file!" << endl;
            break;
                    
        case 2:  //Load feature
            if (this->load())
                cout << "Load the master.txt file successfully!" << endl;
            else
                cout << "Failed to load the master.txt file!" << endl;
            break;

        case 3:  //Store feature
            if (this->store())
                cout << "Store the master.txt file successfully!" << endl;
            else
                cout << "Failed to store the master.txt file!" << endl;
            break;

        case 4:  //Make absence feature
            this->makeAbsence();
            break;

        case 5:  //Edit absence feature
            this->editAbsence();
            break;

        case 6:  //Report feature
            if (!this->report())
                cout << "Failed to open the file!" << endl;
            break;

        default:
            break;
        }

        if (opt != 7)  // The exit has not been chosen
        {
            cout << "\n\n************************************************************************************\n";
            cout << "Please, hit the ENTER to return the main menu!";
            _getch();
            system("cls");   //Clear the screen to turn back the main menu
        }

    } while (opt != 7);  //Exit

}