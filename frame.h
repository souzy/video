#pragma once
#include "global.h"
#include <cstdio>
class Frame {
        public:
                Frame(int w, int h); // {pixels = new unsigned char[W * H * 3]; }
		~Frame();
                void setPixel(int x, int y, byte r, byte g, byte b);
                void clear();
                bool isOutside(int x, int y) const;
                void writeFrame(FILE * file) const;

        private:
        int w;
        int h;
        unsigned char * pixels;
};
