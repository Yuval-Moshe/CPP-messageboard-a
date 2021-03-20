#pragma once
#include <array>
using namespace std;
#include "Direction.hpp"
using namespace ariel;

namespace ariel
{
    class Board
    {
        array<array<char, 100>, 100> b_arr;

    public:
        void post(int row, int column, Direction, string message);
        string read(int row, int column, Direction, int length);
        void show();
    };
}