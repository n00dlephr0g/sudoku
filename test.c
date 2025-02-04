#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "input.c"
#include "draw.c"

int main() {
    clear();
    draw_box_standard(0,0,85,25);
    draw_grid(3,1,9);
    draw_grid(63,1,3);
    move(0,25);
    return 0;
}