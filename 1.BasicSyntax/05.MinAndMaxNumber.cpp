// 05MinAndMaxNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int size;
	cin >> size;

	int num;
	int max_num = INT32_MIN;
	int min_num = INT32_MAX;
	for (int i = 0; i < size; i++)
	{
		cin >> num;
		if (num < min_num)
		{
			min_num = num;
		}
		if (num > max_num)
		{
			max_num = num;
		}
	}
	cout << min_num << " " << max_num << endl;
    return 0;
}

