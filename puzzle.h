#ifndef PUZZLE_H
#define PUZZLE_H

#define ORIGINAL 0
#define UNANSWERED 1
#define ANSWERED 2

struct Cell
{
    //cell type
    int state;
    //the original value
    char trueValue;
    //possible values marked by player
    int markings[9];
    //the answer of the player
    char answer;
    //the actual answer
    char solution;
};

struct Puzzle
{
    struct Cell cells[9][9];
};



#endif
