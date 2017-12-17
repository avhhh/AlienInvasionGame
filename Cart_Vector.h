#ifndef CART_VECTOR_H
#define CART_VECTOR_H


class Cart_Vector
{
public:
	//Member Variables
	double x;
	double y;
	//Constructors
	Cart_Vector();
	Cart_Vector(double, double);
};

//Overloaded Operators
Cart_Vector operator*(Cart_Vector, double);
Cart_Vector operator / (Cart_Vector, double);
ostream& operator << (ostream&, Cart_Vector);

#endif
