// 06SmallestDifference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>


using namespace std;

void print_smallest_difference(int size, vector <int> numbers)
{
	int difference = 0;
	int smallest_difference = INT32_MAX;
	for (int first_num = 0; first_num < size; first_num++)
	{
		for (int second_num = 0; second_num < size; second_num++)
		{
			if (first_num == second_num)
			{
				continue;
			}
			else if (first_num != second_num)
			{
				if (numbers[first_num] >= 0 && numbers[second_num] >= 0)
				{
					difference = abs(numbers[first_num] - numbers[second_num]);
				}
				else if (numbers[first_num] <= 0 && numbers[second_num] <= 0)
				{
					difference = abs(numbers[first_num] - numbers[second_num]);
				}
				else if (numbers[first_num] <= 0 || numbers[second_num] <= 0)
				{
					difference = abs(numbers[first_num]) + abs(numbers[second_num]);
				}

				if (difference < smallest_difference)
				{
					smallest_difference = difference;
				}
			}
		}
	}
	cout << smallest_difference << endl;
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

	print_smallest_difference(size, numbers);
	return 0;
}

