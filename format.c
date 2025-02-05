#include <stdio.h>

// format
#define RESET 0
#define BRIGHT 1
#define DIM 2
#define UNDERLINE 4
#define INVERSE 7
#define HIDDEN 8

// foreground
#define FG_DEFAULT 39
#define FG_WHITE 97
#define FG_RED 31
#define FG_GREEN 32
#define FG_YELLOW 33
#define FG_BLUE 34
#define FG_MAGENTA 35
#define FG_CYAN 36

// background
#define BG_DEFAUT 49
#define BG_BLACK 40
#define BG_RED 41
#define BG_GREEN 42
#define BG_YELLOW 43
#define BG_BLUE 44
#define BG_MAGENTA 45
#define BG_CYAN 46


void set_format(int code)
{
    printf("\e[%dm", code);
}


void set_formats(int* codes, int len)
{
    for (int i = 0; i < len; i++)
    {
        set_format(codes[i]);
    }
}