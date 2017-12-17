#ifndef PERSON_H
#define PERSON_H

#include "Game_Object.h"
#include "Cart_Point.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
class Person : public Game_Object
{
	public:
		Person();
		Person(char);
		Person(Cart_Point, int, char);
		void start_moving(Cart_Point);
		void stop();
		void show_status();
		virtual ~Person();
		
		//Virtual Functions
		virtual void start_supplying(Oxygen_Depot* inputDepot);
		virtual void start_depositing(Space_Station* inputStation);
		virtual void go_to_station(Space_Station* inputStation);

		//New additions for alien
		bool is_alive();
		void take_hit(int attack_strength);

		//Allows to change the speed
		void setspeed(double new_speed);


	protected:
		bool update_location();
		void setup_destination(Cart_Point);
		//New additions for alien
		int health;

	private:
		double speed;
		Cart_Point destination;
		Cart_Vector delta;
};

#endif