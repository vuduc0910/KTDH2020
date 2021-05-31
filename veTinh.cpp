#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include "Shape_basic.h"
#include "Giao_dien.h"
#include "oto.h"
#define PI 3.14159265359

void MT_TinhTien(float xtt, float ytt, float mttt[3][3])
{	
	mttt[0][0]= 1;
	mttt[0][1]= 0;
	mttt[0][2]= 0;
	
	mttt[1][0]= 0;
	mttt[1][1]= 1;
	mttt[1][2]= 0;
	
	mttt[2][0]= xtt;
	mttt[2][1]= ytt;
	mttt[2][2]= 1;
}

void MT_Quay(float mtq[3][3], float gocQuay){
	
	mtq[0][0]= cos(gocQuay);
	mtq[0][1]= sin(gocQuay);
	mtq[0][2]= 0;
	
	mtq[1][0]= -sin(gocQuay);
	mtq[1][1]= cos(gocQuay);
	mtq[1][2]= 0;
	
	mtq[2][0]= 0;
	mtq[2][1]= 0;
	mtq[2][2]= 1;
	
}

void MT_BienDoiTL(float mtdb[3][3],float x, float y){
	
	mtdb[0][0]= x;
	mtdb[0][1]= 0;
	mtdb[0][2]= 0;
	
	mtdb[1][0]= 0;
	mtdb[1][1]= y;
	mtdb[1][2]= 0;
	
	mtdb[2][0]= 0;
	mtdb[2][1]= 0;
	mtdb[2][2]= 1;
	
}

void MT_DoiXung_trucX(float mtdx[3][3]){
	
	mtdx[0][0]= 1;
	mtdx[0][1]= 0;
	mtdx[0][2]= 0;
	
	mtdx[1][0]= 0;
	mtdx[1][1]= -1;
	mtdx[1][2]= 0;
	
	mtdx[2][0]= 0;
	mtdx[2][1]= 0;
	mtdx[2][2]= 1;
	
}

void MT_DoiXung(float mtdb[3][3]){
	
	mtdb[0][0]= -1;
	mtdb[0][1]= 0;
	mtdb[0][2]= 0;
	
	mtdb[1][0]= 0;
	mtdb[1][1]= -1;
	mtdb[1][2]= 0;
	
	mtdb[2][0]= 0;
	mtdb[2][1]= 0;
	mtdb[2][2]= 1;
	
}


void updateMT_1x3(float truoc[3], float sau[3])
{
	for(int j = 0;j<3; j++)
	{
		truoc[j] = sau[j] ;
	}
}

void updateMT_3x3(float truoc[][3], float sau[][3])
{
	for(int i=0; i<3; i++)
	{
		for(int j = 0;j<3; j++)
		{
			truoc[i][j] = sau[i][j] ;
		}
	}
	
}

void NhanMT_1x3(float A[3],float B[3][3])
{
	float kq[3];
	for(int i=0;i<3;i++)
	{	
		kq[i]=0;
		for(int j=0; j<3; j++)
		{
			kq[i]= kq[i] + A[j]*B[j][i];
		}
	}
	updateMT_1x3(A,kq);
}

void nhanMT_3x3(float A[][3], float B[][3] )
{	
	float kq[3][3];
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<3;k++)
		{
			kq[i][k]=0;
			for(int j=0;j<3;j++)
			{
				kq[i][k] = kq[i][k]+A[i][j]*B[j][k];
			}
		}
	}
	updateMT_3x3(A,kq);
}


int Quay_quanh_1D(float G[3],float A[3], float gocQuay)
{
	float gocMoi = tinhgoc(gocQuay);
	float mtttO[3][3], mtttCB[3][3], mtq[3][3];
	
	MT_TinhTien(-G[0],-G[1],mtttO);
	MT_TinhTien(G[0],G[1],mtttCB);
	MT_Quay(mtq,gocMoi);
	
	NhanMT_1x3(A,mtttO);
	NhanMT_1x3(A,mtq);
	NhanMT_1x3(A,mtttCB);
	
}

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
	float TD_matTroi[3] = {x_frame+size*5/2, y_frame+size*5/2,1};
	float TD_traiDat[3] = {TD_matTroi[0]+250, TD_matTroi[1],1};
	float TD_VeTinh[3] =  {TD_traiDat[0]+100, TD_traiDat[1],1};
	float C[3] ={800,300,1};
	float A1[3] ={C[0]-10,C[1],1} , A2[3]= {C[0],C[1]-10,1},  A1_dx[3], A2_dx[3];
	
	updateMT_1x3(A1_dx,A1);
	updateMT_1x3(A2_dx,A2);
	
	DoiXung_1D(C,A1_dx); 
	DoiXung_1D(C,A2_dx);
	
	draw_HanhTinh(TD_matTroi[0],TD_matTroi[1], 80, YELLOW);	 //Mat Troi	
	
	setcolor(1);
	setfillstyle(SOLID_FILL, WHITE);
	circle(TD_matTroi[0]-35,TD_matTroi[1]-30,15);
	floodfill(TD_matTroi[0]-35+2,TD_matTroi[1]-30+2,1);
	reset_color();	
	
	setcolor(1);
	setfillstyle(SOLID_FILL, WHITE);
	circle(TD_matTroi[0]+35,TD_matTroi[1]-30,15);
	floodfill(TD_matTroi[0]+35+2,TD_matTroi[1]-30+2,1);
	reset_color();	
	
	line_5pixel(TD_matTroi[0]-25,TD_matTroi[1]+30,TD_matTroi[0]+20,TD_matTroi[1]+30, RED);
	put_5pixel(TD_matTroi[0]-30,TD_matTroi[1]+35,RED);
	put_5pixel(TD_matTroi[0]+30,TD_matTroi[1]+35,RED);
	
	
	float k=4, k2 = 0.25;
	
	float dem =1;
	int xm, ym;
	while(1)
	{	
		draw_HanhTinh(TD_traiDat[0],TD_traiDat[1], 25, LIGHTBLUE);	//Trai Dat
		draw_HanhTinh(TD_VeTinh[0],TD_VeTinh[1], 15, RED);	// Mat trang
		draw_Sao(A1, A2, A1_dx, A2_dx,MAGENTA);
		
		delay(20);
	
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
				
				return;
			}
		}
		
	}
	
}

