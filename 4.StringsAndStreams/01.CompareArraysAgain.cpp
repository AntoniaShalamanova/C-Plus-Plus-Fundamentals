// CompareArraysAgain.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void print_equal(string first_line, string second_line)
{
	if (first_line == second_line)
	{
		cout << "equal" << endl;
	}
	else
	{
		cout << "not equal" << endl;
	}

}

int main()
{
	string first_line;
	string second_line;

	getline(cin, first_line);
	getline(cin, second_line);

	print_equal(first_line, second_line);
	return 0;
}

