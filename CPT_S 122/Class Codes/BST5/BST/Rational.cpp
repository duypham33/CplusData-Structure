// We will place the definitions for only
// Rational's operations in this file

#include "Rational.h"

//Rational::Rational()
//{
//	mNumerator = 0;
//	mDenominator = 1;
//}
//
//Rational::Rational(int newNumerator, int newDenominator)
//{
//	mNumerator = newNumerator;
//	mDenominator = newDenominator;
//}

Rational::Rational(const int newNumerator, const int newDenominator)
{
	//mNumerator = newNumerator;
	mpNumerator = new int;
	*mpNumerator = newNumerator;

	mpDenominator = new int;

	// validate the denominator
	if (newDenominator != 0)
	{
		*mpDenominator = newDenominator;
	}
	else
	{
		*mpDenominator = 1;
	}
}

int Rational::getNumerator() const
{
	return *mpNumerator;
}

int Rational::getDenominator() const
{
	return *mpDenominator;
}


void Rational::setNumerator(const int newNumerator)
{
	*mpNumerator = newNumerator;
}

void Rational::setDenominator(const int newDenominator)
{
	// validate the denominator
	if (newDenominator != 0)
	{
		*mpDenominator = newDenominator;
	}
	else
	{
		*mpDenominator = 1;
	}
}

// implicitly called when passing-by-value
Rational::Rational(const Rational &copy)
{
	//mNumerator = copy.mNumerator; // could also work
	/*setNumerator(copy.getNumerator());
	setDenominator(copy.getDenominator());*/
	this->mpNumerator = new int(copy.getNumerator());
	this->mpDenominator = new int;
	this->setDenominator(copy.getDenominator());

}

Rational Rational::add(const Rational &rhs)
{
	Rational result;

	result.setDenominator(rhs.getDenominator() *
		getDenominator());
	result.setNumerator(rhs.getNumerator() * getDenominator() +
		getNumerator()*rhs.getDenominator());

	return result;
}

Rational::~Rational()
{
	cout << "Inside destructor for Rational" << std::endl;
	delete mpDenominator;
	delete mpNumerator;
}

Rational & Rational::operator= (const Rational &rhs)
{
	// fill in during class
	if (this != &rhs)
	{
		*(this->mpDenominator) = *(rhs.mpDenominator);
		*(this->mpNumerator) = *(rhs.mpNumerator);
	}

	return *this;
}
bool operator< (const Rational& lhs, const Rational& rhs)
{
	return (lhs.getNumerator() * rhs.getDenominator() < 
		rhs.getNumerator() * lhs.getDenominator());
}

std::ifstream& operator>> (std::ifstream& lhs, Rational& rhs)
{
	int num = 0;
	lhs >> num;
	rhs.setNumerator(num);
	char slash = '\0';
	lhs >> slash;
	int den = 0;
	lhs >> den;
	rhs.setDenominator(den);

	return lhs;
}

std::ostream& operator<< (std::ostream& lhs, const Rational& rhs)
{
	lhs << rhs.getNumerator() << " / " << rhs.getDenominator();

	return lhs;
}