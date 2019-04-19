/* 
	3 4	 ->	5.000
	6 8

	3 4	 ->	2.000
	5 4

	8 -2 ->	11.402
	-1 5
*/

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class points //create class "points"
{
private:
	double x1, y1, x2, y2; //create fields for locations of two points

public:
	points(double x1, double y1, double x2, double y2) //make constructor
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	double distance() //make method "distance" which  return double 
	{
		double diff_x = this->x1 - this->x2;;
		double diff_y = this->y1 - this->y2;;
		
		double distance = sqrt(pow(diff_x, 2) + pow(diff_y, 2));

		return distance;
	}
};

int main()
{
	double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2; //read from the console locations on two points
	cout << endl;

	points p(x1, y1, x2, y2); //create object "p" with that locations on the points

	cout << fixed << setprecision(3) << p.distance() << endl; //return on the console distance of the points
    return 0;
}

