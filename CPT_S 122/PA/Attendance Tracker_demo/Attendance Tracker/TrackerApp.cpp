
/*

    This file is to establish the definitions for all programmer-defined functions of Tracker App class, aside from main ()

*/


#include "TrackerApp.h"


//Function definitions


TrackerApp::TrackerApp()
{
   
}


TrackerApp::TrackerApp(const List<Data>  newList)
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



List<Data>* TrackerApp::getListPtr() 
{
    return &mMasterList;
}



void TrackerApp::makeAbsence()
{
    //Firstly, display the master list
    mMasterList.print();

    cout << "\n************************************************************\n";
    cout << "   Today(m/d/y): " << CommonFunc::currentDate() << endl;
    
    //Runs through the master list, to ask each student
    Node<Data>* pCur = mMasterList.getHeadPtr();

    while (pCur != NULL)
    {
        CommonFunc::askAbsence(pCur);
        pCur = pCur->getNextPtr();
    }
}







void TrackerApp::editAbsence()
{
    //Firstly, display the master list
    mMasterList.print();
   
    if (mMasterList.getHeadPtr() != NULL)      //Check if the list is empty or not
    {
        Node<Data>* pSearch = NULL;

        do
        {
            cout << "\n************************************************************\n";
            cout << "  Please, enter the ID number of the student to edit: ";

            int ID = 0;
            cin >> ID;
            //cin.ignore();

            pSearch = CommonFunc::searchID(mMasterList.getHeadPtr(), ID);

            if (pSearch == NULL)
            {
                cout << "\n  This ID does not exist in the master list!\n";
            }
        } while (pSearch == NULL);
        
        cout << "\n************************************************************\n";
        cout << "  All of the absent dates of " << pSearch->getDataPtr()->getName() << ": ";

        //Display the all of the absent dates
        if (pSearch->getDataPtr()->getpAbsenDates()->isEmpty())
        {
            cout << "   EMPTY" << endl;
        }

        else
        {
            pSearch->getDataPtr()->getpAbsenDates()->print();
            bool found = false;

            cin.ignore();
            do
            {              
                cout << "\n************************************************************\n";
                cout << " Please, type the date(m / d / y) that you want to remove out of the list:  ";

                string date;
                cin.sync();                
                std::getline(cin, date);
                

                found = pSearch->getDataPtr()->getpAbsenDates()->remove(date);
                if (!found)
                {
                    cout << " This date does not exist in the list or be invalid! Make sure you fill in exact form (m / d / y)!" << endl;
                }
            } while (!found);

            cout << "\n\n  The chosen date was successfully removed!" << endl;

            //Updating the number of absences field
            int absenNum = pSearch->getDataPtr()->getAbsenNum() - 1;
            pSearch->getDataPtr()->setAbsenNum(absenNum);
        }

        //delete pSearch;
    }
}






void TrackerApp::reportVer1()
{
    Node<Data>* pCur = mMasterList.getHeadPtr();

    ofstream fout;
    fout.open("reportVersion1.txt", std::ios::out);

    if (fout.is_open())
    {
        if (pCur == NULL)    //Empty list
        {
            cout << " There is currently no student in the class!\n";
            fout << " There is currently no student in the class!\n";
        }

        else
        {
            while (pCur != NULL)
            {
                CommonFunc::printVer1(pCur, fout);
                pCur = pCur->getNextPtr();
            }

            cout << "\n*************************************************************************\n";
            cout << " The report was stored to the file!" << endl;
        }
    }
}



void TrackerApp::reportVer2()
{
    Node<Data>* pCur = mMasterList.getHeadPtr();

    ofstream fout;
    fout.open("reportVersion2.txt", std::ios::out);

    if (fout.is_open())
    {
        if (pCur == NULL)    //Empty list
        {
            cout << " There is currently no student in the class!\n";
            fout << " There is currently no student in the class!\n";
        }

        else
        {
            //Prompt a threshold for the number of absences
            cout << " Please, enter a number as threshold for the number of absences: ";
            int threshold = 0;
            cin >> threshold;

            cout << "**************************************************************************\n\n";

            bool found = false;
            while (pCur != NULL)
            {
                if (pCur->getDataPtr()->getAbsenNum() > threshold)
                {
                    cout << "  " << pCur->getDataPtr()->getName() << " with " << pCur->getDataPtr()->getAbsenNum() << " absence(s)" << endl;
                    fout << "  " << pCur->getDataPtr()->getName() << " with " << pCur->getDataPtr()->getAbsenNum() << " absence(s)" << endl;
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
                cout << "No student with absences that exceed threshold\n";
                fout << "No student with absences that exceed threshold\n";
            }
        }
    }
}















void TrackerApp::generateReport()
{
    cout << "   TWO VERSIONS" << endl;
    cout << " 1. Display and store all the students with the number of absences and the most recent date" << endl;
    cout << " 2. Display and store all the students who are absent greater than threshold inputted" <<endl;

    int opt = 0;
    do
    {
        cin.ignore();
        cout << "\n\n Please, enter your option (1-2): ";
        cin >> opt;

        if (opt != 1 && opt != 2)
        {
            cout << "\n\n Your option is invalid! Please, try again!" << endl;
        }
    } while (opt != 1 && opt != 2);

        
    system("cls");
    if (opt == 1)
    {
        reportVer1();
    }

    else if (opt == 2)
    {
        reportVer2();
    }
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
                { cout << "Store the master file successfully!" << endl; }
                else { cout << "The master list is empty! Stored nothing to the file!" << endl; }
                break;

        case 4:
                makeAbsence();
                break;

        case 5:
                editAbsence();
                break;

        case 6:
                generateReport();
                break;

        case 7: mMasterList.print();
                break;

        default: break;
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
namespace CommonFunc
{

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




    void askAbsence(Node<Data>* pCurrent)
    {
        char answer = '\0';    //'y' for Yes, 'n' for No

        cout << "Was " << pCurrent->getDataPtr()->getName() << " absent for today? (y/n): ";
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





    Node<Data>* searchID(Node<Data>* pList, int ID)
    {
        Node<Data>* pCur = pList;

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





    void printVer1(Node<Data>* pNode, ofstream& fout)
    {
        int num = pNode->getDataPtr()->getAbsenNum();

        //Display to screen
        cout << "  " << pNode->getDataPtr()->getName() << " was absent " << num << " time(s)";
             //<< " times with the most recent date " << pNode->getDataPtr()->getpAbsenDates()->peek() << endl;

        //Write to the .txt file
        fout << " " << pNode->getDataPtr()->getName() << " was absent " << num << " time(s)";
            //<< " times with the most recent date " << pNode->getDataPtr()->getpAbsenDates()->peek() << endl;

        if (num == 0)
        {
            cout << endl;
            fout << endl;
        }

        else
        {
            cout << " with the most recent date " << pNode->getDataPtr()->getpAbsenDates()->peek() << endl;
            fout << " with the most recent date " << pNode->getDataPtr()->getpAbsenDates()->peek() << endl;
        }
            
    }
};