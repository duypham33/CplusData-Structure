#include "Manager.h"

//Manager::Manager(const string& newName,
//	const double& newPayRate,
//	const double& newHours,
//	const bool& newSalariedEmployee)
//{
//	
//	/*mName = newName;
//	mPayRate = newPayRate;
//	mHours = newHours;*/
//}

double Manager::calculatePay()
{
	double result = 0.0;

	if (!this->isSalaried)
	{
		// employee
		result = Employee::calculatePay();
	}
	else
	{
		// manager
		result = this->mPayRate;//this->getPayRate();
		//this->getPayRate = -8000;
	
	}

	return result;
}