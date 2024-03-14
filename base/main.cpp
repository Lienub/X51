#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <cassert>
#include "image.h"
#include "io.h"
#include "transformations_valeurs.h"
#include "transformations_valeurs_rgb.h"
#include "filtres.h"
#include "bruit.h"


void test_accesseurs()
{
    Image <uint8_t> im(10,10);

    // test des accesseurs () par indice
    for (int i=0; i<im.getSize(); i++)
    {
        im(i)=i;
    }

    for(int i=0; i<im.getSize(); i++)
    {
        assert(im(i)==i);
    }

    // test des accesseurs () par coordonnées
    for (int y=0; y<im.getDy(); y++)
    {
        for (int x=0; x<im.getDx(); x++)
        {
            im(x,y)=x+y;
        }
    }

     for (int y=0; y<im.getDy(); y++)
    {
        for (int x=0; x<im.getDx(); x++)
        {
            assert(im(x,y)==x+y);
        }
    }

}

int print_info(const Image<uint8_t> &image) {
    std::cout << "Width: " << image.getDx() << std::endl;
    std::cout <<  "Height: " << image.getDy() << std::endl;
    std::cout << "Size: " << image.getSize() << std::endl;
    std::vector<uint8_t> pixels = image.getPixels();
    int sum = 0;
    for (int i = 0; i < pixels.size(); i++) {
        sum += pixels[i];
    }
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Min: " << (int)(image.getMin()) << std::endl;
    std::cout << "Max: " << (int)(image.getMax()) << std::endl;
    std::cout << "Mean Greyscale: " << sum / pixels.size() << std::endl;
    return 0;
}

int test_lecture_ecriture(const std::string &filename) {
    if (filename.substr(filename.find_last_of(".") + 1) == "pgm") {
        Image<uint8_t> img = readPGM(filename);
        writePGM(img, "test.pgm");
        print_info(img);
    } else if (filename.substr(filename.find_last_of(".") + 1) == "ppm") {
        Image<RGB> img = readPPM(filename);
        writePPM(img, "test.ppm");
    }
    return 0;
}


int main(int argc, const char * argv[]) 
{
    test_lecture_ecriture("../test-images/baboon.ppm");
    std::cout << "Test des accesseurs aux pixels" << std::endl;
    
    test_accesseurs();

    std::cout << "Test des accesseurs aux pixels OK" << std::endl;

    // Tests

    Image<uint8_t> img = readPGM("../test-images/grumpy.pgm");

    std::cout << "Test bruit impulsionnel 15% :";
    Image<uint8_t> bruit_imp_15 = bruit_impulsionnel(img, 0.15);
    std::cout << " OK" << std::endl;

    std::cout << "Test bruit impulsionnel 40% :";
    Image<uint8_t> bruit_imp_40 = bruit_impulsionnel(img, 0.4);
    std::cout << " OK" << std::endl;
    
    std::cout << "Bruit gaussien moyenne 0 ecart type 15 :";
    Image<uint8_t> bruit_gauss_15 = bruit_gaussien(img, 15);
    std::cout << " OK" << std::endl;

    std::cout << "Bruit gaussien moyenne 0 ecart type 30 :";
    Image<uint8_t> bruit_gauss_30 = bruit_gaussien(img, 30);
    std::cout << " OK" << std::endl;

    // Ecriture des images
    writePGM(bruit_imp_15, "../res-images/bruit_imp_15.pgm");
    writePGM(bruit_imp_40, "../res-images/bruit_imp_40.pgm");
    writePGM(bruit_gauss_15, "../res-images/bruit_gauss_15.pgm");
    writePGM(bruit_gauss_30, "../res-images/bruit_gauss_30.pgm");

    return 0;
}
 