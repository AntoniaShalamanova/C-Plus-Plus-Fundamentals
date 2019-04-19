/*
Information in the file "ReadFromFile.txt":

Person ID: 0
Manufacturer name: Dodge
Model name: Challenger
Horsepower: 900
Registration number: W 0000 QM
Person name: Bai Ivan
Person age: 40
Person ID: 1
Manufacturer name: Bugatti
Model name: Veyron
Horsepower: 1200
Registration number: Q 4444 PM
Person name: Ionko Ionkov
Person age: 30
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class  Cars //make class "Cars" with class "Owner" and fields 
{			//"manufacturer_name", "model_name", "horsepower", "registration_number"
public:
	class Owner //make class "Owner" with fields "person_name", "person_age", "person_ID"
	{
	public:
		string person_name, person_age, person_ID;
	};

	string manufacturer_name, model_name, horsepower, registration_number;
	Owner owner;

	string get_info()  //make getter wich print all fields on the console
	{
		ostringstream out_stream;
		out_stream << this->owner.person_ID << endl
			<< this->manufacturer_name << endl
			<< this->model_name << endl
			<< this->horsepower << endl
			<< this->registration_number << endl
			<< this->owner.person_name << endl
			<< this->owner.person_age << endl << endl;

		return out_stream.str();
	}

}object[100]; //create object "object" with max 100 records


int main()
{
	string manufacturer_name, model_name, horsepower, registration_number;   //this is the classes fields
	string	person_name, person_age, person_ID;

	int records_number;
	cout << "Enter number of records: "; //in my file "ReadFromFile.txt" has 2 records
	cin >> records_number;
	cout << endl;

	ifstream input;
	input.open("ReadFromFile.txt");

	for (int i = 0; i < records_number; i++)
	{
		getline(input, person_ID);
		getline(input, manufacturer_name);
		getline(input, model_name);
		getline(input, horsepower);                //insert from file "input.txt" fields of the class "Cars"
		getline(input, registration_number);
		getline(input, person_name);
		getline(input, person_age);

		object[i].owner.person_ID = person_ID;
		object[i].manufacturer_name = manufacturer_name;
		object[i].model_name = model_name;
		object[i].horsepower = horsepower;
		object[i].registration_number = registration_number;
		object[i].owner.person_name = person_name;
		object[i].owner.person_age = person_age;

		cout << object[i].get_info(); //print to the console all fields from the file "ReadFromFile.txt"
	}

	return 0;
}