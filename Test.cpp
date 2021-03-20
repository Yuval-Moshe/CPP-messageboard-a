/**
 * Tests for messageboard-a.
 *
 * AUTHOR: Yuval Moshe
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

string create_dashed_str(int length)
{
    string ans;
    for (int i = 0; i < length; i++)
    {
        ans += "-";
    }
    return ans;
}
string create_n_length_string(int length)
{
    srand(time(NULL));
    int min = 97;
    int max = 122;
    string ans;
    for (int i = 0; i < length; i++)
    {
        ans += (char)(min + rand() / (RAND_MAX / (max - min + 1) + 1));
    }
    return ans;
}

TEST_CASE("Regular Post & Reads")
{
    Board board;
    //Reading An Empty Line in Both Direction -> Should Return Dashes
    for (int i = 0; i < 50; i++)
    {
        CHECK(board.read((int)(rand() * 50), (int)(rand() * 50), Direction::Horizontal, i) == create_dashed_str(i)); // Change Rand()
        CHECK(board.read((int)(rand() * 50), (int)(rand() * 50), Direction::Vertical, i) == create_dashed_str(i));
    }

    // Regualr Post & Reads
    board.post(0, 0, Direction::Horizontal, "Hello");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "Hello");
    board.post(1, 0, Direction::Horizontal, "World");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "World");
    board.post(2, 0, Direction::Horizontal, "This");
    CHECK(board.read(0, 0, Direction::Horizontal, 5) == "This");
    board.post(3, 0, Direction::Horizontal, "Is");
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == "Is");
    board.post(4, 0, Direction::Horizontal, "A");
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == "A");
    board.post(5, 0, Direction::Horizontal, "CPP");
    CHECK(board.read(0, 0, Direction::Horizontal, 3) == "CPP");
    board.post(6, 0, Direction::Horizontal, "Course");
    CHECK(board.read(0, 0, Direction::Horizontal, 6) == "Course");
    board.post(7, 0, Direction::Horizontal, "Test");
    CHECK(board.read(0, 0, Direction::Horizontal, 4) == "Test");
    board.post(8, 0, Direction::Horizontal, "Of");
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == "Of");
    board.post(9, 0, Direction::Horizontal, "Assignment");
    CHECK(board.read(0, 0, Direction::Horizontal, 10) == "Assignment");
    board.post(10, 0, Direction::Horizontal, "MessageBoard-a");
    CHECK(board.read(0, 0, Direction::Horizontal, 14) == "MessageBoard-a");
}

TEST_CASE("Bad Insertions")
{
    Board board;
    // Posting to a non-exiting row:
    CHECK_THROWS(board.post(-1, 0, Direction::Horizontal, "Hello"));
    CHECK_THROWS(board.post(0, -1, Direction::Horizontal, "Hello"));
    CHECK_THROWS(board.post(-1, -1, Direction::Horizontal, "Hello"));
    CHECK_THROWS(board.post(-1, 0, Direction::Vertical, "Hello"));
    CHECK_THROWS(board.post(0, -1, Direction::Vertical, "Hello"));
    CHECK_THROWS(board.post(-1, -1, Direction::Vertical, "Hello"));
    // Reading From A Non Exsiting Row
    CHECK_THROWS(board.read(-1, 0, Direction::Horizontal, 5));
    CHECK_THROWS(board.read(0, -1, Direction::Horizontal, 5));
    CHECK_THROWS(board.read(-1, -1, Direction::Horizontal, 5));
    CHECK_THROWS(board.read(-1, 0, Direction::Vertical, 5));
    CHECK_THROWS(board.read(0, -1, Direction::Vertical, 5));
    CHECK_THROWS(board.read(-1, -1, Direction::Vertical, 5));
    // Reading A Negative Length
    CHECK_THROWS(board.read(0, 0, Direction::Horizontal, -2));
    CHECK_THROWS(board.read(0, 0, Direction::Vertical, -2));
}
