#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "puzzle.h"


void init_puzzle(struct Puzzle* puzzle)
{
    for (int y = 0; y<9; y++)
    {
        char item;
        for (int x = 0; x < 9; x++)
        {
            puzzle->cells[x][y].trueValue = 0;
        }
        printf("\n");

    }
}


int read_puzzle(struct Puzzle* puzzle, char* filename)
{
    //define variables
    FILE* file;

    //open file
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File is NULL\n");
        return 2;
    }

    //initialise puzzle
    init_puzzle(puzzle);
    //read and parse file
    //read 9 lines
    for (int y = 0; y<9; y++)
    {
        char item;
        for (int x = 0; x < 9; x++)
        {
            fread(&item, 1, 1, file);
            if (item =='\n') {break;}
            if (isdigit(item)) 
            {
                puzzle->cells[x][y].trueValue = item;
            }
            else
            {
                puzzle->cells[x][y].trueValue = '0';
            }
        }
        printf("\n");

    }



    //close file
    fclose(file);


    return 0;
}
