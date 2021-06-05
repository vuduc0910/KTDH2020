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
	float xa = float(A[0]-(A[2]*sqrt(2))/2);
	float ya = float(A[1]-(A[2]*sqrt(2))/2);
	
	A[0] = xa;
	A[1] = ya;
	A[2] = 1;
}


void nhap_GT_HinhHop(int xcl, int ycl,string &A_x, string &A_y, string &A_z, string &Dai, string &Rong, string &Cao)
{
	
	int vt=0;
	
	if(1070 +450 < xcl && 700+5 < ycl && xcl< 1070 +550 && ycl<700+30)
	{
		paint_Box(1070 +450,700+5,1070 +550,700+30,CYAN,RED);
		if(!A_x.empty())
		{
			outtextxy(1070 +460,700+10,stringToChar(A_x));
		}
		vt =1;
	}
	else if(1070 +450 < xcl && 700+40 < ycl && xcl< 1070 +550 && ycl<700+65)
	{
		paint_Box(1070 +450,700+40,1070 +550,700+65,CYAN,RED);
		if(!A_y.empty())
		{
			outtextxy(1070 +460,700+45,stringToChar(A_y));
		}
		vt =2;
	}
	else if(1070 +450 < xcl && 700+75 < ycl && xcl< 1070 +550 && ycl<700+100)
	{
		paint_Box(1070 +450,700+75,1070 +550,700+100,CYAN,RED);
		if(!A_z.empty())
		{
			outtextxy(1070 +460,700+80,stringToChar(A_z));
		}
		vt =3;
	}
	else if(1070 +450 < xcl && 700+110 < ycl && xcl< 1070 +550 && ycl<700+135)
	{
		paint_Box(1070 +450,700+110,1070 +550,700+135,CYAN,RED);
		if(!Dai.empty())
		{
			outtextxy(1070 +460,700+115,stringToChar(Dai));
		}
		vt =4;
	}
	else if(1070 +450 < xcl && 700+145 < ycl && xcl< 1070 +550 && ycl<700+170)
	{
		paint_Box(1070 +450,700+145,1070 +550,700+170,CYAN,RED);
		if(!Rong.empty())
		{
			outtextxy(1070 +460,700+150,stringToChar(Rong));
		}
		vt =5;
	}
	else if(1070 +450 < xcl && 700+180 < ycl && xcl< 1070 +550 && ycl<700+205)
	{
		paint_Box(1070 +450,700+180,1070 +550,700+205,CYAN,RED);
		if(!Cao.empty())
		{
			outtextxy(1070 +460,700+185,stringToChar(Cao));
		}
		vt =6;
	}
	
	while(1)
	{
		switch(vt)
		{
			case 1:
				{
					char s = getch();
					int ascii_value = s;
					if(ascii_value==13)
					{
						paint_Box(1070 +450,700+5,1070 +550,700+30,WHITE,RED);
						outtextxy(1070 +460,700+10,stringToChar(A_x));
						vt =0;
					}
					else if(ascii_value == 8 && !A_x.empty())
					{
						A_x.erase(A_x.begin() + A_x.length()-1)	;
						paint_Box(1070 +450,700+5,1070 +550,700+30,CYAN,RED);
						outtextxy(1070 +460,700+10,stringToChar(A_x));
					}
					else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
						if(A_x.length()<4)
						{
							A_x = A_x+s;
						}
						settextstyle(3,0,1);
						outtextxy(1070 +460,700+10,stringToChar(A_x));
					}
				}
				break;
			case 2:
			{
				char s = getch();
				int ascii_value = s;
				if(ascii_value==13)
				{
					paint_Box(1070 +450,700+40,1070 +550,700+65,WHITE,RED);
					outtextxy(1070 +460,700+45,stringToChar(A_y));
					vt =0;
				}
				else if(ascii_value == 8 && !A_y.empty())
				{
					A_y.erase(A_y.begin() + A_y.length()-1)	;
					paint_Box(1070 +450,700+40,1070 +550,700+65,CYAN,RED);
					outtextxy(1070 +460,700+45,stringToChar(A_y));
				}
				else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
					if(A_y.length()<4)
					{
						A_y = A_y+s;
					}
					settextstyle(3,0,1);
					outtextxy(1070 +460,700+45,stringToChar(A_y));
				}
			}
				break;
			case 3:
			{
				char s = getch();
				int ascii_value = s;
				if(ascii_value==13)
				{
					paint_Box(1070 +450,700+75,1070 +550,700+100,WHITE,RED);
					outtextxy(1070 +460,700+80,stringToChar(A_z));
					vt =0;
				}
				else if(ascii_value == 8 && !A_z.empty())
				{
					A_z.erase(A_z.begin() + A_z.length()-1)	;
					paint_Box(1070 +450,700+75,1070 +550,700+100,CYAN,RED);
					outtextxy(1070 +460,700+80,stringToChar(A_z));
				}
				else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
					if(A_z.length()<4)
					{
						A_z = A_z+s;
					}
					settextstyle(3,0,1);
					outtextxy(1070 +460,700+80,stringToChar(A_z));
				}
			}
				break;	
			case 4:
			{
				char s = getch();
					int ascii_value = s;
					if(ascii_value==13)
					{
						paint_Box(1070 +450,700+110,1070 +550,700+135,WHITE,RED);
						outtextxy(1070 +460,700+115,stringToChar(Dai));
						vt =0;
					}
					else if(ascii_value == 8 && !Dai.empty())
					{
						Dai.erase(Dai.begin() + Dai.length()-1)	;
						paint_Box(1070 +450,700+110,1070 +550,700+135,CYAN,RED);
						outtextxy(1070 +460,700+115,stringToChar(Dai));
					}
					else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
						if(Dai.length()<4)
						{
							Dai = Dai+s;
						}
						settextstyle(3,0,1);
						outtextxy(1070 +460,700+115,stringToChar(Dai));
					}
			}
				break;	
			case 5:
			{
				char s = getch();
					int ascii_value = s;
					if(ascii_value==13)
					{
						paint_Box(1070 +450,700+145,1070 +550,700+170,WHITE,RED);
						outtextxy(1070 +460,700+150,stringToChar(Rong));
						vt =0;
					}
					else if(ascii_value == 8 && !Rong.empty())
					{
						Rong.erase(Rong.begin() + Rong.length()-1)	;
						paint_Box(1070 +450,700+145,1070 +550,700+170,CYAN,RED);
						outtextxy(1070 +460,700+150,stringToChar(Rong));
					}
					else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
						if(Rong.length()<4)
						{
							Rong = Rong+s;
						}
						settextstyle(3,0,1);
						outtextxy(1070 +460,700+150,stringToChar(Rong));
					}
			}
				break;	
			case 6:
			{
				char s = getch();
					int ascii_value = s;
					if(ascii_value==13)
					{
						paint_Box(1070 +450,700+180,1070 +550,700+205,WHITE,RED);
						outtextxy(1070 +460,700+185,stringToChar(Cao));
						vt =0;
					}
					else if(ascii_value == 8 && !Cao.empty())
					{
						Cao.erase(Cao.begin() + Cao.length()-1)	;
						paint_Box(1070 +450,700+180,1070 +550,700+205,CYAN,RED);
						outtextxy(1070 +460,700+185,stringToChar(Cao));
					}
					else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
						if(Cao.length()<4)
						{
							Cao = Cao+s;
						}
						settextstyle(3,0,1);
						outtextxy(1070 +460,700+185,stringToChar(Cao));
					}
			}
				break;			
			default:
				vt=0;
				break;	
		}
		if(vt==0)
		{
			break;
		}
	}
	
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

void draw_Shape(float A[3],float B[3],float C[3],float D[3],float A2[3],float B2[3],float C2[3],float D2[3],
				float dai, float rong, float cao,int color)
{
	draw_OXYZ();
	
	float O[4] = {x_frame + (size*5)/2, y_frame+  (size*5)/2,0,1};
	
	B[0] =A[0]+rong, B[1]=A[1], B[2] = A[2];
	C[0] =A[0]+rong, C[1]=A[1], C[2] = A[2]+dai;
	D[0] =A[0], 	 D[1]=A[1], D[2] = A[2]+dai;
	
	A2[0] =A[0], 	  A2[1]=A[1]+ cao, A2[2] = A[2] ;
	B2[0] =A[0]+rong, B2[1]=A[1]+ cao, B2[2] = A[2] ;
	C2[0] =A[0]+rong, C2[1]=A[1]+ cao, C2[2] = A[2]+dai ;
	D2[0] =A[0],      D2[1]=A[1]+ cao, D2[2] = A[2]+dai ;
	
	
	string tdA = "A ("+floatToString(A[0])+ ","+floatToString(A[1])+","+floatToString(A[2])+")";
	outtextxy(1070 +15,700+10, stringToChar(tdA));
	string tdB = "B ("+floatToString(B[0])+ ","+floatToString(B[1])+","+floatToString(B[2])+")";
	outtextxy(1070 +15,700+35, stringToChar(tdB));
	string tdC = "C ("+floatToString(C[0])+ ","+floatToString(C[1])+","+floatToString(C[2])+")";
	outtextxy(1070 +15,700+60, stringToChar(tdC));
	string tdD = "D ("+floatToString(D[0])+ ","+floatToString(D[1])+","+floatToString(D[2])+")";
	outtextxy(1070 +15,700+85, stringToChar(tdD));
	
	string tdA2 = "A2 ("+floatToString(A2[0])+ ","+floatToString(A2[1])+","+floatToString(A2[2])+")";
	outtextxy(1070 +15,700+110, stringToChar(tdA2));
	string tdB2 = "B2 ("+floatToString(B2[0])+ ","+floatToString(B2[1])+","+floatToString(B2[2])+")";
	outtextxy(1070 +15,700+135, stringToChar(tdB2));
	string tdC2 = "C2 ("+floatToString(C2[0])+ ","+floatToString(C2[1])+","+floatToString(C2[2])+")";
	outtextxy(1070 +15,700+160, stringToChar(tdC2));
	string tdD2 = "D2 ("+floatToString(D2[0])+ ","+floatToString(D2[1])+","+floatToString(D2[2])+")";
	outtextxy(1070 +15,700+185, stringToChar(tdD2));
	
	
	float mttt[3][3], mtdxx[3][3];
	
	chuyenDoi3D_2D(A);
	chuyenDoi3D_2D(B);
	chuyenDoi3D_2D(C);
	chuyenDoi3D_2D(D);
	
	chuyenDoi3D_2D(A2);
	chuyenDoi3D_2D(B2);
	chuyenDoi3D_2D(C2);
	chuyenDoi3D_2D(D2);
	
	MT_TinhTien(O[0],O[1], mttt);
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
	
	
	outtextxy(A[0]+10, A[1]-10, "A");
	outtextxy(B[0]+10, B[1]-10, "B");
	outtextxy(C[0]+10, C[1]-10, "C");
	outtextxy(D[0]+10, D[1]-10, "D");
	
	outtextxy(A2[0]+10, A2[1]-10, "A2");
	outtextxy(B2[0]+10, B2[1]-10, "B2");
	outtextxy(C2[0]+10, C2[1]-10, "C2");
	outtextxy(D2[0]+10, D2[1]-10, "D2");
	
	 
	line_netDut(ROUND5(A[0]), ROUND5(A[1]), ROUND5(A2[0]), ROUND5(A2[1]),color);
	line_netDut(ROUND5(A[0]), ROUND5(A[1]), ROUND5(B[0]), ROUND5(B[1]),color);
	line_netDut(ROUND5(A[0]), ROUND5(A[1]), ROUND5(D[0]), ROUND5(D[1]),color);
	
	line_5pixel((int)C[0], (int)C[1], (int)C2[0], (int)C2[1],color);
	line_5pixel((int)C[0], (int)C[1], (int)B[0], (int)B[1],color);
	line_5pixel((int)C[0], (int)C[1], (int)D[0], (int)D[1],color);
	
	line_5pixel((int)B2[0],	(int)B2[1], (int)C2[0], (int)C2[1],color);
	line_5pixel((int)B2[0], (int)B2[1], (int)A2[0],(int)A2[1],color);
	line_5pixel((int)B2[0], (int)B2[1], (int)B[0], (int)B[1],color);
	
	line_5pixel((int)D2[0], (int)D2[1], (int)C2[0], (int)C2[1],color);
	line_5pixel((int)D2[0], (int)D2[1],(int)A2[0],(int)A2[1],color);
	line_5pixel((int)D2[0], (int)D2[1], (int)D[0], (int)D[1],color);
	
}
void draw_lapPhuong(){
	
	
	paint_Box(1070,700,1700,getmaxy()-10,WHITE,RED);
	
	string A_x, A_y, A_z, Dai, Rong, Cao;
	
	float dai= 300, rong= 300, cao= 300;
	float A[3]={100,0,100}, B[3], C[3], D[3], A2[3], B2[3], C2[3], D2[3] ;
	
	draw_Shape(A,B,C,D,A2,B2,C2,D2,dai,rong,cao,RED);
	
	outtextxy(1070 +400,700+10, "A_x:");
	paint_Box(1070 +450,700+5,1070 +550,700+30,WHITE,RED);
	
	outtextxy(1070 +400,700+45, "A_y:");
	paint_Box(1070 +450,700+40,1070 +550,700+65,WHITE,RED);
	
	outtextxy(1070 +400,700+80, "A_z:");
	paint_Box(1070 +450,700+75,1070 +550,700+100,WHITE,RED);
	
	outtextxy(1070 +400,700+115, "Dai:");
	paint_Box(1070 +450,700+110,1070 +550,700+135,WHITE,RED);
	
	outtextxy(1070 +400,700+150, "Rong:");
	paint_Box(1070 +450,700+145,1070 +550,700+170,WHITE,RED);
	
	outtextxy(1070 +400,700+185, "Cao:");
	paint_Box(1070 +450,700+180,1070 +550,700+205,WHITE,RED);
	
	paint_Box(1070 +290,700+180,1070 +330,700+210,WHITE,BLUE);
	outtextxy(1070 +300,700+185, "OK");
	
		int xm, ym;
		while(1)
		{
			delay(0.1);
			if(ismouseclick(WM_LBUTTONDBLCLK)){
			
        	getmouseclick(WM_LBUTTONDBLCLK,xm,ym);
        	
        	nhap_GT_HinhHop(xm,ym,A_x,A_y,A_z,Dai,Rong,Cao);
        	
        	if(1070 +290< xm && 700+180<ym && xm<1070 +330 && ym< 700+210)
			{
				paint_Box(1070 +290,700+180,1070 +330,700+210,RED,BLUE);
				delay(50);
				paint_Box(1070 +290,700+180,1070 +330,700+210,WHITE,BLUE);
				outtextxy(1070 +300,700+185, "OK");
				if(!A_x.empty()&&!A_y.empty()&&!A_z.empty()&&!Dai.empty()&&!Rong.empty()&&!Cao.empty())
				{
					
					clear_Screen();
					outtextxy(A[0]+10, A[1]-10, "      ");
					outtextxy(B[0]+10, B[1]-10, "      ");
					outtextxy(C[0]+10, C[1]-10, "      ");
					outtextxy(D[0]+10, D[1]-10, "      ");
					
					outtextxy(A2[0]+10, A2[1]-10, "           ");
					outtextxy(B2[0]+10, B2[1]-10, "           ");
					outtextxy(C2[0]+10, C2[1]-10, "           ");
					outtextxy(D2[0]+10, D2[1]-10, "           ");
					
				
					outtextxy(1070 +15,700+10, "                                                 ");					
					outtextxy(1070 +15,700+35, "                                                 ");				
					outtextxy(1070 +15,700+60, "                                                 ");				
					outtextxy(1070 +15,700+85, "                                                 ");
					
					outtextxy(1070 +15,700+110, "                                                 ");					
					outtextxy(1070 +15,700+135, "                                                 ");					
					outtextxy(1070 +15,700+160, "                                                 ");
					outtextxy(1070 +15,700+185, "                                                 ");
					
					
					A[0] = stringToInt(A_x);
					A[1] = stringToInt(A_y);
					A[2] = stringToInt(A_z);
					
					dai = stringToInt(Dai);
					rong = stringToInt(Rong);
					cao = stringToInt(Cao);
					
					draw_Shape(A,B,C,D,A2,B2,C2,D2,dai,rong,cao,RED);
				}
			}
        	
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
					
					
					for(int i=10 ; i<200; i+=20)
					{
						outtextxy(1070 +15,700+i,"                                 ");
					}
					paint_Box(1070,700,1700,getmaxy()-10,WHITE,WHITE);
					
					outtextxy(1070 +400,700+10, "                        ");
					paint_Box(1070 +450,700+5,1070 +550,700+30,WHITE,WHITE);
					
					outtextxy(1070 +400,700+45,  "                       ");
					paint_Box(1070 +450,700+40,1070 +550,700+65,WHITE,WHITE);
					
					outtextxy(1070 +400,700+80,  "                       ");
					paint_Box(1070 +450,700+75,1070 +550,700+100,WHITE,WHITE);
					
					outtextxy(1070 +400,700+115,  "                      ");
					paint_Box(1070 +450,700+110,1070 +550,700+135,WHITE,WHITE);
					
					outtextxy(1070 +400,700+150,  "                      ");
					paint_Box(1070 +450,700+145,1070 +550,700+170,WHITE,WHITE);
					
					outtextxy(1070 +400,700+185,  "                      ");
					paint_Box(1070 +450,700+180,1070 +550,700+205,WHITE,WHITE);
					
					paint_Box(1070 +290,700+180,1070 +330,700+210,WHITE,WHITE);
					outtextxy(1070 +300,700+185,  "                 ");
					
					return;
				}
			}
			
		}
}

void nhap_GT_HinhCau(string &A_x, string &A_y, string &A_z, string &R, int xcl, int ycl)
{
	
	int vt=0;
	
	if(1070 +450 < xcl && 700+5 < ycl && xcl< 1070 +550 && ycl<700+30)
	{
		paint_Box(1070 +450,700+5,1070 +550,700+30,CYAN,RED);
		if(!A_x.empty())
		{
			outtextxy(1070 +460,700+10,stringToChar(A_x));
		}
		vt =1;
	}
	else if(1070 +450 < xcl && 700+40 < ycl && xcl< 1070 +550 && ycl<700+65)
	{
		paint_Box(1070 +450,700+40,1070 +550,700+65,CYAN,RED);
		if(!A_y.empty())
		{
			outtextxy(1070 +460,700+45,stringToChar(A_y));
		}
		vt =2;
	}
	else if(1070 +450 < xcl && 700+75 < ycl && xcl< 1070 +550 && ycl<700+100)
	{
		paint_Box(1070 +450,700+75,1070 +550,700+100,CYAN,RED);
		if(!A_z.empty())
		{
			outtextxy(1070 +460,700+80,stringToChar(A_z));
		}
		vt =3;
	}
	else if(1070 +450 < xcl && 700+110 < ycl && xcl< 1070 +550 && ycl<700+135)
	{
		paint_Box(1070 +450,700+110,1070 +550,700+135,CYAN,RED);
		if(!R.empty())
		{
			outtextxy(1070 +460,700+115,stringToChar(R));
		}
		vt =4;
	}
	while(1)
	{
		switch(vt)
		{
			case 1:
				{
					char s = getch();
					int ascii_value = s;
					if(ascii_value==13)
					{
						paint_Box(1070 +450,700+5,1070 +550,700+30,WHITE,RED);
						outtextxy(1070 +460,700+10,stringToChar(A_x));
						vt =0;
					}
					else if(ascii_value == 8 && !A_x.empty())
					{
						A_x.erase(A_x.begin() + A_x.length()-1)	;
						paint_Box(1070 +450,700+5,1070 +550,700+30,CYAN,RED);
						outtextxy(1070 +460,700+10,stringToChar(A_x));
					}
					else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
						if(A_x.length()<4)
						{
							A_x = A_x+s;
						}
						settextstyle(3,0,1);
						outtextxy(1070 +460,700+10,stringToChar(A_x));
					}
				}
				break;
			case 2:
			{
				char s = getch();
				int ascii_value = s;
				if(ascii_value==13)
				{
					paint_Box(1070 +450,700+40,1070 +550,700+65,WHITE,RED);
					outtextxy(1070 +460,700+45,stringToChar(A_y));
					vt =0;
				}
				else if(ascii_value == 8 && !A_y.empty())
				{
					A_y.erase(A_y.begin() + A_y.length()-1)	;
					paint_Box(1070 +450,700+40,1070 +550,700+65,CYAN,RED);
					outtextxy(1070 +460,700+45,stringToChar(A_y));
				}
				else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
					if(A_y.length()<4)
					{
						A_y = A_y+s;
					}
					settextstyle(3,0,1);
					outtextxy(1070 +460,700+45,stringToChar(A_y));
				}
			}
				break;
			case 3:
			{
				char s = getch();
				int ascii_value = s;
				if(ascii_value==13)
				{
					paint_Box(1070 +450,700+75,1070 +550,700+100,WHITE,RED);
					outtextxy(1070 +460,700+80,stringToChar(A_z));
					vt =0;
				}
				else if(ascii_value == 8 && !A_z.empty())
				{
					A_z.erase(A_z.begin() + A_z.length()-1)	;
					paint_Box(1070 +450,700+75,1070 +550,700+100,CYAN,RED);
					outtextxy(1070 +460,700+80,stringToChar(A_z));
				}
				else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
					if(A_z.length()<4)
					{
						A_z = A_z+s;
					}
					settextstyle(3,0,1);
					outtextxy(1070 +460,700+80,stringToChar(A_z));
				}
			}
				break;	
			case 4:
			{
				char s = getch();
					int ascii_value = s;
					if(ascii_value==13)
					{
						paint_Box(1070 +450,700+110,1070 +550,700+135,WHITE,RED);
						outtextxy(1070 +460,700+115,stringToChar(R));
						vt =0;
					}
					else if(ascii_value == 8 && !R.empty())
					{
						R.erase(R.begin() + R.length()-1)	;
						paint_Box(1070 +450,700+110,1070 +550,700+135,CYAN,RED);
						outtextxy(1070 +460,700+115,stringToChar(R));
					}
					else if((48<=ascii_value && ascii_value <=57) || ascii_value ==45){
						if(R.length()<4)
						{
							R = R+s;
						}
						settextstyle(3,0,1);
						outtextxy(1070 +460,700+115,stringToChar(R));
					}
			}
				break;	
						
			default:
				vt=0;
				break;	
		}
		if(vt==0)
		{
			break;
		}
	}
	
}

void draw_Shape_cau(float A[3], int bk, int color)
{
	draw_OXYZ();
	float O[4] = {x_frame + (size*5)/2, y_frame+  (size*5)/2,0,1};
	
	float mttt[3][3], mtdxx[3][3];
	
	string tdA = "O ("+floatToString(A[0])+ ","+floatToString(A[1])+","+floatToString(A[2])+")";
	outtextxy(1070 +15,700+10, stringToChar(tdA));
	string ktbk = "R= "+intToString(bk) ;
	outtextxy(1070 +15,700+35, stringToChar(ktbk));
	
	
	chuyenDoi3D_2D(A);
	MT_TinhTien(O[0],O[1], mttt);
	MT_DoiXung_trucX(mtdxx);	
	
	NhanMT_1x3(A,mtdxx);
	NhanMT_1x3(A,mttt);
	
	draw_Circle(A[0], A[1],bk,color);
	draw_elipse(A[0], A[1],bk,(int)(bk*(sqrt(2)/2)),color);
	
	put_5pixel(A[0],A[1],color);
	outtextxy(A[0]+10,A[1]+10,"O");
}

void draw_hinhCau()
{
	
	paint_Box(1070,700,1700,getmaxy()-10,WHITE,RED);
	
	float O[4] = {x_frame + (size*5)/2, y_frame+  (size*5)/2,0,1},
	A[3]={200,0,200};
	int bk =200;
	string A_x, A_y,A_z,R;
	
	draw_Shape_cau(A,bk,RED);
	
	outtextxy(1070 +400,700+10, "O_x:");
	paint_Box(1070 +450,700+5,1070 +550,700+30,WHITE,RED);
	
	outtextxy(1070 +400,700+45, "O_y:");
	paint_Box(1070 +450,700+40,1070 +550,700+65,WHITE,RED);
	
	outtextxy(1070 +400,700+80, "O_z:");
	paint_Box(1070 +450,700+75,1070 +550,700+100,WHITE,RED);
	
	outtextxy(1070 +400,700+115, "R :");
	paint_Box(1070 +450,700+110,1070 +550,700+135,WHITE,RED);
	
	
	paint_Box(1070 +290,700+180,1070 +330,700+210,WHITE,BLUE);
	outtextxy(1070 +300,700+185, "OK");
	
	int xm, ym;
		while(1)
		{
			delay(0.1);
			if(ismouseclick(WM_LBUTTONDBLCLK)){
				
        	getmouseclick(WM_LBUTTONDBLCLK,xm,ym);
        	
        	nhap_GT_HinhCau(A_x,A_y,A_z,R,xm,ym);
        	
        	if(1070 +290< xm && 700+180<ym && xm<1070 +330 && ym< 700+210)
			{
				paint_Box(1070 +290,700+180,1070 +330,700+210,RED,BLUE);
				delay(50);
				paint_Box(1070 +290,700+180,1070 +330,700+210,WHITE,BLUE);
				outtextxy(1070 +300,700+185, "OK");
				if(!A_x.empty()&&!A_y.empty()&&!A_z.empty()&&!R.empty())
				{
					
					clear_Screen();
					outtextxy(A[0]+10,A[1]+10,"      ");
					outtextxy(1070 +15,700+10, "                                                 ");
					outtextxy(1070 +15,700+35, "                                                 ");
					
					A[0] = stringToInt(A_x);
					A[1] = stringToInt(A_y);
					A[2] = stringToInt(A_z);
					
					bk = stringToInt(R);
					
					draw_Shape_cau(A,bk,RED);
				}
        	}
        	if(5*size+x_frame+350 <xm && xm <5*size+x_frame+500 && 
				y_frame+520< ym && ym< y_frame+570)
				{
					setfillstyle(SOLID_FILL,YELLOW);
					floodfill(5*size+x_frame+350+2,y_frame+520+2,0);
					
					delay(200);
					setfillstyle(SOLID_FILL,WHITE);
					floodfill(5*size+x_frame+350+2,y_frame+520+2,0);
					
					outtextxy(A[0]+10,A[1]+10,"      ");
					outtextxy(1070 +15,700+10, "                                                 ");
					outtextxy(1070 +15,700+35, "                                                 ");
					
					paint_Box(1070,700,1700,getmaxy()-10,WHITE,WHITE);
					
					outtextxy(1070 +400,700+10, "                        ");
					paint_Box(1070 +450,700+5,1070 +550,700+30,WHITE,WHITE);
					
					outtextxy(1070 +400,700+45,  "                       ");
					paint_Box(1070 +450,700+40,1070 +550,700+65,WHITE,WHITE);
					
					outtextxy(1070 +400,700+80,  "                       ");
					paint_Box(1070 +450,700+75,1070 +550,700+100,WHITE,WHITE);
					
					outtextxy(1070 +400,700+115,  "                      ");
					paint_Box(1070 +450,700+110,1070 +550,700+135,WHITE,WHITE);
					
					outtextxy(1070 +400,700+150,  "                      ");
					paint_Box(1070 +450,700+145,1070 +550,700+170,WHITE,WHITE);
					
					outtextxy(1070 +400,700+185,  "                      ");
					paint_Box(1070 +450,700+180,1070 +550,700+205,WHITE,WHITE);
					
					paint_Box(1070 +290,700+180,1070 +330,700+210,WHITE,WHITE);
					outtextxy(1070 +300,700+185,  "                 ");
					
					
					return;
				}
			}
			
		}
		
	
}

