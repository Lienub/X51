#ifndef BRUIT_H 
#define BRUIT_H

#include "image.h"

Image <uint8_t> bruit_impulsionnel(const Image<uint8_t> &img, double p);
Image <uint8_t> bruit_gaussien(const Image<uint8_t> &img, double sigma);
#endif