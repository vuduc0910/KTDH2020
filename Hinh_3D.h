#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include "Shape_basic.h"
#include "veTinh.h"

void update_MT1x4(float truoc[4], float sau[4]);


void update_MT4x4(float truoc[][4], float sau[][4]);

void MTD(float A[], float x,float y,float z);

void MTTT_3D(float mttt[][4], float xtt,float ytt,float ztt);

void MTQx_3D(float mtqx[][4],float goc);

void MTQy_3D(float mtqy[][4],float goc);


void MTQz_3D(float mtqz[][4],float goc);

void nhanMT_3D(float A[4], float B[][4]);

// p x m & n x p  (cot x hang)
void nhan2MT4x4_3D(float A[][4], float B[][4] );

void dinh_3D(float A[4],float B[4],float C[4],float D[4], 
				float A2[4],float B2[4],float C2[4],float D2[4], float cd, float cr, float cc);

//MTTT ve O
void MTTT_ve_O(float A[4], int xtt, int ytt, int ztt);

//MTTT comeback 
void MTTT_cb(float A[4],int xtt, int ytt, int ztt);

void PQ_1dtrucX_3D(float O[4],float A[4],float goc);

void PQ_1dtrucY_3D(float O[4],float A[4],float goc);

void PQ_1dtrucZ_3D(float O[4],float A[4],float goc);

void MTDX_trucX_3D();

void MT_chieu3D(float MTC[4][4], float r);

void chuyenDoi3D_2D(float A[3]);

void draw_OXYZ();
void nhap_GT_HinhHop();
void draw_lapPhuong();

void draw_hinhCau();

