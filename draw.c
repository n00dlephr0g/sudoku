#include <stdio.h>
#include <string.h>
#include "ascii.c"
#include "format.c"


#define W 7
#define H 3


void clear() {
    set_format(RESET);
    printf("\033[2J");
}


void move_cursor(int x, int y) {
    printf("\033[%d;%dH",y+1,x+1);
}


void draw_num(int x, int y, int value) {
    move_cursor(x+(W%2), y+(H%2));
    printf("%d", value);
}

void draw_line(int x, int y, int len, char centre, char edge)
{
    move_cursor(x,y);
    printf("%c",edge);
    for (int e=1;e<len;e++)
    {
        move_cursor(x+e,y);
        printf("%c",centre);
    }
    move_cursor(x+len-1,y);
    printf("%c",edge);
}

void draw_box(int x, int y, int w, int h, char horizontal, char vertical, char corner)
{
    draw_line(x, y, w, horizontal, corner);
    for (int j = 1; j < h-1;j++)
    {
        draw_line(x, y+j, w, ' ', vertical);
    }
    draw_line(x, y+h-1, w, horizontal, corner);
}


void draw_box_standard(int x, int y, int w, int h)
{
    draw_box(x,y,w,h,'-','|','+');
}


void draw_box_thick(int x, int y, int w, int h)
{
    draw_box(x,y,w,h,'=','#','@');
}


void draw_cell(int x, int y) 
{
    char h = '-';
    char v = '|';
    char c = '+';
    draw_box(x, y, W, H, h, v, c);
}


void draw_selected(int x, int y)
{
    char h = '=';
    char v = '#';
    char c = '@';
    set_format(FG_GREEN);
    draw_box(x, y, W, H, h, v, c);
    set_format(RESET);
}


void draw_grid(int x, int y, int size)
{
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            // printf("coord: (%d, %d)\n", i*6, j*2);
            draw_cell((i*(W-1))+x,(j*(H-1))+y);
        }
    }
}


void draw_stage()
{
    draw_box_standard(0,0,85,25);
    draw_grid(3,1,9);
    draw_grid(63,1,3);
}


