#include <graphics.h>
#include <iostream>
#include "Giao_dien.h"
#include "data.h"
#include "clock.h"
#include "xu_li.h"
#include "oto.h"
#include "Hinh_3D.h"
#include "veTinh.h"
#include "Shape_basic.h"
using namespace std;
int main(){
	
	int gd = DETECT, gm;
	initwindow(1500, 900);
	setbkcolor(WHITE);		
    cleardevice();		
	//frame();
	menu();
	//draw_clock();
	//draw_oto();
	//draw_Space();
	//draw_lapPhuong();	
	//draw_hinhCau();
	getch();
	closegraph();
	return 0;
	
	
}
