#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include "Shape_basic.h"
#include "Giao_dien.h"
#define PI 3.14159265359

using namespace std;



void MTTT(float xtt, float ytt, float mttt[3][3])
{	
	float mt[3][3]=
	{
		{1, 0, 0},
		{0, 1, 0},
		{xtt, ytt, 1}	
	};
	for(int i=0 ;i<3;i++)
	{
		for(int j=0 ;j<3;j++)
		{
			mttt[i][j] = mt[i][j];
		}
	}
	
}
//ket qua tinh tien
int KQTT(float x, float y, float xtt,float ytt, float &xd , float &yd)
{
	// diem ban dau
	
	float ip[3]={x,y,1};
	float kq[3];
	float mttt[3][3];
	MTTT(xtt,ytt,mttt);
	
	for(int i=0;i<3;i++)
	{	
		kq[i]=0;
		for(int j=0; j<3; j++)
		{
			kq[i]= kq[i] + ip[j]*mttt[j][i];
		}
	}
	xd= kq[0];
	yd= kq[1];
	
}

// A cap mxn * B cap nxp = C cap mxp

void draw_oto()
{
	float d= 300;
	float x1 =300, x2 =250, x3=225, x4=195, x5=90, x6=90, x7=150, x8=225, x9=300;
	float y1 =y_frame+size*5-50, y2=y_frame+size*5-50, y3=y_frame+size*5-50, y4=y_frame+size*5-50, y5=y_frame+size*5-50,
	y6=y_frame+size*5-130, y7=y_frame+size*5-130, y8=y_frame+size*5-200, y9=y_frame+size*5-200;
	
	float xd2, xd3, xd4, xd5, xd6, xd7, xd8;
	float yd2, yd3, yd4, yd5, yd6, yd7, yd8;
	
	float i =0;
	int xm, ym;
	while(!kbhit())
	{
		
		KQTT(x2+i,y2,2*(d-x2),0,xd2,yd2);
		KQTT(x3+i,y3,2*(d-x3),0,xd3,yd3);
		KQTT(x4+i,y4,2*(d-x4),0,xd4,yd4);
		KQTT(x5+i,y5,2*(d-x5),0,xd5,yd5);
		KQTT(x6+i,y6,2*(d-x6),0,xd6,yd6);
		KQTT(x7+i,y7,2*(d-x7),0,xd7,yd7);
		KQTT(x8+i,y8,2*(d-x8),0,xd8,yd8);
		
		line_5pixel(x1+i,y1,x2+i,y2,1);
		draw_Circle(x3+i,y3,25,2);
		line_5pixel(x4+i,y4,x5+i,y5,1);
		line_5pixel(x5+i,y5,x6+i,y6+5,1);
		line_5pixel(x6+i,y6,x7+i,y7,1);
		line_5pixel(x7+i,y7,x8+i,y8+5,1);
		line_5pixel(x8+i,y8,x9+i,y9,1);
		
		line_5pixel(x1+i,y1,xd2-5,yd2,1);
		draw_Circle(xd3,yd3,25,2);
		line_5pixel(xd4,yd4,xd5-5,yd5,1);
		line_5pixel(xd5,yd5,xd6,yd6+5,1);
		line_5pixel(xd6-5,yd6,xd7,yd7,1);
		line_5pixel(xd7,yd7-5,xd8,yd8,1);
		line_5pixel(xd8,yd8,x9+i,y9,1);
		
		
		//xoa hinh cu
		if(i<300-5){
			
			delay(100);
			
			line_5pixel(x1+i,y1,x2+i,y2,15);
			draw_Circle(x3+i,y3,25,15);
			line_5pixel(x4+i,y4,x5+i,y5,15);
			line_5pixel(x5+i,y5,x6+i,y6+5,15);
			line_5pixel(x6+i,y6,x7+i,y7,15);
			line_5pixel(x7+i,y7,x8+i,y8+5,15);
			line_5pixel(x8+i,y8,x9+i,y9,15);
			
			line_5pixel(x1+i,y1,xd2-5,yd2,15);
			draw_Circle(xd3,yd3,25,15);
			line_5pixel(xd4,yd4,xd5-5,yd5,15);
			line_5pixel(xd5,yd5,xd6,yd6+5,15);
			line_5pixel(xd6-5,yd6,xd7,yd7,15);
			line_5pixel(xd7,yd7-5,xd8,yd8,15);
			line_5pixel(xd8,yd8,x9+i,y9,15);
			
			i+=10 ;
		}
		if(ismouseclick(WM_LBUTTONDBLCLK)){
        	getmouseclick(WM_LBUTTONDBLCLK,xm,ym);
        	if(5*size+x_frame+350 <xm && xm <5*size+x_frame+500 && 
				y_frame+520< ym && ym< y_frame+570)
			{
				setfillstyle(SOLID_FILL,YELLOW);
				floodfill(5*size+x_frame+350+2,y_frame+520+2,0);
				
				delay(200);
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(5*size+x_frame+350+2,y_frame+520+2,0);
				
				return;
			}
		}
		
	}
	
	
	
}

