#include "Shape.hpp"
#include <iostream>
using namespace std;    

//kurucu
Shape::Shape (int x,int y, int z, int width, int height, char karakter): x(x), y(y), z(z), width (width), height (height), cizimKarakteri(karakter){}
//yıkıcı
Shape::~Shape() {}


void Shape::move (int dx, int dy) //her şekil için ortak olan hareket fonksiyonu
    {
        this->x += dx;
        this->y += dy;
    }


int Shape::getZ()const   //her şekil için ortak olan getZ fonksiyonu
    {
        return this->z;
    }

