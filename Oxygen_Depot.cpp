#include <iostream>
using namespace std;

#include "Oxygen_Depot.h"
#include "Game_Object.h"
//Constructors 
Oxygen_Depot::Oxygen_Depot(): Game_Object('O')
{
	amount_oxygen = 50;
	state = 'f';
	cout << "Oxygen_Depot default constructed" << endl;
}

Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId):Game_Object('O')
{
	amount_oxygen = 50;
	id_num = inputId;
	location = inputLoc;
	state = 'f';
	cout << "Oxygen_Depot constructed" << endl;
}

//Public Member Functions
bool Oxygen_Depot::is_empty()
{
	if (amount_oxygen == 0)
		return true;
	else
		return false;
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract)
{
	if (amount_oxygen > amount_to_extract || amount_oxygen == amount_to_extract)
		{
			amount_oxygen -= amount_to_extract;
			return amount_to_extract;
		}
	else
		{
			double current_oxy = amount_oxygen;
			amount_oxygen = 0;
			return current_oxy;
		}
}

bool Oxygen_Depot::update()
{
	if (amount_oxygen == 0)
	{
		if (state == 'e')
			return false; // nothing happened because it already knows depot is empty
		state = 'e';  // depot is empty
		display_code = 'o';  //signifies a deteriorated depot
		cout << "Oxygen_Depot " << id_num << " has been depleted." << endl;
		return true; // signifies an event happened
	}
	else
		return false; //signifies nothing happened
}

void Oxygen_Depot::show_status()
{
	cout << "Oxygen Depot status: ";
	Game_Object::show_status();
	cout << " at location " << location;
	cout << " contains " << amount_oxygen << "." << endl;
}
Oxygen_Depot::~Oxygen_Depot()
{
	cout << "Oxygen_Depot destructed." << endl;
}