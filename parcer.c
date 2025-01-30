#include <stdio.h>

char* get_file_name()
{
    char *filename[50];
    printf("enter puzzle file");
    scanf("%s", filename);
    filename = malloc(3 * sizeof(filename));
    return filename;
}

int ** read_puzzle()
{
    FILE *filePointer;
    return 0;
}



