#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include "Shape_basic.h"
#include "Giao_dien.h"
#include "oto.h"
#define PI 3.14159265359

void MT_TinhTien(float xtt, float ytt, float mttt[3][3]);


void MT_Quay(float mtq[3][3], float gocQuay);

void updateMT_1x3(float truoc[3], float sau[3]);

void updateMT_3x3(float truoc[][3], float sau[][3]);


void NhanMT_1x3(float A[3],float B[3][3]);


void nhanMT_3x3(float A[][3], float B[][3] );


void MT_DoiXung_trucX(float mtdx[3][3]);

int Quay_quanh_1D(float G[3],float A[3], float gocQuay);


void draw_HanhTinh(float x, float y,float r,float color,float color_border);

void draw_Sao();

void draw_Space();


