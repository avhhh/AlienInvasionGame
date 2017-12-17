#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Cart_Point.h"

// Declaration of class
class Game_Object
{
	protected:
		//protected member variables
		Cart_Point location;
		int id_num;
		char display_code;
		char state;

	public:
		//constructors
		Game_Object(char in_code);
		Game_Object(Cart_Point in_loc, int in_id, char in_code);

		//member functions
		Cart_Point get_location();
		int get_id();
		char get_state();
		void drawself(char* ptr); //Added Function for View
		virtual void show_status(); //virtual function
		virtual bool update() = 0; //pure virtual functions
		virtual bool is_alive(); // virtual function for Person
		virtual ~Game_Object(); //Destructor
};
#endif
