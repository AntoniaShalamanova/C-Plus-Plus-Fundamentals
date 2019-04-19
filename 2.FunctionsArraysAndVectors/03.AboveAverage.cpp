// 03AboveAverage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void print_larger_numbers(int size, vector <int> numbers)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += numbers[i];
	}

	double average = sum / size*1.0;

	for (int i = 0; i < size; i++)
	{
		if (numbers[i] >= average)
		{
			cout << numbers[i] << " ";
		}
	}
}

int main()
{
	int size;
	cin >> size;
	vector <int> numbers;
	int num;

	for (int i = 0; i < size; i++)
	{
		cin >> num;
		numbers.push_back(num);
	}

	print_larger_numbers(size, numbers);
    return 0;
}

