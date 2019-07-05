#pragma once

#include <string>
#include "word.hh"

namespace print
{
    std::string print_flipped(const std::string& word, Color c);
    std::string print_centered(const Word& word, int padding, bool colors);
    std::string print_word(const Word& word, bool colors);
}