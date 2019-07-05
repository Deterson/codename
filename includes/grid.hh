#pragma once

#include <array>
#include "word.hh"
#include "color.hh"
#include "word.hh"

#define WIDTH 5
#define N_WORDS 8

namespace grid
{
    class Grid
    {
    private:
        std::array<Word, 25> words_;
    public:
        Grid();

        Word& get(int x, int y);
        const std::array<Word, 25> &getWords() const;

        int count(Color c);

        void print(bool colors = false);
    };
}