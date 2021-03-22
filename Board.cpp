
#include <array>
using namespace std;
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;

namespace ariel
{
    void Board::post(int row, int column, Direction dir, const string &message) {}
    string Board::read(int row, int column, Direction dir, int length)
    {
        return "Hello";
    }
    void Board::show() {}
}
