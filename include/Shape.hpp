#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string> //tür adını döndürmek için
#include <fstream> //dosya giriş çıkış

using namespace std;

class Shape
{

    protected: // triangle rectangle ve star doğrudan erişebilecek

    int x,y; //şeklin referans konumu
    int z; //çizim önceliği
    int width, height; //şeklin boyutları
    char cizimKarakteri; //şekli neyle çizdiğimiz * # @ gibi

    public:

    Shape(int x, int y, int z, int width, int height, char cizimKarakteri);  //bu benim shape sınıfımın constructorı
    
    virtual ~Shape(); //bu da destructor
    
    virtual void draw(char** screenBuffer)=0; //verilen ekrana şekli çizer

    virtual void save(ofstream& outFile)=0; //şeklin verilerin0i dosyaya kaydeder

    virtual string getType()const=0; 

    void move (int dx, int dy); 

    int getZ()const; 
};

#endif