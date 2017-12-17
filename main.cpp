#include<iostream>
#include <typeinfo>
#include <string>
using namespace std;

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Astronaut.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Person.h"
#include "View.h"
#include "Model.h"
#include "Game_Command.h"
#include "Input_Handling.h"

int main()
{
	/*cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2017" << endl;
	cout << "Programming Assignment 3" << endl;
	*/
	cout << "Welcome to Alien Invasion!" << endl;
	cout << "Created by Yan Yan Huang" << endl;
	cout << "Select a command to begin." << endl;
	Model m1;
	View v1;
	char command;
	m1.show_status();
	m1.display(v1);
	
while(command != 'q')
{	
	try{
	//Asks the user for a command
	cout << "Enter a command: ";
	cin >> command;

	switch(command)
	{
		case 'm':
		{
			do_move_command(m1);
			break;
		}

		case 'w':
		{
			do_work_a_depot_command(m1);
			break;
		}

		case 'd':
		{
			do_deposit_moonstones_command(m1);
			break;
		}

		case 's':
		{
			do_stop_command(m1);
			break;
		}

		case 'l':
		{
			do_lock_in_at_a_station_command(m1);
			break;
		}

		case 'g':
		{
			do_go_command(m1);
			m1.show_status();
			m1.display(v1);
			break;
		}

		case 'r':
		{
			do_run_command(m1);
			m1.show_status();
			m1.display(v1);
			break;
		}

		case 'a':
		{
			do_attack_command(m1);
			break;
		}

		case 'n':
		{
			handle_new_command(m1);
			break;
		}

		default:
		{
			if(command != 'q')
			{
				cin.clear();
				cin.ignore();
				throw Invalid_Input("Illegal Format");
			}	
		}
	} //end of switch
}//try end

catch(Invalid_Input& except)
	{
		cout << "Invalid Input - " << except.msg_ptr << endl;
	}
} //end of while loop


if(command == 'q')
{
	do_quit_command(m1);
}

	return 0;
}
