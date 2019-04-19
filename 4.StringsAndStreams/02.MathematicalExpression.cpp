// 02MathematicalExpression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void check_brackets(string expression)
{
	int count_open = 0;
	int count_close = 0;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '(')
		{
			count_open++;
		}
		else if (expression[i] == ')')
		{
			count_close++;
		}
	}
	if (count_open == count_close)
	{
		cout << "correct" << endl;
	}
	else
	{
		cout << "incorrect" << endl;
	}
}

int main()
{
	string expression;
	getline(cin, expression);

	check_brackets(expression);
    return 0;
}

