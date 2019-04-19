
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class  Cars //make class "Cars" with class "Owner" and fields 
{			//"manufacturer_name", "model_name", "horsepower", "registration_number"
public:
	class Owner //make class "Owner" with fields "person_name", "person_age", "person_ID"
	{
	public:
		string person_name;
		int person_age;
		int person_ID;
	};

	string manufacturer_name;
	string model_name;
	double horsepower;
	string registration_number;
	Owner owner;

	void print_all_info()  //make method wich print all info for one record in file "SaveToFile.txt"
	{
		ofstream output;
		output.open("SaveToFile.txt", ios::ate);

		output << "Person ID: " << this->owner.person_ID << endl
			<< "Manufacturer name: " << this->manufacturer_name << endl
			<< "Model name: " << this->model_name << endl
			<< "Horsepower: " << this->horsepower << endl
			<< "Registration number: " << this->registration_number << endl
			<< "Person name: " << this->owner.person_name << endl
			<< "Person age: " << this->owner.person_age << endl << endl;

		output.close();
	}

}object[100]; //create object "object" wich is array with max 100 records

int main()
{
	int input_number; //this is for records number
	string manufacturer_name;
	string model_name;
	double horsepower;
	string registration_number; //this is the classes fields
	string person_name;
	int person_age;
	int person_ID;

	cout << "Enter numbers of input: ";
	cin >> input_number;
	cout << endl;

	for (int i = 0; i < input_number; i++) //this loop insert the fields of every record
	{
		cout << "Enter manufacturer name of the car: ";
		cin >> manufacturer_name;

		cout << "Enter model name of the car: ";
		cin >> model_name;

		cout << "Enter horsepower of the car: ";
		cin >> horsepower;

		cin.ignore();
		cout << "Enter registration number of the car: ";
		getline(cin, registration_number);

		cout << "Enter name of the person: ";
		getline(cin, person_name);

		cout << "Enter age of the person: ";
		cin >> person_age;
		cout << endl;

		person_ID = i;

		object[i].manufacturer_name = manufacturer_name;
		object[i].model_name = model_name;
		object[i].horsepower = horsepower;
		object[i].registration_number = registration_number;
		object[i].owner.person_name = person_name;
		object[i].owner.person_age = person_age;
		object[i].owner.person_ID = person_ID;

		object[i].print_all_info(); //this print to "SaveToFile.txt" current record
	}
	return 0;
}