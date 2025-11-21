#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "Shape.hpp" //kalıtım alacağımız ana sınıf
#include "Screen.hpp" 


class Triangle : public Shape
{
    public:

    Triangle (int x, int y, int z, int width, int height, char karakter); //kurucu

    virtual ~Triangle(); //yıkıcı

    virtual void draw (char** screenBuffer) override; 

    virtual void save (ofstream& outFile) override; 

    virtual string getType()const override; 
};


#endif 