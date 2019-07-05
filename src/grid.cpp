#include <iomanip>
#include <iostream>
#include "print.hh"
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
        std::cout << std::endl;
        int padding = 15;

        for (int i = 0; i < WIDTH * (padding + 1) + 1; i++)
            std::cout << "-";

        std::cout << std::endl;

        for (int i = 0; i < WIDTH; i++)
        {
            for (int j = WIDTH - 1; j >= 0; j--)
            {
                std::cout << "|" << print::print_centered(get(i, j), padding, colors);
            }

            std::cout << "|" << std::endl;
            for (int j = 0; j < WIDTH * (padding + 1) + 1; j++)
                std::cout << "-";
            std::cout << std::endl;
        }

        std::cout << std::endl << std::endl << std::endl;
    }
}