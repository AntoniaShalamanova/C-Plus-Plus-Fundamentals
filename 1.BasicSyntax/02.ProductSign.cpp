// 02ProductSign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	
	int minus = 0;
	if (num1 == 0 || num2 == 0 || num3 == 0)
	{
		cout << "+" << endl;
		return 0;
	}

	if (num1 < 0)
	{
		minus++;
	}
	if (num2 < 0)
	{
		minus++;
	}
	if (num3 < 0)
	{
		minus++;
	}

	if (minus % 2 == 0)
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
	}
    return 0;
}

