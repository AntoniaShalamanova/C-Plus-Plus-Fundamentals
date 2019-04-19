/*
	3
	A 3 a b c
	B 2 d e
	C 4 a b c d
	4					->		4 4 4 1 0
	A
	A
	C
	A
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int teams_number;
	cin >> teams_number;

	map<string, vector<string>> teams;
	string team_name;
	int players_number;
	string players_name;
	for (int i = 0; i < teams_number; i++)
	{
		cin >> team_name;
		cin >> players_number;
		for (int i = 0; i < players_number; i++)
		{
			cin >> players_name;
			teams[team_name].push_back(players_name);
		}
	}

	int winning_teams_number;
	cin >> winning_teams_number;
	string win_team;
	map<string, int> players_points;
	set<string> win_teams;
	for (int i = 0; i < winning_teams_number; i++)
	{
		cin >> win_team;
		win_teams.insert(win_team);
		for (int i = 0; i < teams[win_team].size(); i++)
		{
			players_points[teams[win_team][i]]++;
		}
	}

	bool is_equal = false;
	for (auto team : teams)
	{
		is_equal = false;
		for (auto win_team : win_teams)
		{
			if (team.first == win_team)
			{
				is_equal = true;
				break;
			}
		}

		if (is_equal == false)
		{
			for (int i = 0; i < teams[team.first].size(); i++)
			{
				players_points[teams[team.first][i]] + 0;
			}
		}
	}

	for (auto i : players_points)
	{
		cout << i.second << " ";
	}
	cout << endl;

    return 0;
}

