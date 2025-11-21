#ifndef STAR_HPP
#define STAR_HPP
#include "Shape.hpp" //kalıtım alacağımız ana sınıf
#include "Screen.hpp" 


class Star : public Shape
{
    public:

    Star (int x, int y, int z, int width, int height, char karakter); //kurucu

    virtual ~Star(); //yıkıcı

    virtual void draw (char** screenBuffer) override; 
    virtual void save (ofstream& outFile) override;
    virtual string getType()const override; 

};


#endif 