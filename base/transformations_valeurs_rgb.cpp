#include "transformations_valeurs_rgb.h"
#include "transformations_valeurs.h"

Image<HSV> conversion_RGB_HSV(const Image<RGB> &imSource)
{
    Image <HSV> imResult(imSource.getDx(),imSource.getDy());

    return imResult;
}



Image<RGB> conversion_HSV_RGB(const Image<HSV> &imSource)
{
    Image <RGB> imResult(imSource.getDx(),imSource.getDy());

    return imResult;
}

Image <RGB> egalisation(const Image <RGB> &image)
{

    return image;
}

Image <RGB> egalisation_independante(const Image <RGB> &image)
{
  
    return image;
}