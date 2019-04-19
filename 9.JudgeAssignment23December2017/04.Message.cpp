/*
	chug a mug of mead and another mug mead chug another mug of mead warrior .
	2
	3 0
	2 1

	output:
	mead
	chug
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int main()
{
	string line;
	int queries_number, occurrence_count, index;
	vector<string> correct_words;
	getline(cin, line);
	cin >> queries_number;

	map<string, int> words;
	string current_word = "";
	for (int symbol = 0; symbol < line.size(); symbol++)
	{
		if (line[symbol] == ' ')
		{
			words[current_word]++;
			current_word = "";
			symbol++;
		}
		current_word += line[symbol];
	}

	ostringstream words_stream;
	for (int query = 0; query < queries_number; query++)
	{
		cin >> occurrence_count >> index;
		for (auto word = words.begin(); word != words.end(); word++)
		{
			if (word->second == occurrence_count)
			{
				correct_words.push_back(word->first);
			}
		}
		if (correct_words.size() == 0 || index < 0 || index >= correct_words.size())
		{
			words_stream << "." << endl;
		}
		else
		{
			words_stream << correct_words[index] << endl;
			correct_words.clear();
		}
	}
	cout << words_stream.str();
	return 0;
}

