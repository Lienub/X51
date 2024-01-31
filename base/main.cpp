#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <cassert>
#include "image.h"
#include "io.h"
#include "transformations_valeurs.h"
#include "transformations_valeurs_rgb.h"


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


int main(int argc, const char * argv[]) 
{
   
    std::cout << "Test des accesseurs aux pixels" << std::endl;
    
    test_accesseurs();

    std::cout << "Test des accesseurs aux pixels OK" << std::endl;



    return 0;
}
