#pragma once

#include <string>

enum class Color
{
    BLUE = 0,
    RED = 1,
    NEUTRAL = 2,
    BLACK = 3
};

Color other_team(Color c);

std::string print_color(Color c);