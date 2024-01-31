#ifndef FILTRES_H
#define FILTRES_H

#include "image.h"

Image <double> convolution(const Image <uint8_t> &image, const Image <double> &masque);

#endif