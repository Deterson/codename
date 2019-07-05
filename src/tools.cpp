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

int is_espion(int player)
{
    return player == E_RED || player == E_BLUE;
}

int is_maitre_espion(int player)
{
    return player == ME_BLUE || player == ME_RED;
}

int same_team(int p1, int p2)
{
    p1--;
    p2--;
    p1 /= 2;
    p2 /= 2;
    return p1 == p2;
}

Color player_color(int player)
{
    if (player == 1 || player == 2)
        return Color::BLUE;
    return Color::RED;
}
