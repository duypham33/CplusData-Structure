#include "Rectangle.h"

//Rectangle::Rectangle()
//{
//	mWidth = 0.0;
//	mLength = 0.0;
//}

//Rectangle::Rectangle(double newLength, double newWidth)
//{
//	mLength = newLength;
//	this->mWidth = newWidth;
//}


Rectangle::Rectangle(double newLength, double newWidth)
{
	mLength = newLength;
	this->mWidth = newWidth;
}

// copy constructor - invoked when a Rectangle object is passed by value
Rectangle::Rectangle(Rectangle& copy)
{
	mWidth = copy.getWidth();
	mLength = copy.getLength();
}

// copy assignment operator
Rectangle& Rectangle::operator= (const Rectangle& rhs)
{
	// check for self-assignment
	// this pointer - address of instance of the object
	if (this != &rhs)
	{
		mWidth = rhs.getWidth();
		mLength = rhs.getLength();
	}

	return *this;
}

Rectangle::~Rectangle()
{
	// no resources to clean up in this example
	std::cout << "Inside the destructor." << std::endl;
}

double Rectangle::getWidth() const
{
	return mWidth;
}

double Rectangle::getLength() const
{
	return mLength;
}

void Rectangle::setWidth(double& newWidth) // can we ensure that newWidth doesn't get changed? yes!
{
	if (newWidth >= 0)
	{
		mWidth = newWidth;
	}
	else
	{
		mWidth = 0.0;
	}
}

void Rectangle::setLength(double& newLength)
{
	mLength = newLength;
}

// non member function
void f(Rectangle r) // r is passed by value - copy will be made
{
	std::cout << "r length: " << r.getLength() << std::endl;
}

std::ostream& operator<< (std::ostream& lhs, const Rectangle& rhs)
{
	lhs << "length: " << rhs.getLength() << " " << "width: " << rhs.getWidth();

	return lhs;
}