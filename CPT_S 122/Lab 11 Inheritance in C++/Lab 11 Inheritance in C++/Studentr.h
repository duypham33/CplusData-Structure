
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Student Class

*/


#ifndef STUDENT_H //guard code

#define STUDENT_H

#include "Person.h"



struct stuCourse
{
	string courseName;
	int credits;
	int grade;
};





class Student : public Person
{
public:
	//Constructor
	Student();

	//Operators
	Student& operator = (const Student& rhs);

	friend istream& operator >> (istream& lhs, Student& rhs);

	friend ostream& operator << (ostream& lhs, Student& rhs);

	//Setters
	void setCoursesPtr(stuCourse* const newCourses);
	void setNumCors(const int& newNumCors);
	void setTotalCres(const int& newTotalCres);

	//Getters
	stuCourse* getCoursesPtr();
	int getNumCors();
	int getTotalCres();

	//Methods
	void computeTotlCres();
	double computeGPA();

private:
	stuCourse* mCourses;
	int mNumCors;
	int mTotalCres;
};












#endif