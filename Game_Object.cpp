#include <iostream>
using namespace std;

#include "Game_Object.h"

//Constructors
Game_Object::Game_Object(char in_code)
{
	display_code = in_code;
	id_num = 1;
	state = 's';
	location = Cart_Point();
	cout << "Game_Object constructed" << endl;
}

Game_Object::Game_Object(Cart_Point in_loc, int in_id, char in_code)
{
	display_code = in_code;
	id_num = in_id;
	state = 's';
	location = in_loc;
	cout << "Game_Object constructed" << endl;
}

// Member Functions
Cart_Point Game_Object::get_location()
{
	return location; 
}

int Game_Object::get_id()
{
	return id_num;
}

char Game_Object::get_state()
{
	return state;
}

void Game_Object::show_status()
{
	cout << display_code << id_num;
}

Game_Object::~Game_Object()
{
	cout << "Game_Object destructed." << endl;
}

void Game_Object::drawself(char* ptr)
{
	ptr[0] = display_code;
	ptr[1] = '0' + id_num;
}

//virtual function
bool Game_Object::is_alive()
{
	return true;
}