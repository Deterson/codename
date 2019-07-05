#pragma once

#include "game.hh"
#include "color.hh"
#include <iostream>
#include <limits>

class Game;

namespace play
{
    int espion(Game &game, Color c);
    int maitre_espion(Game &game, Color c);
    int other_team(Game &game, Color c, int curplr, bool show);

    int enter_words(Game &game, Color c, int to_find, bool show, bool must_find = true);

    int guess_words(Game& game, Color c, bool show, int to_find = std::numeric_limits<int>::max());
}