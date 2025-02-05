#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>

struct termios tty;

void hide_cursor() {printf("\e[?25h");}
void show_cursor() {printf("\e[?25l");}

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
    e: edit
    c: colour
    u: up
    d: down
    r: right
    l: left
    h: help
    */
    int c = getchar();
    if (isdigit(c))
    {
        return (char)c;
    }
    switch (c)
    {
    case 10: //enter
        return 's';
    case 101: //e
        return 'e';
    case 127: //backspace
        return 'd';
    case 99: //c
        return 'd';
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
        else
        {
            return ' ';
        }
    case 106: //j
        return 'u';
    case 107: //k
        return 'd';
    case 108: //h
        return 'r';
    case 104: //l
        return 'l';
    default:
        return ' ';
    }
}