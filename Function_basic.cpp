#include <graphics.h>
#include <iostream>
#include <string>
#include <sstream>
#include "data.h"
#include <math.h>
#define ROUND(a) (int)(a+0.5)
#define PI 3.14159265359


float tinhgoc(float goc){
    return (goc*PI/180);
}

void reset_color(){
	setcolor(0);
	setbkcolor(15);
}

char * stringToChar(string s){
	char *text = new char[s.length() + 1];
	strcpy(text, s.c_str());
	return text;
}

string floatToString(float a)
{
	stringstream sstream;
	sstream << a;
    string num_str = sstream.str();
    return num_str;
}
string intToString(int a)
{
	stringstream sstream;
	sstream << a;
    string num_str = sstream.str();
    return num_str;
}
int stringToInt(string a)
{
	int kq;
	stringstream geek(a);
	geek>>kq;
	return kq;
}
char* floatToChar(float a)
{
	stringstream sstream;
	sstream << a;
    string num_str = sstream.str();
    
    char *text = new char[num_str.length() + 1];
	strcpy(text, num_str.c_str());
	return text;
}
char* intToChar(int a)
{
  stringstream sstream;
  sstream << a;
  string temp_str = sstream.str();
  char* char_type = (char*) temp_str.c_str();
  return char_type;
  
}

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

void NhanMT_1x3_traKQ(float A[3],float B[3][3],float kq[3])
{
	for(int i=0;i<3;i++)
	{	
		kq[i]=0;
		for(int j=0; j<3; j++)
		{
			kq[i]= kq[i] + A[j]*B[j][i];
		}
	}
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


void Quay_quanh_1D(float G[3],float A[3], float gocQuay)
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


void Dx_quaOxOy(float O[3], float A[3], float kq[3], float tl){
	float mtdx[3][3], mttt[3][3], mtcb[3][3], mtbdtl[3][3];;
	
	MT_DoiXung(mtdx);
	MT_TinhTien(-O[0],-O[1], mttt);
	MT_TinhTien(O[0],O[1], mtcb);
	MT_BienDoiTL(mtbdtl, tl, tl);
	
	NhanMT_1x3_traKQ(A,mttt,kq);
	NhanMT_1x3(kq,mtbdtl);
	NhanMT_1x3(kq,mtdx);
	NhanMT_1x3(kq,mtcb);
	
}


