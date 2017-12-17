#include <iostream>
#include<stdlib.h>
#include <list>
#include <ctime>
#include <cstdlib>
#include<string>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "Model.h"
//Constructors
Model::Model()
{
	time = 0;
	count_down = 10;
	num_objects = 8;
	num_persons = 2;
	num_depots = 2;
	num_station = 2;
	num_aliens = 2;

	// Making Astronaut 1
	Astronaut* a1 = new Astronaut(1, Cart_Point(5,1));
	object_ptrs.push_back(a1);
	active_ptrs.push_back(a1);
	person_ptrs.push_back(a1);
	/*
	object_ptrs[0] = a1;
	person_ptrs[0] = a1;
	*/
	// Making Astronaut 2
	Astronaut* a2 = new Astronaut(2, Cart_Point(10,1));
	object_ptrs.push_back(a2);
	active_ptrs.push_back(a2);
	person_ptrs.push_back(a2);
	/*
	object_ptrs[1] = a2;
	person_ptrs[1] = a2;
	*/
	//Making Oxygen Depot 1
	Oxygen_Depot* o1 = new Oxygen_Depot(Cart_Point (1, 20), 1);
	object_ptrs.push_back(o1);
	active_ptrs.push_back(o1);
	depot_ptrs.push_back(o1);
	/*
	object_ptrs[2] = o1;
	depot_ptrs[0] = o1;
	*/
	//Making Oxygen Depot 2
	Oxygen_Depot* o2 = new Oxygen_Depot(Cart_Point (10, 20), 2);
	object_ptrs.push_back(o2);
	active_ptrs.push_back(o2);
	depot_ptrs.push_back(o2);
	/*
	object_ptrs[3] = o2;
	depot_ptrs[1] = o2;
	*/
	//Making Space Station 1
	Space_Station* s1 = new Space_Station();
	object_ptrs.push_back(s1);
	active_ptrs.push_back(s1);
	station_ptrs.push_back(s1);
	/*
	object_ptrs[4] = s1;
	station_ptrs[0] = s1;
	*/
	//Making Space Station 2
	Space_Station* s2 = new Space_Station(Cart_Point(5,5), 2);
	object_ptrs.push_back(s2);
	active_ptrs.push_back(s2);
	station_ptrs.push_back(s2);
	/*
	object_ptrs[5] = s2;
	station_ptrs[1] = s2;
	*/
	//Making Alien 1
	Alien* x1 = new Alien(1, Cart_Point(7,14));
	object_ptrs.push_back(x1);
	active_ptrs.push_back(x1);
	alien_ptrs.push_back(x1);
	/*
	object_ptrs[6] = x1;
	alien_ptrs[0] = x1;
	*/
	//Making Alien 2
	Alien* x2 = new Alien(2, Cart_Point(7,5));
	object_ptrs.push_back(x2);
	active_ptrs.push_back(x2);
	alien_ptrs.push_back(x2);
	/*
	object_ptrs[7] = x2;
	alien_ptrs[1] = x2;
	*/
	cout << "Model default constructed" << endl;
}


//Destructor
Model::~Model()
{
	list<Game_Object*>::iterator objects;
	for (objects = object_ptrs.begin(); objects != object_ptrs.end(); objects++)
	{
		delete *objects; 
	}
	cout << "Model destructed" << endl;
}


//Seach functions through the pointer arrays
Person* Model::get_Person_ptr(int id)
{
	list<Person*>::iterator astronauts;
	for(astronauts = person_ptrs.begin(); astronauts != person_ptrs.end(); astronauts++)
	{
		if((**astronauts).get_id() == id)
		{
			return *astronauts; 
		}
	}
		return 0;
	
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id)
{
	list<Oxygen_Depot*>::iterator depots;
	for(depots = depot_ptrs.begin(); depots != depot_ptrs.end(); depots++)
	{
		if((**depots).get_id() == id)
		{
			return *depots; 
		}
	}
		return 0; //test case
}

Space_Station* Model::get_Space_Station_ptr(int id)
{
	list<Space_Station*>::iterator stations;
	for(stations = station_ptrs.begin(); stations != station_ptrs.end(); stations++)
	{
		if((**stations).get_id() == id)
		{
			return *stations; 
		}
	}
		return 0;

}

//finds the right alien object in pointer
Alien* Model::get_alien_ptr(int id)
{
	list<Alien*>::iterator aliens;
	for(aliens = alien_ptrs.begin(); aliens != alien_ptrs.end(); aliens++)
	{
		if((**aliens).get_id() == id)
		{
			return *aliens; 
		}
	}
		return 0;
}

bool Model::update()
{
	//Making the iterators
	list<Person*>::iterator astronauts;
	list<Game_Object*>::iterator objects;
	list<Space_Station*>::iterator stations;
	list<Oxygen_Depot*>::iterator depots;
	list<Alien*>::iterator aliens;
	//To determine whether gravity should change
	/*
	//Every 5 seconds pass, the gravity changes
	if(time % 5 == 0)
	{
		string gravityarray[3] = {"Normal","Decreased","Increased"};
		int gravityindex = (rand()% 3);
		gravity = gravityarray[gravityindex];
		cout << "Gravity status: " << gravity << endl;

	}
	*/
	//losing the game
	if (count_down == 0)
	{
		cout << "You lose!" << endl;
		exit(0);
	}
	
	//keeps track of dead astronauts
	int dead_astronaut = 0;
	for(astronauts = person_ptrs.begin(); astronauts != person_ptrs.end(); astronauts++) //fix this
	{
		if((**astronauts).get_state() == 'x')
			dead_astronaut++;
	}

	//checks if any astronauts are alive
	if(dead_astronaut == num_persons)
	{
		cout << "You lose!" << endl;
		exit(0);
	}
	
	int counter_stationu = 0; //total number of upgraded stations
	int counter_station = 0; // total number of stations with at least one astronaut
	int counter_astro = 0; // total number of astronauts in stations
	bool event = false;
	if(count_down != 0)
	{
		time++;
		// original loop: for(int i = 0; i < num_station; i++)
		for(stations = station_ptrs.begin(); stations != station_ptrs.end(); stations++)
		{
			if((**stations).get_state() == 'u')
			{
				counter_stationu++;
				if((**stations).get_astronaut() > 0)
				{
					counter_station++;
					counter_astro += (**stations).get_astronaut();
				}
			}
		}
		//If all the stations are upgraded and has at least one astronaut
		if(counter_station == num_station && counter_astro == num_persons)
		{
			cout << "Blast off! You win!" << endl;
			exit(0);
		}

		// If all the stations are upgraded

		else if (counter_stationu == num_station)
		{
			cout << "Ready for take off? " << count_down << "..." << endl;
			int missing = num_persons-counter_astro;
			cout << "Missing " << missing << " astronauts!" << endl;
			count_down--;
			bool is_update;

			//updates all the game objects
			for (objects = object_ptrs.begin(); objects != object_ptrs.end(); objects++)
			{
				is_update = (**objects).update();
				if (is_update == true)
				{
					event = is_update;
				}
			}

			//checks if any objects died
			for(objects = active_ptrs.begin(); objects != active_ptrs.end(); objects++)
			{
				if((**objects).get_state() == 'x')
				{
					cout << "Dead object removed." << endl;
					objects = active_ptrs.erase(objects);
				}
			}
		}
		//if all the stations are NOT upgraded
		else
		{
			bool is_update;
			//updates all the game objects
			for (objects = object_ptrs.begin(); objects != object_ptrs.end(); objects++)
			{
				is_update = (**objects).update();
				if (is_update == true)
				{
					event = is_update;
				}
			}

			//checks if any objects died
			for(objects = active_ptrs.begin(); objects != active_ptrs.end(); objects++)
			{
				if((**objects).get_state() == 'x')
				{
					cout << "Dead object removed." << endl;
					objects = active_ptrs.erase(objects);
				}
			}
		}
	}
	return event;
}


void Model::display(View &view)
{	
	view.clear();
	list<Game_Object*>::iterator objects;
	for(objects = object_ptrs.begin(); objects != object_ptrs.end(); objects++)
	{
		if((**objects).get_state() != 'x')
		{
			view.plot(*objects);
		}
	}
	view.draw();

}


void Model::show_status()
{
	cout << "Time: " << time << endl;
	list<Game_Object*>::iterator objects;
	for (objects = object_ptrs.begin(); objects != object_ptrs.end(); objects++)
	{
		(**objects).show_status();
	}
}

//Below are functions that applies the new objects into the linked list
void Model::set_depot(Oxygen_Depot* new_o)
{
	object_ptrs.push_back(new_o);
	active_ptrs.push_back(new_o);
	depot_ptrs.push_back(new_o);

}

void Model::set_station(Space_Station* new_s)
{
	object_ptrs.push_back(new_s);
	active_ptrs.push_back(new_s);
	station_ptrs.push_back(new_s);
}
void Model::set_astronaut(Astronaut* new_a)
{
	object_ptrs.push_back(new_a);
	active_ptrs.push_back(new_a);
	person_ptrs.push_back(new_a);
}
void Model::set_alien(Alien* new_x)
{
	object_ptrs.push_back(new_x);
	active_ptrs.push_back(new_x);
	alien_ptrs.push_back(new_x);
}