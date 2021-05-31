#include <graphics.h>
#include <iostream>
#include <math.h>
#include "Shape_basic.h"
#include "data.h"

using namespace std;

void frame(){

	for(int i= 0 ; i<size ;i++)
	{
		for(int j =0 ; j< size ;j++)
		{
			int x = i*5;
			int y = j*5;
			paint_Box(x+x_frame,y+y_frame,x+x_frame+5,y+y_frame+5,WHITE,7);		
		}	
	}	
}

void draw_OXOY(int color)
{
	setcolor(color);
	line(x_frame-50, 5*size/2+ y_frame, x_frame+size*5+50, 5*size/2+ y_frame);  // hoanh
	line(5*size/2+ x_frame, y_frame-50, 5*size/2+x_frame, y_frame+size*5+50); 	// tung
	reset_color();
}
void draw_OXY(int color){
	
	if(color == WHITE)
	{
		draw_OXOY(color);
		draw_Triangle(x_frame-50,5*size/2+ y_frame,
								x_frame-25,5*size/2+ y_frame-10,
								x_frame-25,5*size/2+ y_frame+10,color);
		draw_Triangle(x_frame+size*5+50, 5*size/2+ y_frame,
								x_frame+size*5+25, 5*size/2+ y_frame-10,
								x_frame+size*5+25, 5*size/2+ y_frame+10,color);
								
		draw_Triangle(5*size/2+ x_frame-10, y_frame-25,
								5*size/2+ x_frame+10, y_frame-25,
								5*size/2+ x_frame, y_frame-50, color);
		draw_Triangle(5*size/2+x_frame-10, y_frame+size*5+25,
								5*size/2+x_frame+10, y_frame+size*5+25,
								5*size/2+x_frame, y_frame+size*5+50,color);
								
		settextstyle(3,0,2);						
		outtextxy(x_frame+size*5+25, 5*size/2+ y_frame+20,"  ");
		outtextxy(5*size/2+ x_frame + 20, y_frame-25,"  ");
		
		frame();
			
	}
	else{
		draw_OXOY(color);		
		draw_Triangle(x_frame-50,5*size/2+ y_frame,
								x_frame-25,5*size/2+ y_frame-10,
								x_frame-25,5*size/2+ y_frame+10,color);
		draw_Triangle(x_frame+size*5+50, 5*size/2+ y_frame,
								x_frame+size*5+25, 5*size/2+ y_frame-10,
								x_frame+size*5+25, 5*size/2+ y_frame+10,color);
								
		draw_Triangle(5*size/2+ x_frame-10, y_frame-25,
								5*size/2+ x_frame+10, y_frame-25,
								5*size/2+ x_frame, y_frame-50, color);
		draw_Triangle(5*size/2+x_frame-10, y_frame+size*5+25,
								5*size/2+x_frame+10, y_frame+size*5+25,
								5*size/2+x_frame, y_frame+size*5+50,color);
								
		settextstyle(3,0,2);						
		outtextxy(x_frame+size*5+25, 5*size/2+ y_frame+20,"X");
		outtextxy(5*size/2+ x_frame + 20, y_frame-25,"Y");
		outtextxy(5*size/2+ x_frame-5, 5*size/2+ y_frame-10,"O");
	}

	reset_color();
}


void clear_btn(int x,int y){
	outtextxy(x,y,"                                   	           ");
}

void clear_Screen()
{
	paint_Box(0,0,5*size+x_frame+240,getmaxy(),WHITE,0);
}

void interface_menu(){
	
	
	paint_Box(5*size+x_frame+250,y_frame+100,5*size+x_frame+600,y_frame+620,WHITE,0);
	
	// btn-Ve 2D
	paint_Box(5*size+x_frame+300,y_frame+150,5*size+x_frame+550,y_frame+200,WHITE,0);
	
	clear_btn(5*size+x_frame+300+10,y_frame+150+15);
	outtextxy(5*size+x_frame+300+10,y_frame+150+15,"Ve 2D");
	
	// btn-Ve 3D
	paint_Box(5*size+x_frame+300,y_frame+220,5*size+x_frame+550,y_frame+270,WHITE,0);
	
	clear_btn(5*size+x_frame+300+10,y_frame+220+15);
	outtextxy(5*size+x_frame+300+10,y_frame+220+15,"Ve 3D");
	

	paint_Box(5*size+x_frame+300,y_frame+290,5*size+x_frame+550,y_frame+340,WHITE,15);
	setcolor(15);
	outtextxy(5*size+x_frame+300+10,y_frame+290+15,"Vu Tru");
	reset_color();
	
	paint_Box(5*size+x_frame+350,y_frame+520,5*size+x_frame+500,y_frame+570,WHITE,15);
	setcolor(15);
	outtextxy(5*size+x_frame+350+50,y_frame+520+15,"Back");
	reset_color();
}
void interface_2D(){
	
	paint_Box(5*size+x_frame+300,y_frame+150,5*size+x_frame+550,y_frame+200,WHITE,0);	
	outtextxy(5*size+x_frame+300+10,y_frame+150+15,"Ve oto");
	
	paint_Box(5*size+x_frame+300,y_frame+220,5*size+x_frame+550,y_frame+270,WHITE,0);
	outtextxy(5*size+x_frame+300+10,y_frame+220+15,"Dong ho");
	
	paint_Box(5*size+x_frame+300,y_frame+290,5*size+x_frame+550,y_frame+340,WHITE,0);
	outtextxy(5*size+x_frame+300+10,y_frame+290+15,"Vu Tru");
	
	//btn back
	paint_Box(5*size+x_frame+350,y_frame+520,5*size+x_frame+500,y_frame+570,WHITE,0);
	outtextxy(5*size+x_frame+350+50,y_frame+520+15,"Back");
	
}
void interface_3D(){
	paint_Box(5*size+x_frame+300,y_frame+150,5*size+x_frame+550,y_frame+200,WHITE,0);
	outtextxy(5*size+x_frame+300+10,y_frame+150+15,"Hinh hop chu nhat");
	
	paint_Box(5*size+x_frame+300,y_frame+220,5*size+x_frame+550,y_frame+270,WHITE,0);
	outtextxy(5*size+x_frame+300+10,y_frame+220+15,"Hinh cau");
	
	//btn back
	paint_Box(5*size+x_frame+350,y_frame+520,5*size+x_frame+500,y_frame+570,WHITE,0);
	outtextxy(5*size+x_frame+350+50,y_frame+520+15,"Back");
}


