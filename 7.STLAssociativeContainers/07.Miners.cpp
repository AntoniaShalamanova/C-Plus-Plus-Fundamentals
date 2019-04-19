/*
	Gold			Gold -> 155				 
	155				Silver -> 10			
	Silver			Copper -> 17			
	10										 
	Copper										
	17
	stop

	gold			gold -> 170
	155				silver -> 10
	silver			copper -> 17
	10
	copper
	17
	gold
	15
	stop	
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void print_resources_quantity(vector<string> elements)
{
	unordered_map<string, int> resources_and_quantity;
	for (int current_element = 0; current_element < elements.size(); current_element += 2)
	{
		if (current_element == elements.size() - 1)
		{											//crawls all vector "elements" 
			break;									//if current element is the last element of the vector breaks
		}
		string resource = elements[current_element];            //current_element is resource
		int quantity = stoi(elements[current_element + 1]);     //next element is quantity
		resources_and_quantity[resource] += quantity;           //check map for that resource and sum his quantity
	}
	
	for (auto pairs : resources_and_quantity)         //crawls all map "resources_and_quantity" and print his content
	{
		cout << pairs.first << " -> " << pairs.second << endl;
	}
	cout << endl;
}

int main()
{
	vector<string> elements;
	string lines;
	while (lines != "stop")     //read strings "lines" from the console and if they are different from "stop"
	{							//push them in vector "elements"
		cin >> lines;
		elements.push_back(lines);
	}
	cout << endl;
	
	print_resources_quantity(elements);
    return 0;
}

