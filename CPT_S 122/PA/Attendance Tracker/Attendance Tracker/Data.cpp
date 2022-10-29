
/*

	This file is to establish the definitions for all programmer-defined functions of Data class, aside from main ()

*/


#include "Data.h"


//Function definitions

//Default constructor
Data::Data()
{
	//Initialize data members
	mRecordNum = 0;
	mID = 0;
	mName = "";
	mEmail = "";
	mUnits = "";
	mMajor = "";
	mLevel = "";
	mAbsentNum = 0;
}


//Destructor
Data::~Data()
{
	//No resources are needed to deleted
}



//Setters

void Data::setBasicInf(const int& newRecordNum, const int& newID, const string& newName, const string& newEmail,
	const string& newUnits, const string& newMajor, const string& newLevel)
{
	this->mRecordNum = newRecordNum;
	this->mID = newID;
	this->mName = newName;
	this->mEmail = newEmail;
	this->mUnits = newUnits;
	this->mMajor = newMajor;
	this->mLevel = newLevel;
}




//Getter
//This is used to to detect a empty line in the file. Usually, there is an empty line at the end of file.
//So if the record number of the data equals 0, it read the empty line and parse to the data. Then we won't insert this empty data to the list.
int Data::getRecordNum() const
{
	return this->mRecordNum;
}



int Data::getID() const
{
	return this->mID;
}


string Data::getName() const
{
	return this->mName;
}

Stack* Data::getpAbsenDates()
{
	return (&this->mAbsenDates);
}

int Data::getAbsentNum() const
{
	return this->mAbsentNum;
}


//This function increase the number of absent times, once the student is absent for a date. Or decrease it when the user removes one absent date.
// flag == 1, then increases it. If flag == 0, decreases it.
void Data::modifyAbsence(int flag)
{
	if (flag)
		this->mAbsentNum++;
	else
		this->mAbsentNum--;
}


// Friend overloaded fstream insertion operator - Directly access the private data members without getters
ofstream& operator << (ofstream& lhs, const Data& rhs)
{
	//Write the record in the form:   1,1111,"Smith,John",smithj@cpts122.edu,4,CS,Freshman
	lhs << rhs.mRecordNum << "," << rhs.mID << ",\"" << rhs.mName << "\"," << rhs.mEmail << ","
		<< rhs.mUnits << "," << rhs.mMajor << "," << rhs.mLevel;

	return lhs;
}


// Friend overloaded stream insertion operator - Directly access the private data members without getters
ostream& operator << (ostream& lhs, const Data& rhs)
{
	lhs << rhs.mID << "      " << setw(20) << left << rhs.mName << setw(5) << left << rhs.mMajor << "     " << setw(15) << left << rhs.mLevel
	    << endl;
	return lhs;
}



//Non-member functions

//This function helps split a string into multiples strings, useful to get the record data 
string slitString(string& source, string delimiter)
{
	string retString = "";

	size_t pos = source.find(delimiter);   //The position of the first character of the delimiter in the string
	retString = source.substr(0, pos);     //Get a sub-string from index 0 to the found position
	source.erase(0, pos + delimiter.length());  //Remove the sub-string out the string

	return retString;  //Return the sub-string
}


//Overloaded operator >> for Data type with filestream 
fstream& operator >> (fstream& lhs, Data& rhs)
{
	string line;   //This string is used to read the line 
	string token;  //This string is used to get sub-strings as record data

	//Get the data line in the form:   1,1111,"Smith,John",smithj@cpts122.edu,4,CS,Freshman
	std::getline(lhs, line);
	if (line == "")  //An empty line
		return lhs;

	//Get record number
	token = slitString(line, ",");
	int newRecordNum = atoi(token.c_str());

	//Get ID
	token = slitString(line, ",");
	int newID = atoi(token.c_str());

	//Get name
	slitString(line, "\"");    //Remove "
	string newName = slitString(line, "\"");
	slitString(line, ",");

	//Get email
	string newEmail = slitString(line, ",");

	//Get units	
	string newUnits = slitString(line, ",");

	//Get major
	string newMajor = slitString(line, ",");

	//Get level
	string newLevel = line;

	//Set data 
	rhs.setBasicInf(newRecordNum, newID, newName, newEmail, newUnits, newMajor, newLevel);

	return lhs;
}