
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Data class

*/


#ifndef DATA_H //guard code

#define DATA_H

#include <fstream>   //Neccessary to work with files
#include <iomanip>   //for using setw() to display nicer output
#include "Stack.h"

using std::fstream;
using std::ofstream;
using std::ostream;

// For displaying nicer output
using std::setw;
using std::left;


//This class stores the fields acquired from each record of each student
class Data
{
public:
	//Default constructor
	Data();

	//Destructor
	~Data();

	//Setter
	void setBasicInf(const int& newRecordNum, const int& newID, const string& newName, const string& newEmail,
		const string& newUnits, const string& newMajor, const string& newLevel);

	//Getter
	//This is used to to detect a empty line in the file. Usually, there is an empty line at the end of file.
	//So if the record number of the data equals 0, it read the empty line and parse to the data. Then we won't insert this empty data to the list.
	int getRecordNum() const;
	int getID() const;
	string getName() const;
	Stack* getpAbsenDates();
	int getAbsentNum() const;
	
	//This function increase the number of absent times, once the student is absent for a date. Or decrease it when the user removes one absent date.
	// flag == 1, then increases it. If flag == 0, decreases it.
	void modifyAbsence(int flag);

	//Friend functions
	// Friend overloaded fstream insertion operator - Directly access the private data members without getters
	friend ofstream& operator << (ofstream& lhs, const Data& rhs);

	// Friend overloaded stream insertion operator - Directly access the private data members without getters
	friend ostream& operator << (ostream& lhs, const Data& rhs);

private:
	//Data members
	int mRecordNum;      // Record number (max 3 digits)
	int mID;             // ID number (max 9 digits)
	string mName;        // Name (last, first)
	string mEmail;       // Email
	string mUnits;       // Units (the number of credits for class or AU for audit)
	string mMajor;       // Program (major)
	string mLevel;       // Level (freshman, sophomore, junior, senior, graduate)
	int mAbsentNum;      // The number of absences that each student had
	Stack mAbsenDates;   // The dates of absences of each student (This is stored in the stack data structure)
};



//Non-member functions

//This function helps split a string into multiples strings, useful to get the record data 
string slitString(string& source, string delimiter);

//Overloaded operator >> for Data type with filestream 
fstream& operator >> (fstream& lhs, Data& rhs);






#endif