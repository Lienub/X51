#include "transformations_valeurs.h"


Image <uint8_t> seuillage(const Image <uint8_t> &image, uint8_t s_min, uint8_t s_max)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
   
    for(int i=0; i<image.getSize(); i++)
    {
        if(image(i)>=s_min && image(i)<=s_max)
            resultat(i)=255;
        else
            resultat(i)=0;
    }

    return resultat;
}


Image <uint8_t> negatif(const Image <uint8_t> &image)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
   
    for(int i=0 ; i<image.getSize() ; i++) {
        resultat(i) = 255 - image(i);
    }

    return resultat;
}

Image <uint8_t> quantification(const Image <uint8_t> &image, int k)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
    // reechelonner les valeurs
    for(int i=0; i<resultat.getSize(); i++)
    {
        resultat(i) = (256/pow(2,k)) * (image(i)/(256/pow(2,k)));
    }

    return resultat;
}



std::vector<int> histogramme(const Image <uint8_t> &image)
{
    std::vector<int> histo(256,0);
    
    return histo;
}

Image <uint8_t> etirement_contraste(const Image <uint8_t> &image, uint8_t new_min, uint8_t )
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
   
    return resultat;
}

Image <uint8_t> egalisation(const Image <uint8_t> &image)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
  
    return resultat;
}

