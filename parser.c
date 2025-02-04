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
        // char line[256];
        // int row[9];

        // fgets(line, 256, file);
        // sscanf(line,"%d%d%d%d%d%d%d%d%d",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8]);

        // for (int i = 0; i < 9; i++)
        // {
        //     printf("%d", row[i]);
        // }
        // printf("\n");

        char item;
        int intInLine = 0;
        while (fread(&item, 1, 1, file) > 0) 
        {
            if (isdigit(item))
            {
                intInLine++;
                int row = x;
                int col = intInLine;
                int value = item - '0';
                //set_trueValue(puzzle, value, row, col);
                // printf("%c", item);
            }
            if (intInLine==9) {break;}
        }
        // printf("\n");

    }

    //close file
    fclose(file);


    return 0;
}
