#ifndef ALIEN_H
#define ALIEN_H

#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

class Alien: public Game_Object
{
	private:
		int attack_strength;
		double range;
		Person* target;
		double speed;
		Cart_Point destination;
		Cart_Vector delta;

	public:
		Alien();
		Alien(int in_id, Cart_Point in_loc);
		void start_attack(Person* in_target);
		bool update();
		void show_status();
		//stuff for moving alien
		void start_moving(Cart_Point);
		void stop();
		bool update_location();
		void setup_destination(Cart_Point);
		~Alien();
		void setspeed(double new_speed);


};

#endif