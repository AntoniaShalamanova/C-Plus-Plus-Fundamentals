// 03MergeTrains.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

void print_final_configuration(string numbers_of_track_A, string numbers_of_track_B)
{
	stack<int> reverse_single_track;
	string ordered_single_track = "";
	int current_number;
	priority_queue<int> single_track_decreasing;
	istringstream input_numbers_A(numbers_of_track_A);
	istringstream input_numbers_B(numbers_of_track_B);

	while (input_numbers_A >> current_number)
	{
		single_track_decreasing.push(current_number);
	}
	while (input_numbers_B >> current_number)
	{
		single_track_decreasing.push(current_number);
	}

 	while (!single_track_decreasing.empty())
	{
		ordered_single_track += to_string(single_track_decreasing.top());
		single_track_decreasing.pop();
		ordered_single_track += " ";
	}

	istringstream input_ordered(ordered_single_track);
	while (input_ordered >> current_number)
	{
		reverse_single_track.push(current_number);
	}

	while (!reverse_single_track.empty())
	{
		if (numbers_of_track_A.find(to_string(reverse_single_track.top())) != string::npos)
		{
			cout << "A";
		}
		else
		{
			cout << "B";
		}
		reverse_single_track.pop();
	}
	cout << endl;

	cout << ordered_single_track << endl;
}

int main()
{
	string numbers_of_track_A;
	string numbers_of_track_B;

	getline(cin, numbers_of_track_A);
	getline(cin, numbers_of_track_B);

	print_final_configuration(numbers_of_track_A, numbers_of_track_B);
	return 0;
}

