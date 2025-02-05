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
    struct Puzzle* puzzle;
    read_puzzle(puzzle, "puzzles/real1.txt");
}
