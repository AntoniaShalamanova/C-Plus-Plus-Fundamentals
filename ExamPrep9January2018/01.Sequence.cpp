/* 
13
25 3 5 19 7 9 11 13 15 17 21 23 27

output: 9
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int nums_number;
	cin >> nums_number;

	vector<int> sequence;
	int number;
	for (size_t i = 0; i < nums_number; i++)
	{
		cin >> number;
		sequence.push_back(number);
	}

	int i = 0;
	int count = 1;
	int max_subsequence = 0;
	while (i != sequence.size())
	{
		if (sequence.size() == 1)
		{
			cout << "1";
			return 0;
		}
		if (i == sequence.size() - 1)
		{
			if (count > max_subsequence)
			{
				max_subsequence = count;
			}
			break;
		}
		if (sequence[i+1] > sequence[i])
		{
			count++;
		}
		else
		{
			if (count > max_subsequence)
			{
				max_subsequence = count;
			}
			count = 1;
		}

		i++;
	}

	cout << max_subsequence << endl;
    return 0;
}

