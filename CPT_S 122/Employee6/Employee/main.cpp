// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

// History: 7/20 - Discussed pure virtual functions and abstract classes.
//          7/19 - Formally inroduced dynamic polymorphism
//                 and programming in the "general." Pay close
//                 attention to the nonmember function printPay ()
//                 defined in main ().
//          7/16 - Introduced keyword virtual to the base class
//                 Employee::calculatePay (). It allows for
//                 dynamic binding to occur while the program is executing.
//                 We also implemented some code in main ()
//                 to illustrate how dynamic our code really is.
//          7/15 - Implemented Manager constructor and destructor.
//                 Implemented Manager::calculatePay ().
//                 Discussed the order in which the constructors
//                 and destructors are invoked. 
//          7/14 - Discussed inheritance. Employee is the
//                 base class in this example and Manager
//                 is the derived class. Basic inheritance
//                 C++ syntax was introduced.

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.h"
#include "Manager.h"

void printPay(Employee& obj);

int main(void)
{
	Employee e1("Jonathan", 25, 88);
	Manager m1("Kelsi", 7500, 70, true);

	Employee* pEmp = new Employee("Jonathan", 25, 88), 
		*pManager = new Manager("Kelsi", 7500, 70, true);

	Manager* pM2 = new Manager;

	Employee* arrpEmp[100] = { nullptr };
	int count = 0, numEmp = 0;

	//printPay(e1);
	//printPay(m1);

	//printPay(*pEmp);
	//printPay(*pManager);

	std::cout << "Enter number of Employees to create: ";
	std::cin >> numEmp;

	while (count < numEmp)
	{
		std::cout << "What type? (1): Basic Employee, (2): Manager: ";
		int employeeType = 0;
		std::cin >> employeeType;

		switch (employeeType)
		{
		case 1: arrpEmp[count] = new Employee("Jonathan", 25, 88);
			// note that on the surface level - lines
			// 56 and 59 are the same! However,
			// the calculatePay () function invoked is not the same!
			break;
		case 2: arrpEmp[count] = new Manager("Kelsi", 7500, 70, true);
			//std::cout << "Pay: " << arrpEmp[count]->calculatePay() << std::endl;
			break;
		}
		std::cout << "Pay: " << arrpEmp[count]->calculatePay() << std::endl;
		printPay(*arrpEmp[count]);

		++count;
	}

	//std::cout << "Jonathan: " << e1.calculatePay() << std::endl;
	//std::cout << "Kelsi: " << m1.calculatePay() << std::endl;

	//std::cout << "Jonathan: " << pEmp->calculatePay() << std::endl;
	//// the line below doesn't give us the result we expect. Think about why?
	//// we'll discuss it more in lecture 7/16
	//std::cout << "Kelsi: " << pManager->calculatePay() << std::endl;


	return 0;
}

void printPay(Employee& obj)
{
	std::cout << "Pay: " << obj.calculatePay() << std::endl;
}