/*
Hello World
copy 2 3
paste 5
copy 6 23
paste 2
end

output: HeHello Worldllo Hello World
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int get_from(string sequence, int from)
{
	while (from > 0 && sequence[from - 1] != ' ')
	{
		from--;
	}

	return from;
}

int get_to(string sequence, int to)
{
	while (to < sequence.size() - 1 && sequence[to + 1] != ' ')
	{
		to++;
	}

	return to;
}

int main()
{
	string sequence, operation, clipboard;
	int from, to, position;
	getline(cin, sequence);
	stack<string> all_clipboards;

	do
	{
		cin >> operation;

		if (operation == "copy")
		{
			cin >> from >> to;

			from = get_from(sequence, from);
			to = get_to(sequence, to);

			clipboard = sequence.substr(from, to - from + 1);
			all_clipboards.push(clipboard);
		}

		else if (operation == "paste")
		{
			cin >> position;

			if (all_clipboards.size() == 0)
			{
				continue;
			}
			else if (sequence[position] == ' ')
			{
				clipboard = all_clipboards.top();
				all_clipboards.pop();
				clipboard += ' ';
				sequence.insert(position + 1, clipboard);
			}
			else
			{
				clipboard = all_clipboards.top();
				all_clipboards.pop();
				sequence.insert(position, clipboard);
			}
			clipboard = "";
		}
	} while (operation != "end");


	cout << sequence << endl;
	return 0;
}

