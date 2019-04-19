// 04TheMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print_modify_matrix(int special_row, int special_col, char special_element, 
						 vector<vector<char>> matrix, int rows_number, int cols_number)
{
	char element_for_change = matrix[special_row][special_col];
	matrix[special_row][special_col] = special_element;

	int current_row = special_row;
	int current_col = special_col;
	vector<int> current_rows;
	vector<int> current_cols;
	vector<int> next_rows;
	vector<int> next_cols;
	current_rows.push_back(special_row);
	current_cols.push_back(special_col);

	while (!current_rows.empty() && !current_cols.empty())
	{
		for (int i = 0; i < current_rows.size(); i++)
		{
			if (current_rows[i] + 1 <= rows_number - 1)
			{
				if (matrix[current_rows[i] + 1][current_cols[i]] == element_for_change)
				{
					matrix[current_rows[i] + 1][current_cols[i]] = special_element;
					current_row = current_rows[i] + 1;
					current_col = current_cols[i];
					next_rows.push_back(current_row);
					next_cols.push_back(current_col);
				}
			}
			if (current_cols[i] + 1 <= cols_number - 1)
			{
				if (matrix[current_rows[i]][current_cols[i] + 1] == element_for_change)
				{
					matrix[current_rows[i]][current_cols[i] + 1] = special_element;
					current_row = current_rows[i];
					current_col = current_cols[i] + 1;
					next_rows.push_back(current_row);
					next_cols.push_back(current_col);
				}
			}
			if (current_rows[i] - 1 >= 0)
			{
				if (matrix[current_rows[i] - 1][current_cols[i]] == element_for_change)
				{
					matrix[current_rows[i] - 1][current_cols[i]] = special_element;
					current_row = current_rows[i] - 1;
					current_col = current_cols[i];
					next_rows.push_back(current_row);
					next_cols.push_back(current_col);
				}
			}
			if (current_cols[i] - 1 >= 0)
			{
				if (matrix[current_rows[i]][current_cols[i] - 1] == element_for_change)
				{
					matrix[current_rows[i]][current_cols[i] - 1] = special_element;
					current_row = current_rows[i];
					current_col = current_cols[i] - 1;
					next_rows.push_back(current_row);
					next_cols.push_back(current_col);
				}
			}
		}

		current_rows.clear();
		current_cols.clear();
		for (int i = 0; i < next_rows.size(); i++)
		{
			current_rows.push_back(next_rows[i]);
			current_cols.push_back(next_cols[i]);
		}
		next_rows.clear();
		next_cols.clear();
	}

	for (int row = 0; row < rows_number; row++)
	{
		for (int col = 0; col < cols_number; col++)
		{
			cout << matrix[row][col];
		}
		cout << endl;
	}
}

int main()
{
	int rows_number, cols_number, special_row, special_col;
	char element, special_element;
	vector<vector<char>> matrix;
	vector<char> line;

	cin >> rows_number >> cols_number;
	for (int row = 0; row < rows_number; row++)
	{
		for (int col = 0; col < cols_number; col++)
		{
			cin >> element;
			line.push_back(element);
		}
		matrix.push_back(line);
		line.clear();
	}

	cin >> special_element;
	cin >> special_row >> special_col;
	cout << endl;

	print_modify_matrix(special_row, special_col, special_element, matrix, rows_number, cols_number);
    return 0;
}

