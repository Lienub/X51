#include "bruit.h"
#include <random>

Image <uint8_t> bruit_impulsionnel(const Image<uint8_t> &img, double p)
{
    Image <uint8_t> res(img);
    
   

    return res;
}
Image <uint8_t> bruit_gaussien(const Image<uint8_t> &img, double sigma)
{
    std::default_random_engine generator;

    Image <uint8_t> res(img);
    
    return res;
}
