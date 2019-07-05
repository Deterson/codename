#include "play.hh"

namespace play
{
    int espion(Game &game, Color c)
    {
        std::string temp;
        int to_find = -1;
        while (to_find < 0 || to_find > game.getGrid().count(c))
        {
input2:
            std::cout << "Combien de mots à trouver vous a indiqué votre coéquipier?\n";
            getline(std::cin, temp);
            try
            {
                to_find = std::stoi(temp);
            }
            catch(std::exception&)
            {
                goto input2;
            }
        }


        std::cout << "Quels sont les mots que vous devinez? Ecrivez-les dans l'ordre ";
        std::cout << "et appuyez sur Entrée après chaque mot." << std::endl;
        std::cout << "Vous devez deviner au moins 1 mot" << std::endl;

        int ret = guess_words(game, c, false, to_find);
        return ret;
    }

    int enter_words(Game &game, Color c, int to_find, bool show, bool must_find) // 0 = arrêté, -1/1 = mort, 2 = extra word
    {
        int guessed_words = 0;
        while (guessed_words < to_find)
        {
            game.getGrid().print(show);

            std::string guessed;
            getline(std::cin, guessed);

            if (guessed.empty())
            {
                if (guessed_words > 0 || !must_find)
                    break;
                std::cout << "Au moins un mot doit être rentré." << std::endl;
                continue;
            }


            grid::Position pos = game.find_word(guessed);
            if (pos.x == -1)
                std::cout << "Ce mot n'existe pas dans la grille. Vérifiez l'orthographe."
                          << std::endl;
            else if (pos.x == -2)
                std::cout << "Ce mot a déjà été deviné." << std::endl;
            else
            {
                int result = game.play_word(pos, c);

                if (result == 1)
                    break;
                if (result == 2)
                    return (c == Color::BLUE) ? -1 : 1;

                int finished = game.finished();
                if (finished)
                    return finished;

                guessed_words++;
            }
            if (guessed_words > 0 && guessed_words < to_find)
                std::cout << "Ecrivez un nouveau mot, ou appuyez sur Entrée pour passer." << std::endl;
        }
        if (guessed_words == to_find)
            return 2;
        return 0;
    }

    int maitre_espion(Game &game, Color c)
    {
        std::cout << "Indiquez à votre coéquipier un seul indice, et le nombre de mots qu'il doit" <<
                 " trouver avec cet indice." << std::endl;
        std::cout << "Quels sont les mots que votre coéquipier a devinés? Ecrivez-les dans l'ordre ";
        std::cout << "et appuyez sur Entrée après chaque mot." << std::endl;
        std::cout << "Votre coéquipier doit deviner au moins 1 mot" << std::endl;

        return guess_words(game, c, true);
    }


    int guess_words(Game& game, Color c, bool show, int to_find)
    {
        int res = enter_words(game, c, to_find, show);

        if (res == 2)
        {
            std::cout << "Vous avez deviné " << to_find << " mots." <<
                      " Vous pouvez tenter de deviner un mot supplémentaire.\n" <<
                      " Appuyez sur Entrée pour arrêter votre tour" << std::endl;
            res = enter_words(game, c, 1, false, false);
            if (res == 1 || res == -1)
                return res;
        }

        return res;
    }

    int other_team(Game &game, Color c, int curplr, bool show)
    {
        std::string other = game.getPlayers()[curplr - 1];
        std::cout << "Quels sont les mots que " + other + " a devinés? Ecrivez-les dans l'ordre ";
        std::cout << "et appuyez sur Entrée après chaque entrée." << std::endl;
        std::cout << "L'équipe adverse doit deviner au moins 1 mot" << std::endl;

        int ret = guess_words(game, other_team(c), show);
        return ret;
    }

}