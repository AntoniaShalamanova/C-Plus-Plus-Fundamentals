/*
	3 16 4 5 6 8 9 			16 9 4
	1 9 4 16 8 25 49 16		49 25 16 16 9 4 1
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void print_sqrt_numbers(string line)
{
	vector<int>  numbers;
	vector<int>  sqrt_numbers;
	string current_number = "";
	int parse_current_number;
	for (int symbol = 0; symbol < line.size(); symbol++)  //crawls all line of numbers
	{
		if (line[symbol] != ' ')
		{
			current_number += line[symbol];   //make string with current number
		}
		else
		{
			parse_current_number = stoi(current_number);
			numbers.push_back(parse_current_number);  //if symbol is ' ' insert in the vector "numbers" current number
			current_number = "";   // empty the string for the next number
		}
	}
	parse_current_number = stoi(current_number);
	numbers.push_back(parse_current_number);  //this is for the last one number

	for (int number : numbers)    //check all number in vector "numbers"
	{ 
		double root = sqrt(number);                    
		int whole_part = root / 1;				   //if whole part of the root of the number at second 
		if (whole_part * whole_part == number)	   //degree is that number that number have accurate root   
		{
			sqrt_numbers.push_back(number);    
		}
	}

	sort(sqrt_numbers.begin(), sqrt_numbers.end());  //sort strings in vector "numbers"
	
	for (int number = sqrt_numbers.size() - 1; number >= 0; number--)
	{													            //crawls all vector and push all numbers
		cout << sqrt_numbers[number] << " ";                       	//with " <= " in string "short_numbers"
	}
}

int main()
{
	string line;
	getline(cin, line);  //read line of numbers from the console
	cout << endl;

	print_sqrt_numbers(line);
	return 0;
}

