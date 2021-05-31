#include <graphics.h>
#include <iostream>
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
