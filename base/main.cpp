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
    // test_lecture_ecriture("../test-images/baboon.ppm");
    // std::cout << "Test des accesseurs aux pixels" << std::endl;
    
    // test_accesseurs();

    // std::cout << "Test des accesseurs aux pixels OK" << std::endl;

    Image<uint8_t> img = readPGM("../test-images/grumpy.pgm");
    std::vector<double> pixels{1.0/16, 2.0/16, 1.0/16, 2.0/16, 4.0/16, 2.0/16, 1.0/16, 2.0/16, 1.0/16};
    Image<double> masque(3,3, pixels);
    Image<double> gauss = masque_gaussien(70);
    Image<double> conv = convolution(img, gauss);
    Image<uint8_t> result = convert_double_to_uint8(conv);
    // writePGM(seuillage(img, 110, 255), "seuillage.pgm");
    // writePGM(negatif(img), "negatif.pgm");
    writePGM(result, "convolution.pgm");

    

    return 0;
}²²
