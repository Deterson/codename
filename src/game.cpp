#include "game.hh"

Game::Game(std::string p1, std::string p2, std::string p3, std::string p4, int player)
{
    assert(player >= 1 && player <= 4);
    players_ = {std::move(p1), std::move(p2), std::move(p3), std::move(p4)};
    grid_ = grid::Grid();
    this->player_ = player;
}

Game::Game(int player) : Game("player1", "player2", "player3", "player4", player)
{}

int Game::play_word(grid::Position p, Color c) // 0: all good / 1: stop / 2: dead
{
    Word& w = grid_.get(p.x, p.y);
    if (w.isFlipped())
    {
        std::cout << "Ce mot a déjà été deviné." << std::endl;
        return -1;
    }

    w.flip();
    Color curC = w.getColor();
    std::cout << print_color(curC) << std::endl;

    if (curC == Color::BLACK)
        return 2;
    if (curC != c)
        return 1;
    return 0;
}

grid::Position Game::find_word(const std::string& word)
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (word == grid_.get(i, j).getWord())
            {
                if (grid_.get(i, j).isFlipped())
                    return grid::Position(-2, -2);
                return grid::Position(i, j);
            }
        }
    }

    return grid::Position(-1, -1);
}

int Game::finished()
{
    if (grid_.count(Color::BLUE) == 0)
        return 1;
    if (grid_.count(Color::RED) == 0)
        return -1;
    return 0;
}

const std::array<std::string, 4> &Game::getPlayers() const
{
    return players_;
}

int Game::loop(int plr)
{
    std::string temp;
    int curplr = 1;

    while (finished() == 0)
    {
        getGrid().print(plr == 2 || plr == 4);

        std::cout << "C'est à " << getPlayers().at(curplr - 1) << " de jouer\n" << std::endl;

        int res = 0;

        if (curplr == plr && is_espion(plr))
            res = play::espion(*this, player_color(plr));
        else if (same_team(curplr, plr) && is_maitre_espion(plr))
            res = play::maitre_espion(*this, player_color(plr));
        else
            res = play::other_team(*this, player_color(plr), curplr, is_maitre_espion(plr));

        if (res != 0)
            return res; // 1 si bleu, -1 si rouge

        curplr = 4 - curplr; // change current player
    }

    return 1;
}

grid::Grid &Game::getGrid()
{
    return grid_;
}


