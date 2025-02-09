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
    draw_char(1,1,(char)4);
}
