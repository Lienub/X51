#ifndef TRANSFORMATIONS_VALEURS_RGB_H
#define TRANSFORMATIONS_VALEURS_RGB_H

#include "image.h"


Image <RGB> quantification(const Image <RGB> &image, int k);
Image <RGB> egalisation(const Image <RGB> &image);
Image <RGB> egalisation_independante(const Image <RGB> &image);
Image <HSV> conversion_RGB_HSV(const Image <RGB> &image);
Image <RGB> conversion_HSV_RGB(const Image <HSV> &image);


#endif