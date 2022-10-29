
/*

  This is the header file that stores standard library includes, #defined and function prototypes and definitions of DataAnalysis Class

*/


#ifndef DATA_ANALYSIS_H   //guard code

#define DATA_ANALYSIS_H

#include "BST.h"
#include <fstream>     //Neccessary to work with file
#include <sstream>     //Neccessary to use stringstream, which is efficient to parse a string 
#include <conio.h>     //Neccessary to use _getch() function

using std::ifstream;

//This class is for the main application
class DataAnalysis
{
public:
	//Default constructor
	DataAnalysis();

	//Destructor
	~DataAnalysis();

	//This function runs the main applicaiton. (Calls the private functions)
	bool runAnalysis();

private:
	//Data members
	BST mTreePurchased;    //Represents the products that were purchased
	BST mTreeSold;         //Represents the products that were sold
	ifstream mCsvStream;   //The filestream for reading the data.csv file

	//Private functions
	//This function opens the data.csv file. Returns true if the file is opened, false is otherwise.
	void openFile();
	//This function reads one line from the file and splits the line into units, type, and transaction fields.
	void readLine(int& units, string& type, string& transaction);
	//This function loops until all lines are read from the file; calls the insertNode() function below, 
	//and then displays the current contents of both BSTs; use inOrderTraversal() to display the trees.
	void displayProducts();
	//This function compares the transaction field and inserts the units and type into the appropriate tree (mTreeSold or mTreePurchased)
	void insertNode(int& units, string& type, string& transaction);
	//This function writes to the screen the type and number of units that are least purchased and sold, and the most purchased and sold.
	void reportTrend();
};


#endif