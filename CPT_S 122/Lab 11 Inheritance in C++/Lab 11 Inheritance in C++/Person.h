
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Person Class

*/


#ifndef PERSON_H //guard code

#define PERSON_H


#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::istream;
using std::ostream;

using std::string;



class Person
{
public:
	//Constructor
	Person(const string& newName = "", const int& newAge = 0,
		   const string& newGender = "", const int& newHeight = 0);

	//Copy constructor
	Person(const Person& copy);

	//Destructor
	~Person();

	//Overloaded assignment operator
	Person& operator = (const Person& rhs);

	//Overloaded stream insertion operator
	friend istream& operator >> (istream& lhs, Person& rhs);


	//Overloaded stream extraction operator
	friend ostream& operator << (ostream& lhs, Person& rhs);

	//Setters
	void setName(const string& newName);
	void setAge(const int& newAge);
	void setGender(const string& newGender);
	void setHeight(const int& newHeight);

	//Getters
	string getName();
	int getAge();
	string getGender();
	int getHeight();


protected:
	string mName;
	int mAge;
	string mGender;
	int mHeight;     //(cm)
};












#endif
