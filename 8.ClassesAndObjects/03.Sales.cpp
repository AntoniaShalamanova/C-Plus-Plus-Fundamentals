/*
	5
	Sofia beer 1.20 160
	Varna chocolate 2.35 86
	Sofia coffee 0.40 853
	Varna apple 0.86 75.44
	Plovdiv beer 1.10 88

	Output:
	Plovdiv -> 96.80
	Sofia -> 533.20
	Varna -> 266.98
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class sale //create class "sale"
{
private:
	string town, product;
	double price, quantity;  //create fields for current town

public:
	sale(string town, string product, double price, double quantity)  //make constructor
	{
		this->town = town;
		this->product = product;
		this->price = price;
		this->quantity = quantity;
	}

	string get_current_town()  //make method "get_current_town" which  return name of current town
	{
		return this->town;
	}

	double get_sale()  //make method "get_sale" which return current sale in that town
	{
		return this->price * this->quantity;
	}
};

int main()
{
	int input_numbers;
	string town, product;
	double price, quantity;
	map<string, double> total_sales;

	cin >> input_numbers;  //read from the console numbers of inputs

	for (int input = 0; input < input_numbers; input++)  
	{
		cin >> town >> product >> price >> quantity; //on each input we insert the fields for the class "sale"
		sale s(town, product, price, quantity); //create object "s" with that fields
		total_sales[s.get_current_town()] += s.get_sale(); //insert in map "total_sales" town and total sales for that town
	}
	cout << endl;
	
	for (auto town_sales : total_sales) //earn all pair of strings and double in map "total_sales" on the console
	{
		cout << town_sales.first << " -> " << fixed << setprecision(2) << town_sales.second << endl;
	}
	cout << endl;
	
    return 0;
}

