#include <stdio.h>
#include <stdlib.h>

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

char ** get_filename()
{
    //define variable
    char** filenamePointer = malloc(256 * sizeof(filename));
    //get user input
    printf("enter puzzle file:\n");
    scanf("%s", filenamePointer);
    //return pointer
    return filenamePointer;
}

int read_puzzle(struct Puzzle puzzle)
{
    //define variables
    FILE* file;
    char** filenamePointer;
    char* filename;
    

    //get filename
    filenamePointer = get_filename();
    sprintf(filename, "%s", filenamePointer);
    free(filenamePointer);

    //open file
    file = fopen(filename, "r");
    if (file == NULL)
    {
        return 1;
    }

    //read and parce file
    

    //close file
    fclose(file);


    return 0;
}


