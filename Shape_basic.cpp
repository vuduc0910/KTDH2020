#include <graphics.h>
#include <iostream>
#include "data.h"
#include "Function_basic.h"
#include <math.h>
#define ROUND(a) (int)(a+0.5)
#define PI 3.14159265359

using namespace std;

void paint_Box(int x1, int y1, int x2, int y2, int col, int col_border)
{
	setcolor(col_border);
	rectangle(x1,y1,x2+5,y2+5);
	setfillstyle(SOLID_FILL,col);
	floodfill(x1+2,y1+2,col_border);
	reset_color();	
}

//Ve Tam giac
void draw_Triangle(int x1, int y1, int x2, int y2, int x3, int y3,int color){
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	line(x1,y1,x2,y2);
	line(x1,y1,x3,y3);
	line(x2,y2,x3,y3);
	floodfill(((x1+x3)/2+x2)/2, ((y1+y3)/2+y2)/2, color);
	reset_color();
}

void put_5pixel(int x,int y, int col){
	
	x=x/5*5;
	y=y/5*5;
	setcolor(col);
	rectangle(x,y,x+4,y+4);
	setfillstyle(SOLID_FILL,col);
	floodfill(x+2,y+2,col);
	reset_color();	
}

void Hoan_vi(int &a,int &b){
	int tmp=a;
	a=b;
	b=tmp;
}

void line_5pixel(int x1,int y1,int x2,int y2, int col){
	
	int x,y,dx,dy,p,p1,p2;
	if(x1>x2){
		Hoan_vi(x1,x2);
	 	Hoan_vi(y1,y2);
	}
	//put_5pixel(x,y,col);
	
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	if(dy<dx){
		p=2*dy-dx;
		put_5pixel(x,y,col);
		
		while(x<=x2){
			x+=5;
			if(p<0)
				p+=2*dy;
			else{   
				if(y1<y2){
					y+=5;
					p+=2*(dy-dx);
				   }else{
					y-=5;
					p+=2*(dy-dx);
				}
			}
			put_5pixel(x,y,col);
		}
	}
	else{
		p=2*dx-dy;
		put_5pixel(x,y,col);
		
		if(y1<y2){
			while(y<=y2){
				y+=5;
				if(p<0)
					p+=2*dx;
				else{
					x+=5;
					p+=2*(dx-dy);
				}
				put_5pixel(x,y,col);

			}
		}
		else{
			while(y>=y2){
				y-=5;
				if(p<0)
					p+=2*dx;
				else{
					x+=5;
					p+=2*(dx-dy);
				}
				put_5pixel(x,y,col);
				
			}
		}
	}
}

void line_netDut(int x1,int y1,int x2,int y2, int col)
{
	int x,y,dx,dy,p,p1,p2;
	if(x1>x2){
		Hoan_vi(x1,x2);
	 	Hoan_vi(y1,y2);
	}
	//put_5pixel(x,y,col);
	
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	if(dy<dx){
		p=2*dy-dx;
		put_5pixel(x,y,col);
		
		while(x<=x2){
			x+=5;
			if(p<0)
				p+=2*dy;
			else{   
				if(y1<y2){
					y+=5;
					p+=2*(dy-dx);
				   }else{
					y-=5;
					p+=2*(dy-dx);
				}
			}
			if(x%30 ==0 )
			{
				put_5pixel(x,y,WHITE);
				
			}else{
				put_5pixel(x,y,col);
			}
			
		}
	}
	else{
		p=2*dx-dy;
		put_5pixel(x,y,col);
		
		if(y1<y2){
			while(y<=y2){
				y+=5;
				if(p<0)
					p+=2*dx;
				else{
					x+=5;
					p+=2*(dx-dy);
				}
				if(y%30 ==0 )
				{
					put_5pixel(x,y,WHITE);
					
				}else{
					put_5pixel(x,y,col);
				}

			}
		}
		else{
			while(y>=y2){
				y-=5;
				if(p<0)
					p+=2*dx;
				else{
					x+=5;
					p+=2*(dx-dy);
				}
				if(y%30 ==0 )
				{
					put_5pixel(x,y,WHITE);
					
				}else{
					put_5pixel(x,y,col);
				}
					
			}
		}
	}
}

void ve_8Diem(int xc, int yc, int x, int y, int color)
{
    put_5pixel(x + xc, y + yc,color);
    put_5pixel(-x + xc, y + yc, color);
    put_5pixel(x + xc, -y + yc, color);
    put_5pixel(-x + xc, -y + yc, color);
    put_5pixel( y + xc, x + yc, color);
    put_5pixel(-y + xc, x + yc, color);
    put_5pixel(y + xc, -x + yc, color);
    put_5pixel(-y + xc, -x + yc, color);
}
void draw_Circle(int xc,int yc,int r,int color) {	

    int x = 0, y = r;
    int f = 1 - r;   //	5/4 - r
    ve_8Diem(xc, yc, x, y,color);

    while (x < y)
    {
        if (f < 0) f += (x << 1) + 3;
        else
        {
            y-=5;
            f += ((x - y) << 1) + 5;
        }
        x+=5;
        ve_8Diem(xc, yc, x, y,color);
    }

}

void Ve4diem(int xc,int yc,int x, int y, int color)
{
    
    put_5pixel(xc+x,yc+y,color);
    put_5pixel(xc-x,yc+y,color);
   
    if(x% 10 ==0)
    {
    	put_5pixel(xc-x,yc-y,color);
    	put_5pixel(xc+x,yc-y,color);
	}
    
   
}

void draw_elipse(int xc, int yc, int a,int b,int color)
{
	float p,a2,b2;
    int x,y;
    a2=pow(a,2);
    b2=pow(b,2);
    x=0;
    y=b;
     
    p=2*((float)b2/a2)-(2*b)+1;
     
    //ve nhanh thu 1(tu tren xuong )
    while(((float)b2/a2)*x<=y)
    {
        Ve4diem(xc,yc,x,y,color);
        if(p<0)
        {
            p=p+2*((float)b2/a2)*(2*x+3);
        }
        else{
            p= p- 4*y + 2*((float)b2/a2)*(2*x+3);
            y-=5;
        }
        x+=5;
    }
    //ve nhanh thu 2(tu duoi len )
    y=0;
    x=a;
    p=2*((float)a2/b2)-2*a+1;
    while(((float)a2/b2)*y<=x)
    {
        Ve4diem(xc,yc,x,y,color);
        if(p<0)
        {
            p=p +2*((float)a2/b2)*(2*y+3);
        }
        else
        {
            p=p- 4*x + 2*((float)a2/b2)*(2*y+3);
            x-=5;
        }
        y+=5;
    }
}


