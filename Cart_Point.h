#ifndef CART_POINT_H
#define CART_POINT_H

#include "Cart_Vector.h"
//Declaration of class
class Cart_Point
{
public:
	//member variables
	double x;
	double y;

	//Constructors
	Cart_Point(double, double);
	Cart_Point();	

};
//Nonmember Functions
double cart_distance(Cart_Point, Cart_Point);

//Overloaded Operator Functions
Cart_Point operator + (Cart_Point&, Cart_Vector&);
Cart_Vector operator - (Cart_Point&, Cart_Point&);
ostream& operator << (ostream&, Cart_Point);

#endif
