#include <iostream>
using namespace std;

#include "Space_Station.h"
#include "Game_Object.h"
//Constructors
Space_Station::Space_Station():Game_Object('s')
{
	amount_moonstones = 0;
	number_astronauts = 0;
	cout << "Space_Station default constructed" << endl;
}

Space_Station::Space_Station(Cart_Point inputLoc, int inputId):Game_Object('s')
{
	amount_moonstones = 0;
	number_astronauts = 0;
	id_num = inputId;
	location = inputLoc;
	state = 'o';
	cout << "Space_Station constructed" << endl;

}

//Public Member Functions
void Space_Station::deposit_moonstones(double deposit_amount)
{
	amount_moonstones += deposit_amount;
}

bool Space_Station::add_astronaut()
{
	if(state == 'u') //if space station is upgraded, astronauts can be added
	{
		number_astronauts++;
		return true;
	}

	else
	{
		cout << "Station is not upgraded" << endl; // test case
		return false;
	}
}

int Space_Station::get_astronaut()
{
	return number_astronauts;
}

bool Space_Station::update()
{
	if (state == 'u')
		return false; //space station already upgraded nothing happened

	if(amount_moonstones > 10 || amount_moonstones == 10)
	{
		state = 'u';  //upgraded space station
		display_code = 'S'; // space station has been upgraded
		cout << display_code << id_num << " has been upgraded." << endl;
		return true;  //signifies something has happened
	}
	else
		return false; // cannot upgrade space station - nothing happened
}

void Space_Station::show_status()
{
	cout << "Space Station status: ";
	Game_Object::show_status();
	cout << " at " << location; 
	cout << " contains " << amount_moonstones;
	cout << " moonstones and contains " << number_astronauts << " astronauts. ";
	if(state != 'u')
		cout << "Not yet upgraded." << endl;
	else if(state == 'u')
		cout << "Upgraded." << endl;
	else
		cout << endl;
}

Space_Station::~Space_Station()
{
	cout << "Space_Station destructed." << endl;
}