#include "filtres.h"

Image<uint8_t> convert_double_to_uint8(const Image<double> &image){
    Image<uint8_t> res(image.getDx(), image.getDy());
    return res;
}



double somme_ponderee(const Image <uint8_t> &image, const Image <double> &masque, int x, int y) 
{
    return 0.0;
}

Image <double> convolution(const Image <uint8_t> &image, const Image <double> &masque)
{
    return Image <double> (image.getDx(), image.getDy());

}

Image <double> masque_gaussien( double sigma)
{
    return Image <double> (1, 1);
}