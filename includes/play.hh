#pragma once

#include <game.hh>
#include <iostream>
namespace play
{
    int espion(Game &game, Color c);
    int maitre_espion(Game &game, Color c);
    int other_team(Game& game, Color c);

    int guess_words(Game& game, Color c);
}