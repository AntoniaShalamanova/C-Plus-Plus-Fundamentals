// 05CartesianProduct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void print_products(int size, vector <int> numbers)
{
	for (int first_num = 0; first_num < size; first_num++)
	{
		for (int second_num = 0; second_num < size; second_num++)
		{
			cout << numbers[first_num] * numbers[second_num] << " ";
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

	print_products(size, numbers);
    return 0;
}

