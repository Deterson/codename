#pragma once

#include <string>
#include <array>
#include <vector>

#include "color.hh"
#include "tools.hh"

class Word
{
private:
    std::string word_;
    Color color_;
    bool flipped_;
public:
    Word();
    Word(std::string word, Color color);

    static std::array<Word, 25> random_words();
};
