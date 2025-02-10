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
    init_game(game);
    read_puzzle(&(game->puzzle),"puzzles/real1.txt");
    draw_stage(game);

    // main loop
    while (gameOver==0)
    {
        char input = get_action();
        int end = step(game, input);
        if (end)
        {break;}
    }


    exit_input_mode();
    return 0;
}
