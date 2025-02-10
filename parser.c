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
            puzzle->cells[x][y].state = UNANSWERED;
            puzzle->cells[x][y].trueValue = 0;
            for (int m = 0; m < 9; m++)
            {
                puzzle->cells[x][y].markings[m] = 0;
            }
        }
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
        for (int x = 0; x < 10; x++)
        {
            int res = fread(&item, 1, 1, file);
            if (item =='\n' || res < 1) {break;}
            char value;
            if (isdigit(item) && item != 0)
            {
                value = item;
            }
            else
            {
                value = '0';
            }
            puzzle->cells[x][y].trueValue = value;
        }
    }



    //close file
    fclose(file);


    return 0;
}
