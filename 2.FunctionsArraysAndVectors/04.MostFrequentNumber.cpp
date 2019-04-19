// 04MostFrequentNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


void print_most_frequent_number(int size, vector <int> numbers)
{
	int count_0 = 0, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, 
		count_5 = 0, count_6 = 0, count_7 = 0, count_8 = 0, count_9 = 0;

	for (int i = 0; i < size; i++)
	{
		if (numbers[i] == 0)
		{
			count_0++;
		}
		else if (numbers[i] == 1)
		{
			count_1++;
		}
		else if (numbers[i] == 2)
		{
			count_2++;
		}
		else if (numbers[i] == 3)
		{
			count_3++;
		}
		else if (numbers[i] == 4)
		{
			count_4++;
		}
		else if (numbers[i] == 5)
		{
			count_5++;
		}
		else if (numbers[i] == 6)
		{
			count_6++;
		}
		else if (numbers[i] == 7)
		{
			count_7++;
		}
		else if (numbers[i] == 8)
		{
			count_8++;
		}
		else if (numbers[i] == 9)
		{
			count_9++;
		}
	}

	vector <int> max_numbers;
	int max_count = 0;
	if (count_0 > max_count)
	{
		max_count = count_0;
		max_numbers.clear();
		max_numbers.push_back(0);
	}
	else if (count_0 == max_count)
	{
		max_count = count_0;
		max_numbers.push_back(0);
	}

	if (count_1 > max_count)
	{
		max_count = count_1;
		max_numbers.clear();
		max_numbers.push_back(1);
	}
	else if (count_1 == max_count)
	{
		max_count = count_1;
		max_numbers.push_back(1);
	}

	if (count_2 > max_count)
	{
		max_count = count_2;
		max_numbers.clear();
		max_numbers.push_back(2);
	}
	else if (count_2 == max_count)
	{
		max_count = count_2;
		max_numbers.push_back(2);
	}

	if (count_3 > max_count)
	{
		max_count = count_3;
		max_numbers.clear();
		max_numbers.push_back(3);
	}
	else if (count_3 == max_count)
	{
		max_count = count_3;
		max_numbers.push_back(3);
	}

	if (count_4 > max_count)
	{
		max_count = count_4;
		max_numbers.clear();
		max_numbers.push_back(4);
	}
	else if (count_4 == max_count)
	{
		max_count = count_4;
		max_numbers.push_back(4);
	}

	if (count_5 > max_count)
	{
		max_count = count_5;
		max_numbers.clear();
		max_numbers.push_back(5);
	}
	else if (count_5 == max_count)
	{
		max_count = count_5;
		max_numbers.push_back(5);
	}

	if (count_6 > max_count)
	{
		max_count = count_6;
		max_numbers.clear();
		max_numbers.push_back(6);
	}
	else if (count_6 == max_count)
	{
		max_count = count_6;
		max_numbers.push_back(6);
	}

	if (count_7 > max_count)
	{
		max_count = count_7;
		max_numbers.clear();
		max_numbers.push_back(7);
	}
	else if (count_7 == max_count)
	{
		max_count = count_7;
		max_numbers.push_back(7);
	}

	if (count_8 > max_count)
	{
		max_count = count_8;
		max_numbers.clear();
		max_numbers.push_back(8);
	}
	else if (count_8 == max_count)
	{
		max_count = count_8;
		max_numbers.push_back(8);
	}

	if (count_9 > max_count)
	{
		max_count = count_9;
		max_numbers.clear();
		max_numbers.push_back(9);
	}
	else if (count_9 == max_count)
	{
		max_count = count_9;
		max_numbers.push_back(9);
	}

	for (int max_num:max_numbers)
	{
		cout << max_num << " ";
	}
}

int main()
{
	int size;
	cin >> size;
	vector <int> numbers;
	int numb;

	for (int i = 0; i < size; i++)
	{
		cin >> numb;
		numbers.push_back(numb);
	}

	print_most_frequent_number(size, numbers);
    return 0;
}

