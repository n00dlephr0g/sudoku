#include "puzzle.h"



char get_cell_value(struct Cell* cell)
{
    if (cell->trueValue == '0') //has no initial value
    {
        if (cell->state == ANSWERED)
        {
            return cell->answer;
        }
        else
        {
            return ' ';
        }
    }
    else
    {
        return cell->trueValue;
    }
}


int is_cell_marked(struct Cell* cell)
{
    for (int n = 0; n < 9; n++)
    {
        if (cell->markings[n] > 0)
        {
            return 1;
        }
    }
    return 0;
}