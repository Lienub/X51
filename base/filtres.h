#ifndef FILTRES_H
#define FILTRES_H

#include "image.h"


Image<uint8_t> convert_double_to_uint8(const Image<double> &image);

double somme_ponderee(const Image <uint8_t> &image, const Image <double> &masque, int x, int y);

Image <double> convolution(const Image <uint8_t> &image, const Image <double> &masque);

Image <double> masque_gaussien( double sigma);

Image <uint8_t> filtre_median(const Image <uint8_t> &image, int taille_fenetre);


#endif