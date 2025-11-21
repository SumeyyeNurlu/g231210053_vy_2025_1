#ifndef RECT_HPP
#define RECT_HPP
#include "Shape.hpp" //kalıtım alacağımız ana sınıf
#include "Screen.hpp" 

class Rect : public Shape
{
    public:

    Rect (int x, int y, int z, int width, int height, char karakter); //kurucu

    virtual ~Rect(); //yıkıcı

    virtual void draw (char** screenBuffer) override; 

    virtual void save (ofstream& outFile) override;

    virtual string getType()const override;

};

#endif 