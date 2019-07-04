#pragma once

#include <array>
#include <utility>
#include "grid.hh"
#include "position.hh"

class Game
{
private:
    std::array<std::string, 4> players_; // players_[0] and players_[1] are together
    grid::Grid grid_;
    int player_;

public:
    Game(std::string p1, std::string p2, std::string p3, std::string p4, int player);
    explicit Game(int player);

    int play_word(grid::Position p, Color c);
    grid::Position find_word(const std::string& word);

    int finished();

};