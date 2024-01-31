#include "transformations_valeurs.h"


Image <uint8_t> seuillage(const Image <uint8_t> &image, uint8_t s_min, uint8_t s_max)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
   
    return resultat;
}


Image <uint8_t> negatif(const Image <uint8_t> &image)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
   
    return resultat;
}

Image <uint8_t> quantification(const Image <uint8_t> &image, int k)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());

    return resultat;
}



std::vector<int> histogramme(const Image <uint8_t> &image)
{
    std::vector<int> histo(256,0);
    
    return histo;
}

Image <uint8_t> etirement_contraste(const Image <uint8_t> &image, int new_min, int new_max)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
   
    return resultat;
}

Image <uint8_t> egalisation(const Image <uint8_t> &image)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
  
    return resultat;
}

