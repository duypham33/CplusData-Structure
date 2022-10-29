
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Tracker App class

*/


#ifndef TRACKER_APP_H //guard code

#define TRACKER_APP_H
#define _CRT_SECURE_NO_WARNINGS //ignore the error about localtime()

#include "List.h"

#include <conio.h>     //Neccessary to use getch() function
#include <time.h>      //Neccessary to use time(), and localtime() functions


//This class is to implement the main application 
class TrackerApp
{
public:
	//Default constructor
	TrackerApp();

	//Destructor
	~TrackerApp();

	//Operations

	//This function displays the main menu
	void displayMenu();

	//This function prompts the user for an option of a feature. Returns the valid option
	int getOption();

	//This function runs the main application
	void runApp();

private:
	//Data member - The master list
	List<Data> mMasterList;

	////////////////////////////////////// Private Functions \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	
    // This function is a helper for import and load features. This reads all records from the file and inserts each record at front of the master list.
	bool read(fstream& fin);

	// Import feature: Read record from a file, and OVERWRITES the master list. 
	// So the destroyList() function in the List class is used to clear the list before loading new records
	bool importList();

	// Load feature: Populates the master list with previous records from master.txt file. So it inserts more nodes, not overwrites the list.
	bool load();

	// Store feature: Stores the contents of the master list’s nodes to master.txt
	bool store();

	//Functions for the feature of making absence
	//This function gets the current day based on the local time
	string currentDate();
	//This function prompts the user for whether the student is absent or not on the current day
	void askAbsence(Node<Data>* pCur);
	//This function runs through the master list, displays each student's name, and prompts if he/she was absent for the current day.
	void makeAbsence();

	//Functions for the feature of edtting absence
	//This function searches a node with the record matching with the ID or student name that the user enters.
	Node<Data>* search(string IDorNAME);
	//This function prompts the user for a date to remove from absent dates of the student just found!
	void askDate(Node<Data>* pFound);
	//This function is for the whole feature of editting absence
	void editAbsence();

	//Functions for generating reports
	//This function reports version 1: Shows all of the students in the class and 
	// the number of times they have been absent, along with the date of the most recent absence (peek ())
	bool reportVer1();
	//This function reports version 2: Shows the names of the students absent for those who are absent greater than some threshold set.
	bool reportVer2();
	//This function is for the whole report feature
	bool report();

};




#endif