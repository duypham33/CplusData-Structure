
/*

    This file is to establish the definitions for all programmer-defined functions of Student Class, aside from main ()

*/


#include "Studentr.h"


//Function definitions
Student::Student()
{
    mName = "";
    mAge = 0;
    mGender = "";
    mHeight = 0;

    mCourses = NULL;
    mNumCors = 0;
    mTotalCres = 0;
}


Student& Student::operator = (const Student& rhs)
{
    if (this != &rhs)
    {
        mName = rhs.mName;
        mAge = rhs.mAge;
        mGender = rhs.mGender;
        mHeight = rhs.mHeight;

        mCourses = rhs.mCourses;
        mNumCors = rhs.mNumCors;
        mTotalCres = rhs.mTotalCres;
    }

    return (*this);
}



istream& operator >> (istream& lhs, Student& rhs)
{

    return lhs;
}



ostream& operator << (ostream& lhs, Student& rhs)
{

    return lhs;
}



void Student::setCoursesPtr(stuCourse* const newCourses)
{
    this->mCourses = newCourses;
}

void Student::setNumCors(const int& newNumCors)
{
    this->mNumCors = newNumCors;
}


void Student::setTotalCres(const int& newTotalCres)
{
    this->mTotalCres = newTotalCres;
}



stuCourse* Student::getCoursesPtr()
{
    return mCourses;
}


int Student::getNumCors()
{
    return mNumCors;
}


int Student::getTotalCres()
{
    return mTotalCres;
}






void Student::computeTotlCres()
{
    int sum = 0;
    for (int i = 0; i < mNumCors; i++)
    {
        sum += mCourses[i].credits;
    }

    this->mTotalCres = sum;
}



double Student::computeGPA()
{
    int sum = 0;
    for (int i = 0; i < mNumCors; i++)
    {
        sum += (mCourses[i].credits) * (mCourses[i].grade);
    }

    return ((double)sum / mTotalCres);
}