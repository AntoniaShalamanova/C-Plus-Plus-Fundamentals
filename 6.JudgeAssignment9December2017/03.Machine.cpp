// 03Machine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	string current_line, concat, num1_str, num2_str;
	stack<string> numbers;
	vector<string> reverse_numbers;
	int num1, num2, sum, diff;

while (true)
	{
		cin >> current_line;

		if (current_line == "sum")
		{
			num1 = stoi(numbers.top());
			numbers.pop();
			num2 = stoi(numbers.top());
			numbers.pop();
			sum = num1 + num2;
			numbers.push(to_string(sum));
		}
		else if (current_line == "subtract")
		{
			num1 = stoi(numbers.top());
			numbers.pop();
			num2 = stoi(numbers.top());
			numbers.pop();
			diff = num1 - num2;
			numbers.push(to_string(diff));
		}
		else if (current_line == "concat")
		{
			num1_str = numbers.top();
			numbers.pop();
			num2_str = numbers.top();
			numbers.pop();
			concat = num2_str + num1_str;
			numbers.push(concat);
		}
		else if (current_line == "discard")
		{
			numbers.pop();
		}
		else if (current_line == "end")
		{
			while(!numbers.empty())
			{
				reverse_numbers.push_back(numbers.top());
				numbers.pop();
			}

			for (int number = reverse_numbers.size()-1; number >= 0; number--)
			{
				cout << reverse_numbers[number] << endl;
			}
			return 0;
		}
		else
		{
			numbers.push(current_line);
		}
		current_line = "";
	}
    return 0;
}

