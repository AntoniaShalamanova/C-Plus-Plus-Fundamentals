
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class  Planets //make class "Planets"
{			   
public:
	string planet_name;
	string system_name;
	int position;
	size_t weight;
	size_t radius;
	string type;

	void change_system_name(string system_name)   //make setter wich change the name of the system
	{
		this->system_name = system_name;
	}

	void change_planet_type(string type)  //make setter wich change the type of the planet
	{
		this->type = type;
	}

	string print_to_console()  //make getter wich print on the console record you look for
	{
		ostringstream info;
		info << this->system_name << " - " << this->position
			<< " (" << this->planet_name << ") "
			<< "{mass: " << this->weight << ", radius: "
			<< this->radius << "}" << endl;
		
		return info.str();
	}

	void print_to_file()  //make method wich print all info in file "PlanetsInfo.txt"
	{
		ofstream output;
		output.open("PlanetsInfo.txt", ios::app); //ios::app keep the previous records you entered

		output << this->system_name << " - " << this->position
			<< " (" << this->planet_name << ") "
			<< "{mass: " << this->weight << ", radius: "
			<< this->radius << "}" << endl << endl;

		output.close();
	}
}object[100];

int main()
{
	int record_number; //this is for records number

	string planet_name;
	string system_name;
	int position;                //this is the classes fields
	size_t weight;
	size_t radius;
	string type;

	cout << "Enter number of records: ";
	cin >> record_number;
	cout << endl;
	cin.ignore();

	for (int i = 0; i < record_number; i++) //this loop insert the fields of every record
	{
		cout << "Enter the name of the planet: ";
		getline(cin, planet_name);

		cout << "Enter the name of the system: ";
		getline(cin, system_name);

		cout << "Enter position of the planet in the system: ";
		cin >> position;

		cout << "Enter weight of the planet in kilograms: ";
		cin >> weight;

		cout << "Enter radius of the planet in meters: ";
		cin >> radius;

		cout << "Enter type of the planet (STAR, ROCKY PLANET, GAS GIANT, UNKNOWN): ";
		cin.ignore();
		getline(cin, type);
		cout << endl;

		object[i].planet_name = planet_name;
		object[i].system_name = system_name;
		object[i].position = position;
		object[i].weight = weight;
		object[i].radius = radius;
		object[i].type = radius;
	}


	string update;
	int selected_number;
	int selected_input;

	do //this is the update
	{
		cout << "Do you want to update the data? (YES/NO): ";
		cin >> update;
		cout << endl;

		if (update == "YES")
		{
			cout << "Press 1 to change system name" << endl
				<< "Press 2 to change planet type "; //this choose 1st or 2nd setter 
			cin >> selected_number;
			cout << endl;

			cout << "Select record which you want to update (From 0 to " << record_number - 1 << "): ";
			cin >> selected_input;  //this choose number of record which you want to update
			cout << endl;

			if (selected_number == 1) //this is the 1st setter which change the system name
			{
				cout << "Enter the new name of the system: ";
				cin.ignore();
				getline(cin, system_name);
				cout << endl;

				object[selected_input].change_system_name(system_name);
			}
			else if (selected_number == 2) //this is the 2nd setter which change the planet type
			{
				cout << "Enter new type of the planet: ";
				cin.ignore();
				getline(cin, type);
				cout << endl;
				object[selected_input].change_planet_type(type);
			}
		}
	} while (update != "NO");


	string searched_planet;
	cout << "Enter the name of the planet you looking for: ";
	cin.ignore();
	getline(cin, searched_planet);
	for (int i = 0; i < record_number; i++)
	{
		if (object[i].planet_name == searched_planet)     //search planet and prints all information for her
		{
			cout << object[i].print_to_console() << endl;
			break;
		}
	}
	

	for (int i = 0; i < record_number; i++)
	{											//print to the file "PlanetsInfo.txt" all
		object[i].print_to_file();				//records, and those which is updated too
	}

	return 0;
}