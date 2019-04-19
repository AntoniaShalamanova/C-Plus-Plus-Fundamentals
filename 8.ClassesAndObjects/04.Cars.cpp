
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

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

	void change_owner(string person_name, int person_age, string registration_number) 
	{
		this->owner.person_name = person_name;
		this->owner.person_age = person_age;              //make setter wich change the car owner  
		this->registration_number = registration_number;
	}

	void change_owner_name(string person_name)
	{
		this->owner.person_name = person_name;  //make setter wich change only the person name
	}

	void change_owner_age(int person_age)  //make setter wich change only the person age
	{
		this->owner.person_age = person_age;
	}

	string get_all_info()  //make getter wich keep all info for one record
	{
		ostringstream info;
		info << "Person ID: " << this->owner.person_ID << endl
			<< "Manufacturer name: " << this->manufacturer_name << endl
			<< "Model name: " << this->model_name << endl
			<< "Horsepower: " << this->horsepower << endl
			<< "Registration number: " << this->registration_number << endl
			<< "Person name: " << this->owner.person_name << endl
			<< "Person age: " << this->owner.person_age << endl;
		return info.str();
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
			cout << "Press 1 to change owner" << endl
				<< "Press 2 to change owner name" << endl //this choose 1st, 2nd or 3th setter 
				<< "Press 3 to change owner age ";
			cin >> selected_number;
			cout << endl;

			cout << "Select input which you want to update (From 0 to " << input_number - 1 << "): ";
			cin >> selected_input;  //this choose number of record which you want to update
			cout << endl;

			if (selected_number == 1) //this is the 1st setter which change the car owner
			{
				cout << "Enter name of new owner: ";
				cin.ignore();
				getline(cin, person_name);
				cout << "Enter age of new owner: ";
				cin >> person_age;
				cout << "Enter new registration number: ";
				cin.ignore();
				getline(cin, registration_number);
				cout << endl;
				object[selected_input].change_owner(person_name, person_age, registration_number);
			}
			else if (selected_number == 2) //this is the 2nd setter which change the owner name
			{
				cout << "Enter new name of owner: ";
				cin.ignore();
				getline(cin, person_name);
				cout << endl;
				object[selected_input].change_owner_name(person_name);
			}
			else if (selected_number == 3) //this is the 3th setter which change the owner age
			{
				cout << "Enter new age of owner: ";
				cin >> person_age;
				cout << endl;
				object[selected_input].change_owner_age(person_age);
			}
		}
	} while (update != "NO");


	cout << "All RECORDS:" << endl << endl;
	for (int i = 0; i < input_number; i++) //this earns all records, and those which is updated too
	{
		cout << object[i].get_all_info() << endl;
	}

	return 0;
}

