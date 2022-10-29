
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

//Class of complex number
class Complex
{
public:
	//Constructor
	Complex(const double& newReal = 0.0, const double& newImaginary = 0.0);

	//Destructor
	~Complex();

	//Setters
	void setReal(const double& newReal);
	void setImaginary(const double& newImaginary);

	//Getters
	const double& getReal();
	const double& getImaginary();


	//Operations
	Complex& add(Complex& rhs);  //Addition

	void read();   //Read

	void print();  //Display the object data to the screen

private:
	double mReal;
	double mImaginary;
};



Complex& add(Complex& lhs, Complex& rhs);


Complex& operator + (Complex& lhs, Complex& rhs);

Complex& operator - (Complex& lhs, Complex& rhs);

istream& operator >> (istream& lhs, Complex& rhs);

ostream& operator << (ostream& lhs, Complex& rhs);