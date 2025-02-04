#include <stdio.h>
#include "puzzle.h"
#include "parser.c"

int main()
{
    struct Puzzle puzzle;
    int output = read_puzzle(&puzzle);
    printf("%d", output);
    return 0;
}
