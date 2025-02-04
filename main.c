#include "puzzle.h"
#include "parser.c"
#include "draw.c"
#include "input.c"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>



int main()
{
    // initialise variables
    int gameOver = 0;
    int mainGrid = 0;
    int cellGrid = 0;
    


    //setup stage
    enter_input_mode();
    // clear();
    // draw_grid(0,0,9);
    // draw_grid(60, 0, 3);
    
    // main loop
    while (1)
    {
        //char input = get_key();
        char input = getchar();
        printf("%d\n", (int)input);
    }


    exit_input_mode();
    return 0;
}
