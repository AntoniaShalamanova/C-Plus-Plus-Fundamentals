
#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <unordered_map>
#include <vector>
#include <limits>

using namespace std;

class Points 
{
private:
	int x1, y1, x2, y2; 

public:
	Points(int x1, int y1, int x2, int y2) 
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	double get_distance()  
	{
		double diff_x = this->x1 - this->x2;;
		double diff_y = this->y1 - this->y2;;

		double distance = sqrt(pow(diff_x, 2) + pow(diff_y, 2));

		return distance;
	}
};

int main()
{
	int input_number;
	cin >> input_number;

	string town_name;
	string town_x, town_y;
 	vector<vector<string>> cities;
	vector<string> town;
	for (size_t i = 0; i < input_number; i++)
	{
		cin >> town_name >> town_x >> town_y;
		town.push_back(town_name);
		town.push_back(town_x);
		town.push_back(town_y);
		cities.push_back(town);
		town.clear();
	}
	
	double current_distance;
	int min_distance = INT32_MAX;
	vector<string>min_distance_couples;
	int current_town = 0;
	int next_town;
	while (current_town < cities.size()-1)
	{
		int x1 = atoi(cities[current_town][1].c_str());
		int y1 = atoi(cities[current_town][2].c_str());
		string current_town_name = cities[current_town][0];
		current_town++;
		next_town = current_town;

		while (next_town < cities.size())
		{
			int x2 = atoi(cities[next_town][1].c_str());
			int y2 = atoi(cities[next_town][2].c_str());
			string next_town_name = cities[next_town][0];

			Points p(x1, y1, x2, y2);
			current_distance = p.get_distance();

			if (current_distance < min_distance)
			{
				min_distance = current_distance;
				min_distance_couples.clear();
				min_distance_couples.push_back(current_town_name);
				min_distance_couples.push_back(next_town_name);
			}
			else if (current_distance == min_distance)
			{
				min_distance_couples.push_back(current_town_name);
				min_distance_couples.push_back(next_town_name);
			}
			next_town++;
		}
	}

	cout << min_distance_couples[0] << "-" << min_distance_couples[1] << endl;
	return 0;
}

