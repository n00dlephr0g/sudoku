#include "puzzle.c"
#include <stdio.h>

int main()
{
    char** filenamePointer;
    char* filename;
    filenamePointer = get_filename();
    sprintf(filename, "%s", filenamePointer);
    free(filenamePointer);
    printf("%s\n", filename);
    return 0;
}
