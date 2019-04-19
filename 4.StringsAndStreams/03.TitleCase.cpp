// 03TitleCase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void print_title_case(string sentance)
{
	for (int i = 0; i < sentance.size(); i++)
	{
		if (i == 0)
		{
			sentance[i] = toupper(sentance[i]);
		}
		if (sentance[i] == ' ' || sentance[i] == ',')
		{
			sentance[i + 1] = toupper(sentance[i + 1]);
		}
	}
	cout << sentance << endl;
}

int main()
{
	string sentance;
	getline(cin, sentance);

	print_title_case(sentance);
    return 0;
}

