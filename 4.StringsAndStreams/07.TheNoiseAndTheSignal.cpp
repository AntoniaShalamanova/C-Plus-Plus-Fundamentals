// 07TheNoiseAndTheSignal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void print_longest_noise(string str)
{
	string max_str = "";
	string letters = "";
	int i = 0;
	while (i < str.size())
	{
		if (str[i] == ' ')
		{
			i++;
		}
		while (str[i] != ' ' && str[i] != '\0')
		{
			if (isdigit(str[i]))
			{
				i++;
			}
			else
			{
				letters += str[i];
				i++;
			}
		}
		if (letters.size() > max_str.size())
		{
			max_str = letters;
		}
		else if (letters.size() == max_str.size())
		{
			if (letters < max_str)
			{
				max_str = letters;
			}
		}
		letters = "";
	}
	if (max_str == "")
	{
		cout << "no noise" << endl;
	}
	else
	{
		cout << max_str << endl;
	}
}

int main()
{
	string str;
	getline(cin, str);

	print_longest_noise(str);
	return 0;
}

