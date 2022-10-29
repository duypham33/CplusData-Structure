
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Tracker App class

*/


#ifndef TRACKER_APP_H //guard code

#define TRACKER_APP_H
#define _CRT_SECURE_NO_WARNINGS //ignore the error about localtime()

#include "List.h"
#include "List.cpp"

#include <conio.h>
#include <time.h>





namespace CommonFunc
{
string currentDate();

void askAbsence(Node<Data>*pCurrent);

Node<Data>* searchID(Node<Data>* list, int ID);

void printVer1(Node<Data>* pNode, ofstream& fout);
};





class TrackerApp
{
public:
	//Default constructor
	TrackerApp();

	//Constructor
	TrackerApp(const List<Data> newList);

	//Destructor
	~TrackerApp();

	void displayMenu();
	int getOption();

	void read(fstream& infile);
	void import();
	void load();
	bool store();
	void makeAbsence();
	void editAbsence();
	void reportVer1();
	void reportVer2();

	void generateReport();

	List<Data>* getListPtr();


	void run();
	

private:
	List<Data> mMasterList;    

	//void destroy();
};







#endif
