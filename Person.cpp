#include <iostream>
#include <math.h>
using namespace std;

#include "Person.h"
//Constructors
Person::Person() : Game_Object('A')
{
	speed = 5;
	cout << "Person default constructed." << endl;
}

Person::Person(char in_code):Game_Object(in_code)
{
	speed = 5;
	cout << "Person constructed." << endl;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code):Game_Object(in_loc, in_id, in_code)
{
	speed = 5;
	cout << "Person constructed." << endl;
}

void Person::start_moving(Cart_Point dest)
{
	//if statement for locked case
	if (state == 'l')
	{
		cout << "Astronaut is locked and cannot move." << endl;
	}
	
	setup_destination(dest);
	
	if((delta.x != 0 && delta.y != 0) ||(delta.x == 0 && delta.y != 0) || (delta.x != 0 && delta.y == 0))
	{
		
		state = 'm';
		cout << "Moving " << id_num;
		cout << " to " << dest << endl;
		Game_Object::show_status(); 
		cout << ": On my way." << endl;
	}
	
}

void Person::stop()
{
	state = 's';
	Game_Object::show_status();
	cout << ": Stopped." << endl;	
}

void Person::show_status()
{
	Game_Object::show_status();
	cout << " at " << location;
	if (state == 'x')
		cout << " is dead." << endl;
	else if (state == 's')
		cout << " is stopped"; 
	else if (state == 'l')
		cout << " is locked"; 
	else
		cout << " moving at speed of " << speed << " towards " << destination << " at each step of " << delta;
}

bool Person::update_location()
{
	if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y))
	{
		location = destination;
		
		//when locked, only calls the "I'm there" once
		static int count = 0;
		if(state == 'l')
		{
			if(count == 0)
			{
				Game_Object::show_status();
				cout << ": I'm there!" << endl;
				count++;
				return true;
			}
			else
			{
				return true;
			}
			
		}

		else
		{
			Game_Object::show_status();
			cout << ": I'm there!" << endl;
			return true;
		}
		
	}

	else
	{
		location = location + delta;
		Game_Object::show_status();
		cout << ": step..." << endl;
		return false;
	}
}

void Person::setup_destination(Cart_Point dest)
{
	destination = dest;
	if(destination.x == location.x && destination.y == location.y)
	{
		if(state != 'l')
		{
			Game_Object::show_status();
			cout << ": I'm already there. see?" << endl;
		}

		delta = Cart_Vector();
	}
	else
	{
		delta = (destination-location)*(speed/cart_distance(destination, location)); //something is wrong with delta
	}
	

}

void Person::start_supplying(Oxygen_Depot* inputDepot)
{
	cout << "Sorry, I can't work a depot" << endl;
}
void Person::start_depositing(Space_Station* inputStation)
{
	cout << "Sorry, I can't work a station" << endl;
}
void Person::go_to_station(Space_Station* inputStation)
{
	cout << "Sorry, I can't lock into a station" << endl;
}

//New additions for alien
bool Person::is_alive()
{
	if (state == 'x')
		return true;
	else
		return false;
}

void Person::take_hit(int attack_strength)
{
	health -= attack_strength;
	if (health <= 0)
	{
		state = 'x';
		Game_Object::show_status();
		cout << ": Gasp! I'm dying..." << endl;
	}
	else
	{
		Game_Object::show_status();
		cout << ": Ouch!" << endl;
	}
}

//Deconstructor
Person::~Person()
{
	cout << "Person destructed." << endl;
}

void Person::setspeed(double new_speed)
{
	speed = new_speed;
}

