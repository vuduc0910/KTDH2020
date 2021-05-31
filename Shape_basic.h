#include <graphics.h>
#include <iostream>
#include "data.h"
#include "Function_basic.h"
#include <math.h>
#define ROUND(a) (int)(a+0.5)
#define PI 3.14159265359

using namespace std;

void paint_Box(int x1, int y1, int x2, int y2, int col, int col_border);

void draw_Triangle(int x1, int y1, int x2, int y2, int x3, int y3,int color);

void put_5pixel(int x,int y, int col);

void line_5pixel(int x1,int y1,int x2,int y2, int col);

void line_netDut(int x1,int y1,int x2,int y2, int col);

void ve_8Diem(int xc, int yc, int x, int y, int color);

void draw_Circle(int xc,int yc,int r,int color);

void Ve4diem(int xc,int yc,int x, int y, int color);

void draw_elipse(int xc, int yc, int a,int b,int color);
