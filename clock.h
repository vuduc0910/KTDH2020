#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include "Shape_basic.h"
#define PI 3.14159265359

using namespace std;

void vekhung(int xc,int yc,int bk);
void kimgiay(int xc , int yc,int bk,int cl,int goc);
void kimphut(int xc , int yc, int bk,int cl,int goc);
void kimgio(int xc , int yc,int bk,int cl,int goc);
void vekim(int xc , int yc,int bk,float d1,float d2,float d3);
void gocdau(int gio,int phut,int giay, float &d1, float &d2, float &d3);
void draw_clock();
