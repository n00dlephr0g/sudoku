#include "puzzle.h"
#include "draw.h"

// define constants

#define LOOK_MODE = 0; // looking around main grid
#define MARK_MODE = 1; // marking cell
#define EDIT_MODE = 2; // editiing answer


struct Game
{
    //initial mode
    int mode = LOOK_MODE;
    // x and y position in overview
    int xLook = 0;
    int yLook = 0;
    
    struct Puzzle puzzle;
}


int step()
{
    return 0;
}
