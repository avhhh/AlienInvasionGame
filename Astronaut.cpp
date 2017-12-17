#include <iostream>
using namespace std;

#include "Astronaut.h"

//Constructors
Astronaut::Astronaut(): Person()
{
	health = 5;
	amount_moonstones = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;
	cout << "Astronaut default constructed." << endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc): Person(in_loc, in_id, 'A')
{
	health = 5;
	amount_moonstones  = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;
	cout << "Astronaut constructed." << endl;

}

//Public member functions
bool Astronaut::update()
{
	switch(state){
		//The state is stopped
		case 's' : 
		{	
			if (health < 3)
			{
				display_code = 'a';
			}

			return false;
		}

		//The state is moving
		case 'm' : 
		{
			if (Person::update_location() == true)
			{
				state = 's';
				return true;
			}

			else if(state == 'l')
			{
				cout << "Astronaut is locked and cannot move." << endl;
				return false;
			}

			else
			{
				if (health < 3)
				{
					display_code = 'a';
				}
				
				if (amount_oxygen == 0)
				{
					cout << "I can't move, I'm out of oxygen." << endl;
					state = 'x';
					return true;			
				}
				else
				{
					amount_moonstones++;
					amount_oxygen--;
				}
				return false;
			}
		}

		//Outbound to depot
		case 'o':
		{
			if (Person::update_location() == true)
			{
				state = 'g';
				return true;
			}

			else if(state == 'l')
			{
				cout << "Astronaut is locked and cannot move." << endl;
				return false;
			}

			else
			{
				if (amount_oxygen == 0)
				{
					cout << "I can't move, I'm out of oxygen." << endl;
					state = 'x'; //Astronaut dies
					return true;		
				}
				else
				{
					amount_moonstones++;
					amount_oxygen--;
				}
				return false;
			}
		}
		// Getting oxygen
		case 'g':
		{
			double amt_extract = depot->extract_oxygen();
			amount_oxygen += amt_extract;
			Game_Object::show_status();
			cout << ": Got " << amt_extract << " more oxygen." << endl;
			state = 's';
			return true; 
		}

		//Inbounding to station
		case 'i':
		{
			if (Person::update_location() == true)
			{
				state = 'd';
				return true;
			}

			else if(state == 'l')
			{
				cout << "Astronaut is locked and cannot move." << endl;
				return false;
			}
			
			else
			{
				if (amount_oxygen == 0)
				{
					cout << "I can't move, I'm out of oxygen." << endl;
					state = 'x';
					return true;
				}
				else
				{
					amount_moonstones++;
					amount_oxygen--;
				}
				return false;
			}
		}
			
		//Depositing Moonstones
		case 'd':
		{
			home->deposit_moonstones(amount_moonstones);
			Game_Object::show_status();
			cout << ": Deposit " << amount_moonstones << " moonstones." << endl;
			amount_moonstones = 0;
			state = 's';
			return true;
		}
		//Locking into Space Station
		case 'l':
		{
			if (Person::update_location() == true)
			{
				if(home->get_astronaut() == 0)
				{
					home->add_astronaut();
				}
				return false; 
			}
			else
				return false;
		}

		case 'x':
		{			
			return false;
		}
	}
}
void Astronaut::start_supplying(Oxygen_Depot* inputDepot)
{
	//if statement for locked case
	if (state == 'l')
	{
		cout << "Astronaut is locked and cannot move." << endl;
	}
	else
	{
		depot = inputDepot;
		Person::setup_destination(depot->get_location()); 
		state = 'o';
		// The print statement for start_supplying
		cout << "Astronaut " << Game_Object::get_id();
		cout << " supplying from Oxygen Depot " << depot->get_id() << "." << endl;
		Game_Object::show_status();
		cout << ": Yes, my lord." << endl;

	}	
}

void Astronaut::start_depositing(Space_Station* inputStation)
{
	//if statement for locked case
	if (state == 'l')
	{
		cout << "Astronaut is locked and cannot move." << endl;
	}

	else
	{
		home = inputStation;
		Person::setup_destination(home->get_location()); 
			
		state = 'i';
		//The print statement for start_depositing
		cout << "Astronaut " << Game_Object::get_id();
		cout << " depositing at Space Station " << home->get_id() << "." << endl;
		Game_Object::show_status();
		cout << ": Yes, my lord." << endl;
	}
}

void Astronaut::go_to_station(Space_Station* inputStation)
{
	//if statement for locked case
	if (state == 'l')
	{
		cout << "Astronaut is locked and cannot move." << endl;
	}

	else if (inputStation->get_state() == 'u')
	{
		home = inputStation;
		Person::setup_destination(home->get_location());
		state = 'l';
		cout << "Astronaut " << Game_Object::get_id();
		cout <<" locking in at Space Station " << home->get_id() <<"." << endl;
	}
	else
	{
		cout << "Station is not upgraded." << endl;
	}
	
}

void Astronaut::show_status()
{
	cout << "Astronaut status: ";
	Person::show_status();
	switch(state){
		case 's':
			cout <<" with " << amount_oxygen << " oxygen and ";
			cout << amount_moonstones << " moon stones." << endl;
			break;
		case 'm':
			cout << endl;
			break;
		case 'o':
			cout << " is outbound to a Depot with " << amount_oxygen;
			cout <<" oxygen and " << amount_moonstones << " moonstones." << endl;
			break;
		case 'g':
			cout << " is getting oxygen from Depot." << endl;
			break;
		case 'i':
			cout << " is inbound to home with load: " << amount_moonstones << " moon stones and ";
			cout << amount_oxygen << " oxygen." << endl;
			break;
		case 'd':
			cout << " is depositing " << amount_moonstones << " moon stones." << endl;
			break;
		case 'l':
			if (amount_oxygen == 0)
			{
				cout << ". Out of oxygen." << endl;
			}
			else
			{
				cout << " at Space Station." << endl;
			}
			break;
	}
}
Astronaut::~Astronaut()
{
	cout << "Astronaut destructed." << endl;
}