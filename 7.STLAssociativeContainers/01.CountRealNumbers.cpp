/*  
	8 2.5 2.5 8 2.5    2.5 -> 3     8 -> 2 
	1.5 5 1.5 3        1.5 -> 2     3 -> 1        5 -> 1
	-2 0.33 0.33 2     -2 -> 1      0.33 -> 2     2 -> 1
*/


#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

void count_numbers(string line_of_numbers)
{
	map<string, int> numbers;
	string current_number = "";
	for (int symbol = 0; symbol < line_of_numbers.size(); symbol++) //crawls all line
	{
		if (line_of_numbers[symbol] != ' ')
		{
			current_number += line_of_numbers[symbol]; //make string with current number
		}
		else
		{
			numbers[current_number]++; //if symbol is ' ' check map for current number
			current_number = "";	// empty the string for the next number
		}
	}
	numbers[current_number]++;

	for (pair<string, int> number : numbers)                        //print all numbers with their  
	{																//encounters from map "numbers"
		cout << number.first << " -> " << number.second << endl;  
	}
}

int main()
{
	string line_of_numbers;
	getline(cin, line_of_numbers); //read all line of numbers
	cout << endl;

	count_numbers(line_of_numbers);
	return 0;
}

