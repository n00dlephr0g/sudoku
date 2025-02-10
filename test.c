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
    enter_input_mode();
    while (1)
    {
        set_format(FG_CYAN);
        printf("%c\n",get_action());
    }
    exit_input_mode();
}
