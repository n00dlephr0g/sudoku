#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cell
{
    //the original value
    char trueValue;
    //possible values marked by player
    char markings[9];
    //the answer of the player
    char answer;
};

struct Puzzle
{
    struct Cell cells[9][9];
};

char stdinBuffer[1024];

int get_filename()
{
    //get user input
    printf("enter puzzle file:\n");
    if (fgets(stdinBuffer, sizeof(stdinBuffer), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return -1;
    }
    size_t len = strlen(stdinBuffer);
    if (len > 0 && stdinBuffer[len - 1] == '\n') {
        stdinBuffer[len - 1] = '\0';
    }

    return 0;
}

int read_puzzle(struct Puzzle* puzzle)
{
    //define variables
    FILE* file;
    char filename[1024];
    

    //get filename
    if (get_filename() == 0) {
        sprintf(filename, "%s", stdinBuffer);
    } else {
        return 1;
    }

    //open file
    file = fopen(filename, "r");
    if (file == NULL)
    {
        return 2;
    }

    //read and parce file
    

    //close file
    fclose(file);


    return 0;
}


