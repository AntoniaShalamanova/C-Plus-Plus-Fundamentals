// 02WordMatching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_similar_words_count(string first_row, string second_row)
{
	vector<vector<char>> check_words;
	vector<char> word;
	int symbols = 0;

	while(symbols < first_row.size())
	{
		if(isalpha(first_row[symbols]))
		{
			word.push_back(first_row[symbols]);
			symbols++;
		}
		else
		{
			check_words.push_back(word);
			word.clear();
			symbols++;
		}
	}
	check_words.push_back(word);

	string special_word = "";
	string number = "";
	int percent;
	for (int letters = 0; letters < second_row.size(); letters++)
	{
		if (second_row[letters] == ' ')
		{
			for (int numbers = letters + 1; numbers < second_row.size(); numbers++)
			{
				number += second_row[numbers];
			}
			percent = atoi(number.c_str());
			break;
		}
		special_word += second_row[letters];
	}

	int count_match_symbols = 0;
	int count_match_words = 0;
	double current_percent;
	for (int words = 0; words < check_words.size(); words++)
	{
		count_match_symbols = 0;
		if (check_words[words].size() == special_word.size() && check_words[words][0] == special_word[0])
		{
			for (int i = 0; i < special_word.size(); i++)
			{
				if (check_words[words][i] == special_word[i])
				{
					count_match_symbols++;
				}
			}
		}

		current_percent = count_match_symbols * (100.0 / special_word.size());
		if (percent <= current_percent)
		{
			count_match_words++;
		}
	}

	cout << count_match_words << endl;
}

int main()
{
	string first_row, second_row;
	getline(cin, first_row);
	getline(cin, second_row);

	print_similar_words_count(first_row, second_row);
    return 0;
}

