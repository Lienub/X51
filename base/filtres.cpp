#include "filtres.h"
#include <cmath>


Image<uint8_t> convert_double_to_uint8(const Image<double> &image){
    Image<uint8_t> res(image.getDx(), image.getDy());

    for(int i = 0; i < res.getSize() ; i ++) {
        res(i) = (uint8_t)image(i);
    }

    return res;
}



double somme_ponderee(const Image <uint8_t> &image, const Image <double> &masque, int x, int y) 
{
    double resultat = 0.0;
    int dx = masque.getDx();
    int dy = masque.getDy();

    for (int i = 0; i < dx; i++) {
        for (int j = 0; j < dy; j++) {
            int nx = x - dx / 2 + i;
            int ny = y - dy / 2 + j;

            if (nx >= 0 && nx < image.getDx() && ny >= 0 && ny < image.getDy()) {
                resultat += image(nx,ny) * masque(i,j);
            }
        }
    }

        return resultat;

}

Image <double> convolution(const Image <uint8_t> &image, const Image <double> &masque)
{
    Image<double> resultat(image.getDx(), image.getDy());
    
    for(int i = 0 ; i < image.getDx() ; i++) {
        for (int j = 0; j < image.getDy() ; j++) {
            resultat(i,j) = somme_ponderee(image, masque, i, j);
        }
    }

    return resultat;

}

Image <double> masque_gaussien( double sigma)
{
    int taille = 3 * sigma;

    // Assurer que la taille est impaire pour un masque symétrique
    if (taille % 2 == 0) {
        taille++; // Augmenter la taille d'un pour la rendre impaire
    }

    // Créer le masque gaussien
    Image<double> masque(taille, taille);
    double somme = 0.0;

    // Remplir le masque avec les valeurs de la fonction de densité de probabilité gaussienne
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            int x = i - taille / 2;
            int y = j - taille / 2;
            masque(i, j) = exp(-(x*x+y*y)/(2*sigma*sigma));
            somme += masque(i, j); // Calculer la somme des valeurs pour la normalisation
        }
    }

    // Normaliser le masque
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            masque(i, j) /= somme;
        }
    }

    return masque;
}