#include <iostream>
#include <cmath>
using namespace std;

#include "Cart_Vector.h"

//Constructors
Cart_Vector::Cart_Vector() 
{
	x = 0.0;
	y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	x = inputx;
	y = inputy;
}

//Overloaded Operators
Cart_Vector operator*(Cart_Vector v1, double d)
{
	double x;
	double y;
	if (d == 0)
	{
		x = v1.x;
		y = v1.y;
	}
	else
	{
		x = v1.x * d;
		y = v1.y * d;
	}
	return Cart_Vector(x, y);
}

Cart_Vector operator / (Cart_Vector &v1, double d)
{
	Cart_Vector* pvector = new Cart_Vector;
	
	double x;
	double y;
	if (d == 0)
	{
		x = v1.x;
		y = v1.y;
	}
	else
	{
		x = v1.x/d;
		y = v1.y/d;
	}
	*pvector = Cart_Vector(x, y);
	return *pvector;

}

ostream& operator << (ostream& os, Cart_Vector v1)
{
	os << "<" << v1.x << ", " << v1.y << ">"; 
	return os;
}
