#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include "Shape_basic.h"
#include "veTinh.h"
#define PI 3.14159265359

using namespace std;

void vekhung(float O[3],int bk){
     int d,x1,y1,x2,y2;
    // ve hinh tron
    draw_Circle((int)O[0],(int)O[1],bk,RED);
    d = 0;
    
    
    while(d<360){
    	
    	float X1[3] = {O[0]+bk,O[1],1};
    	float X2[3] = {O[0]+bk-30,O[1],1};
    	float X3[3] = {O[0]+bk-8,O[1],1};
    	float MTQ[3][3];
    	
    	Quay_quanh_1D(O,X1,d);
    	Quay_quanh_1D(O,X2,d);
    	Quay_quanh_1D(O,X3,d);
    	
    	if(d%30 ==0)
    	{
	        line_5pixel(X1[0],X1[1], X2[0],X2[1],1);
		}
		else{
			line_5pixel(X1[0],X1[1], X3[0],X3[1],2);	
		}
		d+=6;
        
    }
}

void kimgiay(float O[3],int bk,int cl,int goc){
    //ve kim giay co ban kinh bk, mau cl, goc bat dau
    float X1[3] = {O[0]+bk-70,O[1],1};
	float MTQ[3][3];
	Quay_quanh_1D(O,X1,goc);
	
    line_5pixel(X1[0],X1[1],O[0],O[1],cl);
} 
  
void kimphut(float O[3], int bk,int cl,int goc){
    //ve kim phut
    float X1[3] = {O[0]+bk-120,O[1],1};
	float MTQ[3][3];
	Quay_quanh_1D(O,X1,goc);
	
    line_5pixel(X1[0],X1[1],O[0],O[1],cl);
}
  
void kimgio(float O[3],int bk,int cl,int goc){
   //ve kim gio
    float X1[3] = {O[0]+bk-180,O[1],1};
	float MTQ[3][3];
	Quay_quanh_1D(O,X1,goc);
	
    line_5pixel(X1[0],X1[1],O[0],O[1],cl);
}
  
void vekim(float O[3],int bk,float d1,float d2,float d3){
	int xm, ym;
    while(!kbhit()){
    	
        kimgiay(O,bk,BLUE,d3); //ve kim giay ung voi goc d1
        if (d3==d2) kimphut(O,bk,RED,d2); // may ve cac net chong len nhau nen phai ve lai net cu da mat
        if (d3==d1) kimgio(O,bk,YELLOW,d1);
        kimphut(O,bk,RED,d2);
        if (d2==d1) kimgio(O,bk,RED,d1);
        kimgio(O,bk,YELLOW,d1);
        
        delay(1000);
        kimphut(O,bk,WHITE,d2); //xoa di net cu, ve net moi de tao di chuyen
        kimgiay(O,bk,WHITE,d3);
        kimgio(O,bk,WHITE,d1);
        d3+=6; d2+=0.1; d1+=1/120;
        
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
		draw_OXY(BLUE);
    }
}
void gocdau(int gio,int phut,int giay, float &d1, float &d2, float &d3){
	
    d3 = giay*6 + 270; // 12h ung voi goc 270
    d2 = phut*6 + giay*0.1 + 270;
    d1 = gio*30 + phut*0.5 + giay*1/120 +270;
    
}

void draw_clock()
{
	int bk = 300;
	int gio = 1,phut = 30 ,giay = 1;
    float d1=0,d2=0,d3=0;
    int xc = ((x_frame+(size*5)/2)/5)*5;
    int yc = ((y_frame+(size*5)/2)/5)*5;
    
    float O[3] = {xc,yc,1};
    
    gocdau(gio,phut,giay,d1,d2,d3);
    vekhung(O,bk);
    vekim(O,bk,d1,d2,d3);
}
