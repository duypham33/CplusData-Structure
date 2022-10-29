
#include "header.h"

int main(void)
{
	Complex c1(3.5, -2), c2(-5.5, 7), c3;
	cout << "c1: " << c1 << "c2: " << c2 << "c3: " << c3;
	cout << endl;
	
	c3 = c1.add(c2);
	cout << "c3 = c1.add(c2): ";
	c3.print(); cout << endl;

	//Prompt c4
	Complex c4;
	cout << "Please, enter an complex number(c4) in the form a + bi: ";
	c4.read();
	cout << "c4: " << c4;

	c2 = c1 + c4;
	cout << "c2 = c1 + c4: ";  c2.print();
	cout << endl << endl;

	//Prompt c5
	Complex c5;
	cout << "Please, enter an complex number(c5) in the form a + bi: ";
	cin >> c5;
	cout << "c5: " << c5;

	c5 = add(c3, c2);
	cout << "c5 = add(c3, c2): " << c5 << endl;


	//Subtraction
	c4 = c5 - c1;
	cout << "c4 = c5 - c1: ";  c4.print();



	return 0;    //The program was successful
}