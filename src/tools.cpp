#include "tools.hh"


int line_count(const std::string& filename)
{
    std::ifstream myfile(filename);

    // new lines will be skipped unless we stop it from happening:
    myfile.unsetf(std::ios_base::skipws);

    // count the newlines with an algorithm specialized for counting:
    unsigned ret = std::count(std::istreambuf_iterator<char>(myfile), std::istreambuf_iterator<char>(), '\n');

    return ret;
}

int other_team(int player)
{
    if (player < 3)
        return 3 - player;

    return 7 - player;
}

Color player_color(int player)
{
    if (player == 1 || player == 2)
        return Color::BLUE;
    return Color::RED;
}
