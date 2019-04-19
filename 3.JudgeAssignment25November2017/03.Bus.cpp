// 03Bus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print_minimum_minutes(int arriving_hours_number, vector <int> arriving_hours, int departure_hour)
{
	int departure_minutes = (departure_hour / 100) * 60 + (departure_hour % 100);
	int arriving_minutes = 0;
	int diff = 0;
	int min_minutes = INT32_MAX;
	for (int i = 0; i < arriving_hours_number; i++)
	{
		arriving_minutes = (arriving_hours[i] / 100) * 60 + (arriving_hours[i] % 100);
		diff = departure_minutes - (arriving_minutes);
		if (diff < 0)
		{
			continue;
		}
		else
		{
			if (diff<min_minutes)
			{
				min_minutes = diff;
			}
		}
	}
	cout << min_minutes << endl;
}

int main()
{
	int arriving_hours_number;
	cin >> arriving_hours_number;

	int arriving_hour;
	vector <int> arriving_hours;
	int departure_hour;

	for (int i = 0; i < arriving_hours_number; i++)
	{
		cin >> arriving_hour;
		arriving_hours.push_back(arriving_hour);
	}
	cin >> departure_hour;

	print_minimum_minutes(arriving_hours_number, arriving_hours, departure_hour);
    return 0;
}

