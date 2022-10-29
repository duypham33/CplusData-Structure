
#include "header.h"



Complex::Complex(const double& newReal, const double& newImaginary)
{
	this->mReal = newReal;
	this->mImaginary = newImaginary;
}

Complex::~Complex()
{

}

void Complex::setReal(const double& newReal)
{
	this->mReal = newReal;
}



void Complex::setImaginary(const double& newImaginary)
{
	this->mImaginary = newImaginary;
}


const double& Complex::getReal()
{
	return mReal;
}


const double& Complex::getImaginary()
{
	return mImaginary;
}


Complex& Complex::add(Complex& rhs)
{
	Complex sum;
	sum.setReal(this->mReal + rhs.mReal);
	sum.setImaginary(this->mImaginary + rhs.mImaginary);

	return sum;
}


Complex& add(Complex& lhs, Complex& rhs)
{
	Complex sum;
	sum.setReal(lhs.getReal() + rhs.getReal());
	sum.setImaginary(lhs.getImaginary() + rhs.getImaginary());

	return sum;
}


Complex& operator + (Complex& lhs, Complex& rhs)
{
	Complex sum;
	sum.setReal(lhs.getReal() + rhs.getReal());
	sum.setImaginary(lhs.getImaginary() + rhs.getImaginary());

	return sum;
}


Complex& operator - (Complex& lhs, Complex& rhs)
{
	Complex sub;
	sub.setReal(lhs.getReal() - rhs.getReal());
	sub.setImaginary(lhs.getImaginary() - rhs.getImaginary());

	return sub;
}



void Complex::read()
{
	string s;    //Form a + bi (or a - bi)
	std::getline(cin, s);

	//Get a (real part)
	string delimeter = " ";    //The whitespace between a and +
	size_t pos = s.find(delimeter);
	string token = s.substr(0, pos);    //This token is "a" - real part
	s.erase(0, pos + delimeter.length());      //Now, s is "+ bi" (or "- bi"))

	this->mReal = atof(token.c_str());  //Get mReal

	//Get sign of the imaginary part(+ or -)
	pos = s.find(delimeter);      //The whitespace betwwen + (or -) and bi
	token = s.substr(0, pos);   //This token is the sign
	s.erase(0, pos + delimeter.length());      //Now, s is "bi"

	double sign = 0.0;
	if (token == "+")
		sign = 1.0;
	else
		sign = -1.0;

	//Get b (imaginary part)
	delimeter = "i";
	pos = s.find(delimeter);
	token = s.substr(0, pos);

	this->mImaginary = sign * atof(token.c_str());
}


istream& operator >> (istream& lhs, Complex& rhs)
{
	string s;   //Form a + bi (or a - bi)
	std::getline(lhs, s);

	//Get a (real part)
	string delimeter = " ";    //The whitespace between a and +
	size_t pos = s.find(delimeter);
	string token = s.substr(0, pos);    //This token is "a" - real part
	s.erase(0, pos + delimeter.length());      //Now, s is "+ bi" (or "- bi"))

	rhs.setReal(atof(token.c_str()));  //Get mReal

	//Get sign of the imaginary part(+ or -)
	pos = s.find(delimeter);      //The whitespace betwwen + (or -) and bi
	token = s.substr(0, pos);   //This token is the sign
	s.erase(0, pos + delimeter.length());      //Now, s is "bi"

	double sign = 0.0;
	if (token == "+")
		sign = 1.0;
	else
		sign = -1.0;

	//Get b (imaginary part)
	delimeter = "i";
	pos = s.find(delimeter);
	token = s.substr(0, pos);

	rhs.setImaginary(sign * atof(token.c_str()));

	return lhs;
}



void Complex::print()
{
	cout << this->mReal;

	if (this->mImaginary >= 0.0)
		cout << " + " << this->mImaginary;
	else
		cout << " - " << (-this->mImaginary);

	cout << "i" << endl;
}



ostream& operator << (ostream& lhs, Complex& rhs)
{
	lhs << rhs.getReal();
	
	if (rhs.getImaginary() >= 0.0)
		lhs << " + " << rhs.getImaginary();
	else
		lhs << " - " << (-rhs.getImaginary());

	lhs << "i" << endl;

	return lhs;
}