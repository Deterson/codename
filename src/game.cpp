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
    Word w = grid_.get(p.x, p.y);
    if (w.isFlipped())
        return -1;
    if (c == w.getColor())
        return
}

grid::Position Game::find_word(const std::string& word)
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (word == grid_.get(i, j).getWord())
                return grid::Position(i, j);
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


