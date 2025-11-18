#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Shape.hpp" //kalıtım alacağımız ana sınıfın başlık dosyasını dahil ettim



class Rectangle : public Shape
{
    public:

    Rectangle (int x, int y, int z, int width, int height, char karakter); //constructer

    virtual ~Rectangle(); //deconstructer

    virtual void draw (char** screenBuffer) override; //ekrana çizme fonksiyonu , draw fonksiyonunu override etti

    virtual void save (ofstream& outFile) override; //dosyaya kaydetme fonksiyonu , save fonksiyonunu override etti

    virtual string getType()const override; //şeklin türünü döndüren fonksiyon , getType fonksiyonunu override etti


};


#endif 