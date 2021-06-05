#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include "Shape_basic.h"
#include "Giao_dien.h"
#include "oto.h"
#include "Function_basic.h"
#define PI 3.14159265359

void draw_HanhTinh(float x, float y,float r,float color)
{
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	draw_Circle(x,y,r,color);
	floodfill(x+2,y+2,color);
	reset_color();	
}

void BienDoiTL_1D(float G[3], float A[3],float x, float y)
{
	float mttt_veO[3][3], mttt_cb[3][3], mtbdtl[3][3];
	
	MT_TinhTien(-G[0],-G[1],mttt_veO);
	MT_TinhTien(G[0],G[1],mttt_cb);
	MT_BienDoiTL(mtbdtl,x,y);
	
	NhanMT_1x3(A,mttt_veO);
	NhanMT_1x3(A,mtbdtl);
	NhanMT_1x3(A,mttt_cb);
	
}

void DoiXung_1D(float G[3], float A[3])
{
	
	float mttt_veO[3][3], mttt_cb[3][3], mtdx[3][3];
	
	MT_TinhTien(-G[0],-G[1],mttt_veO);
	MT_TinhTien(G[0],G[1],mttt_cb);
	MT_DoiXung(mtdx);
	
	NhanMT_1x3(A,mttt_veO);
	NhanMT_1x3(A,mtdx);
	NhanMT_1x3(A,mttt_cb);
}

void draw_Sao(float A1[3], float A2[3],float A3[3], float A4[3], int color){
	
	
	line_5pixel(A1[0]-5,A1[1], A3[0],A3[1],color);
	line_5pixel(A2[0],A2[1]-5, A4[0],A4[1],color);
	
}

void draw_Space()
{
	
	paint_Box(1070,700,1700,getmaxy()-10,WHITE,RED);
	
	float TD_matTroi[3] = {x_frame+size*5/2, y_frame+size*5/2,1};
	float TD_traiDat[3] = {TD_matTroi[0]+280, TD_matTroi[1],1};
	float TD_VeTinh[3] =  {TD_traiDat[0]+100, TD_traiDat[1],1};
	float C[3] ={850,300,1};
	float A1[3] ={C[0]-10,C[1],1} , A2[3]= {C[0],C[1]-10,1},  A1_dx[3], A2_dx[3];
	
	
	draw_HanhTinh(TD_matTroi[0],TD_matTroi[1], 80, YELLOW);	 //Mat Troi	
	
	string tdMT = "Mat_troi ("+floatToString(TD_matTroi[0])+ ","+floatToString(TD_matTroi[1])+")";
	outtextxy(1070 +15,700+10, stringToChar(tdMT));
	
	string tdS = "Sao ("+floatToString(C[0])+ ","+floatToString(C[1])+")";
	outtextxy(1070 +15,700+85, stringToChar(tdS));
		
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	circle(TD_matTroi[0]-35,TD_matTroi[1]-30,15);
	floodfill(TD_matTroi[0]-35+2,TD_matTroi[1]-30+2,WHITE);
	
	setfillstyle(SOLID_FILL,WHITE);
	circle(TD_matTroi[0]+35,TD_matTroi[1]-30,15);
	floodfill(TD_matTroi[0]+35+2,TD_matTroi[1]-30+2,WHITE);
	
	line_5pixel(TD_matTroi[0]-25,TD_matTroi[1]+30,TD_matTroi[0]+20,TD_matTroi[1]+30, RED);
	
	settextstyle(3,0,2);
	
	updateMT_1x3(A1_dx,A1);
	updateMT_1x3(A2_dx,A2);
	
	DoiXung_1D(C,A1_dx); 
	DoiXung_1D(C,A2_dx);
	
	
	float k=4, k2 = 0.25;
	
	float dem =1;
	int xm, ym;
	while(1)
	{	
		
	
		draw_HanhTinh(TD_traiDat[0],TD_traiDat[1], 25, LIGHTBLUE);	//Trai Dat
		string tdTD = "Trai_Dat ("+floatToString((int)TD_traiDat[0])+ ","+floatToString((int)TD_traiDat[1])+")";
		outtextxy(1070 +15,700+35, stringToChar(tdTD));
		
		draw_HanhTinh(TD_VeTinh[0],TD_VeTinh[1], 15, RED);	// Mat trang
		string tdMTr = "Mat_Trang ("+floatToString((int)TD_VeTinh[0])+ ","+floatToString((int)TD_VeTinh[1])+")";
		outtextxy(1070 +15,700+60, stringToChar(tdMTr));
		
		draw_Sao(A1, A2, A1_dx, A2_dx,MAGENTA);
		
		delay(20);
		outtextxy(1070 +90,700+35, "                      ");
		outtextxy(1070 +115,700+60, "                      ");
		
		draw_HanhTinh(TD_VeTinh[0],TD_VeTinh[1], 15, WHITE);	// xoa Mat trang	
		draw_HanhTinh(TD_traiDat[0],TD_traiDat[1], 25, WHITE);	//xoa Trai Dat
		
		float A[2]={TD_traiDat[0],TD_traiDat[1]};
		float mttt[3][3];
		Quay_quanh_1D(TD_matTroi,TD_traiDat,1);
		MT_TinhTien(TD_traiDat[0]-A[0],TD_traiDat[1]-A[1],mttt);
		NhanMT_1x3(TD_VeTinh,mttt);
		Quay_quanh_1D(TD_traiDat,TD_VeTinh,-10);
		
		draw_Sao(A1, A2, A1_dx, A2_dx,WHITE);
		
		if(dem==1)
		{
			BienDoiTL_1D(C,A1,k,k);
			BienDoiTL_1D(C,A2,k,k);
			BienDoiTL_1D(C,A1_dx,k,k);
			BienDoiTL_1D(C,A2_dx,k,k);
			dem++;
		}
		else if(dem==2)
		{
			BienDoiTL_1D(C,A1,k2,k2);
			BienDoiTL_1D(C,A2,k2,k2);
			BienDoiTL_1D(C,A1_dx,k2,k2);
			BienDoiTL_1D(C,A2_dx,k2,k2);
			dem--;
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
				
				outtextxy(TD_matTroi[0],TD_matTroi[1],"             ");
				for(int i = 10; i<100; i+=25)
				{
					outtextxy(1070 +15,700+i,"                                       ");
				}
				
				paint_Box(1070,700,1700,getmaxy()-10,WHITE,WHITE);
				return;
			}
		}
		
		draw_OXY(BLUE);
		
	}
	
}

