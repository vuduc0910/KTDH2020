#include <graphics.h>
#include <iostream>
#include <math.h>
#include "data.h"
#include "clock.h"
#include "oto.h"
#include "veTinh.h"
#include "Giao_dien.h"
#include "Hinh_3D.h";
using namespace std;

void xuli_menu(){
	int x,y;
	int page = 0;
 	int ve_2d = 0;
 	int ve_3d = 0;
 	
 	
	while(true)
	{
		delay(0.0001);
		if(ismouseclick(WM_LBUTTONDBLCLK)){
			getmouseclick(WM_LBUTTONDBLCLK,x,y);
			
			if(page ==0)
			{
				if(5*size+x_frame+300 < x && x < 5*size+x_frame+550 && 
				y_frame+150<y && y<y_frame+200){
				
					setfillstyle(SOLID_FILL,YELLOW);
					floodfill(5*size+x_frame+300+2,y_frame+150+2,0);
					
					delay(200);
					setfillstyle(SOLID_FILL,WHITE);
					floodfill(5*size+x_frame+300+2,y_frame+150+2,0);
					
					page = 1;
					ve_2d =1;
					interface_2D();
					
				}
				else if(5*size+x_frame+300 < x && x < 5*size+x_frame+550 && 
				y_frame+220<y && y<y_frame+270){
		
					setfillstyle(SOLID_FILL,YELLOW);
					floodfill(5*size+x_frame+300+2,y_frame+220+2,0);
					
					delay(200);
					setfillstyle(SOLID_FILL,WHITE);
					floodfill(5*size+x_frame+300+2,y_frame+220+2,0);
					
					page = 1;
					ve_3d = 1;
					interface_3D();	
				}
			}
			else{
				if(5*size+x_frame+300 < x && x < 5*size+x_frame+550 && 
				y_frame+150<y && y<y_frame+200){
				
					setfillstyle(SOLID_FILL,YELLOW);
					floodfill(5*size+x_frame+300+2,y_frame+150+2,0);
					
					delay(200);
					setfillstyle(SOLID_FILL,WHITE);
					floodfill(5*size+x_frame+300+2,y_frame+150+2,0);
					if(ve_2d ==1)
					{	
						
						draw_OXY(RED);
						draw_oto();			
						clear_Screen();
						
					}
					else if(ve_3d == 1)
					{
						draw_lapPhuong();	
						clear_Screen();
					}
				}
				else if(5*size+x_frame+300 < x && x < 5*size+x_frame+550 && 
				y_frame+220<y && y<y_frame+270){
		
					setfillstyle(SOLID_FILL,YELLOW);
					floodfill(5*size+x_frame+300+2,y_frame+220+2,0);
					
					delay(200);
					setfillstyle(SOLID_FILL,WHITE);
					floodfill(5*size+x_frame+300+2,y_frame+220+2,0);
					if(ve_2d ==1)
					{
						draw_OXY(BLUE);
						draw_clock();	
						clear_Screen();			
					}
					else if(ve_3d == 1)
					{
						draw_hinhCau();	
						clear_Screen();
					}
				}
				else if(5*size+x_frame+300 < x && x < 5*size+x_frame+550 && 
				y_frame+290<y && y<y_frame+340){
					
					setfillstyle(SOLID_FILL,YELLOW);
					floodfill(5*size+x_frame+300+2,y_frame+290+2,0);
					
					delay(200);
					setfillstyle(SOLID_FILL,WHITE);
					floodfill(5*size+x_frame+300+2,y_frame+290+2,0);
					if(ve_2d ==1)
					{
						draw_OXY(BLUE);
						draw_Space();
						clear_Screen();			
					}
					
				}
				else if(5*size+x_frame+350 <x && x <5*size+x_frame+500 && 
				y_frame+520< y && y< y_frame+570 && page!=0){
					
					setfillstyle(SOLID_FILL,YELLOW);
					floodfill(5*size+x_frame+350+2,y_frame+520+2,0);
					
					delay(200);
					setfillstyle(SOLID_FILL,WHITE);
					floodfill(5*size+x_frame+350+2,y_frame+520+2,0);
					
					page = 0;
					ve_2d = 0;
					ve_2d = 0;
					//draw_OXY(WHITE);
					interface_menu();
				}

			}
			
		}
		
	}
}
void menu()
{
	setcolor(0);
	settextstyle(3,0,2);

	clear_Screen();
	interface_menu();
	xuli_menu();
	
	reset_color();
	
}
