#include<iostream>
using namespace std;

#include "View.h"
View::View()
{
	size = 11;
	scale = 2;
	origin = Cart_Point(0,0);
}

//checks if the object is within the display
bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
{
	ix = (location.x-origin.x)/scale;
	iy = (location.y-origin.y)/scale;

	if(ix <= size-1 && iy <= size-1 && ix >= 0 && iy >= 0) 
	{
		return true;
	}
	else
	{
		cout << "An object is outside the display" << endl; 
		return false;
	}
}
//clears the display
void View::clear()
{
	for(int i = 0; i < 11; i++)
	{
		for(int j = 0; j < 11; j++)
		{
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::plot(Game_Object* ptr)
{
	int ix;
	int iy;
	if(get_subscripts(ix, iy, ptr->get_location()) == true)
	{
		if(grid[ix][iy][0] != '.')
		{
			grid[ix][iy][0] = '*';
			grid[ix][iy][1] = ' ';
		}
		else
		{
			ptr->drawself(grid[ix][iy]);
		}
	}

}

void View::draw()
{
	int printx = 0;
	int printy = 20;
	for(int j = 10; j >= -1; j--) // the rows
	{
		for(int i = -1; i < 11; i++) // the columns
		{
			//If it is the bottom row
			if(j == -1)
			{
				if(i%2 == 0)
				{
					if(printx == 0)
					{
						cout << printx;
						printx+=4;
						cout << "  ";
					}
					if(printx != 24)
					{
						cout << " ";
						cout << printx;
						printx+=4;
					}
				}
				else
				{
					if(printx == 16||printx == 20)
						cout << ' ';
					else
						cout << "  ";
				}
			}
			
			//If its an odd row first column
			else if(i == -1)
			{
				if(j%2 == 0)
				{
					if (printy< 12)
					{
						cout << printy;
						printy-=4;
						cout << ' ';
					}
					else
					{
						cout << printy;
						printy-=4;
					}
					
				}
				else
				{
					cout << "  ";
				}
				
			}

			//puts the dots and spaces
			else
			{
				cout << grid[i][j][0];
				cout << grid[i][j][1];
				
			}
			
		}
		cout << endl;
	}
}