#include "Rectangle.hpp"
#include <fstream>
using namespace std;


//BURAYA MUTLAKA BAK SONRA
// NOT: Bu sabitler geçicidir ve daha sonra merkezi bir Screen
// sınıfı veya yapılandırma dosyası tarafından yönetilmelidir.
const int SCREEN_WIDTH = 80; //Ekran genişliği
const int SCREEN_HEIGHT = 25; //Ekran yüksekliği

    Rectangle::Rectangle (int x, int y, int z, int width, int height, char karakter)
    : Shape (x, y, z, width, height, karakter) //ana sınıfın constructorını çağırdım
        {
            //kurucu gövdesi genelde boş olmalı çünkü iş başlatma listesinde yapılır
        }

        
    Rectangle::~Rectangle()
        {
            //sınıfta new ile özel bir bellek alanı ayrılmadığı için yıkıcının gövdesi boş kalsın
        }


    string Rectangle::getType()const  // getType fonksiyonunu implementasyon
        {
            return "Rectangle"; //şeklin türünü "rectangle" döndürüyor
        }


    void Rectangle::save (ofstream& outFile)  // save fonksiyonunu implementasyon
        {
            //şeklin tüm özelliklerini dosyaya kaydediyor
            outFile << getType() << " " << x << " " << y << " " << z << " " << width << " " << height << " " << cizimKarakteri << endl;
        }



    
            
    void Rectangle::draw(char** screenBuffer) // draw'fonksiyonunun implementasyonu:  
                                            // Doldurulmuş bir dikdörtgen çizmek için iç içe iki 'for' döngüsü kullanılır.     
                                             // Dış döngü satırları (y), iç döngü sütunları (x) gezer.
        {
      
            for (  int i = this->y;    i < this->y + this->height;     ++i  ) 
                
                {   
                
                    if (i < 0 || i >= SCREEN_HEIGHT)
                        {
                            continue;
                        }

                    for (int j = this->x; j < this->x + this->width; ++j) 
                        {
                            
                            if (j < 0 || j >= SCREEN_WIDTH) 
                                {
                                    continue; 
                                }

                            screenBuffer[i][j] = this->cizimKarakteri;
                        }
                }
        }





    