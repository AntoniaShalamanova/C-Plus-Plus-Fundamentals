// 01Pipes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void print_years_before_replacement(int number_of_pipes, 
									vector <int> measurements_last_year, 
									vector <int> measurements_this_year)
{
	int damage;
	int years;
	for (int i = 0; i < number_of_pipes; i++)
	{
		damage = measurements_last_year[i] - measurements_this_year[i];
		years = measurements_this_year[i] / damage;
		cout << years << " ";
	}
}

int main()
{
	int number_of_pipes;
	cin >> number_of_pipes;

	vector <int> measurements_last_year;
	vector <int> measurements_this_year;
	int measurment;

	for (int i = 0; i < number_of_pipes; i++)
	{
		cin >> measurment;
		measurements_last_year.push_back(measurment);
	}

	for (int i = 0; i < number_of_pipes; i++)
	{
		cin >> measurment;
		measurements_this_year.push_back(measurment);
	}

	print_years_before_replacement(number_of_pipes, measurements_last_year, measurements_this_year);
    return 0;
}

