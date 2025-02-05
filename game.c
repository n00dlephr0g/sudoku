#include "puzzle.h"
#include "draw.c"

// define constants

#define LOOK_MODE 0 // looking around main grid
#define MARK_MODE 1 // marking cell
#define EDIT_MODE 2 // editiing answer


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


int step(struct Game* game, char input)
{
    return 0;
}
