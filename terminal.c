#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

struct termios tty;

void hide_cursor() {printf("\033[?25h");}
void show_cursor() {printf("\033[?25l");}

void enter_input_mode() 
{
    tcgetattr(STDIN_FILENO, &tty);

    struct termios ntty = tty;

    ntty.c_lflag &= ~ICANON;
    ntty.c_lflag &= ~ECHO;
    ntty.c_cc[VMIN] = 1;
    ntty.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &ntty);

    hide_cursor();

    return;
}

void exit_input_mode()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);

    show_cursor();

    return;
}

char get_action()
{
    /*
    s: select
    b: back
    d: delete
    m: mark
    c: colour
    u: up
    d: down
    r: right
    l: left
    h: help
    */
    int c = getchar();
    // return input if input is number
    if (isdigit(c))
    {
        return (char)c;
    }
    // return appropriate char for recieved input
    switch (c)
    {
    case 10: //enter
        return 's';
    case 115: //s
        return 's';
    case 101: //e
        return 'm';
    case 109: //m
        return 'm';
    case 127: //backspace
        return 'd';
    case 99: //c
        return 'd';
    case 98: //b
        return 'b';
    case 113: //q
        return 'b';
    case 27:
        if (getchar() == 91)
        {
            switch (getchar())
            {
                case 65:
                return 'u';
                case 66:
                return 'd';
                case 67:
                return 'r';
                case 68:
                return 'l';
            }
        }
    case 106: //j
        return 'd';
    case 107: //k
        return 'u';
    case 108: //h
        return 'r';
    case 104: //l
        return 'l';
    default:
        return ' ';
    }
}