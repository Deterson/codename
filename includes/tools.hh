#pragma once

#include <fstream>
#include <algorithm>
#include <string>
#include "color.hh"
#include "game.hh"

int line_count(const std::string& filename);

int is_espion(int player);
int is_maitre_espion(int player);
int same_team(int p1, int p2);


Color player_color(int player);