// Roxettes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int print_unique_DNA(string str)
{
	bool equal = false;
	vector <string> DNAs;
	string DNA = "";
	int letters = 0;
	int letter = 0;
	while (letters < str.size() - 1)
	{
		while (letters < letter + 5)
		{
			DNA += str[letters];
			letters++;
		}
		DNAs.push_back(DNA);
		DNA = "";
		letter += 5;
	}

	for (int current_DNA = 0; current_DNA < DNAs.size(); current_DNA++)
	{
		for (int i = 0; i < DNAs.size(); i++)
		{
			if (current_DNA != i)
			{
				if (DNAs[current_DNA] == DNAs[i])
				{
					equal = true;
					break;
				}
			}
		}
		if (equal == false)
		{
			cout << DNAs[current_DNA] << endl;
			return 0;
		}
		equal = false;
	}
}

int main()
{
	string str;
	getline(cin, str);

	print_unique_DNA(str);
	return 0;
}

