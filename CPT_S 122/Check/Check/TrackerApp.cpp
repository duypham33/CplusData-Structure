
/*

    This file is to establish the definitions for all programmer-defined functions of Tracker App class, aside from main ()

*/


#include "TrackerApp.h"


//Function definitions


TrackerApp::TrackerApp()
{

}


TrackerApp::TrackerApp(const List<Data> newList)
{
    this->mMasterList = newList;
}


TrackerApp::~TrackerApp()
{

}



void TrackerApp::displayMenu()
{
    cout << "\t\t\t\tMAIN MENU" << endl;
    cout << "\t\t\t  1. Import course list" << endl;
    cout << "\t\t\t  2. Load master list" << endl;
    cout << "\t\t\t  3. Store master list" << endl;
    cout << "\t\t\t  4. Mark absences" << endl;
    cout << "\t\t\t  5. Edit absences" << endl;
    cout << "\t\t\t  6. Generate report" << endl;
    cout << "\t\t\t  7. Print list" << endl;
    cout << "\t\t\t  8. Exit" << endl;

    cout << "  ****************************************************************************" << endl << endl;
}



int TrackerApp::getOption()
{
    int opt = 0;

    do
    {
        cout << " Please, enter your menu option (1-8): ";
        cin >> opt;

        if (opt < 1 || opt > 8)
        {
            cout << "\n Your option number is invalid! Please, try again!" << endl << endl;
        }
    } while (opt < 1 || opt > 8);

    return opt;
}




void TrackerApp::read(fstream& infile)
{
    //Get the title line first
    string titleLine;
    std::getline(infile, titleLine);


    //Read the data
    Data* newDataPtr = new Data();
    while (!infile.eof())
    {
        //Read the data
        infile >> (*newDataPtr);

        //Insert into the master list at front
        mMasterList.InsertAtFront(*newDataPtr);
    }

    delete newDataPtr;
}







void TrackerApp::import()
{
    fstream infile;
    infile.open("courseList.csv", std::ios::in);

    if (mMasterList.getHeadPtr() != NULL)
    {
        mMasterList.clearList();
    }

    read(infile);

    infile.close();
}



void TrackerApp::load()
{
    fstream infile;
    infile.open("master.txt", std::ios::in);


    if (infile.eof())
    {
        cout << "The file is empty!" << endl;
    }

    else
    {
        read(infile);
    }

    infile.close();
}



bool TrackerApp::store()
{
    bool success = false;

    ofstream outfile;
    outfile.open("master.txt");


    Node<Data>* pMem = mMasterList.getHeadPtr();

    if (pMem != NULL)    //The master list is not empty
    {
        //Write the title line first
        outfile << "Record number,ID,Name,Email,Units,Program,Level";

        //Overwrite the data

        int recordNum = 1;
        while (pMem != NULL)
        {
            outfile << endl << recordNum << ",";
            outfile << *(pMem->getDataPtr());

            recordNum++;
            pMem = pMem->getNextPtr();
        }

        success = true;
    }

    outfile.close();

    return success;
}



List<Data> TrackerApp::getList() const
{
    return mMasterList;
}



void TrackerApp::makeAbsence()
{
    //Firstly, display the master list
    mMasterList.print();

    cout << "\n************************************************************\n";
    cout << "   Today(m/d/y): " << currentDate() << endl;
    cout << setw(60) << "(y/n)" << endl;

    //Runs through the master list, to ask each student
    Node<Data>* pCur = mMasterList.getHeadPtr();

    while (pCur != NULL)
    {
        askAbsence(pCur);
        pCur = pCur->getNextPtr();
    }
}







void TrackerApp::editAbsence()
{

}









string currentDate()
{
    time_t t = time(0);   // get time now
    struct tm* now = localtime(&t);

    //cout << "  Today(m/d/y): " << (now->tm_mon + 1) << " / " << now->tm_mday << " / " << (now->tm_year + 1900) << endl;

    //Get the date in string form to push into the stack of absence dates
    int number = (now->tm_mon + 1);
    string month = std::to_string(now->tm_mon + 1);
    string day = std::to_string(now->tm_mday);
    string year = std::to_string(now->tm_year + 1900);

    string date = month + " / " + day + " / " + year;

    return date;
}















void TrackerApp::run()
{
    int option = 0;
    do
    {
        displayMenu();
        option = getOption();

        system("cls");

        switch (option)
        {
        case 1: import();
            cout << "Import the course file successfully!" << endl;
            break;

        case 2: load();
            cout << "Load the master file successfully!" << endl;
            break;

        case 3:
            if (store() == true)
            {
                cout << "Store the master file successfully!" << endl;
            }
            else { cout << "The master list is empty! Stored nothing to the file!" << endl; }
            break;

        case 4:
            makeAbsence();
            break;


        case 7: 
            //Print the title
            cout << setw(55) << "THE MASTER LIST" << endl;
            cout << " ID" << setw(14) << "Name" << setw(25) << "Email" <<
                setw(21) << "Units" << setw(11) << "Major" << setw(12) << "Level" << endl;
            mMasterList.print();
            cout.clear();
            break;

        default:
            break;
        }

        if (option != 8)
        {
            cout << "\n\n****************************************************************\n";
            cout << "Please, hit the ENTER to return the main menu!";
            _getch();   system("cls");
        }

    } while (option != 8);
}




void TrackerApp::run2()
{
    int option = 0;
    do
    {
        displayMenu();
        option = getOption();

        system("cls");

        if (option == 1)
        {
            import();
            cout << "Import the course file successfully!" << endl;
        }

        else if (option == 2)
        {
            load();
            cout << "Load the master file successfully!" << endl;
        }


        else if (option == 3)
        {
            if (store() == true)
            {
                cout << "Store the master file successfully!" << endl;
            }
            else { cout << "The master list is empty! Stored nothing to the file!" << endl; }
        }

        else if (option == 4)
        {
            makeAbsence();
        }

        else if (option == 7)
        {
            mMasterList.print();
        }


        if (option != 8)
        {
            cout << "\n\n****************************************************************\n";
            cout << "Please, hit the ENTER to return the main menu!";
            _getch();   system("cls");
        }



    } while (option != 8);
}






















/// <summary>
/// 
/// </summary>
/// <param name="pCurrent"></param>

void askAbsence(Node<Data>* pCurrent)
{
    char answer = '\0';    //'y' for Yes, 'n' for No

    cout << "Was " << pCurrent->getDataPtr()->getName() << setw(20) << left << " absent for today?: ";
    cin >> answer;
    cin.ignore();

    if (answer == 'y')     //If yes, update the number and the dates of absences 
    {
        //Increase the number of absent times
        int absenNum = pCurrent->getDataPtr()->getAbsenNum() + 1;
        pCurrent->getDataPtr()->setAbsenNum(absenNum);

        //Push the date into the stack of absent dates
        string date = currentDate();
        pCurrent->getDataPtr()->getpAbsenDates()->push(date);
    }
}





Node<Data>* searchID(List<Data> list, int ID)
{
    Node<Data>* pCur = list.getHeadPtr();

    while (pCur != NULL)
    {
        if (pCur->getDataPtr()->getID() == ID)
        {
            break;   //break the loop
        }

        pCur = pCur->getNextPtr();
    }

    return pCur;     //If the ID does not exist in the list, pCur = NULL 
}