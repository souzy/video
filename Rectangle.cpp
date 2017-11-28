#include "Rectangle.h"
#include "frame.h"
extern Frame frame;

Rectangle::Rectangle(int w, int h, byte r, byte g, byte b, int x, int y) {
	this->w = w;
	this->h = h;
	this->x = x;
	this->y = y;
	this->r = r;
	this->g = g;
	this->b = b;
	this->dx = 0;	
	this->dy = 0;
}

void Rectangle::draw(double time){
	if (frame.isOutside(x, y)) return;
	int x0 = x;
	int x1 = x + w;
	int y0 = y;
	int y1 = y + h;
	// clamp(&x0, &y0);
	// clamp(&x1, &y1);
	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			frame.setPixel(x, y, r, g, b);
		}
	}
	this->x = this->dx * time;
	this->y = this->dy * time;
}

void Rectangle::speed(double dx, double dy){
	this->dx = dx;
	this->dy = dy;

}
