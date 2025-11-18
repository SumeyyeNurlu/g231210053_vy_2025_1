#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "Shape.hpp" //kalıtım alacağımız ana sınıfın başlık dosyasını dahil ettim



class Triangle : public Shape
{
    public:

    Triangle (int x, int y, int z, int width, int height, char karakter); //constructer

    virtual ~Triangle(); //deconstructer

    virtual void draw (char** screenBuffer) override; //ekrana çizme fonksiyonu , draw fonksiyonunu override etti

    virtual void save (ofstream& outFile) override; //dosyaya kaydetme fonksiyonu , save fonksiyonunu override etti

    virtual string getType()const override; //şeklin türünü döndüren fonksiyon , getType fonksiyonunu override etti


};


#endif 