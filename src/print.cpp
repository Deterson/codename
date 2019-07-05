#include "print.hh"

namespace print
{
    std::string print_centered(const std::string& word, int padding)
    {
        std::string ret;
        int len = word.length();

        for (int i = 0; i < (padding - len) / 2; i++)
            ret.append(" ");
        if ((len - padding) % 2 != 0)
            ret.append(" ");

        ret.append(word);

        for (int i = 0; i < (padding - len) / 2; i++)
            ret.append(" ");
        return ret;
    }
}