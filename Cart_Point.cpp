#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

#include "Cart_Point.h"

//Constructors
Cart_Point::Cart_Point(double inputx, double inputy) // Do we need the game object?
{
	x = inputx;
	y = inputy;
}
Cart_Point::Cart_Point()
{
	x = 0.0;
	y = 0.0;	
}

//Overloaded Operators
Cart_Point operator + (Cart_Point &p1, Cart_Vector &v1)
{
	double x = p1.x + v1.x;
	double y = p1.y + v1.y;
	return Cart_Point(x, y);
}

Cart_Vector operator - (Cart_Point &p1, Cart_Point &p2)
{
	double delta_x = p1.x - p2.x;
	double delta_y = p1.y - p2.y;
	return Cart_Vector(delta_x, delta_y);
}

ostream& operator << (ostream& os, Cart_Point p1)
{

	os << "(" << p1.x << ", " << p1.y << ")"; 
	return os;
	
}

//Nonmember Function
double cart_distance(Cart_Point p1, Cart_Point p2)
{
	//Declares essential variables
	double hori_diff;	
	double vert_diff;
	double tot_diff;

	// Finds the difference in x and y
	hori_diff = p2.x - p1.x;
	vert_diff = p2.y - p1.y;
	hori_diff = abs(hori_diff);
	vert_diff = abs(vert_diff);

	//Use the distance formula
	hori_diff = pow(hori_diff, 2);
	vert_diff = pow(vert_diff, 2);
	tot_diff = hori_diff + vert_diff;
	tot_diff = sqrt(tot_diff);

	return tot_diff;
	
}

