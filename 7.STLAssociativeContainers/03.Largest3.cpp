/*
	10 30 15 20 50 5	  50 30 20		
	20 30				  30 20
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print_largest_three(string line_of_numbers)
{
	vector<double> numbers;
	string current_number = "";

	for (int symbol = 0; symbol < line_of_numbers.size(); symbol++)  //crawls all line of numbers
	{
		if (line_of_numbers[symbol] != ' ')
		{
			current_number += line_of_numbers[symbol];   //make string with current number
		}
		else
		{
			numbers.push_back(stoi(current_number));  //insert in vector "numbers" current number
			current_number = "";   // empty the string for the next number
		}
	}
	numbers.push_back(stoi(current_number));  //this is for the last one number

	sort(numbers.begin(), numbers.end());   //sort the vector "numbers"


	if (numbers.size() <= 3)
	{
		for (int i = numbers.size() - 1; i >= 0; i--) //if size of vector is 3 or less prints while i = 0
		{
			cout << numbers[i] << " ";
		}
	}
	else
	{
		for (int i = numbers.size() - 1; i > numbers.size() - 4; i--)  
		{
			cout << numbers[i] << " ";   //if size of vector is greater than 3 prints the three numbers at the end
		}
	}
}

int main()
{
	string line_of_numbers;
	getline(cin, line_of_numbers);  //read all line of numbers
	cout << endl;

	print_largest_three(line_of_numbers);
    return 0;
}

