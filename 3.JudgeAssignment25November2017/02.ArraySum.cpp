// 02ArraySum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void print_weighted_sum_array(int arrays_number,
	int elements_number,
	vector <int> arrays,
	int weight, vector <int> weights)
{
	for (int i = 0; i < elements_number; i++)
	{
		int c = i;
		int k = 0;
		int result = 0;
		for (c; c < arrays.size(); c += elements_number)
		{
				result += arrays[c] * weights[k];
				k++;
		}
		cout << result << " ";
	}
}

int main()
{
	int arrays_number, elements_number;
	cin >> arrays_number >> elements_number;

	int number;
	vector <int> arrays;
	vector <int> weights;
	int weight;

	for (int i = 0; i < arrays_number; i++)
	{
		for (int i = 0; i < elements_number; i++)
		{
			cin >> number;
			arrays.push_back(number);
		}
	}

	for (int i = 0; i < arrays_number; i++)
	{
		cin >> weight;
		weights.push_back(weight);
	}

	print_weighted_sum_array(arrays_number, elements_number, arrays, weight, weights);
	return 0;
}

