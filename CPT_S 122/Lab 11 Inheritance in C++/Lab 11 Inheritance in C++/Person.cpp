
/*

    This file is to establish the definitions for all programmer-defined functions of Person Class, aside from main ()

*/


#include "Person.h"


//Function definitions
Person::Person(const string& newName, const int& newAge, const string& newGender, const int& newHeight)
{
    mName = newName;
    mAge = newAge;
    mGender = newGender;
    mHeight = newHeight;
}


Person::Person(const Person& copy)
{
    this->mName = copy.mName;
    this->mAge = copy.mAge;
    this->mGender = copy.mGender;
    this->mHeight = copy.mHeight;
}


Person::~Person()
{

}


Person& Person::operator = (const Person& rhs)
{
    if (this != &rhs)
    {
        mName = rhs.mName;
        mAge = rhs.mAge;
        mGender = rhs.mGender;
        mHeight = rhs.mHeight;
    }

    return (*this);
}



istream& operator >> (istream& lhs, Person& rhs)
{
    string name;
    int age = 0;
    string gender;
    int height = 0;

    //lhs.ignore();
    cout << "Enter name: ";
    std::getline(lhs, name);
    rhs.setName(name);

    cout << "Enter age: ";
    lhs >> age;
    rhs.setAge(age);
    lhs.ignore();

    cout << "Enter gender: ";
    std::getline(lhs, gender);
    rhs.setGender(gender);
    
    cout << "Enter height: ";
    lhs >> height;       
    rhs.setHeight(height);
    
    return lhs;
}



ostream& operator << (ostream& lhs, Person& rhs)
{
    lhs << "Name: " << rhs.getName() << endl;
    lhs << "Age: " << rhs.getAge() << endl;
    lhs << "Gender: " << rhs.getGender() << endl;
    lhs << "Height: " << rhs.getHeight() << endl;

    return lhs;
}



void Person::setName(const string& newName)
{
    mName = newName;
}

void Person::setAge(const int& newAge)
{
    mAge = newAge;
}


void Person::setGender(const string& newGender)
{
    mGender = newGender;
}


void Person::setHeight(const int& newHeight)
{
    mHeight = newHeight;
}



string Person::getName()
{
    return mName;
}



int Person::getAge()
{
    return mAge;
}


string Person::getGender()
{
    return mGender;
}



int Person::getHeight()
{
    return mHeight;
}
