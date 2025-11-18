#include "Shape.hpp"
#include <iostream>
using namespace std;    


Shape::Shape (int x,int y, int z, int width, int height, char karakter) //constructor
 : x(x), y(y), z(z), width (width), height (height), cizimKarakteri(karakter)
    {
         //kurucu gövdesi genelde boş olmalı çünkü iş başlatma listesinde yapılır
    }


Shape::~Shape()
    {
        //mesela burayı sonra bellek temizliği için kullanabiliriz gerekiirse
    }


void Shape::move (int dx, int dy) //her şekil için ortak olan hareket fonksiyonunu implement ettim
    {
        this->x += dx;
        this->y += dy;
    }


int Shape::getZ()const   //her şekil için ortak olan getZ fonksiyonunu implement ettim
    {
        return this->z;
    }

