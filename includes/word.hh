#pragma once

#include <numeric>
#include <random>
#include <algorithm>
#include <assert.h>
#include <fstream>
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

    const std::string &getWord() const;
    Color getColor() const;
    bool isFlipped() const;

    void setFlipped();

    static std::array<Word, 25> random_words();
};