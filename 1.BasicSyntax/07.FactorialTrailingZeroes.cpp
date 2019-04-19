// 07FactorialTrailingZeroes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	unsigned long long int product = 1;
	for (int i = 1; i <= num; i++)
	{
		product *= i;
	}

	int zeros = 0;
	int is_zero = 0;
	while (product > 0)
	{
		is_zero = product % 10;
		product /= 10;
		if (is_zero == 0)
		{
			zeros++;
		}
		else
		{
			break;
		}
	}
	cout << zeros << endl;
    return 0;
}

