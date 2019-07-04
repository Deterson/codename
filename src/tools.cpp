#include "tools.hh"


int line_count(const std::string& filename)
{
    std::ifstream myfile(filename);

    // new lines will be skipped unless we stop it from happening:
    myfile.unsetf(std::ios_base::skipws);

    // count the newlines with an algorithm specialized for counting:
    unsigned ret = std::count(std::istreambuf_iterator<char>(myfile), std::istreambuf_iterator<char>(), '\n');

    return ret;
}
