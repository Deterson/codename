#include <iostream>
#include <game.hh>

int choose_plr(std::string basicString);

std::string get_seed()
{
    std::string ret;
    std::cout << "Quelle seed voulez-vous utiliser pour cette partie?" << std::endl;
    getline(std::cin, ret);
    return ret;
}

int get_player_n()
{
input:
    std::string temp;
    std::cout << "Quel est ton numéro de joueur?" <<
              "\n1 (espion) et 2 (maître-espion), bleus, jouent contre 3 (espion) et 4 (maître-espion), rouge" <<
              std::endl;

    getline(std::cin, temp);


    int ret;
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


int choose_plr(std::string seed_str)
{
    std::hash<std::string> hasher;
    auto hashed = hasher(seed_str);
    return (hashed % 2 == 0) * 2 + 1; // 1 ou 3
}


int main()
{
    std::string seed_str = get_seed();
    int plr = get_player_n();

    int plr_start = choose_plr(seed_str);

    Game game = Game(plr, seed_str, plr_start);

    std::cout << "C'est à l'équipe " << (plr_start == 1 ? "BLEUE" : "ROUGE") << " de commencer!";

    int winner = game.loop();

    print_winner(game, winner);

    return 0;
}

