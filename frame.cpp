#include <stdio.h>
#include <cstring>
#include "frame.h"
#include "Rectangle.h"
Frame::Frame(int w, int h) {
    this->w = w;
    this->h = h;
    pixels = new byte[w * h * 3];
}

Frame::~Frame() {
    delete pixels;
}

void Frame::setPixel(int x, int y, byte r, byte g, byte b){
    pixels[y * w * 3 + x * 0] = r;
    pixels[y * w * 3 + x * 1] = g;
    pixels[y * w * 3 + x * 2] = b;
}

void Frame::clear() {
  memset(pixels, 0, h * w * 3);
}

bool Frame::isOutside(int x, int y) const {
  return x < 0 || x >= w || y < 0 || y >=h;
}

void Frame::writeFrame(FILE * file) const{
  fwrite(pixels, 3, w * h, file);
}
