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


std::array<Word, 25> Word::random_words(const std::string& seed_str, int plr_start)
{
    std::array<Word, 25> ret;
    int number_of_lines = line_count("dico");
    assert(number_of_lines >= 25);

    // a vector to hold all the indices: 0 to number_of_lines
    std::vector<int> line_indices(25);
    std::iota(begin(line_indices), end(line_indices), 0); // init line_indices

    std::random_device r;

    std::hash<std::string> hasher;
    auto hashed = hasher(seed_str); //returns std::size_t

    std::seed_seq seed{hashed};
    std::mt19937 eng(seed);

    std::seed_seq seed2{hashed};
    std::mt19937 eng2(seed2);

    // shuffle the line_indices:
    std::shuffle(begin(line_indices), end(line_indices), eng);

    std::array<Color, 25> colors{};
    int i = 0;
    for (; i < N_WORDS + (plr_start == 1); i++)
        colors.at(i) = Color::BLUE;
    for (; i < N_WORDS * 2 + 1; i++)
        colors.at(i) = Color::RED;
    for (; i < WIDTH * WIDTH - 1; i++)
        colors.at(i) = Color::NEUTRAL;
    colors.at(WIDTH * WIDTH - 1) = Color::BLACK;

    std::shuffle(begin(colors), end(colors), eng2);


    std::string line;
    std::ifstream file("dico");

    int line_number = 0;
    while (std::getline(file, line))
    {
        for (int j = 0; j < 25; j++)
        {
            if (line_number == line_indices[j])
                ret.at(j) = Word(line, colors[line_number]);
        }
        ++line_number;
    }

    return ret;
}

const std::string &Word::getWord() const
{
    return word_;
}

Color Word::getColor() const
{
    return color_;
}

bool Word::isFlipped() const
{
    return flipped_;
}

void Word::flip()
{
    flipped_ = true;
}
