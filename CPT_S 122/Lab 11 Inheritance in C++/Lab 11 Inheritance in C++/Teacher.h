
/*

  This is the header file that stores standard library includes, #defined and function prototypes of Teacher Class

*/


#ifndef TEACHER_H //guard code

#define TEACHER_H

#include "Person.h"



struct teaCourse
{
	string courseName;
	int credits;
	double averGrade;     //The average grade of students’ in course
};


class Teacher : public Person
{
public:
	//Constructor
	Teacher();

	//Operators
	Teacher& operator = (const Teacher& rhs);

	friend istream& operator >> (istream& lhs, Teacher& rhs);

	friend ostream& operator << (ostream& lhs, Teacher& rhs);

	//Setters
	void setCoursesPtr(teaCourse* const newCourses);
	void setNumCors(const int& newNumCors);
	void setTotalCres(const int& newTotalCres);

	//Getters
	teaCourse* getCoursesPtr();
	int getNumCors();
	int getTotalCres();

	//Methods
	void computeTotlCres();
	double computeAverGrades();


private:
	teaCourse* mCourses;
	int mNumCors;
	int mTotalCres;
};





#endif
