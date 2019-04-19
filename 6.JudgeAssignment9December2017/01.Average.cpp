// 01Average.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int hex_to_dec(char first_symbol, char second_symbol)
{
	int sum;
	if (first_symbol >= 'a')
	{
		sum = (first_symbol - 87) * 16;
	}
	else
	{
		sum = (first_symbol - 48) * 16;
	}

	if (second_symbol >= 'a')
	{
		sum += (second_symbol - 87);
	}
	else
	{
		sum += (second_symbol - 48);
	}
	return sum;
}

void sum_average(string first_color, string second_color)
{
	cout << "#";
	char first_symbol;
	char second_symbol;
	for (int channel = 0; channel < first_color.size(); channel += 2)
	{
		if (channel == first_color.size() - 1)
		{
			break;
		}
		else
		{
			first_symbol = first_color[channel];
			second_symbol = first_color[channel + 1];

			int first_color_sum = hex_to_dec(first_symbol, second_symbol);

			first_symbol = second_color[channel];
			second_symbol = second_color[channel + 1];

			int second_color_sum = hex_to_dec(first_symbol, second_symbol);

			int sum_average = first_color_sum + second_color_sum;
			if (sum_average > 225)
			{
				while (sum_average > 225)
				{
					sum_average /= 2;
				}
			}
			else
			{
				sum_average /= 2;
			}

			cout << hex << setfill('0') << setw(2) << sum_average;
		}
	}
	cout << endl;
}

int main()
{
	string line;
	getline(cin, line);
	cout << endl;

	vector<string> colors;
	string current_color = "";
	for (int symbol = 1; symbol < line.size(); symbol++)
	{
		if (line[symbol] == ' ')
		{
			colors.push_back(current_color);
			current_color = "";
			symbol += 2;
		}
		current_color += line[symbol];
	}
	colors.push_back(current_color);

	string first_color = colors[0];
	string second_color = colors[1];

	sum_average(first_color, second_color);
	return 0;
}
