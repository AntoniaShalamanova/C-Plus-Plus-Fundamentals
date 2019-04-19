

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_are_equal(int first_matrix_rows, int second_matrix_rows,
					 vector<string> first_matrix, vector<string> second_matrix)
{
	bool are_equal;
	if (first_matrix_rows != second_matrix_rows)
	{
		are_equal = false;
	}
	else
	{
		for (int row = 0; row < first_matrix_rows; row++)
		{
			if (first_matrix[row] == second_matrix[row])
			{
				are_equal = true;
			}
			else
			{
				are_equal = false;
				break;
			}
		}
	}
	if (are_equal == false)
	{
		cout << "not equal" << endl;
	}
	else
	{
		cout << "equal" << endl;
	}
}

int main()
{
	int first_matrix_rows;
	int second_matrix_rows;
	vector<string> first_matrix;
	vector<string> second_matrix;
	string line = "";

	cin >> first_matrix_rows;
	for (int row = 0; row < first_matrix_rows; row++)
	{
		cin.ignore();
		getline(cin, line);
		first_matrix.push_back(line);
		line = "";
	}

	cin >> second_matrix_rows;
	for (int row = 0; row < second_matrix_rows; row++)
	{
		cin.ignore();
		getline(cin, line);
		second_matrix.push_back(line);
		line = "";
	}

	print_are_equal(first_matrix_rows, second_matrix_rows, first_matrix, second_matrix);
    return 0;
}

