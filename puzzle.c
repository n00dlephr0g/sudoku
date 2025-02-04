#include "puzzle.h"


int set_trueValue(struct Puzzle* puzzle, int value, int row, int col)
{
    // return error code if the values are not in range
    if (0<=value<10 || 0<=row<10 || 0<=col<10) {return 1;}
    puzzle->cells[col][row].trueValue = value;
    return 0;
}