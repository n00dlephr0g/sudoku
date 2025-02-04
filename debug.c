#include "puzzle.h"
#include "parser.c"
#include "draw.c"
#include "input.c"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>



int main()
{
    enter_input_mode();

    while (1)
    {
        char input = getchar();
        printf("%c: %d\n", input, (int)input);
    }


    exit_input_mode();
    return 0;
}