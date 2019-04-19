/*
1		->	45
100			90


1		->	45
90


450000000000000000000000000000000000000013	->	450000000000000000000000000000000000000045
450000000000000000000000000000000000000100		450000000000000000000000000000000000000090
*/

#include "stdafx.h"
#include "BigInt.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Numbers
{
public:
	int64_t start_number;
	int64_t end_number;

	Numbers(int64_t start_number, int64_t end_number)
	{
		this->start_number = start_number;
		this->end_number = end_number;
	}

	string print_numbers()
	{
		ostringstream number_stream;
		for (int64_t current_number = start_number; current_number < end_number; current_number++)
		{
			if (current_number % 45 == 0)
			{
				number_stream << current_number << endl;
			}
		}
		return number_stream.str();
	}
};

int main()
{
	int64_t start_number;
	int64_t end_number;

	cin >> start_number >> end_number;

	Numbers object(start_number, end_number);
	cout << object.print_numbers() << endl;
	return 0;
}

