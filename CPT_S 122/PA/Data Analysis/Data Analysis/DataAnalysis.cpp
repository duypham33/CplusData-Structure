
/*

    This file is to establish the definitions for all programmer-defined functions of BST Class, aside from main ()

*/

#include "DataAnalysis.h"

//Function definitions

//Default constructor
DataAnalysis::DataAnalysis()
{
    //The empty BSTs is initialized
}

//Destructor
DataAnalysis::~DataAnalysis()
{
    //The destructors of BSTs has been invoked! The BSTs are destroyed!
}


//This function runs the main applicaiton. (Calls the private functions)
bool DataAnalysis::runAnalysis()
{
    //Open the data.csv file
    this->openFile();
    if (this->mCsvStream.is_open())
    {
        cout << "   \t\tConsumer Products Analysis Over 48 Hours" << endl;
        //Display the contents of the two BSTs, which will be printed in order
        cout << "Please, press the ENTER key to view the products that are purchased and sold!";
        _getch();
        this->displayProducts();
        cout << "*******************************************************************************" << endl;
        //Display the trends in consumer products over a 48-hour period
        cout << "Please, press the ENTER key to view the trends in consumer products over a 48-hour period!";
        _getch();
        this->reportTrend();

        return true;
    }

    else
    {
        cout << "The analysis program is failed!" << endl;
        return false;
    }   
}




//Private functions

//This function opens the data.csv file. Returns true if the file is opened, false is otherwise.
void DataAnalysis::openFile()
{
    //Opens the data.csv file
    this->mCsvStream.open("data.csv", std::ios::in);
}


//This function reads one line from the file and splits the line into units, type, and transaction fields.
void DataAnalysis::readLine(int& units, string& type, string& transaction)
{
    string line = "";   //The string used to read the line
    //Read the line in the file
    this->mCsvStream >> line;
    if (line == "")  //An empty line
    {
        units = -1;
        type = "";
        transaction = "";
    }
    else
    {
        //Splits the line into units, type, and transaction fields
        std::stringstream ss(line);    //Stringstream is efficient to parse a string
        std::getline(ss, type, ',');   //Use type to get the string unit first, so we do not need to declare any temp string to get the string unit
        units = atoi(type.c_str());    //Convert the string unit into integer

        std::getline(ss, type, ',');       //Get the string type
        std::getline(ss, transaction);     //Get the string transaction
    }
}


//This function loops until all lines are read from the file; calls the insertNode() function below, 
//and then displays the current contents of both BSTs; use inOrderTraversal() to display the trees.
void DataAnalysis::displayProducts()
{
    if (this->mCsvStream.is_open())
    {
        //The file is opened
        string line = "";   //The string used to read the title line
        this->mCsvStream >> line;   //Read the title line
        while (!this->mCsvStream.eof())   //Loops until all lines are read from the file
        {
            //Read and parse the line by calling the readLine() function
            int units = 0;
            string type = "";
            string transaction = "";
            this->readLine(units, type, transaction);
            if (units != -1)  //Check whether the line is empty or not
            {
                //Insert the units and type into the appropriate tree - calls insertNode() function
                this->insertNode(units, type, transaction);
            }
        }

        //Displays the current contents of both BSTs; use inOrderTraversal() to display the trees.
        cout << endl << endl <<  "The products that were purchased over a 48-hour period:" << endl;
        this->mTreePurchased.inOrderTraversal();
        cout << endl;
        cout << "The products that were sold over a 48-hour period:" << endl;
        this->mTreeSold.inOrderTraversal();
    }

    else
        cout << "Failed to open the data.csv file!" << endl;

    //Close the file
    this->mCsvStream.close();
}


//This function compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased)
void DataAnalysis::insertNode(int& units, string& type, string& transaction)
{
    if (transaction == "Purchased")
        this->mTreePurchased.insert(type, units);
    else
        this->mTreeSold.insert(type, units);
}


//This function writes to the screen the type and number of units that are least purchased and sold, and the most purchased and sold.
void DataAnalysis::reportTrend()
{
    cout << endl << endl;
    cout << "The product with the number of units that were most sold:  ";
    this->mTreeSold.findLargest().printData();

    cout << "The product with the number of units that were least sold:  ";
    this->mTreeSold.findSmallest().printData();

    cout << endl;

    cout << "The product with the number of units that were most purchased:  ";
    this->mTreePurchased.findLargest().printData();

    cout << "The product with the number of units that were least purchased:  ";
    this->mTreePurchased.findSmallest().printData();
}