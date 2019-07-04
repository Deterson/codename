#pragma once

#include <fstream>
#include <algorithm>
#include <string>
#include "color.hh"

int line_count(const std::string& filename);
int other_team(int player);

Color player_color(int player);