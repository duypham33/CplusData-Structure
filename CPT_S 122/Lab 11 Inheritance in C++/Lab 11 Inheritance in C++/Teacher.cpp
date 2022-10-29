
/*

    This file is to establish the definitions for all programmer-defined functions of Teacher Class, aside from main ()

*/


#include "Teacher.h"


//Function definitions

/*

    This file is to establish the definitions for all programmer-defined functions of Student Class, aside from main ()

*/


#include "Studentr.h"


//Function definitions
Teacher::Teacher()
{
    mName = "";
    mAge = 0;
    mGender = "";
    mHeight = 0;

    mCourses = NULL;
    mNumCors = 0;
    mTotalCres = 0;
}


Teacher& Teacher::operator = (const Teacher& rhs)
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



istream& operator >> (istream& lhs, Teacher& rhs)
{

    return lhs;
}



ostream& operator << (ostream& lhs, Teacher& rhs)
{

    return lhs;
}



void Teacher::setCoursesPtr(teaCourse* const newCourses)
{
    this->mCourses = newCourses;
}

void Teacher::setNumCors(const int& newNumCors)
{
    this->mNumCors = newNumCors;
}


void Teacher::setTotalCres(const int& newTotalCres)
{
    this->mTotalCres = newTotalCres;
}



teaCourse* Teacher::getCoursesPtr()
{
    return mCourses;
}


int Teacher::getNumCors()
{
    return mNumCors;
}


int Teacher::getTotalCres()
{
    return mTotalCres;
}






void Teacher::computeTotlCres()
{
    int sum = 0;
    for (int i = 0; i < mNumCors; i++)
    {
        sum += mCourses[i].credits;
    }

    this->mTotalCres = sum;
}



double Teacher::computeAverGrades()
{
    double sum = 0.0;
    for (int i = 0; i < mNumCors; i++)
    {
        sum += (mCourses[i].credits) * (mCourses[i].averGrade);
    }

    return (sum / mTotalCres);
}