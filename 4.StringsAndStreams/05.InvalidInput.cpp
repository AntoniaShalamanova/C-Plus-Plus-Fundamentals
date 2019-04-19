// 05InvalidInput.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_sum(string str)
{
	string word = "";
	vector <string> invalid_element;
	int sum = 0;

	int i = 0;
	while(i < str.size())
	{
		if (str[i] == '-' && isdigit(str[i+1]))
		{
			word = "";
			while (str[i] != ' ' && str[i] != '\0')
			{
				if (str[i] == '-')
				{
					i++;
				}
				else
				{
					word += str[i];
					i++;
				}
			}
			sum += -(stoi(word));
		}
		else if (str[i] == ' ')
		{
			i++;
		}
		else if (isdigit(str[i]))
		{
			word = "";
			while (str[i] != ' ' && str[i] != '\0')
			{
				word += str[i];
				i++;
			}
			sum += (stoi(word));
		}
		else
		{
			word = "";
			while (str[i] != ' ' && str[i] != '\0')
			{
				word += str[i];
				i++;
			}
			invalid_element.push_back(word);
			invalid_element.push_back(" ");
		}
	}
	cout << sum << endl;
	for (string element : invalid_element)
	{
		cout << element;
	}
	cout << endl;
}

int main()
{
	string str;
	getline(cin, str);

	print_sum(str);
	return 0;
}

