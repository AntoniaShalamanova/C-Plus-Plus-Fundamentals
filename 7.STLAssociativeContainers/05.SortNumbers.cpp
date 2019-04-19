/*
	8 2 7 3	       2 <= 3 <= 7 <= 8
	2 4 -9	       -9 <= 2 <= 4
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print_sort_numbers(string line)
{
	vector<string>  numbers;
	string current_number = "";
	for (int symbol = 0; symbol < line.size(); symbol++)  //crawls all line of numbers
	{
		if (line[symbol] != ' ')
		{
			current_number += line[symbol];   //make string with current number
		}
		else
		{
			numbers.push_back(current_number);  //if symbol is ' ' insert in the vector "numbers" current number
			current_number = "";   // empty the string for the next number
		}
	}
	numbers.push_back(current_number);  //this is for the last one number

	sort(numbers.begin(), numbers.end()); //sort strings in vector "numbers"

	string sort_numbers = "";
	for (string number : numbers)                 
	{													//crawls all vector and push all numbers
		sort_numbers += number + " <= ";		//with " <= " in string "short_numbers"
	}
	
	for (int number = 0; number < sort_numbers.size() - 3; number++)
	{
		cout << sort_numbers[number];   //print all string "short_numbers" without last " <= "
	}
	cout << endl;
}

int main()
{
	string line;
	getline(cin, line);  //read line of numbers from the console
	cout << endl;

	print_sort_numbers(line);
    return 0;
}

