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


void draw_char(int x, int y, char c) {
    move_cursor(x, y);
    printf("%c", c);
}


void draw_horizontal_line(int x, int y, int l, char c)
{
    for (int i = x; i < x+l; i++)
    {
        draw_char(i,y,c);
    }
}


void draw_vertical_line(int x, int y, int l, char c)
{
    for (int i = y; i < y+l; i++)
    {
        draw_char(x,i,c);
    }
}


void draw_box(int x, int y, int w, int h, char horizontal, char vertical, char corner)
{
    int x2 = x+w-1;
    int y2 = y+h-1;
    //top line
    draw_horizontal_line(x, y, w, horizontal);
    //bottom line
    draw_horizontal_line(x, y2, w, horizontal);
    //left line
    draw_vertical_line(x, y, h, vertical);
    //right line
    draw_vertical_line(x2, y, h, vertical);
    // draw corners
    draw_char(x, y, corner);
    draw_char(x2, y, corner);
    draw_char(x, y2, corner);
    draw_char(x2, y2, corner);

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


void draw_cell_thick(int x, int y)
{
    char h = '=';
    char v = '#';
    char c = '@';
    draw_box(x, y, W, H, h, v, c);
}


void draw_selected(int x, int y)
{
    set_format(FG_GREEN);
    draw_cell_thick(x, y);
    reset_format();
}


void draw_grid(int x, int y, int size)
{
    int pixelSize = size*(W-1) + 1;
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            // printf("coord: (%d, %d)\n", i*6, j*2);
            draw_cell((i*(W-1))+x,(j*(H-1))+y);
        }
    }
}



