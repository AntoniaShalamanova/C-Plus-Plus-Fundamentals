// 01CompareArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void are_equal(int first_array_size, vector <int> first_array, int second_array_size, vector <int> second_array)
{
	if (first_array_size != second_array_size)
	{
		cout << "not equal" << endl;
	}
	else
	{
		for (int i = 0; i <= first_array_size; i++)
		{
			if (i == first_array_size)
			{
				cout << "equal" << endl;
				break;
			}
			if (first_array[i] == second_array[i])
			{
				continue;
			}
			else
			{
				cout << "not equal" << endl;
				break;
			}
		}
	}
}

int main()
{
	int first_array_size, second_array_size;
	int number;

	cin >> first_array_size;
	vector <int> first_array;
	for (int i = 0; i < first_array_size; i++)
	{
		cin >> number;
		first_array.push_back(number);
	}

	cin >> second_array_size;
	vector <int> second_array;
	for (int i = 0; i < second_array_size; i++)
	{
		cin >> number;
		second_array.push_back(number);
	}

	are_equal(first_array_size, first_array, second_array_size, second_array);
    return 0;
}

