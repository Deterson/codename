#pragma once

namespace grid
{
    class Position
    {
    public:
        int x{};
        int y{};

        Position()
        {
            x = 0;
            y = 0;
        }

        Position(int i, int j)
        {
            x = i;
            y = j;
        }
    };
}
