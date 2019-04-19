// 03QuadraticEquation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	double discr = pow(b, 2) -4 * a * c;
	double x1, x2;
	if (discr<0)
	{
		cout << "no roots" << endl;
	}
	else if (discr == 0)
	{
		x1 = (-b + sqrt(discr)) / (2.0 * a);
		cout << x1 << endl;
	}

	else
	{
		x1 = (-b + sqrt(discr)) / (2.0 * a);
		x2 = (-b - sqrt(discr)) / (2.0 * a);
		cout << x1 << " " << x2 << endl;
	}
    return 0;
}

