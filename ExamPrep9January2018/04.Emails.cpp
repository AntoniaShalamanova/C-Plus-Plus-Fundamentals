/*
ab
5
ab ab a
a a abba a
bb aa ab
.

output:
ab ab a
bb aa ab
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

int main()
{
	string searched_word, message;
	int messages_num, count = 0;
	map<int, string, std::greater<int>> correct_messages;

	cin >> searched_word >> messages_num;
	cin.ignore();
	do
	{
		getline(cin, message);

		string current_word = "";
		for (int symbol = 0; symbol < message.size(); symbol++)  
		{
			if (message[symbol] != ' ')
			{
				current_word += message[symbol];    
			}
			else
			{
				if (current_word == searched_word)
				{
					count++;
				}
				current_word = "";
			}
		}
		if (current_word == searched_word)
		{
			count++;
		}
		current_word = "";

		if (count != 0)
		{
			correct_messages[count] = message;
		}
		count = 0;

	} while (message != ".");
	

	for (auto i = correct_messages.begin(); i != correct_messages.end(); i++)
	{
		if (count == messages_num)
		{
			break;
		}
		cout << (*i).second << endl;
		count++;
	}
    return 0;
}

