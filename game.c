#include "puzzle.h"
#include "draw.c"

// define constants
#define LOOK_MODE 0 // looking around main grid
#define MARK_MODE 1 // marking cell
#define EDIT_MODE 2 // editiing answer

// screen coordinates
#define LOOK_OFFSET_X 3
#define LOOK_OFFSET_Y 1
#define MARK_OFFSET_X 63
#define MARK_OFFSET_Y 1


struct Game
{
    //initial mode
    int mode;
    // x and y position in overview
    int xLook;
    int yLook;

    // x and y position in marking
    int xMark;
    int yMark;
    
    struct Puzzle puzzle;
};


int mark_pos_to_index(int x, int y)
{
    return (y*3) + x;
}


void set_mode(struct Game* game, int modeNum)
{
    game->mode = modeNum;
    return;
}


void set_look_pos(struct Game* game, int x, int y)
{
    game->xLook = x;
    game->yLook = y;
    return;
}


void set_mark_pos(struct Game* game, int x, int y)
{
    game->xMark = x;
    game->yMark = y;
    return;
}


void init_game(struct Game* game)
{
    set_mode(game, LOOK_MODE);
    set_look_pos(game, 0, 0);
    set_mark_pos(game, 0, 0);
    return;
}


void draw_stage()
{
    //outline
    draw_box_standard(0,0,85,21);
    //look grid
    draw_grid(LOOK_OFFSET_X,1,9);
    //markings grid
    draw_grid(MARK_OFFSET_X,MARK_OFFSET_Y,3);
    //move to bottom
    move_cursor(0,21);
}



void step(struct Game* game, char input)
{
    
}


