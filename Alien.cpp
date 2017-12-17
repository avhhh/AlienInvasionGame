#include <iostream>
#include <math.h>
using namespace std;

#include "Alien.h"

Alien::Alien():Game_Object('X')
{
	attack_strength = 2;
	range = 2.0;
	target = NULL;
	speed = 5;
	cout << "Alien default constructed." << endl;

}

Alien::Alien(int in_id, Cart_Point in_loc):Game_Object(in_loc, in_id, 'X')
{
	attack_strength = 2;
	range = 2.0;
	target = NULL;
	speed = 5;
	cout << "Alien constructed." << endl;
}

void Alien::start_attack(Person* in_target)
{
	double target_dist = cart_distance(destination, in_target->get_location());
	if(target_dist <= range)
	{
		Game_Object::show_status();
		cout << ": Smash!" << endl;
		target = in_target;
		state = 'a';
	}
	else
	{
		Game_Object::show_status();
		cout << ": Target out of range" << endl;
		Game_Object::show_status();
		cout << ": Chaaaaarge." << endl;

	}
}

bool Alien::update()
{
	switch(state){
		case 's':
		{
			return false;
		}

		case 'm':
		{
			if (update_location() == true)
			{
				state = 's';
				return true;
			}

			else
			{
				return false;
			}
		}

		case 'a':
		{
			double target_dist = cart_distance(destination, target->get_location());
			//target is no longer in range
			if(target_dist > range)
			{
				state = 's';
				Game_Object::show_status();
				cout << ": Target out of range" << endl;
				Game_Object::show_status();
				cout << ": Chaaaaarge." << endl;
				return true;
			}
			//target is in range
			else
			{
				//target is dead
				if(target->get_state() == 'x')
				{
					Game_Object::show_status();
					cout << ": I win." << endl;
					state = 's';
					return true;
				}

				//target is still alive
				else
				{
					Game_Object::show_status();
					cout << ": Take that!" << endl;
					target->take_hit(attack_strength);
					return false;
				}
			}
		}
	}
}

void Alien::show_status()
{
	Game_Object::show_status();
	cout << " at " << location;
	if (state == 's')
		cout << " is stopped" << endl; 
	else if (state == 'a')
	{
		cout << " attacking astronaut A" << target->get_id() << endl;
	}
	else
		cout << " moving at speed of " << speed << " towards " << destination << " at each step of " << delta << endl;
}

void Alien::start_moving(Cart_Point dest)
{
	setup_destination(dest);
	
	//If the alien is not at the location yet
	if((delta.x != 0 && delta.y != 0) ||(delta.x == 0 && delta.y != 0) || (delta.x != 0 && delta.y == 0)) 
	{
		state = 'm';
		cout << "Moving " << id_num;
		cout << " to " << dest << endl;
		Game_Object::show_status(); 
		cout << ": On my way." << endl;
	}
}

void Alien::stop()
{
	state = 's';
	Game_Object::show_status();
	cout << ": Stopped." << endl;	
}

bool Alien::update_location()
{
	if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y))
	{
		location = destination;
		Game_Object::show_status();
		cout << ": I'm there!" << endl;
		return true;
	}
	else
	{
		location = location + delta;
		Game_Object::show_status();
		cout << ": step..." << endl;
		return false;
	}
}

void Alien::setup_destination(Cart_Point dest)
{
	destination = dest;
	if(destination.x == location.x && destination.y == location.y)
	{
		Game_Object::show_status();
		cout << ": I'm already there. see?" << endl;
		delta = Cart_Vector();
	}
	else
	{
		delta = (destination-location)*(speed/cart_distance(destination, location));
	}
	
}

Alien::~Alien()
{
	cout << "Alien destructed." << endl;
}
//changing the speed of alien
void Alien::setspeed(double new_speed)
{
	speed = new_speed;
}