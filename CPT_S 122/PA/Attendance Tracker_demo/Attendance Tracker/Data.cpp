
/*

    This file is to establish the definitions for all programmer-defined functions of Data class, aside from main ()

*/


#include "Data.h"


//Function definitions


Data::Data()
{
	mID = 0;
	mName = "";
	mEmail = "";
	mUnits = "";
	mMajor = "";
	mLevel = "";
	mAbsenNum = 0;    
	mAbsenDates = {};
}


Data::~Data()
{

}


Data::Data(const Data& copy)
{
	mID = copy.mID;
	mName = copy.mName;
	mEmail = copy.mEmail;
	mUnits = copy.mUnits;
	mMajor = copy.mMajor;
	mLevel = copy.mLevel;
	mAbsenNum = copy.mAbsenNum;
	mAbsenDates = copy.mAbsenDates;
}








void Data::setBasicInf(const int& newID, const string& newName, const string& newEmail,
	                   const string& newUnits, const string& newMajor, const string& newLevel)
{
	mID = newID;
	mName = newName;
	mEmail = newEmail;
	mUnits = newUnits;
	mMajor = newMajor;
	mLevel = newLevel;
}



void Data::setAbsenNum(const int& newAbsenNum)
{
	this->mAbsenNum = newAbsenNum;
}





int Data::getID() const
{
	return mID;
}



string Data::getName() const
{
	return mName;
}


string Data::getEmail() const
{
	return mEmail;
}




string Data::getUnits() const
{
	return mUnits;
}


string Data::getMajor() const
{
	return mMajor;
}



string Data::getLevel() const
{
	return mLevel;
}



int Data::getAbsenNum() const
{
	return this->mAbsenNum;
}



Stack* Data::getpAbsenDates()
{
	return &mAbsenDates;
}





fstream& operator >> (fstream& lhs, Data& rhs)
{
	string line;
	string token;
	
	//Get the data line in the form:   1,1111,"Smith,John",smithj@cpts122.edu,4,CS,Freshman
	std::getline(lhs, line);


	//Remove record number
	slitString(line, ",");

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
	rhs.setBasicInf(newID, newName, newEmail, newUnits, newMajor, newLevel);

	return lhs;
}


string slitString(string& source, string delimiter)
{
	string retString = "";

	size_t pos = source.find(delimiter);
	retString = source.substr(0, pos);
	source.erase(0, pos + delimiter.length());

	return retString;
}




ofstream& operator << (ofstream& lhs, const Data& rhs)
{
	lhs << rhs.getID() << ",\"" << rhs.getName() << "\"," << rhs.getEmail() << ","
		<< rhs.getUnits() << "," << rhs.getMajor() << "," << rhs.getLevel();

	return lhs;
}


ostream& operator << (ostream& lhs, const Data& rhs)
{
	lhs << setw(10) << left << rhs.getID() << setw(20) << left << rhs.getName() << setw(30) << left << rhs.getEmail() 
		<< setw(10) << left << rhs.getUnits() << setw(10) << left << rhs.getMajor() << rhs.getLevel() << endl;

	return lhs;
}