#include <ctype.h>
#include "puzzle.h"
#include "draw.c"
#include "menu.c"
#include "logic.c"

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

#define CURRENTCELL game->puzzle.cells[game->x][game->y]

const char EMPTY_MARK[9] = { 0 };


struct Game
{
    // current game mode
    int modeOld;
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
    game->modeOld = LOOK_MODE;
    game->over = 0;
    game->xOld = 0;
    game->yOld = 0;
    game->x = 0;
    game->y = 0;
    return;
}


void print_debug_line(struct Game* game, char input)
{
    move_cursor(0,21);
    struct Cell cell = CURRENTCELL;
    printf
    (
        "mode {%d} | look {%d,%d} | key {%c}\ntrueValue {%c} | state {%d} | answer {%c}", 
        game->mode,
        game->x,
        game->y,
        input,
        cell.trueValue,
        cell.state,
        cell.answer
    );
}


void print_debug_line_markings(struct Game* game)
{
    move_cursor(0,22);
    int* markings = CURRENTCELL.markings;
    printf
    (
        "%d %d %d %d %d %d %d %d %d ", 
        markings[0],
        markings[1],
        markings[2],
        markings[3],
        markings[4],
        markings[5],
        markings[6],
        markings[7],
        markings[8]
    );
}


void debug_print(char* debugStr)
{
    move_cursor(0,22);
    printf(debugStr);
}


int look_centre_x(int coord)
{
    return LOOK_X + coord * (W-1) + (W+1)/2 - 1;
}


int look_centre_y(int coord)
{
    return LOOK_Y + coord * (H-1) + (H+1)/2 - 1;
}


int mark_centre_x(int coord)
{
    return MARK_X + coord * (W-1) + (W+1)/2 - 1;
}


int mark_centre_y(int coord)
{
    return MARK_Y + coord * (H-1) + (H+1)/2 - 1;
}


int corner_x(int coord)
{
    return LOOK_X + coord * (W-1);
}


int corner_y(int coord)
{
    return LOOK_Y + coord * (H-1);
}


void draw_ans(struct Game* game)
{

    draw_cell(ANS_X,ANS_Y);
}


void draw_puzzle(struct Game* game)
{
    struct Puzzle puzzle = game->puzzle;
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            struct Cell cell = game->puzzle.cells[i][j];
            //initialise coordinates
            int x = look_centre_x(i);
            int y = look_centre_y(j);

            //initialise value
            char value = get_cell_value(&cell);

            //draw based on type
            if (cell.trueValue != '0')
            {
                set_format(FG_YELLOW);
                draw_char(x, y, value);
                reset_format();
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
    int* markings = CURRENTCELL.markings;

    for (int n = 0; n < 9; n++)
    {
        char c;
        int marking = markings[n];
        int i = n%3;
        int j = n/3;
        if (marking == 1)
        {
            c = '0'+(n+1);
        }
        else
        {
            c = ' ';
        }
        draw_char(
            mark_centre_x(i),
            mark_centre_y(j),
            c
        );
    }
}


void draw_look_selected(int x, int y)
{
    draw_cell_thick(corner_x(x), corner_y(y));
}


void draw_update(struct Game* game)
{
    int mode = game->mode;
    
    //OVERRIDE OLD
    draw_cell(
        corner_x(game->xOld),
        corner_y(game->yOld)
    );


    //DRAW UPDATE
    //numbers
    draw_puzzle(game);

    //pencil marks
    draw_marking(game);

    //draw boxes
    switch (mode)
    {
        case LOOK_MODE:
            set_format(FG_GREEN);
            draw_look_selected(game->x,game->y);
            reset_format();
            break;
        case MARK_MODE:
            set_format(FG_BLUE);
            draw_look_selected(game->x,game->y);
            reset_format();
            break;
        case EDIT_MODE:
            set_format(FG_BLUE);
            draw_look_selected(game->x,game->y);
            set_format(FG_GREEN);
            draw_cell_thick(ANS_X, ANS_Y);
            reset_format();
            break;
    }


    move_cursor(0,21);
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

    //move to bottom
    move_cursor(0,21);

    //numbers and markings
    draw_update(game);
    


}


void look(struct Game* game, char input)
{
    game->xOld = game->x;
    game->yOld = game->y;
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
        //edit
        case 'm':
            game->mode = MARK_MODE;
            break;
        case 's':
            game->mode = EDIT_MODE;
            break;
        case 'b':
            game->over = 1;
    }
}


void mark(struct Game* game, char input)
{
    if (isdigit(input))
    {
        int index = (int)(input - '1');
        CURRENTCELL.markings[index] ^= 1;
    }
    switch (input)
    {
        case 'b':
            game->mode = LOOK_MODE;
    }
}


//main loop function
int step(struct Game* game, char input)
{
    //set mode
    int mode = game->mode;

    //execute function based on mode
    switch (mode)
    {
        case LOOK_MODE:
            look(game, input);
            break;
        case MARK_MODE:
            mark(game, input);
            break;
    }

    //exit if game over
    if (game->over)
    {
        return 1;
    }

    draw_update(game);
    //debug line
    print_debug_line(game, input);
    return 0;
}


