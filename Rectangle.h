#pragma once
#include "global.h"

class Rectangle {
	public:
        Rectangle(int w, int h, byte r, byte g, byte b, int x, int y);
	void draw(double time);
	void speed(double dx, double dy);
	
	private:
	int w;
	int h;
	int x;
	int y;
	byte r;
	byte g;
	byte b;
	double dx;
	double dy;
};
