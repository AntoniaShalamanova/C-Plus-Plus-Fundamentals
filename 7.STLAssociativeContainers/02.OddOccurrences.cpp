/*
	Java C# PHP PHP JAVA C java	         java, c#, c
	3 5 5 hi pi HO Hi 5 ho 3 hi pi	     5, hi
	a a A SQL xx a xx a A a XX c	     a, sql, xx, c
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void print_odd_encounter_strings(string sequence)
{
	unordered_map<string, int>  strings;
	string current_string = "";
	for (int symbol = 0; symbol < sequence.size(); symbol++)  //crawls all sequence
	{
		if (sequence[symbol] != ' ')
		{
			sequence[symbol] = tolower(sequence[symbol]); //make all symbols in sequence lower
			current_string += sequence[symbol];   //make string with current number or word
		}
		else
		{
			strings[current_string]++;  //if symbol is ' ' check map for current number or word
			current_string = "";   // empty the string for the next number or word
		}
	}
	strings[current_string]++;  //this is for the last one number or word

	string odd_encounter_strings = "";
	for (pair<string, int> str : strings)  //crawls all map
	{
		if (str.second % 2 != 0)    //check if current string from map is meeting odd times
		{
			odd_encounter_strings += str.first + ", ";   //add current string in odd_encounter_strings 
		}												//with comma and space at the end
	}


	for (int character = 0; character < odd_encounter_strings.size()-2; character++)
	{
		cout << odd_encounter_strings[character];   //prints all odd_encounter_strings
	}												//without the last one comma and space
	cout << endl;
}

int main()
{
	string sequence;
	getline(cin, sequence); //read all line of strings
	cout << endl;

	print_odd_encounter_strings(sequence);
    return 0;
}

