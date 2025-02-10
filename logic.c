#include <puzzle.h>



char get_cell_value(struct Cell* cell)
{
    switch (cell->state)
    {
        case ORIGINAL:
            return cell.trueValue;
        case ANSWERED:
            return cell.answer;
        default:
            return ' ';
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