#include "print.hh"

namespace print
{
    std::string print_word(const Word& word, bool colors)
    {
        std::string str = word.getWord();
        if (word.isFlipped())
            return print_flipped(word.getWord(), word.getColor());

        if (colors)
        {
            switch (word.getColor())
            {
                case Color::BLUE:
                    return "\033[;94m" + str + "\033[0m";
                case Color::RED:
                    return "\033[;31m" + str + "\033[0m";
                case Color::NEUTRAL:
                    return str;
                case Color::BLACK:
                    return "\033[7;37m" + str + "\033[0m";
            }
        }
        return str;
    }



    std::string print_flipped(const std::string& word, Color c)
    {
        switch (c)
        {
            case Color::BLUE:
                return "\033[;34m\033[;44m" + word + "\033[0m";
            case Color::RED:
                return "\033[;31m\033[;41m" + word + "\033[0m";
            case Color::NEUTRAL:
                return "\033[;90m\033[;100m" + word + "\033[0m";
            case Color::BLACK:
                return "\033[;30m\033[;40m" + word + "\033[0m";
        }
        return "oups"; // untriggers -Werror
    }

    int accent_length(const std::string& str)
    {
        int ret = str.length();
        ret -= std::count(str.begin(), str.end(), '\303');


        return ret;
    }

    std::string print_centered(const Word& word, int padding, bool colors)
    {
        std::string ret;

        std::string pads = " ";
        int len = accent_length(word.getWord());

        for (int i = 0; i < (padding - len) / 2; i++)
            ret.append(pads);
        if ((len - padding) % 2 != 0)
            ret.append(pads);

        ret.append(print_word(word, colors));

        for (int i = 0; i < (padding - len) / 2; i++)
            ret.append(pads);
        return ret;
    }
}