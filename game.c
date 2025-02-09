#include <ctype.h>
#include "puzzle.h"
#include "draw.c"
#include "menu.c"

// define constants
#define LOOK_MODE 0 // looking around main grid
#define MARK_MODE 1 // marking selected
#define EDIT_MODE 2 // editing answer

// screen coordinates
#define LOOK_X 3
#define LOOK_Y 1
#define MARK_X 59
#define MARK_Y 1
#define ANS_X MARK_X
#define ANS_Y 8

const char EMPTY_MARK[9] = { 0 };


struct Game
{
    // current game mode
    int mode;
    int over;

    // old coordinates
    int xOld;
    int yOld;

    // x and y position in overview
    int x;
    int y;
    
    // initialise
    struct Puzzle puzzle;
};



void init_game(struct Game* game)
{
    game->mode = LOOK_MODE;
    game->over = 0;
    game->x = 0;
    game->y = 0;
    return;
}


void print_debug_line(struct Game* game)
{
    move_cursor(0,21);
    printf
    (
        "mode {%d} | look {%d,%d}", 
        game->mode,
        game->x,
        game->y
    );
}


void debug_print(char* debugStr)
{
    move_cursor(0,22);
    printf(debugStr);
}


int centre_x(int coord)
{
    return LOOK_X + coord * (W-1) + (W+1)/2 - 1;
}


int centre_y(int coord)
{
    return LOOK_Y + coord * (H-1) + (H+1)/2 - 1;
}


int corner_x(int coord)
{
    return LOOK_X + coord * (W-1);
}


int corner_y(int coord)
{
    return LOOK_Y + coord * (H-1);
}


void draw_puzzle(struct Game* game)
{
    struct Puzzle puzzle = game->puzzle;
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            struct Cell cell = puzzle.cells[i][j];
            char value = cell.trueValue;
            int x = centre_x(i);
            int y = centre_y(j);
            if (value == '0')
            {
                if (cell.isMarked == 0 )
                {
                    draw_char(x, y, ' ');
                }
                else 
                {
                    draw_char(x, y, '*');
                }
            }
            else
            {
                draw_char(x, y, value);
            }
        }
    }
}


void draw_marking(struct Game* game)
{
    struct Puzzle puzzle = game->puzzle;
}


void draw_look_selected(int x, int y)
{
    draw_cell_thick(corner_x(x), corner_y(y));
}


void draw_stage(struct Game* game)
{
    //clear canvas
    clear();

    int mode = LOOK_MODE;

    //outline
    set_format(BRIGHT);
    draw_box_standard(0,0,80,21);
    set_format(RESET);

    //look grid
    draw_grid(LOOK_X,LOOK_Y,9);

    //markings grid
    draw_grid(MARK_X,MARK_Y,3);

    //answer box
    draw_cell(ANS_X,ANS_Y);

    //numbers
    draw_puzzle(&(game->puzzle));

    //draw box and colour based on mode
    if (mode == LOOK_MODE) {set_format(FG_GREEN);}
    else {set_format(FG_BLUE);}
    draw_look_selected(game->x,game->y);
    reset_format();

    //move to bottom
    move_cursor(0,21);

    //debug line
    print_debug_line(game);

}


void look(struct Game* game, char input)
{
    switch (input)
    {
        //movement
        case 'u':
            if (game->y > 0)
            {
                (game->y)--;
            }
            break;
        case 'd':
            if (game->y < 8)
            {
                (game->y)++;
            }
            break;
        case 'r':
            if (game->x < 8)
            {
                (game->x)++;
            }
            break;
        case 'l':
            if (game->x > 0)
            {
                (game->x)--;
            }
            break;
        //enters
        case 'e':
        break;
    }
}


//main loop function
void step(struct Game* game, char input)
{
    //set mode
    int mode = game->mode;
    int moved = 0;
    char string[100];
    debug_print(string);

    {
        switch (mode)
        {
            case LOOK_MODE:
            look(game, input);
            break;

        }
    }


    draw_stage(game);
}


