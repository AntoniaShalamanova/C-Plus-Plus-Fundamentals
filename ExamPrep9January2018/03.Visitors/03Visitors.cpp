/*
entry 1A John 15
entry 1B Tony 16
entry 1A John 15
entry 1C John 86
name John
name Jebediah
entry 1A John 15
entry 1B Tony 16
entry 1A John 15
entry 1E Jebediah 87
entry 1D Mark 16
age 15 87
end

output:
2
0
4
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Visitors
{
public:
	string ID;
	string name;
	int age;

}object[1000];

int main()
{
	string ID, name, operation, searched_name;
	int age;
	int visitors_num = 0, from_age, to_age;
	unordered_set<string> unique_visitors;
	queue<int> result;

	do
	{
		cin >> operation;

		if (operation == "entry")
		{
			cin >> ID >> name >> age;
			object[visitors_num].ID = ID;
			object[visitors_num].name = name;
			object[visitors_num].age = age;
			
			visitors_num++;
		}
		else if (operation == "name")
		{
			cin >> searched_name;
			for (size_t i = 0; i < visitors_num; i++)
			{
				if (object[i].name == searched_name)
				{
					unique_visitors.insert(object[i].ID);
				}
			}
			result.push(unique_visitors.size());
			unique_visitors.clear();
		}
		else if (operation == "age")
		{
			cin >> from_age >> to_age;

			for (size_t i = 0; i < visitors_num; i++)
			{
				if (object[i].age >= from_age && object[i].age < to_age)
				{
					unique_visitors.insert(object[i].ID);
				}
			}
			result.push(unique_visitors.size());
			unique_visitors.clear();
		}
	} while (operation != "end");

	while (!result.empty())
	{
		cout << result.front() << endl;
		result.pop();
	}
	return 0;
}

