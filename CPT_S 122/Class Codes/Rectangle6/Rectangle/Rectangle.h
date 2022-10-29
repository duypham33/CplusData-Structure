#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream> // cout, cin, endl <<, >>
#include <string>
#include <fstream> // operations to work with fstream, ifstream, ofstream

using std::cout;

class Rectangle
{
public: // visible by objects and functions that belong and don't belong to the class
	// special member function - constructor - init the object
//	Rectangle(); // initialize data members/attributes of the class/object
//	Rectangle(double newLength, double newWidth);

	Rectangle(double newLength = 0.0, double newWidth = 0.0);

	// copy constructor - invoked when a Rectangle object is passed by value
	Rectangle(Rectangle &copy);

	// destructor - special member function
	~Rectangle();
	
	// copy assignment operator
	Rectangle & operator= (const Rectangle& rhs);

	// member functions
	// getters
	double getWidth() const; // constant function
	double getLength() const; // constant function

	// setters
	void setWidth(double &newWidth);
	void setLength(double& newLength);

private: // these members are hidden from objects and functions that don't belong to the class!
	// data members
	double mWidth;
	double mLength;
};


// non member function
void f(Rectangle r); // r is passed by value - copy will be made

std::ostream & operator<< (std::ostream& lhs, const Rectangle& rhs);

#endif // ! RECTANGLE_H

