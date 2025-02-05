#include "puzzle.h"
#include "parser.c"
#include "terminal.c"
#include "game.c"
#include <stdio.h>
#include <unistd.h>



int main()
{
    // initialise
    int gameOver = 0;
    struct Game* game;

    //setup stage
    clear();
    enter_input_mode();
    move_cursor(0,22);
    init_game(game);

    // main loop
    while (gameOver==0)
    {
        char input = get_action();
        draw_char(0,0,input);
    }


    exit_input_mode();
    return 0;
}
