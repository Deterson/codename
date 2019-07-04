#include <iostream>
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
                    int to_find = -1;
                    while (to_find < 0 || to_find > grid_.count(Color::BLUE))
                    {
                        std::cout << "Combien de mots à trouver vous a indiqué votre coéquipier?\n";
                        std::cin >> temp;
                        to_find = atoi(temp.c_str());
                    }

                    std::cout << "Quels sont les mots que vous devinez? Ecrivez-les dans l'ordre ";
                    std::cout << "et appuyez sur Entrée après chaque entrée." << std::endl;
                    std::cout << "Vous devez deviner au moins 1 mot" << std::endl;

                    int i = 0;
                    for (; i < to_find; i++)
                    {
                        if (i != 0)
                            std::cout << "Vous pouvez continuer à jouer." <<
                            " Appuyez sur Entrée pour arrêter votre tour." << std::endl;

                        std::string guessed;
                        std::cin >> guessed;

                        if (guessed.empty())
                            break;

                        grid::Position pos = find_word(guessed);
                        if (pos.x == -1)
                        {
                            std::cout << "Ce mot n'existe pas dans la grille. Vérifiez l'orthographe."
                                      << std::endl;
                            i--;
                        }
                        else if (pos.x == -2)
                        {
                            std::cout << "Ce mot a déjà été deviné." << std::endl;
                            i--;
                        }
                        else
                        {
                            int result = play_word(pos, Color::BLUE);

                            if (result == 2)
                                return 2;
                            if (result == 1)
                                break;
                        }
                    }

                    if (i == to_find)
                    {
                        std::cout << "Vous avez deviné " << to_find << " mots." <<
                        " Vous pouvez tenter de deviner un mot supplémentaire.\n" <<
                        " Appuyez sur Entrée pour arrêter votre tour" << std::endl;
                    }
                }
                curplr = 3;
                break;
            case 2:

                curplr = 4;
                break;
            case 3:

                curplr = 2;
                break;
            case 4:

                curplr = 1;
                break;
        }
    }

    return 1;
}


