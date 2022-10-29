
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

class TrackerApp
{
public:
	//Default constructor
	TrackerApp();

	//Constructor
	TrackerApp(const List<Data>  newList);

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


	List<Data> getList() const;


	void run();
	void run2();

private:
	List<Data> mMasterList;

	//void destroy();
};




string currentDate();
//{
//	time_t t = time(0);   // get time now
//	struct tm* now = localtime(&t);
//
//	cout << "  Today(m/d/y): " << (now->tm_mon + 1) << " / " << now->tm_mday << " / " << (now->tm_year + 1900) << endl;
//
//	int number = (now->tm_mon + 1);
//	string month = std::to_string(now->tm_mon + 1);
//	string day = std::to_string(now->tm_mday);
//	string year = std::to_string(now->tm_year + 1900);
//
//	string date = month + day + year;
//
//	return date;
//}



void askAbsence(Node<Data>* pCurrent);

Node<Data>* searchID(List<Data> list, int ID);



#endif

