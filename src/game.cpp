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
        std::cout << "C'est à " << getPlayers().at(curplr) << " de jouer" << std::endl;

        switch(curplr)
        {
            case 1:
                if (plr == 1)
                {
                    if (play::espion(*this, Color::BLUE) == 2)
                        return 2;
                }
                else if (plr == 2)
                {
                    if (play::maitre_espion(*this, Color::BLUE) == 2)
                        return 2;
                }
                else
                {
                    if (play::other_team(*this, Color::BLUE) == 2)
                        return 2;
                }
                curplr = 3;
                break;
            case 2:
                if (plr == 2)
                {
                    if (play::espion(*this, Color::BLUE) == 2)
                        return 2;
                }
                else if (plr == 1)
                {
                    if (play::maitre_espion(*this, Color::BLUE) == 2)
                        return 2;
                }
                else
                {
                    if (play::other_team(*this, Color::BLUE) == 2)
                        return 2;
                }
                curplr = 4;
                break;
            case 3:
                if (plr == 3)
                {
                    if (play::espion(*this, Color::RED) == 2)
                        return 0;
                }
                else if (plr == 4)
                {
                    if (play::maitre_espion(*this, Color::RED) == 2)
                        return 0;
                }
                else
                {
                    if (play::other_team(*this, Color::RED) == 2)
                        return 0;
                }
                curplr = 2;
                break;
            case 4:
                if (plr == 4)
                {
                    if (play::espion(*this, Color::RED) == 2)
                        return 0;
                }
                else if (plr == 2)
                {
                    if (play::maitre_espion(*this, Color::RED) == 2)
                        return 0;
                }
                else
                {
                    if (play::other_team(*this, Color::RED) == 2)
                        return 0;
                }
                curplr = 1;
                break;
        }
    }

    return 1;
}

grid::Grid &Game::getGrid()
{
    return grid_;
}


