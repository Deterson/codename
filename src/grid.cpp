#include "grid.hh"

namespace grid
{
    Grid::Grid()
    {
        this->words_ = Word::random_words();
    }

    Word Grid::get(int x, int y)
    {
        assert(x >= 0 && y >= 0 && x < WIDTH && y < WIDTH);
        return words_.at(y * WIDTH + x);
    }
}