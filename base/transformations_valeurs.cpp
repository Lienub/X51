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
    
    for(int i=0; i<image.getSize(); i++)
    {
        histo[image(i)]++;
    }

    for(int i=0; i<256; i++)
    {
        std::cout << i << " " << histo[i] << std::endl;
    }

    return histo;
}

Image <uint8_t> etirement_contraste(const Image <uint8_t> &image, uint8_t new_min, uint8_t new_max )
{
    std::cout << "avant" << std::endl;
    histogramme(image);

    Image <uint8_t> resultat(image.getDx(), image.getDy());


    uint8_t min = image.getMin();
    uint8_t max = image.getMax();

    // effectue un étirement de contraste de l'image entre les valeurs new_min et new_max.
    for(int i=0; i<image.getSize(); i++)
    {
        resultat(i) = (image(i)-min)*(new_max-new_min)/(max-min) + new_min;
    }

    std::cout << "apres" << std::endl;
    histogramme(resultat);

    return resultat;
}

Image <uint8_t> egalisation(const Image <uint8_t> &image)
{
    Image <uint8_t> resultat(image.getDx(), image.getDy());
  
    //  effectue une égalisation d'histogramme de l'image.
    std::vector<int> histo = histogramme(image);

    return resultat;
}

