#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

struct RGB {
    uint8_t r;  
    uint8_t g; 
    uint8_t b;

    RGB() {};

    RGB(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}

    // copy constructor
    RGB(const RGB &rgb) : r(rgb.r), g(rgb.g), b(rgb.b) {}

   // affectation operator
    RGB& operator=(const RGB &rgb) {
        r = rgb.r;
        g = rgb.g;
        b = rgb.b;
        return *this;
    }

    // equality operator
    bool operator==(const RGB &rgb) const {
        return (r == rgb.r && g == rgb.g && b == rgb.b);
    }
};

struct HSV {
    double h;  
    double s; 
    double v;

    HSV(double h, double s, double v) : h(h), s(s), v(v) {}
    HSV() {};

    // copy constructor
    HSV(const HSV &hsv) : h(hsv.h), s(hsv.s), v(hsv.v) {}

    // affectation operator
    HSV& operator=(const HSV &hsv) {
        h = hsv.h;
        s = hsv.s;
        v = hsv.v;
        return *this;
    }
    // equality operator
    bool operator==(const HSV &hsv) const {
        return (h == hsv.h && s == hsv.s && v == hsv.v);
    }
};


#endif