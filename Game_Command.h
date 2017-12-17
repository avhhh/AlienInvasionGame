#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include "Astronaut.h"
#include "Oxygen_Depot.h"
#include "Space_Station.h"
#include "Model.h"
#include "Alien.h"

void do_move_command(Model &model);
void do_work_a_depot_command(Model &model);
void do_deposit_moonstones_command(Model &model);
void do_stop_command(Model &model);
void do_lock_in_at_a_station_command(Model &model);
void do_go_command(Model &model);
void do_run_command(Model &model);
void do_quit_command(Model &model);
void do_attack_command(Model &model);
void handle_new_command(Model &model);

#endif