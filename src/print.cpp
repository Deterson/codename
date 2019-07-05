#include "print.hh"

namespace print
{
    std::string print_centered(Word word, int padding)
    {
        std::string str = word.getWord();
        std::string ret;
        int len = str.length();

        for (int i = 0; i < (padding - len) / 2; i++)
            ret.append(" ");
        if ((len - padding) % 2 != 0)
            ret.append(" ");

        switch(word.getColor())
        {
            case Color::BLUE:
                ret.append("\033[;34m" + str + "\033[0m");
                break;
            case Color::RED:
                ret.append("\033[;31m" + str + "\033[0m");
                break;
            case Color::NEUTRAL:
                ret.append(str);
                break;
            case Color::BLACK:
                ret.append("\033[1;40m\033[;97m" + str + "\033[0m");
                break;
        }

        for (int i = 0; i < (padding - len) / 2; i++)
            ret.append(" ");
        return ret;
    }
}