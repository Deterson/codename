#include "word.hh"


Word::Word(std::string word, Color color)
{
    word_ = word;
    color_ = color;
    flipped_ = false;
}

Word::Word()
{
    word_ = "blank";
    color_ = Color::NEUTRAL;
    flipped_ = false;
}


std::array<Word, 25> Word::random_words()
{
    std::array<Word, 25> ret;
    int number_of_lines = line_count("dico");

    // a vector to hold all the indices: 0 to number_of_lines
    std::vector<int> line_indices(number_of_lines);
    std::iota(begin(line_indices), end(line_indices), 0); // init line_indices

    // C++11 random library (should be preferred over rand()/srand())
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    std::mt19937 eng(seed);

    // shuffle the line_indices:
    std::shuffle(begin(line_indices), end(line_indices), eng);

    assert(number_of_lines >= 25);

    std::string line;
    std::ifstream file("dico");

    int line_number = 0;
    while (std::getline(file, line))
    {
        for (int i = 0; i < 25; i++)
        {
            if (line_number == line_indices[i])
            {
                ret.at(i) = Word(line, Color::NEUTRAL); //trouver la vraie fonction
            }
        }
        ++line_number;
    }
    //pas oublier de random les couleurs
    return ret;
}
