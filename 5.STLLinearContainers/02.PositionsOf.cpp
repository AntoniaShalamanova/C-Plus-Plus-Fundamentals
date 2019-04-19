// 02PositionsOf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void print_positions(int rows, int cols, vector<vector<int>> matrix, int surched_number)
{
	int count = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (matrix[row][col] == surched_number)
			{
				cout << row << " " << col << endl;
				count++;
			}
		}
	}
	if (count == 0)
	{
		cout << "not found" << endl;
	}
}

int main()
{
	int rows, cols;
	vector<vector<int>> matrix;
	vector<int> current_row;
	int number, surched_number;

	cin >> rows >> cols;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			cin >> number;
			current_row.push_back(number);
		}
		matrix.push_back(current_row);
		current_row.clear();
	}

	cin >> surched_number;
	
	print_positions(rows, cols, matrix, surched_number);
    return 0;
}

