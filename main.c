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
    int gridSelection = 0; //0: main, 1: marking ,2: answer
    int xpos = 0;
    int ypos = 0;
    


    //setup stage
    enter_input_mode();
    clear();
    // main loop
    while (gameOver==0)
    {
        draw_stage();

        char input = get_key();
    }


    exit_input_mode();
    return 0;
}
