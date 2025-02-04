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

int set_trueValue(struct Puzzle* puzzle, int value, int row, int col)
{
    // return error code if the values are not in range
    if (0<value<10 || 0<row<10 || 0<col<10) {return 1;}
    puzzle->cells[col][row].trueValue = value;
    return 0;
}


#endif
