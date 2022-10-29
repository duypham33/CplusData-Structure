
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Data class

*/


#ifndef DATA_H //guard code

#define DATA_H


#include "Stack.h"

#include <fstream>
#include <iomanip>      //for using setw()

using std::fstream;
using std::ofstream;
using std::ostream;

using std::setw;
using std::left;


class Data
{
public:
	//Default constructor
	Data();

	//Destructor
	~Data();

	//Copy constructor
	Data(const Data& copy);

	//Setters
	void setBasicInf(const int& newID, const string& newName, const string& newEmail,
		const string& newUnits, const string& newMajor, const string& newLevel);

	void setAbsenNum(const int& newAbsenNum);

	//Getters
	int getID() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getMajor() const;
	string getLevel() const;
	int getAbsenNum() const;
	Stack* getpAbsenDates();

private:
	// record number (max 3 digits)
	int mID;             // ID number (max 9 digits)
	string mName;        // name (last, first)
	string mEmail;       // email
	string mUnits;          // units (number of credits for class or AU for audit)
	string mMajor;       // program (major)
	string mLevel;       // level (freshman, sophomore, junior, senior, graduate)
	int mAbsenNum;       // the number of absences
	Stack mAbsenDates;   // the dates of absences
};



fstream& operator >> (fstream& lhs, Data& rhs);

string slitString(string& source, string delimiter);

ofstream& operator << (ofstream& lhs, const Data& rhs);



ostream& operator << (ostream& lhs, const Data& rhs);










#endif
