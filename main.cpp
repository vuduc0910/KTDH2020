#include <graphics.h>
#include <iostream>
#include <string>
#include <sstream>
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
	initwindow(1800, 950);
	setbkcolor(WHITE);		
    cleardevice();			//background screen BGI
		
	//frame();

	menu();
	//draw_clock();
	//draw_oto();
	//draw_Space();
	
	//draw_lapPhuong();
//	int a = (int)(581/5)*5;
//	cout<<a<<endl<<endl;
//	line_netDut(504,586,504,288,RED);
	//draw_elipse(500,500,100,50,BLUE);
	
	//draw_hinhCau();
	
	getch();
	closegraph();
	return 0;
	
	
}
