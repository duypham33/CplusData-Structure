// To understand the foundation of C++ and classes, we'll work with a 
// simple Rectangle class.

// History: 3/1 - Worked with std::ofstream and std::fstream. Showed
//                how to write data to an output file.
//          2/26 - Implemented stream insertion operator for Rectangles.
//                 Worked with std::ifstream type.
//          2/24 - Implemented copy assignment operator for Rectangles.
//                 Modified getters () to make them constant functions.
//                 Started implementing stream insertion operator (<<)
//                 to work with Rectangle objects.
//          2/22 - Implemented destructor and copy constructor for 
//                 class Rectangle. Implemented a non-member function
//                 called f () to illustrate how a copy constructor
//                 gets invoked implicitly when a Rectangle object
//                 is passed-by-value.
///         2/19 - Declared class Rectangle. Introduced and implemented a constructor
//                 for initializing our Rectangle. Implemented getters and setters.

#include "Rectangle.h"

int main(void)
{
	Rectangle r1, r2(5.6), r3(9, 7.8); // sizeof(r1) = 2 doubles = 16 bytes
	Rectangle& refR1 = r1; // create a reference to r1
	
	std::ifstream infile;
	infile.open("data.txt", std::ios::in);

	std::ofstream outfile;
	outfile.open("output.txt");

	std::fstream ourStream;
	ourStream.open("data.txt", std::ios::in);
	ourStream.close();
	ourStream.open("output.txt", std::ios::out);
	ourStream.close();

	if (infile.is_open())
	{

		//infile >> r1;
		double length = 0.0;
		infile >> length;
		double width = 0.0;
		infile >> width;
		// infile >> r1;
		r1.setLength(length);
		r1.setWidth(width);
		cout << r1 << std::endl;

		//infile.getline()
		//std::getline()
		infile.close();

		outfile << r1.getLength() << " " << r1.getWidth() << std::endl;

		outfile.close();
	}
	
	bool result = true;
	std::string s1 = "string";

	if (s1 == "string")
	{
		s1 = s1 + "string2"; // append
		std::cout << "this is our string: " << s1 << std::endl;
	}

	r1 = r2 = r3; // copy assignment operator invoked here!
	r1 = refR1; // r1 = r1

	cout << r1 << r2 << std::endl;

	//if (r1 < r2 && r1 < r3)
	//{

	//}

	f(r1); // passing r1 by value; hence, copy constructor for Rectangle invoked

	std::cout << "l: " << r1.getLength() << " w: " << 
		r1.getWidth() << std::endl;

	double num = 8.0;
	r1.setLength(num);
	std::cout << "l: " << r1.getLength() << " w: " <<
		r1.getWidth() << std::endl;

	r2 = r1; // copy assignment operator invoked here!
	std::cout << "l: " << r1.getLength() << " w: " <<
		r1.getWidth() << std::endl;

	return 0;
}