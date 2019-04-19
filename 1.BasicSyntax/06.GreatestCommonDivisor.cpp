// 06GreatestCommonDivisor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	cin >> num1 >> num2;

	int swap;
	while (num2 != 0)
	{
		swap = num2;
		num2 = num1% num2;
		num1 = swap;
	}
	cout << num1;
    return 0;
}

