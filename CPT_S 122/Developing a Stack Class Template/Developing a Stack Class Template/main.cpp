// This example illustrates how to define a Stack class template.

//#include "TestStack.h"
#include "Expression.h"
//#include <vector>

int main(void)
{
	int item1 = -89, item2 = 104;

	//	vector<int> my_vector;

	TestStack<int> tester;

	if (tester.Test(item1, item2))
	{
		cout << "\nThe test passed!\n";
	}
	else
	{
		cout << "\nThe test failed!\n";
	}

	int result = postfixEval("875*+9-");
	cout << result << endl;

	string postfix = infixToPostfix("(4+7*(7-2))/3");
	cout << postfix << endl;

	result = postfixEval(postfix);
	cout << result << endl;

	return 0;
}