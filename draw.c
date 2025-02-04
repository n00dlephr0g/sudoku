#include <stdio.h>

void clear() {
    printf("\033[2J");
}


void move(int x, int y) {
    printf("\033[%d;%dH",y+1,x+1);
}


void draw_box(int x, int y, char horizontal, char vertical, char corner)
{
    move(x,y);
    printf("%c%c%c%c%c%c%c", corner, horizontal, horizontal, horizontal, horizontal, horizontal, corner);
    move(x,y+1);
    printf("%c     %c", vertical, vertical);
    move(x,y+2);
    printf("%c%c%c%c%c%c%c", corner, horizontal, horizontal, horizontal, horizontal, horizontal, corner);
}


void draw_thin_square(int x, int y) 
{
    char h = '-';
    char v = '|';
    char c = '+';
    draw_box(x, y, h, v, c);
}


void draw_thick_square(int x, int y)
{
    
}


void draw_grid(int x, int y)
{
    for (int j = y; j < y+9; j++)
    {
        for (int i = y; i < x+9; i++)
        {
            draw_thin_square(i*6,j*2);
        }
    }
}

