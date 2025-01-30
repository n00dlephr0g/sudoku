#include <stdio.h>
#include <stdlib.h>

struct cell
{
    int trueValue;
};

struct puzzle
{
    struct cell cells[9][9];
};

char ** get_filename()
{
    char** filename = malloc(256 * sizeof(filename));
    printf("enter puzzle file:\n");
    scanf("%s", filename);
    return filename;
}

int read_puzzle()
{
    FILE* filePointer;
    return 0;
}


