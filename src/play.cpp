#include "play.hh"

namespace play
{
    int espion(Game &game, Color c)
    {
        std::string temp;
        int to_find = -1;
        while (to_find < 0 || to_find > game.getGrid().count(Color::BLUE))
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
            getline(std::cin, guessed);

            if (guessed.empty())
                break;

            grid::Position pos = game.find_word(guessed);
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
                int result = game.play_word(pos, c);

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

        return 0;
    }


    int maitre_espion(Game &game, Color c)
    {
        std::cout << "Indiquez à votre coéquipier un seul indice, et le nombre de mots qu'il doit" <<
                 " trouver avec cet indice." << std::endl;
        std::cout << "Quels sont les mots que votre coéquipier a devinés? Ecrivez-les dans l'ordre ";
        std::cout << "et appuyez sur Entrée après chaque entrée." << std::endl;
        std::cout << "Votre coéquipier doit deviner au moins 1 mot" << std::endl;

        if (guess_words(game, c) == 2)
            return 2;
        return 0;
    }

    int guess_words(Game& game, Color c)
    {
        int guessed_words = 0;
        std::string guessed;

        while (true)
        {
            getline(std::cin, guessed);

            if (guessed.empty() && guessed_words != 0)
                break;

            grid::Position pos = game.find_word(guessed);
            if (pos.x == -1)
                std::cout << "Ce mot n'existe pas dans la grille. Vérifiez l'orthographe."
                          << std::endl;
            else if (pos.x == -2)
                std::cout << "Ce mot a déjà été deviné." << std::endl;
            else
            {
                int result = game.play_word(pos, c);
                guessed_words++;
                if (result == 2)
                    return 2;
                if (result == 1)
                    break;
            }
        }

        return 0;
    }

    int other_team(Game& game, Color c)
    {
        std::cout << "Quels sont les mots que l'équipe adverse a devinés? Ecrivez-les dans l'ordre ";
        std::cout << "et appuyez sur Entrée après chaque entrée." << std::endl;
        std::cout << "L'équipe adverse doit deviner au moins 1 mot" << std::endl;

        if (guess_words(game, c) == 2)
            return 2;
        return 0;
    }

}