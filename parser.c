#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "puzzle.h"





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

    //read and parce file
    //read 9 lines
    for (int x = 0; x<9; x++)
    {
        char item;
        int y = 0;
        while (fread(&item, 1, 1, file) > 0) 
        {
            if (isdigit(item))
            {
                y++;
                int value = item - '0';
                //write to puzzle
                puzzle->cells[x][y].trueValue = value;
            }
            if (y==9) {break;}
        }
        // printf("\n");

    }



    //close file
    fclose(file);


    return 0;
}
