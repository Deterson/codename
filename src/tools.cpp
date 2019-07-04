#include "tools.hh"


int count_lines(std::string filename)
{
    std::ifstream myfile(filename);

    // new lines will be skipped unless we stop it from happening:
    myfile.unsetf(std::ios_base::skipws);

    // count the newlines with an algorithm specialized for counting:
    unsigned line_count = std::count
        std::istream_iterator<char>(myfile), std::istream_iterator<char>(), '\n');

    return line_count;
}
