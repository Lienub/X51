#include "image.h"

#include <iostream>
#include <cstring> // memcpy

template<class T>
Image<T>::Image(int dx, int dy):dx(0),dy(0)
{
    if(dx>=0 && dy>=0) {
        this->dx=dx;
        this->dy=dy;
        this->size=dx*dy;
        this->pixels=std::vector<T>(this->size);
    }    
}

template<class T>
Image<T>::Image(int dx, int dy, const std::vector<T> &pixels)
{
    if(dx>=0 && dy>=0 && pixels.size() == (unsigned long)dx*dy) {
        this->dx=dx;
        this->dy=dy;
        this->size=dx*dy;
        this->pixels=pixels;
    }    
}

template<class T>
Image<T>::Image(const Image<T> &image)
{
    this->dx=image.dx;
    this->dy=image.dy;
    this->size=image.size;
    this->pixels=image.pixels;;    
}

template<class T>  
Image<T> &Image<T>::operator=(const Image<T> &image)
{
    if(this!=&image)
    {
    this->dx=image.dx;
    this->dy=image.dy;
    this->size=dx*dy;
    this->pixels=image.pixels;
    }
    return *this;
}

template<class T>
int Image<T>::getDx() const
{
    return dx;
}

template<class T>
int Image<T>::getDy() const
{
    return dy;
}

template<class T> 
int Image<T>::getSize() const
{
    return size;
}
    
template<class T> 
std::vector<T> Image<T>::getPixels() const
{
    return pixels;
}

/// valeur min
template<class T>
T Image<T>::getMin() const
{   
    if(this->pixels.size()==0) 
        return(T(0));
    T min=pixels[0];
    for(int i=0; i<size; ++i) {
        if(pixels[i] < min)
            min=pixels[i];
    }
    return min;
}

/// valeur max
template<class T>
T Image<T>::getMax() const
{
     if(this->pixels.size()==0) 
        return(T(0));
    T max=pixels[0];
    for(int i=0; i<size; ++i) {
        if(pixels[i] > max)
            max=pixels[i];
    }
    return max;
}
template<class T>
void Image<T>::print() const
{
    
    for(int x=0; x<dx; x++) {
        std::cout.width(3);
        std::cout << "----";
    }
    std::cout << "\n";
    
    for(int y=0; y<dy; y++) {
        for(int x=0; x<dx; x++) {
            std::cout.width(3);
            std::cout << (double)(*this)(x,y) << "|";
        }
        std::cout << "\n";
        for(int x=0; x<dx; x++) {
            std::cout.width(3);
            std::cout << "----";
        }
        std::cout << "\n";
    }
}

    
template<class T>
T &Image<T>::operator()(const int &x, const int &y)
{
    return pixels[y * this->dx + x];
}

template<class T>
T Image<T>::operator() (const int &x, const int &y) const
{
    return pixels[y * this->dx + x];
}

   
template<class T>
T &Image<T>::operator()(const int &i)
{
    return pixels[i];
}

template<class T>
T Image<T>::operator() (const int &i) const
{
    return pixels[i];
}
    