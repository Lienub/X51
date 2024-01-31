#ifndef TRANSFORMATIONS_VALEURS_H
#define TRANSFORMATIONS_VALEURS_H

#include "image.h"

Image <uint8_t> seuillage(const Image <uint8_t> &image, uint8_t s_min, uint8_t s_max);
Image <uint8_t> negatif(const Image <uint8_t> &image);
Image <uint8_t> quantification(const Image <uint8_t> &image, int k);
std::vector<int> histogramme(const Image <uint8_t> &image);
Image <uint8_t> etirement_contraste(const Image <uint8_t> &image, int new_min, int new_max);
Image <uint8_t> egalisation(const Image <uint8_t> &image);

#endif