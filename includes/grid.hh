#pragma once

#include <array>
#include "word.hh"
#include "color.hh"

class Grid
{
private:
    std::array<Word, 25> grid_;


public:
    Grid();
};
