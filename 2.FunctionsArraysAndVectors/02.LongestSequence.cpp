// 02LongestSequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void find_longest_sequence(int size, vector <int> numbers)
{
	int max_count = 0;
	int max_count_number = 0;
	int count = 1;
	int number = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == size-1)
		{
			if (numbers[i] == numbers[i - 1])
			{
				number = numbers[i];
				count++;
			}
			else
			{
				if (count >= max_count)
				{
					max_count = count;
					max_count_number = numbers[i];
				}
				count = 1;
			}
		}
		else
		{
			if (numbers[i] == numbers[i + 1])
			{
				number = numbers[i];
				count++;
			}
			else
			{
				if (count >= max_count)
				{
					max_count = count;
					max_count_number = numbers[i];
				}
				count = 1;
			}
		}
	}
	for (int i = 1; i <= max_count; i++)
	{
		cout << max_count_number << " ";
	}
}

int main()
{
	int size;
	cin >> size;
	vector <int> numbers;
	int num;

	for (int i = 1; i <= size; i++)
	{
		cin >> num;
		numbers.push_back(num);
	}

	find_longest_sequence(size, numbers);
    return 0;
}

