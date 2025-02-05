#include "puzzle.h"
#include "parser.c"
#include "terminal.c"
#include "game.c"
#include <stdio.h>
#include <unistd.h>



int main()
{
    // initialise variables
    int gameOver = 0;
    


    //setup stage
    enter_input_mode();
    clear();
    move_cursor(0,22);

    // main loop
    while (gameOver==0)
    {
        char input = get_action();
    }


    exit_input_mode();
    return 0;
}
