// 06TheSignalAndTheNoise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void print_max_num(string str)
{
	int max_num = 0;
	string num;
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
				num += str[i];
				i++;
			}
			else
			{
				i++;
			}
		}
		if (stoi(num) > max_num)
		{
			max_num = stoi(num);
		}
		num = "";
	}
	cout << max_num << endl;
}

int main()
{
	string str;
	getline(cin, str);

	print_max_num(str);
    return 0;
}

