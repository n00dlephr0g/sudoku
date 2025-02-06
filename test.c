#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "terminal.c"
#include "game.c"
#include "parser.c"
#include "puzzle.h"



int main() {
    clear();
    set_format(FG_BLUE);
    draw_cell(0,0);
    set_format(FG_RED);
    draw_cell(10,0);
    set_format(FG_GREEN);
    draw_cell_thick(20,0);
}
