#include <iomanip>
#include <iostream>
#include "grid.hh"

namespace grid
{
    Grid::Grid()
    {
        this->words_ = Word::random_words();
    }

    Word& Grid::get(int x, int y)
    {
        assert(x >= 0 && y >= 0 && x < WIDTH && y < WIDTH);
        return words_.at(y * WIDTH + x);
    }

    const std::array<Word, 25> &Grid::getWords() const
    {
        return words_;
    }

    int Grid::count(Color c)
    {
        int ret = 0;
        for (const Word& w : words_)
        {
            if (w.getColor() == c && !(w.isFlipped()))
                ret++;
        }
        return ret;
    }

    void Grid::print(bool colors)
    {
        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = WIDTH - 1; j >= 0; j--)
            {
                std::cout << std::setw (10) << get(i, j).getWord() << "  ";
            }
            std::cout << std::endl;
        }
    }
}