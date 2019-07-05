#pragma once

#include <array>
#include <utility>
#include <iostream>
#include "play.hh"
#include "grid.hh"
#include "position.hh"

#define E_BLUE 1
#define ME_BLUE 2
#define E_RED 3
#define ME_RED 4


class Game
{
private:
    std::array<std::string, 4> players_; // players_[0] and players_[1] are together
    grid::Grid grid_;
    int plr_;
    int player_start_;

public:
    Game(std::array<std::string, 4> players, int plr, const std::string& seed_str, int plr_start);
    Game(int plr, const std::string& seed_str, int plr_start);

    grid::Position find_word(const std::string& word);
    int play_word(grid::Position p, Color c);

    int finished();

    int loop();

    grid::Grid &getGrid();

    const std::array<std::string, 4> &getPlayers() const;
};