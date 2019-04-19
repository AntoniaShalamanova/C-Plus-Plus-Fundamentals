// 04ReplaceAll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void replace(string sentance, string find_str, string replace_str)
{
	int index = sentance.find(find_str);
	while (index != string::npos)
	{
		sentance.replace(index, find_str.size(), replace_str);
		index = sentance.find(find_str, index + find_str.size());
	}

	cout << sentance << endl;
}

int main()
{
	string sentance, find_str, replace_str;
	getline(cin, sentance);
	cin >> find_str >> replace_str;

	replace(sentance, find_str, replace_str);
    return 0;
}

