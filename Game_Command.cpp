#include<iostream>
#include<stdlib.h>
#include <list>
using namespace std;

#include "Game_Command.h"
#include "Input_Handling.h"
void do_move_command(Model &model)
{
	int ID, x, y;
	//Exception Handling for the id number and the x and y
	try
	{
		cin >> ID >> x >> y;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore();
			throw Invalid_Input("Illegal Format");
		}
	}

	catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
		return;
	}

	cout << "Move Astronaut (enter 'a') or Alien (enter 'x'):";
	char mov_obj;
	//Exception handling for moving the objects 
	try
	{
		cin >> mov_obj;
	
	if(mov_obj == 'a') //moving astronaut
	{
		Person* astro = model.get_Person_ptr(ID);
		if(astro->get_state() != 'x')
		{
			/*
			if(model.gravity == "Decreased")
			{
				astro->setspeed(10);
				cout << "Speed increased" << endl;
			}

			else if(model.gravity == "Increased")
			{
				astro->setspeed(2.5);
				cout << "Speed decreased" << endl;
			}
			else
			{
				astro->setspeed(5);
				cout << "Speed back to normal" << endl;
			}
			*/
			astro->start_moving(Cart_Point(x,y));
		}
		else
		{
			cout << "I can't move, I'm dead." << endl;
		}
		
	}

	else if (mov_obj == 'x') //moving alien
	{
		Alien* alien = model.get_alien_ptr(ID);
		alien->start_moving(Cart_Point(x,y));
	}
	else
	{
		cin.clear();
		cin.ignore();
		throw Invalid_Input("Illegal Format");	
	}

	} //end of try block
	catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
		return;
	}
}
void do_work_a_depot_command(Model &model)
{
	int ID1, ID2;
	try {
	cin >> ID1 >> ID2;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		throw Invalid_Input("Illegal Format");
	}

	Person* astro = model.get_Person_ptr(ID1);
	if(astro->get_state() != 'x')
	{
		Oxygen_Depot* depot = model.get_Oxygen_Depot_ptr(ID2);
		astro->start_supplying(depot);
	}
	else
	{
		cout << "I can't move, I'm dead." << endl;
	}
	}
	catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
		return;
	}
}
void do_deposit_moonstones_command(Model &model)
{
	int ID1, ID2;
try{
	cin >> ID1 >> ID2;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		throw Invalid_Input("Illegal Format");
	}

	Person* astro = model.get_Person_ptr(ID1);
	if(astro->get_state() != 'x')
	{
		Space_Station* station = model.get_Space_Station_ptr(ID2);
		astro->start_depositing(station);
	}
	else
	{
		cout << "I can't move, I'm dead." << endl;
	}

	}	

	catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
		return;
	}
}
void do_stop_command(Model &model)
{
	int ID;
try{
	cin >> ID;

	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		throw Invalid_Input("Illegal Format");
	}

	Person* astro = model.get_Person_ptr(ID);
	astro->stop();
	}

	catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
		return;
	}
}
void do_lock_in_at_a_station_command(Model &model)
{
	int ID1, ID2;
try{
	cin >> ID1 >> ID2;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		throw Invalid_Input("Illegal Format");
	}

	Person* astro = model.get_Person_ptr(ID1);
	if(astro->get_state() != 'x')
	{
		Space_Station* station = model.get_Space_Station_ptr(ID2);
		astro->go_to_station(station);
	}
	
	else
	{
		cout << "I can't move, I'm dead." << endl;
	}

	}

	catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
		return;
	}

}
void do_go_command(Model &model)
{
	cout << "Advancing one tick." << endl;
	model.update();
}

void do_run_command(Model &model)
{
	cout << "Advancing to the next event." << endl;
	int five_times = 0;
	while(five_times < 5)
	{
		five_times++;
		bool is_true = model.update();
		if(is_true == true)
			break;
	}
}

void do_attack_command(Model &model)
{
	int ID1, ID2;
try{
	cin >> ID1 >> ID2;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore();
		throw Invalid_Input("Illegal Format");
	}

	Alien* alien = model.get_alien_ptr(ID1);
	Person* astro = model.get_Person_ptr(ID2);
	alien->start_attack(astro);
	}

catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
		return;
	}
}

void do_quit_command(Model &model)
{
	model.~Model();
	exit(0);
}

//New command
void handle_new_command(Model &model)
{
	char TYPE;
	int ID, x, y;
	try{
	cin >> TYPE >> ID >> x >> y;
	switch(TYPE){

		case 'd':
		{
			Oxygen_Depot* depot = NULL;
			depot = model.get_Oxygen_Depot_ptr(ID);
			if(depot != NULL ||ID > 9)
			{
				cin.clear();
				cin.ignore();
				throw Invalid_Input("Illegal ID");
			}

			Oxygen_Depot* new_o = new Oxygen_Depot(Cart_Point (x, y), ID);
			model.set_depot(new_o); //new function in Model
			break;
		}

		case 's':
		{
			Space_Station* station = NULL;
			station = model.get_Space_Station_ptr(ID);
			if(station != NULL||ID > 9)
			{
				cin.clear();
				cin.ignore();
				throw Invalid_Input("Illegal ID");
			}
			Space_Station* new_s = new Space_Station(Cart_Point(x,y), ID);
			model.set_station(new_s);
			break;
		}

		case 'a':
		{
			Person* astronaut = NULL;
			astronaut = model.get_Person_ptr(ID);
			if(astronaut != NULL||ID > 9)
			{
				cin.clear();
				cin.ignore();
				throw Invalid_Input("Illegal ID");
			}
			Astronaut* new_a = new Astronaut(ID, Cart_Point(x,y));
			model.set_astronaut(new_a);		
			break;
		}

		case 'x':
		{
			Alien* alien = NULL;
			alien = model.get_alien_ptr(ID);
			if(alien != NULL||ID > 9)
			{
				cin.clear();
				cin.ignore();
				throw Invalid_Input("Illegal ID");
			}

			Alien* new_x = new Alien(ID, Cart_Point(x,y));
			model.set_alien(new_x);
			break;
		}

		default:
		{
			cin.clear();
			cin.ignore();
			throw Invalid_Input("Illegal Format");
		}
	}//end of switch
	} //end of try

	catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
		return;
	}
}
