



#include "TestStack.h"

#include <string>
#include <math.h>


int postfixEval(string posfExpr)
{
	if (posfExpr.empty())    //Check if the string is empty
	{
		cout << "The postfix expression is malformed! Please, check it carefully!" << endl;
		return 0;
	}

	else
	{
		Stack<int>* pS = new Stack<int>();    //Initialize a pointer to an empty stack on the heap

		for (int i = 0; i < posfExpr.size(); i++)
		{
			char c = posfExpr[i];
			
			if (c >= 48 && c <= 57)  //a digit from 1 - 9
			{
				//Push onto Stack
				int digit = c - 48;
				pS->push(digit);
			}


			else if (c == '=')
			{
				if (pS->isEmpty())
				{
					cout << "The postfix expression is malformed! Please, check it carefully!" << endl;
					return 0;
				}

				else if (pS->getSize() > 0)
				{
					cout << "The postfix expression is malformed! Please, check it carefully!" << endl;
					return 0;
				}

				else
				{
					int e = 0;
					pS->peek(e);

					return e;
				}
			}


			else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			{
				if (pS->getSize() < 1)
				{
					cout << "The postfix expression is malformed! Please, check it carefully!" << endl;
					return 0;
				}

				else
				{
					int s1 = 0, s2 = 0;
					pS->pop(s2);
					pS->pop(s1);

					int v = 0;
					if (c == '+') { v = s1 + s2; }
					else if (c == '-') { v = s1 - s2; }
					else if (c == '*') { v = s1 * s2; }
					else if (c == '/') { v = s1 / s2; }
					else { v = pow(s1, s2); }

					pS->push(v);
				}
			}
		}

		if (pS->getSize() != 0)
		{
			cout << "The postfix expression is malformed! Please, check it carefully!" << endl;
			return 0;
		}

		else
		{
			int e = 0;
			pS->pop(e);

			return e;
		}

		delete pS;
	}
}




int precedence(char opert)
{
	if (opert == '^')
	{
		return 3;
	}

	else if (opert == '*' || opert == '/')
	{
		return 2;
	}

	else if (opert == '+' || opert == '-')
	{
		return 1;
	}
}



string infixToPostfix(string infix)
{
	if (infix.empty())    //Check if the string is empty
	{
		cout << "The infix expression is empty! So the postfix is empty!" << endl;
		return "";
	}


	else
	{
		Stack<char>* pS = new Stack<char>();    //Initialize a pointer to an empty stack on the heap
		string postfix;

		for (int i = 0; i < infix.size(); i++)
		{
			char c = infix[i];

			if (c >= 48 && c <= 57)
			{
				postfix.push_back(c);
			}

			else if (c == '(')
			{
				pS->push(c);
			}

			else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
			{
				if (pS->isEmpty())    //Check if the stack is empty
				{
					pS->push(c);
				}
				
				else    // !pS->isEmpty() 
				{
					char top = '\0';
					pS->peek(top);

					if (precedence(c) > precedence(top))
					{
						pS->push(c);
					}

					else
					{
						pS->pop(top);
						pS->push(c);

						postfix.push_back(top);
					}
				}
			}



			else if (c == ')')
			{
				char top = '\0';
				char poppedItem = '\0';
				bool isStop = false;

				do
				{
					pS->peek(top);
					if (top != '(')
					{
						pS->pop(poppedItem);
						postfix.push_back(poppedItem);
					}

					else  //top == '('
					{
						pS->pop(poppedItem);
						isStop = true;
					}
				} while (!isStop);
			}
		}



		if (!pS->isEmpty())
		{
			char poppedItem = '\0';
			while (!pS->isEmpty())
			{
				pS->pop(poppedItem);
				postfix.push_back(poppedItem);
			}
		}

		delete pS;

		return postfix;
	}
}