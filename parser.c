#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "puzzle.h"

int read_puzzle(struct Puzzle* puzzle)
{
    //define variables
    FILE* file;
    char filename[1024];


    //get filename
    printf("enter puzzle file:\n");
    if (fgets(filename, 1024, stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }




    printf(filename);
    //open file
    file = fopen(filename, "r");
    if (file == NULL)
    {
        return 2;
    }

    //read and parce file
    //read 9 lines
    for (int x = 0; x<10; x++)
    {
        continue;
    }

    //close file
    fclose(file);


    return 0;
}
