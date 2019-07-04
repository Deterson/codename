#include <iostream>
#include <game.hh>


int main()
{
    std::string temp;
    std::cout << "Quel est ton numéro de joueur?" <<
              " (1 et 2, bleus, jouent contre 3 et 4, rouge)" <<
              std::endl;

    getline(std::cin, temp);

    int plr = -1;
    plr = atoi(temp.c_str());

    if (plr != 1 && plr != 2 && plr != 3 && plr != 4)
    {
        std::cout << "On te demande un chiffre entre 1 et 4 omg";
        return 1;
    }

    Game game = Game(plr);

    int winner = game.loop(plr);

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

    return 0;
}
