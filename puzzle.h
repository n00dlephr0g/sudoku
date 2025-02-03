#ifndef PUZZLE_H
#define PUZZLE_H

struct Cell
{
    //the original value
    char trueValue;
    //possible values marked by player
    char markings[9];
    //the answer of the player
    char answer;
};

struct Puzzle
{
    struct Cell cells[9][9];
};

#endif
