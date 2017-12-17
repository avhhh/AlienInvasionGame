#ifndef MODEL_H
#define MODEL_H

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Astronaut.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "View.h"
#include "Alien.h"
#include <list>
using namespace std;

class Model
{
	private:
		int time; //The simulation time
		int count_down; //time left until ready for take off
		//Game_Object* object_ptrs[10];
		list<Game_Object*> object_ptrs;
		list<Game_Object*> active_ptrs;
		int num_objects;
		//Person* person_ptrs[10];
		list<Person*> person_ptrs;
		int num_persons;
		//Oxygen_Depot* depot_ptrs[10];
		list<Oxygen_Depot*> depot_ptrs;
		int num_depots;
		//Space_Station* station_ptrs[10];
		list<Space_Station*> station_ptrs;
		int num_station;
		//Alien* alien_ptrs[10];
		list<Alien*> alien_ptrs;
		int num_aliens;
		Model(const Model &m1); // copy constructor
	public:
		Model();
		Person* get_Person_ptr(int id);
		Oxygen_Depot* get_Oxygen_Depot_ptr(int id);
		Space_Station* get_Space_Station_ptr(int id);
		Alien* get_alien_ptr(int id);
		bool update();
		void display(View &view);
		void show_status();
		~Model();
		void set_depot(Oxygen_Depot* new_o);
		void set_station(Space_Station* new_s);
		void set_astronaut(Astronaut* new_a);
		void set_alien(Alien* new_x);
		string gravity; //for gravity changes

};
#endif