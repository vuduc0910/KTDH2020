#include <graphics.h>
#include <iostream>
#include "data.h"
#include <math.h>
#define ROUND(a) (int)(a+0.5)
#define PI 3.14159265359


float tinhgoc(float goc);
void reset_color();
char * stringToChar(string s);	
int stringToInt(string a);
string floatToString(float a);
string intToString(int a);
char* floatToChar(float a);
char* intToChar(int a);
void MT_TinhTien(float xtt, float ytt, float mttt[3][3]);
void MT_Quay(float mtq[3][3], float gocQuay);
void MT_BienDoiTL(float mtdb[3][3],float x, float y);
void MT_DoiXung_trucX(float mtdx[3][3]);
void MT_DoiXung(float mtdb[3][3]);
void updateMT_1x3(float truoc[3], float sau[3]);
void updateMT_3x3(float truoc[][3], float sau[][3]);
void NhanMT_1x3(float A[3],float B[3][3]);
void Quay_quanh_1D(float G[3],float A[3], float gocQuay);
void Dx_quaOxOy(float O[3], float A[3], float kq[3], float tl);
