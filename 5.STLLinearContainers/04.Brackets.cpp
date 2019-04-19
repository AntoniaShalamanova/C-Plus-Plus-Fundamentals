// 04Brackets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

void print_are_valid(string expression)
{
	bool are_valid = true;
	int bracket = 0;

	while (bracket < expression.size())
	{
		string current_brackets = "";

		if (expression[bracket] == '{')
		{
			while (expression[bracket] != '}')
			{
				current_brackets += expression[bracket];
				bracket++;
				if (bracket == expression.size())
				{
					are_valid = false;
					break; 
					break;
				}
			}
			if (expression[bracket + 1] == '}')
			{
				bracket++;
				while (expression[bracket] == '}')
				{
					current_brackets += expression[bracket];
					bracket++;
				}
			}
			else
			{
				current_brackets += "}";
				bracket++;
			}
		}
		else if (expression[bracket] == '[')
		{
			while (expression[bracket] != ']')
			{
				current_brackets += expression[bracket];
				bracket++;
				if (bracket == expression.size())
				{
					are_valid = false;
					break;
					break;
				}
			}
			if (expression[bracket + 1] == ']')
			{
				while (expression[bracket] == ']')
				{
					current_brackets += expression[bracket];
					bracket++;
				}
			}
			else
			{
				current_brackets += "]";
				bracket++;
			}
		}
		else if (expression[bracket] == '(')
		{
			while (expression[bracket] != ')')
			{
				current_brackets += expression[bracket];
				bracket++;
				if (bracket == expression.size())
				{
					are_valid = false;
					break;
					break;
				}
			}
			if (expression[bracket + 1] == ')')
			{
				bracket++;
				while (expression[bracket] == ')')
				{
					current_brackets += expression[bracket];
					bracket++;
				}

			}
			else
			{
				current_brackets += ")";
				bracket++;
			}
		}

		int count_curly = 0, count_square = 0, count_round = 0;
		for (int symbol = 0; symbol < current_brackets.size(); symbol++)
		{
			if (current_brackets[symbol] == '{')
			{
				count_curly++;
			}
			else if (current_brackets[symbol] == '}')
			{
				count_curly--;
			}
			else if (current_brackets[symbol] == '[')
			{
				if (current_brackets[symbol + 1] == '{')
				{
					are_valid = false;
					break;
					break;
				}
				count_square++;
			}
			else if (current_brackets[symbol] == ']')
			{
				count_square--;
			}
			else if (current_brackets[symbol] == '(')
			{
				if (current_brackets[symbol + 1] == '{' || current_brackets[symbol + 1] == '[')
				{
					are_valid = false;
					break;
					break;
				}
				count_round++;
			}
			else if (current_brackets[symbol] == ')')
			{
				count_round--;
			}
		}

		if (count_curly != 0 || count_square != 0 || count_round != 0)
		{
			are_valid = false;
			break;
		}
	}


	if (are_valid == true)
	{
		cout << "valid" << endl;
	}
	else
	{
		cout << "invalid" << endl;
	}
}

int main()
{
	string expression;
	getline(cin, expression);

	print_are_valid(expression);
	return 0;
}

