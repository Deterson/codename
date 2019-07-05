#include <iostream>
#include <game.hh>


int get_player_n()
{
input:
    std::string temp;
    std::cout << "Quel est ton numéro de joueur?" <<
              "\n1 (espion) et 2 (maître-espion), bleus, jouent contre 3 (espion) et 4 (maître-espion), rouge" <<
              std::endl;

    getline(std::cin, temp);


    int ret = -1;
    try
    {
        ret = std::stoi(temp);
    }
    catch (std::exception& e)
    {
        std::cout << "bon je vais répeter. ";
        goto input;
    }

    if (ret != 1 && ret != 2 && ret != 3 && ret != 4)
    {
        std::cout << "On te demande un chiffre entre 1 et 4 omg";
        goto input;
    }

    return ret;
}
void print_winner(const Game& game, int winner)
{
    std::string winner_name;
    if (winner == 1)
    {
        winner = 0;
        winner_name = "BLEUS";
    }
    else
    {
        winner = 2;
        winner_name = "ROUGES";
    }

    std::cout << "les " << winner_name << " ont gagné la partie! Bravo à " <<
              game.getPlayers()[winner] << " et à "<<
              game.getPlayers()[winner + 1] << "." << std::endl;
}

int main()
{
    int plr = get_player_n();

    Game game = Game(plr);

    int winner = game.loop(plr);

    print_winner(game, winner);

    return 0;
}
