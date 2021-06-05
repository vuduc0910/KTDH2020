#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include <string>
#include "Shape_basic.h"
#include "Giao_dien.h"
#define PI 3.14159265359

using namespace std;

// dx qua truc thang dung
void DX_quaTrucDung(float A[3],float Dm[3], float kq[3])
{
		kq[0] = Dm[0] + (Dm[0]- A[0]);
		kq[1] = A[1];
		kq[2] = 1;
}

void draw_oto()
{
	float O[3] = {x_frame + (size*5)/2, y_frame+ (size*5)/2, 1};
	
	float A[3] = {300,y_frame+size*5-50,1},
		B[3] = {250,y_frame+size*5-50,1},
		C[3] = {225,y_frame+size*5-50,1},
		D[3] = {195,y_frame+size*5-50,1},
		E[3] = {90, y_frame+size*5-50,1},
		F[3] = {90, y_frame+size*5-130,1},
		G[3] = {150,y_frame+size*5-130,1},
		H[3] = {225,y_frame+size*5-200,1},
		K[3] = {300,y_frame+size*5-200,1};
	
	float A2[3], 
		B2[3],
		C2[3],
		D2[3],
		E2[3],
		F2[3],
		G2[3],
		H2[3],
		K2[3];
	
	float A_dx[3], 
		B_dx[3],
		C_dx[3],
		D_dx[3],
		E_dx[3],
		F_dx[3],
		G_dx[3],
		H_dx[3],
		K_dx[3];
		
	float A2_dx[3], 
		B2_dx[3],
		C2_dx[3],
		D2_dx[3],
		E2_dx[3],
		F2_dx[3],
		G2_dx[3],
		H2_dx[3],
		K2_dx[3];
	
	float tl = 0.5;
	float rbx = 25;
	float rbxtl = rbx*tl;

	
	int i =0;
	int xm, ym;
	int run =1;
	
	
	string A_x, B_x, C_x, D_x, E_x, F_x, G_x, H_x, K_x;  				
	string A_y, B_y, C_y, D_y, E_y, F_y, G_y, H_y, K_y;
	string tA, tB, tC, tD, tE, tF, tG, tH, tK;
	char*  td_A,* td_B,* td_C,* td_D,* td_E,* td_F,* td_G,* td_H,* td_K;
	
	string  B2_x, C2_x, D2_x, E2_x, F2_x, G2_x, H2_x;  				
	string  B2_y, C2_y, D2_y, E2_y, F2_y, G2_y, H2_y;
	string  tB2, tC2, tD2, tE2, tF2, tG2, tH2;
	char*  	td_B2,* td_C2,* td_D2,* td_E2,* td_F2,* td_G2,* td_H2;
	
	string Adx_x, Bdx_x, Cdx_x, Ddx_x, Edx_x, Fdx_x, Gdx_x, Hdx_x, Kdx_x;  				
	string Adx_y, Bdx_y, Cdx_y, Ddx_y, Edx_y, Fdx_y, Gdx_y, Hdx_y, Kdx_y;
	string tAdx, tBdx, tCdx, tDdx, tEdx, tFdx, tGdx, tHdx, tKdx;
	char*  td_Adx,* td_Bdx,* td_Cdx,* td_Ddx,* td_Edx,* td_Fdx,* td_Gdx,* td_Hdx,* td_Kdx;
	
	string  B2dx_x, C2dx_x, D2dx_x, E2dx_x, F2dx_x, G2dx_x, H2dx_x;  				
	string  B2dx_y, C2dx_y, D2dx_y, E2dx_y, F2dx_y, G2dx_y, H2dx_y;
	string  tB2dx, tC2dx, tD2dx, tE2dx, tF2dx, tG2dx, tH2dx;
	char*  	td_A2dx,* td_B2dx,* td_C2dx,* td_D2dx,* td_E2dx,* td_F2dx,* td_G2dx,* td_H2dx;
	
	
	paint_Box(1070,700,1700,getmaxy()-10,WHITE,RED);
	
	while(!kbhit())
	{
		
		DX_quaTrucDung(B,A,B2);
		DX_quaTrucDung(C,A,C2);
		DX_quaTrucDung(D,A,D2);
		DX_quaTrucDung(E,A,E2);
		DX_quaTrucDung(F,A,F2);
		DX_quaTrucDung(G,A,G2);
		DX_quaTrucDung(H,A,H2);
		
		line_5pixel(A[0]+i, A[1],B[0]+i, B[1],BLUE);
		draw_Circle(C[0]+i, C[1],rbx,RED);
		line_5pixel(D[0]+i, D[1],E[0]+i, E[1],BLUE);
		line_5pixel(E[0]+i, E[1],F[0]+i, F[1]+5,BLUE);
		line_5pixel(F[0]+i, F[1],G[0]+i, G[1],BLUE);
		line_5pixel(G[0]+i, G[1],H[0]+i, H[1]+5,BLUE);
		line_5pixel(H[0]+i, H[1],K[0]+i, K[1],BLUE);
		
		line_5pixel(A[0]+i, A[1],B2[0]-5+i, B2[1],BLUE);
		draw_Circle(C2[0]+i, C2[1],rbx,RED);
		line_5pixel(D2[0]+i, D2[1],E2[0]+i, E2[1],BLUE);
		line_5pixel(E2[0]+5+i, E2[1],F2[0]+5+i, F2[1]+5,BLUE);
		line_5pixel(F2[0]+i, F2[1],G2[0]+i, G2[1],BLUE);
		line_5pixel(G2[0]+i, G2[1]-5,H2[0]+i, H2[1]+5,BLUE);
		line_5pixel(H2[0]+i- 5,H2[1],K[0]+i, K[1],BLUE);
		
		line_5pixel(G[0]+i, G[1],G2[0]+i, G[1],BLUE);
		line_5pixel(K[0]+i, K[1],(G[0]+G2[0])/2+i, G[1]-5,BLUE);
		
		
		/*-----------------------------------------------------------------*/ //outtextxy
		settextstyle(2,0,4);
		A_x = intToString((int)A[0]+i);
		A_y = intToString((int)A[1]);
		tA = "A("+A_x+", "+A_y+")";
		td_A = stringToChar(tA);
		outtextxy(A[0]+i, A[1]-15,"A");
		outtextxy(1070 +15,700+10,td_A);
		
		B_x = intToString((int)B[0]+i);
		B_y = intToString((int)B[1]);
		tB = "B("+B_x+", "+B_y+")";
		td_B = stringToChar(tB);
		outtextxy(B[0]+i+10, B[1]-15,"B");
		outtextxy(1070 +15,700+25,td_B);
		
		C_x = intToString((int)C[0]+i);
		C_y = intToString((int)C[1]);
		tC = "C("+C_x+", "+C_y+")";
		td_C = stringToChar(tC);
		outtextxy(C[0]+i, C[1],"C");
		outtextxy(1070 +15,700+40,td_C);
		
		D_x = intToString((int)D[0]+i);
		D_y = intToString((int)D[1]);
		tD = "D("+D_x+", "+D_y+")";
		td_D = stringToChar(tD);
		outtextxy(D[0]+i-10, D[1]-15,"D");
		outtextxy(1070 +15,700+55,td_D);
		
		E_x = intToString((int)E[0]+i);
		E_y = intToString((int)E[1]);
		tE = "E("+E_x+", "+E_y+")";
		td_E = stringToChar(tE);
		outtextxy(E[0]+i+10, E[1]-15,"E");
		outtextxy(1070 +15,700+70,td_E);
		
		F_x = intToString((int)F[0]+i);
		F_y = intToString((int)F[1]);
		tF = "F("+F_x+", "+F_y+")";
		td_F = stringToChar(tF);
		outtextxy(F[0]+i+10, F[1]-15,"F");
		outtextxy(1070 +15,700+85,td_F);
		
		G_x = intToString((int)G[0]+i);
		G_y = intToString((int)G[1]);
		tG = "G("+G_x+", "+G_y+")";
		td_G = stringToChar(tG);
		outtextxy(G[0]+i-10, G[1]-15,"G");
		outtextxy(1070 +15,700+100,td_G);
		
		H_x = intToString((int)H[0]+i);
		H_y = intToString((int)H[1]);
		tH = "H("+H_x+", "+H_y+")";
		td_H = stringToChar(tH);
		outtextxy(H[0]+i-10, H[1]-15,"H");
		outtextxy(1070 +15,700+115,td_H);
	
		K_x = intToString((int)K[0]+i);
		K_y = intToString((int)K[1]);
		tK = "K("+K_x+", "+K_y+")";
		td_K = stringToChar(tK);
		outtextxy(K[0]+i, K[1]-15,"K");
		outtextxy(1070 +15,700+130,td_K);
		
		/**********/
		B2_x = intToString((int)B2[0]+i);
		B2_y = intToString((int)B2[1]);
		tB2 = "B2("+B2_x+", "+B2_y+")";
		td_B2 = stringToChar(tB2);
		outtextxy(B2[0]+i-15, B2[1]-15,"B2");
		outtextxy(1070 +80,700+25,td_B2);
		
		C2_x = intToString((int)C2[0]+i);
		C2_y = intToString((int)C2[1]);
		tC2 = "C2("+C2_x+", "+C2_y+")";
		td_C2 = stringToChar(tC2);
		outtextxy(C2[0]+i, C2[1],"C2");
		outtextxy(1070 +80,700+40,td_C2);
		
		D2_x = intToString((int)D2[0]+i);
		D2_y = intToString((int)D2[1]);
		tD2 = "D2("+D2_x+", "+D2_y+")";
		td_D2 = stringToChar(tD2);
		outtextxy(D2[0]+i+10, D2[1]-15,"D2");
		outtextxy(1070 +80,700+55,td_D2);
		
		E2_x = intToString((int)E2[0]+i);
		E2_y = intToString((int)E2[1]);
		tE2 = "E2("+E2_x+", "+E2_y+")";
		td_E2 = stringToChar(tE2);
		outtextxy(E2[0]+i+10, E2[1]-15,"E2");
		outtextxy(1070 +80,700+70,td_E2);
		
		F2_x = intToString((int)F2[0]+i);
		F2_y = intToString((int)F2[1]);
		tF2 = "F2("+F2_x+", "+F2_y+")";
		td_F2 = stringToChar(tF2);
		outtextxy(F2[0]+i+10, F2[1]-15,"F2");
		outtextxy(1070 +80,700+85,td_F2);
		
		G2_x = intToString((int)G2[0]+i);
		G2_y = intToString((int)G2[1]);
		tG2 = "G2("+G2_x+", "+G2_y+")";
		td_G2 = stringToChar(tG2);
		outtextxy(G2[0]+i+10, G2[1]-15,"G2");
		outtextxy(1070 +80,700+100,td_G2);
		
		H2_x = intToString((int)H2[0]+i);
		H2_y = intToString((int)H2[1]);
		tH2 = "H2("+H2_x+", "+H2_y+")";
		td_H2 = stringToChar(tH2);
		outtextxy(H2[0]+i-10, H2[1]-15,"H2");
		outtextxy(1070 +80,700+115,td_H2);
		
		/*----------------------------------------------------------------*/
		//ve hinh doi xung qua Ox Oy
		
		Dx_quaOxOy(O, A, A_dx, tl);
		Dx_quaOxOy(O, B, B_dx, tl);
		Dx_quaOxOy(O, C, C_dx, tl);
		Dx_quaOxOy(O, D, D_dx, tl);
		Dx_quaOxOy(O, E, E_dx, tl);
		Dx_quaOxOy(O, F, F_dx, tl);
		Dx_quaOxOy(O, G, G_dx, tl);
		Dx_quaOxOy(O, H, H_dx, tl);
		Dx_quaOxOy(O, K, K_dx, tl);
		
		DX_quaTrucDung(B_dx,A_dx,B2_dx);
		DX_quaTrucDung(C_dx,A_dx,C2_dx);
		DX_quaTrucDung(D_dx,A_dx,D2_dx);
		DX_quaTrucDung(E_dx,A_dx,E2_dx);
		DX_quaTrucDung(F_dx,A_dx,F2_dx);
		DX_quaTrucDung(G_dx,A_dx,G2_dx);
		DX_quaTrucDung(H_dx,A_dx,H2_dx);
		
		line_5pixel(A_dx[0]-i, A_dx[1],B_dx[0]-3-i, B_dx[1],RED);
		draw_Circle(C_dx[0]-i, C_dx[1],(int)rbxtl/5*5,BLUE);
		line_5pixel(D_dx[0]-5-i, D_dx[1],E_dx[0]-5-i, E_dx[1],RED);
		line_5pixel(E_dx[0]-i, E_dx[1],F_dx[0]-i, F_dx[1]-5,RED);
		line_5pixel(F_dx[0]-3-i, F_dx[1],G_dx[0]-i, G_dx[1],RED);
		line_5pixel(G_dx[0]-i, G_dx[1]+5,H_dx[0]-i, H_dx[1],RED);
		line_5pixel(H_dx[0]-i, H_dx[1],K_dx[0]-i, K_dx[1],RED);
		
		line_5pixel(A_dx[0]-i,A_dx[1],B2_dx[0]-i, B2_dx[1],RED);
		draw_Circle(C2_dx[0]-i,C2_dx[1],(int)rbxtl/5*5,BLUE);
		line_5pixel(D2_dx[0]-i,D2_dx[1],E2_dx[0]-i, E2_dx[1],RED);
		line_5pixel(E2_dx[0]-i,E2_dx[1],F2_dx[0]-i, F2_dx[1]-5,RED);
		line_5pixel(F2_dx[0]-i,F2_dx[1],G2_dx[0]-i, G2_dx[1],RED);
		line_5pixel(G2_dx[0]-i,G2_dx[1],H2_dx[0]-i-5, H2_dx[1]-5,RED);
		line_5pixel(H2_dx[0]-i,H2_dx[1],K_dx[0]-i, K_dx[1],RED);
		
		line_5pixel(G_dx[0]-i,G_dx[1],G2_dx[0]-i, G_dx[1],RED);
		line_5pixel(K_dx[0]-i,K_dx[1],(G_dx[0]+G2_dx[0])/2-i, G_dx[1]+5,RED);
		
		
		Adx_x = intToString((int)A_dx[0]-i);
		Adx_y = intToString((int)A_dx[1]);
		tAdx = "Adx ("+Adx_x+", "+Adx_y+")";
		td_Adx = stringToChar(tAdx);
		outtextxy(A_dx[0]-i, A_dx[1]-15,"Ad");
		outtextxy(1070 +150,700+10,td_Adx);
		
		Bdx_x = intToString((int)B_dx[0]-i);
		Bdx_y = intToString((int)B_dx[1]);
		tBdx = "Bdx ("+Bdx_x+", "+Bdx_y+")";
		td_Bdx = stringToChar(tBdx);
		outtextxy(B_dx[0]-i-15, B_dx[1]-15,"Bd");
		outtextxy(1070 +150,700+25,td_Bdx);
		
		Cdx_x = intToString((int)C_dx[0]-i);
		Cdx_y = intToString((int)C_dx[1]);
		tCdx = "Cdx ("+Cdx_x+", "+Cdx_y+")";
		td_Cdx = stringToChar(tCdx);
		outtextxy(C_dx[0]-i-5, C_dx[1]-5,"Cd");
		outtextxy(1070 +150,700+40,td_Cdx);
		
		Ddx_x = intToString((int)D_dx[0]-i);
		Ddx_y = intToString((int)D_dx[1]);
		tDdx = "Ddx ("+Ddx_x+", "+Ddx_y+")";
		td_Ddx = stringToChar(tDdx);
		outtextxy(D_dx[0]-i+10, D_dx[1]-15,"Dd");
		outtextxy(1070 +150,700+55,td_Ddx);
		
		Edx_x = intToString((int)E_dx[0]-i);
		Edx_y = intToString((int)E_dx[1]);
		tEdx = "Edx ("+Edx_x+", "+Edx_y+")";
		td_Edx = stringToChar(tEdx);
		outtextxy(E_dx[0]-i+10, E_dx[1]-15,"Ed");
		outtextxy(1070 +150,700+70,td_Edx);
		
		Fdx_x = intToString((int)F_dx[0]-i);
		Fdx_y = intToString((int)F_dx[1]);
		tFdx = "Fdx ("+Fdx_x+", "+Fdx_y+")";
		td_Fdx = stringToChar(tFdx);
		outtextxy(F_dx[0]-i+10, F_dx[1]-15,"Fd");
		outtextxy(1070 +150,700+85,td_Fdx);
		
		Gdx_x = intToString((int)G_dx[0]-i);
		Gdx_y = intToString((int)G_dx[1]);
		tGdx = "Gdx ("+Gdx_x+", "+Gdx_y+")";
		td_Gdx = stringToChar(tGdx);
		outtextxy(G_dx[0]-i-10, G_dx[1]-15,"Gd");
		outtextxy(1070 +150,700+100,td_Gdx);
		
		Hdx_x = intToString((int)H_dx[0]-i);
		Hdx_y = intToString((int)H_dx[1]);
		tHdx = "Hdx ("+Hdx_x+", "+Hdx_y+")";
		td_Hdx = stringToChar(tHdx);
		outtextxy(H_dx[0]-i-10, H_dx[1]+10,"Hd");
		outtextxy(1070 +150,700+115,td_Hdx);
	
		Kdx_x = intToString((int)K_dx[0]-i);
		Kdx_y = intToString((int)K_dx[1]);
		tKdx = "Kdx ("+Kdx_x+", "+Kdx_y+")";
		td_Kdx = stringToChar(tKdx);
		outtextxy(K_dx[0]-i, K_dx[1]+10,"Kd");
		outtextxy(1070 +150,700+130,td_Kdx);
		
		
			/**********/
		B2dx_x = intToString((int)B2_dx[0]-i);
		B2dx_y = intToString((int)B2_dx[1]);
		tB2dx = "B2dx ("+B2dx_x+", "+B2dx_y+")";
		td_B2dx = stringToChar(tB2dx);
		outtextxy(B2_dx[0]-i+5, B2_dx[1]-15,"B2d");
		outtextxy(1070 +230,700+25,td_B2dx);
		
		C2dx_x = intToString((int)C2_dx[0]-i);
		C2dx_y = intToString((int)C2_dx[1]);
		tC2dx = "C2dx ("+C2dx_x+", "+C2dx_y+")";
		td_C2dx = stringToChar(tC2dx);
		outtextxy(C2_dx[0]-i-10, C2_dx[1]-5,"C2d");
		outtextxy(1070 +230,700+40,td_C2dx);
		
		D2dx_x = intToString((int)D2_dx[0]-i);
		D2dx_y = intToString((int)D2_dx[1]);
		tD2dx = "D2dx ("+D2dx_x+", "+D2dx_y+")";
		td_D2dx = stringToChar(tD2dx);
		outtextxy(D2_dx[0]-i-15, D2_dx[1]-15,"D2d");
		outtextxy(1070 +230,700+55,td_D2dx);
		
		E2dx_x = intToString((int)E2_dx[0]-i);
		E2dx_y = intToString((int)E2_dx[1]);
		tE2dx = "E2dx ("+E2dx_x+", "+E2dx_y+")";
		td_E2dx = stringToChar(tE2);
		outtextxy(E2_dx[0]-i+10, E2_dx[1]-15,"E2d");
		outtextxy(1070 +230,700+70,td_E2dx);
		
		F2dx_x = intToString((int)F2_dx[0]-i);
		F2dx_y = intToString((int)F2_dx[1]);
		tF2dx = "F2dx ("+F2dx_x+", "+F2dx_y+")";
		td_F2dx = stringToChar(tF2dx);
		outtextxy(F2_dx[0]-i+10, F2_dx[1]-15,"F2d");
		outtextxy(1070 +230,700+85,td_F2dx);
		
		G2dx_x = intToString((int)G2_dx[0]-i);
		G2dx_y = intToString((int)G2_dx[1]);
		tG2dx = "G2dx ("+G2dx_x+", "+G2dx_y+")";
		td_G2dx = stringToChar(tG2dx);
		outtextxy(G2_dx[0]-i+10, G2_dx[1]-15,"G2d");
		outtextxy(1070 +230,700+100,td_G2dx);
		
		H2dx_x = intToString((int)H2_dx[0]-i);
		H2dx_y = intToString((int)H2_dx[1]);
		tH2dx = "H2dx ("+H2dx_x+", "+H2dx_y+")";
		td_H2dx = stringToChar(tH2dx);
		outtextxy(H2_dx[0]-i-10, H2_dx[1]+10,"H2d");
		outtextxy(1070 +230,700+115,td_H2dx);
		
		delay(50); 
		// Xoa hinh toa do cu
			
		line_5pixel(A[0]+i, A[1],B[0]+i, B[1],WHITE);
		draw_Circle(C[0]+i, C[1],rbx,WHITE);
		line_5pixel(D[0]+i, D[1],E[0]+i, E[1],WHITE);
		line_5pixel(E[0]+i, E[1],F[0]+i, F[1]+5,WHITE);
		line_5pixel(F[0]+i, F[1],G[0]+i, G[1],WHITE);
		line_5pixel(G[0]+i, G[1],H[0]+i, H[1]+5,WHITE);
		line_5pixel(H[0]+i, H[1],K[0]+i, K[1],WHITE);
		
		line_5pixel(A[0]+i, A[1],B2[0]-5+i, B2[1],WHITE);
		draw_Circle(C2[0]+i, C2[1],rbx,WHITE);
		line_5pixel(D2[0]+i, D2[1],E2[0]+i, E2[1],WHITE);
		line_5pixel(E2[0]+5+i, E2[1],F2[0]+5+i, F2[1]+5,WHITE);
		line_5pixel(F2[0]+i, F2[1],G2[0]+i, G2[1],WHITE);
		line_5pixel(G2[0]+i, G2[1]-5,H2[0]+i, H2[1]+5,WHITE);
		line_5pixel(H2[0]+i- 5,H2[1],K[0]+i, K[1],WHITE);
		
		line_5pixel(G[0]+i, G[1],G2[0]+i, G[1],WHITE);
		line_5pixel(K[0]+i, K[1],(G[0]+G2[0])/2+i, G[1]-5,WHITE);
		
		
		
		outtextxy(A[0]+i, A[1]-15,"      ");
		outtextxy(B[0]+i+10, B[1]-15,"      ");
		outtextxy(C[0]+i, C[1],"      ");
		outtextxy(D[0]+i-10, D[1]-15,"      ");
		outtextxy(E[0]+i+10, E[1]-15,"      ");
		outtextxy(F[0]+i+10, F[1]-15,"      ");
		outtextxy(G[0]+i-10, G[1]-15,"      ");
		outtextxy(H[0]+i-10, H[1]-15,"      ");
		outtextxy(K[0]+i, K[1]-15,"      ");
		
		outtextxy(B2[0]+i-15, B2[1]-15,"      ");
		outtextxy(C2[0]+i, C2[1],"      ");
		outtextxy(D2[0]+i+10, D2[1]-15,"      ");
		outtextxy(E2[0]+i+10, E2[1]-15,"      ");
		outtextxy(F2[0]+i+10, F2[1]-15,"      ");
		outtextxy(G2[0]+i+10, G2[1]-15,"      ");
		outtextxy(H2[0]+i-10, H2[1]-15,"      ");
		/*-------------------------------------------------------------------------*/
		
		line_5pixel(A_dx[0]-i, A_dx[1],B_dx[0]-3-i, B_dx[1],WHITE);
		draw_Circle(C_dx[0]-i, C_dx[1],(int)rbxtl/5*5,WHITE);
		line_5pixel(D_dx[0]-5-i, D_dx[1],E_dx[0]-5-i, E_dx[1],WHITE);
		line_5pixel(E_dx[0]-i, E_dx[1],F_dx[0]-i, F_dx[1]-5,WHITE);
		line_5pixel(F_dx[0]-3-i, F_dx[1],G_dx[0]-i, G_dx[1],WHITE);
		line_5pixel(G_dx[0]-i, G_dx[1]+5,H_dx[0]-i, H_dx[1],WHITE);
		line_5pixel(H_dx[0]-i, H_dx[1],K_dx[0]-i, K_dx[1],WHITE);
		
		line_5pixel(A_dx[0]-i, A_dx[1],B2_dx[0]-i, B2_dx[1],WHITE);
		draw_Circle(C2_dx[0]-i, C2_dx[1],(int)rbxtl/5*5,WHITE);
		line_5pixel(D2_dx[0]-i, D2_dx[1],E2_dx[0]-i, E2_dx[1],WHITE);
		line_5pixel(E2_dx[0]-i, E2_dx[1],F2_dx[0]-i, F2_dx[1]-5,WHITE);
		line_5pixel(F2_dx[0]-i, F2_dx[1],G2_dx[0]-i, G2_dx[1],WHITE);
		line_5pixel(G2_dx[0]-i, G2_dx[1],H2_dx[0]-i-5, H2_dx[1]-5,WHITE);
		line_5pixel(H2_dx[0]-i, H2_dx[1],K_dx[0]-i, K_dx[1],WHITE);
		
		line_5pixel(G_dx[0]-i, G_dx[1],G2_dx[0]-i, G_dx[1],WHITE);
		line_5pixel(K_dx[0]-i, K_dx[1],(G_dx[0]+G2_dx[0])/2-i, G_dx[1]+5,WHITE);
		
		
		outtextxy(A_dx[0]-i, A_dx[1]-15,"       ");
		outtextxy(B_dx[0]-i-15, B_dx[1]-15,"       ");
		outtextxy(C_dx[0]-i-5, C_dx[1]-5,"      ");
		outtextxy(D_dx[0]-i+10, D_dx[1]-15,"      ");
		outtextxy(E_dx[0]-i+10, E_dx[1]-15,"      ");
		outtextxy(F_dx[0]-i+10, F_dx[1]-15,"      ");	
		outtextxy(G_dx[0]-i-10, G_dx[1]-15,"      ");	
		outtextxy(H_dx[0]-i-10, H_dx[1]+10,"      ");
		outtextxy(K_dx[0]-i, K_dx[1]+10,"      ");
		
		outtextxy(B2_dx[0]-i+5, B2_dx[1]-15,"          ");
		outtextxy(C2_dx[0]-i-10, C2_dx[1]-5,	"          ");
		outtextxy(D2_dx[0]-i-15, D2_dx[1]-15,"         ");
		outtextxy(E2_dx[0]-i+10, E2_dx[1]-15,"         ");
		outtextxy(F2_dx[0]-i+10, F2_dx[1]-15,"         ");
		outtextxy(G2_dx[0]-i+10, G2_dx[1]-15,"         ");
		outtextxy(H2_dx[0]-i-10, H2_dx[1]+10,"         ");
		
		
			
		if(run ==1){
			i+=10;
			if(i==400)
			{
				run =2;
			}
			if(i%100==0)
			{
				tl+=0.05;
				rbxtl = rbx*tl;
			}
		}	
		else
		{
			i-=10;
			if(i==0)
			{
				run =1;
			}
			if(i%100==0)
			{
				tl-=0.05;
				rbxtl = rbx*tl;
			}
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
				
				settextstyle(3,0,2);
				for(int i =0; i<150; i+=15)
				{
					outtextxy(1070 +15,700+i, "                                                            ");
				}
				
				paint_Box(1070,700,1700,getmaxy()-10,WHITE,WHITE);
				
				return;
			}
		}
		
		draw_OXY(RED);
	}
	
	
	
}

