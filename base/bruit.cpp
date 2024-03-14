#include "bruit.h"
#include <random>

Image <uint8_t> bruit_impulsionnel(const Image<uint8_t> &img, double p)
{
    Image <uint8_t> res(img);

    for (int i = 0; i< img.getDx(); i++) {
        for (int j = 0 ; j < img.getDy() ; j++ ) {
            double pick = (double)rand() / RAND_MAX;

            if (pick > 0 && pick < p) {
                double r = (double)rand() / RAND_MAX;
                if(r < 0.5) {
                    res(i,j) = 0;
                } else {
                    res(i,j) = 255;
                }
            }            
        }
    }
    
   

    return res;
}
Image <uint8_t> bruit_gaussien(const Image<uint8_t> &img, double sigma)
{
    std::default_random_engine generator;

    Image <uint8_t> res(img);

    std::normal_distribution<double> distribution(0.0, sigma);

    for (int i = 0; i< img.getDx(); i++) {
        for (int j = 0 ; j < img.getDy() ; j++ ) {
            // Generation d'un nombre aléatoire suivant la loi de la probabilité gaussienne
            double r = distribution(generator);

            double v = img(i,j) + r;

            // On tronque l'image
            if (v < 0) {
                res(i,j) = 0;
            } else if (v > 255) {
                res(i,j) = 255;
            } else {
                res(i,j) = v;
            }
        }
    }

    return res;
}
