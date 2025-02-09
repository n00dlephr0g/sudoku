#ifndef PUZZLE_H
#define PUZZLE_H

struct Cell
{
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


int set_trueValue(struct Puzzle* puzzle, int value, int row, int col);

#endif
