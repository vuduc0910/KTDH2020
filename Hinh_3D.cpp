#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include <string>
#include "Shape_basic.h"
#include "veTinh.h"

#define ROUND5(a) (int)(a/5)*5

using namespace std;

void update_MT1x4(float truoc[4], float sau[4])
{
	for(int j = 0;j<4; j++)
	{
		truoc[j] = sau[j] ;
	}
	//update_MT1x4(truoc,sau);
}

void update_MT4x4(float truoc[][4], float sau[][4])
{
	for(int i=0; i<4; i++)
	{
		for(int j = 0;j<4; j++)
		{
			truoc[i][j] = sau[i][j] ;
		}
	}
	
}
void MTD(float A[], float x,float y,float z)
{
	A[0] = x;
	A[1] = y;
	A[2] = z;
	A[3] = 1;
}
void MTTT_3D(float mttt[][4], float xtt,float ytt,float ztt)
{
	mttt[0][0]= 1;
	mttt[0][1]= 0;
	mttt[0][2]= 0;
	mttt[0][3]= 0;
	   
	mttt[1][0]= 0;
	mttt[1][1]= 1;
	mttt[1][2]= 0;
	mttt[1][3]= 0;
	   
	mttt[2][0]= 0;
	mttt[2][1]= 0;
	mttt[2][2]= 1;
	mttt[2][3]= 0;
	   
	mttt[3][0]= xtt;
	mttt[3][1]= ytt;
	mttt[3][2]= ztt;
	mttt[3][3]= 1;
	
}
void MTQx_3D(float mtqx[][4],float goc)
{

	mtqx[0][0]= 1;
	mtqx[0][1]= 0;
	mtqx[0][2]= 0;
	mtqx[0][3]= 0;
	   
	mtqx[1][0]= 0;
	mtqx[1][1]= cos(goc);
	mtqx[1][2]= sin(goc);
	mtqx[1][3]= 0;
	   
	mtqx[2][0]= 0;
	mtqx[2][1]= -sin(goc);
	mtqx[2][2]= cos(goc);
	mtqx[2][3]= 0;
	   
	mtqx[3][0]= 0;
	mtqx[3][1]= 0;
	mtqx[3][2]= 0;
	mtqx[3][3]= 1;
	
}
void MTQy_3D(float mtqy[][4],float goc)
{
	mtqy[0][0]= cos(goc);
	mtqy[0][1]= 0;
	mtqy[0][2]= -sin(goc);
	mtqy[0][3]= 0;
	   
	mtqy[1][0]= 0;
	mtqy[1][1]= 1;
	mtqy[1][2]= 0;
	mtqy[1][3]= 0;
	   
	mtqy[2][0]= sin(goc);
	mtqy[2][1]= 0;
	mtqy[2][2]= cos(goc);
	mtqy[2][3]= 0;
	   
	mtqy[3][0]= 0;
	mtqy[3][1]= 0;
	mtqy[3][2]= 0;
	mtqy[3][3]= 1;
	
}

void MTQz_3D(float mtqz[][4],float goc)
{
	
	mtqz[0][0]= cos(goc);
	mtqz[0][1]= sin(goc);
	mtqz[0][2]= 0;
	mtqz[0][3]= 0;
	   
	mtqz[1][0]= -sin(goc);
	mtqz[1][1]= cos(goc);
	mtqz[1][2]= 0;
	mtqz[1][3]= 0;
	   
	mtqz[2][0]= 0;
	mtqz[2][1]= 0;
	mtqz[2][2]= 1;
	mtqz[2][3]= 0;
	   
	mtqz[3][0]= 0;
	mtqz[3][1]= 0;
	mtqz[3][2]= 0;
	mtqz[3][3]= 1;
	
}
void nhanMT_3D(float A[4], float B[][4])

{	float kq[4];
	for(int i=0;i<4;i++)
	{	
		kq[i]=0;
		for(int j=0; j<4; j++)
		{
			kq[i]= kq[i] + A[j]*B[j][i];
		}
	}
	update_MT1x4(A,kq);
}

// p x m & n x p  (cot x hang)
void nhan2MT4x4_3D(float A[][4], float B[][4] )
{	
	float C[4][4];
	for(int i=0;i<4;i++)
	{
		for(int k=0;k<4;k++)
		{
			C[i][k]=0;
			for(int j=0;j<4;j++)
			{
				C[i][k]=C[i][k]+A[i][j]*B[j][k];
			}
		}
	}
	update_MT4x4(A,C);
}

void dinh_3D(float A[4],float B[4],float C[4],float D[4], 
				float A2[4],float B2[4],float C2[4],float D2[4], float cd, float cr, float cc)
{
	MTD(B, A[0]+cr,A[1],A[2]);
	MTD(C, A[0]+cr,A[1]+cd,A[2]);
	MTD(D, A[0],A[1]+cd,A[2]);
	
	MTD(A2, A[0],A[1],A[2]+cc);
	MTD(B2, A[0]+cr,A[1],A[2]+cc);
	MTD(C2, A[0]+cr,A[1]+cd,A[2]+cc);
	MTD(D2, A[0],A[1]+cd,A[2]+cc);
}

//MTTT ve O
void MTTT_ve_O(float A[4], int xtt, int ytt, int ztt)
{
	float MTTTO[4][4];
	MTTT_3D(MTTTO,-xtt,-ytt,-ztt);
	nhanMT_3D(A,MTTTO);
	
}

//MTTT comeback 
void MTTT_cb(float A[4],int xtt, int ytt, int ztt){
	
	float MT_cb[4][4];
	MTTT_3D(MT_cb,xtt,ytt,ztt);
	nhanMT_3D(A,MT_cb);
}


void PQ_1dtrucX_3D(float O[4],float A[4],float goc)
{
	goc = tinhgoc(goc);  //dv Radian
	float KQTT[4],MTQ[4][4],KQQTT[4];
	
	MTTT_ve_O(A,O[0],O[1],O[2]);
	MTQx_3D(MTQ,goc);
	nhanMT_3D(A,MTQ);
	MTTT_cb(A,O[0],O[1],O[2]);
}
void PQ_1dtrucY_3D(float O[4],float A[4],float goc)
{
	goc = tinhgoc(goc);  //dv Radian
	float KQTT[4],MTQ[4][4],KQQTT[4];
	
	MTTT_ve_O(A,O[0],O[1],O[2]);
	MTQy_3D(MTQ,goc);
	nhanMT_3D(A,MTQ);
	MTTT_cb(A,O[0],O[1],O[2]);
	
}

void PQ_1dtrucZ_3D(float O[4],float A[4],float goc)
{
	goc = tinhgoc(goc);  //dv Radian
	float KQTT[4],MTQ[4][4],KQQTT[4];
	
	MTTT_ve_O(A,O[0],O[1],O[2]);
	MTQz_3D(MTQ,goc);
	nhanMT_3D(A,MTQ);
	MTTT_cb(A,O[0],O[1],O[2]);
}


void MT_chieu3D(float MTC[4][4], float r)
{
	MTC[0][0]= 1;
	MTC[0][1]= 0;
	MTC[0][2]= 0;
	MTC[0][3]= 0;
	   
	MTC[1][0]= 0;
	MTC[1][1]= 1;
	MTC[1][2]= 0;
	MTC[1][3]= 0;
	   
	MTC[2][0]= 0;
	MTC[2][1]= 0;
	MTC[2][2]= 0;
	MTC[2][3]= 0;
	   
	MTC[3][0]= 0;
	MTC[3][1]= 0;
	MTC[3][2]= 0;
	MTC[3][3]= 1;
}
void chuyenDoi3D_2D(float A[3])
{
	float xa = float(A[0]-A[2]*sqrt(2)/2);
	float ya = float(A[1]-A[2]*sqrt(2)/2);
	
	A[0] = xa;
	A[1] = ya;
	A[2] = 1;
}


void draw_OXYZ()
{	
	
	setcolor(BLUE);
	line(x_frame+(size*5)/2,y_frame+(size*5)/2,x_frame+(size*5)/2,20);
	line(x_frame+(size*5)/2,y_frame+(size*5)/2,x_frame+(size*5)+55,y_frame+(size*5)/2);
	line(x_frame+(size*5)/2,y_frame+(size*5)/2,x_frame-25,y_frame+(size*5)+30);
	
	draw_Triangle(x_frame+(size*5)/2, 20, x_frame+(size*5)/2-10,40,
							x_frame+(size*5)/2+10,40,BLUE);
	draw_Triangle(x_frame+(size*5)+55,y_frame+(size*5)/2, x_frame+(size*5)+35,y_frame+(size*5)/2-10,
							x_frame+(size*5)+35,y_frame+(size*5)/2+10,BLUE);
	draw_Triangle(x_frame-25,y_frame+(size*5)+30,x_frame-25+5,y_frame+(size*5)+10,x_frame-25+25,y_frame+(size*5)+20,BLUE);
	
}

void draw_lapPhuong(){
	
	draw_OXYZ();
	
	float dai=300, rong= 300, cao= 300;
	float O[4] = {x_frame + (size*5)/2, y_frame+  (size*5)/2,0,1}, A[3]={200,0,200}, 
	
	B[3]= {A[0]+rong,A[1], A[2]},
	C[3]= {A[0]+rong,A[1], A[2]+dai},
	D[3]= {A[0],A[1], A[2]+dai},
	A2[3]= {A[0],A[1]+ cao, A[2]}, 
	B2[3]= {A[0]+rong,A[1]+ cao, A[2]},
	C2[3]= {A[0]+rong,A[1]+ cao, A[2]+dai}, 
	D2[3]= {A[0],A[1]+ cao, A[2]+dai};
	
	
	float mttt[3][3], mtdxx[3][3];
	
	chuyenDoi3D_2D(A);
	chuyenDoi3D_2D(B);
	chuyenDoi3D_2D(C);
	chuyenDoi3D_2D(D);
	
	chuyenDoi3D_2D(A2);
	chuyenDoi3D_2D(B2);
	chuyenDoi3D_2D(C2);
	chuyenDoi3D_2D(D2);
	
	MTTT(O[0],O[1], mttt);
	MT_DoiXung_trucX(mtdxx);	
	
	
	
	NhanMT_1x3(A,mtdxx);
	NhanMT_1x3(A,mttt);
	
	NhanMT_1x3(B,mtdxx);
	NhanMT_1x3(B,mttt);
	
	NhanMT_1x3(C,mtdxx);
	NhanMT_1x3(C,mttt);
	
	NhanMT_1x3(D,mtdxx);
	NhanMT_1x3(D,mttt);
	
	NhanMT_1x3(A2,mtdxx);
	NhanMT_1x3(A2,mttt);
	
	NhanMT_1x3(B2,mtdxx);
	NhanMT_1x3(B2,mttt);
	
	NhanMT_1x3(C2,mtdxx);
	NhanMT_1x3(C2,mttt);
	
	NhanMT_1x3(D2,mtdxx);
	NhanMT_1x3(D2,mttt);
	
	/*string TDD_A = "A("+to_string(A[0])+", "+to_string(A[1])+")";
	string TDD_B = "B("+to_string(B[0])+", "+to_string(B[1])+")";
	string TDD_C = "C("+to_string(C[0])+", "+to_string(C[1])+")";
	string TDD_D = "D("+to_string(D[0])+", "+to_string(D[1])+")";
	
	string TDD_A2 = "A2("+to_string(A2[0])+", "+to_string(A2[1])+")";
	string TDD_B2 = "B2("+to_string(B2[0])+", "+to_string(B2[1])+")";
	string TDD_C2 = "C2("+to_string(C2[0])+", "+to_string(C2[1])+")";
	string TDD_D2 = "D2("+to_string(D2[0])+", "+to_string(D2[1])+")";
	
	char* td_A = stringToChar(TDD_A);
	char* td_B = stringToChar(TDD_B);
	char* td_C = stringToChar(TDD_C);
	char* td_D = stringToChar(TDD_D);
	
	char* td_A2 = stringToChar(TDD_A2);
	char* td_B2 = stringToChar(TDD_B2);
	char* td_C2 = stringToChar(TDD_C2);
	char* td_D2 = stringToChar(TDD_D2);
	
	*/	
	outtextxy(A[0]+10, A[1]-10, "A");
	outtextxy(B[0]+10, B[1]-10, "B");
	outtextxy(C[0]+10, C[1]-10, "C");
	outtextxy(D[0]+10, D[1]-10, "D");
	
	outtextxy(A2[0]+10, A2[1]-10, "A2");
	outtextxy(B2[0]+10, B2[1]-10, "B2");
	outtextxy(C2[0]+10, C2[1]-10, "C2");
	outtextxy(D2[0]+10, D2[1]-10, "D2");
	
	cout<< "A (" << A[0]<<", " << A[1] <<")\n" ;
	cout<< "B (" << B[0]<<", " << B[1] <<")\n" ; 
	cout<< "C (" << C[0]<<", " << C[1] <<")\n" ; 
	cout<< "D (" << D[0]<<", " << D[1] <<")\n" ; 
	
	cout<< "A2 (" << A2[0]<<", " << A2[1] <<")\n" ;
	cout<< "B2 (" << B2[0]<<", " << B2[1] <<")\n" ; 
	cout<< "C2 (" << C2[0]<<", " << C2[1] <<")\n" ; 
	cout<< "D2 (" << D2[0]<<", " << D2[1] <<")\n" ; 
	
	line_netDut(ROUND5(A[0]), ROUND5(A[1]), ROUND5(A2[0]), ROUND5(A2[1]),RED);
	line_netDut(ROUND5(A[0]), ROUND5(A[1]), ROUND5(B[0]), ROUND5(B[1]),RED);
	line_netDut(ROUND5(A[0]), ROUND5(A[1]), ROUND5(D[0]), ROUND5(D[1]),RED);
	
	line_5pixel((int)C[0], (int)C[1], (int)C2[0], (int)C2[1],RED);
	line_5pixel((int)C[0], (int)C[1], (int)B[0], (int)B[1],RED);
	line_5pixel((int)C[0], (int)C[1], (int)D[0], (int)D[1],RED);
	
	line_5pixel((int)B2[0],	(int)B2[1], (int)C2[0], (int)C2[1],RED);
	line_5pixel((int)B2[0], (int)B2[1], (int)A2[0],(int)A2[1],RED);
	line_5pixel((int)B2[0], (int)B2[1], (int)B[0], (int)B[1],RED);
	
	line_5pixel((int)D2[0], (int)D2[1], (int)C2[0], (int)C2[1],RED);
	line_5pixel((int)D2[0], (int)D2[1],(int)A2[0],(int)A2[1],RED);
	line_5pixel((int)D2[0], (int)D2[1], (int)D[0], (int)D[1],RED);
	

		int xm, ym;
		while(1)
		{
			delay(0.1);
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
					
					outtextxy(A[0]+10, A[1]-10, "      ");
					outtextxy(B[0]+10, B[1]-10, "      ");
					outtextxy(C[0]+10, C[1]-10, "      ");
					outtextxy(D[0]+10, D[1]-10, "      ");
					
					outtextxy(A2[0]+10, A2[1]-10, "      ");
					outtextxy(B2[0]+10, B2[1]-10, "      ");
					outtextxy(C2[0]+10, C2[1]-10, "      ");
					outtextxy(D2[0]+10, D2[1]-10, "      ");
					
					return;
				}
			}
		}
}

void draw_hinhCau()
{
	draw_OXYZ();
	
	float O[4] = {x_frame + (size*5)/2, y_frame+  (size*5)/2,0,1},
	A[3]={200,0,200};
	int bk =200;
	float mttt[3][3], mtdxx[3][3];
	
	chuyenDoi3D_2D(A);
	
	
	MTTT(O[0],O[1], mttt);
	MT_DoiXung_trucX(mtdxx);	
	
	NhanMT_1x3(A,mtdxx);
	NhanMT_1x3(A,mttt);
	
	draw_Circle(A[0], A[1],bk,RED);
	draw_elipse(A[0], A[1],bk,bk/2,RED);
	
	put_5pixel(A[0],A[1],BLUE);
	outtextxy(A[0]+10,A[1]+10,"O");
	cout << "A (" <<A[0] <<", " << A[1] <<")";
	
	int xm, ym;
		while(1)
		{
			delay(0.1);
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
					
					outtextxy(A[0]+10,A[1]+10,"      ");
					
					return;
				}
			}
		}
	
	
}

