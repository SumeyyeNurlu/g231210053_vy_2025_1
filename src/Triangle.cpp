#include "Triangle.hpp"
#include <fstream>
using namespace std;


//BURAYA MUTLAKA BAK SONRA
// NOT: Bu sabitler geçicidir ve daha sonra merkezi bir Screen
// sınıfı veya yapılandırma dosyası tarafından yönetilmelidir.
const int SCREEN_WIDTH = 80; //Ekran genişliği
const int SCREEN_HEIGHT = 25; //Ekran yüksekliği

    Triangle::Triangle (int x, int y, int z, int width, int height, char karakter)
    : Shape (x, y, z, width, height, karakter) //ana sınıfın constructorını çağırdım
        {
            //kurucu gövdesi genelde boş olmalı çünkü iş başlatma listesinde yapılır
        }

        
    Triangle::~Triangle()
        {
            //sınıfta new ile özel bir bellek alanı ayrılmadığı için yıkıcının gövdesi boş kalsın
        }


    string Triangle::getType()const  // getType fonksiyonunu implementasyon
        {
            return "Triangle"; //şeklin türünü "triangle" döndürüyor
        }


    void Triangle::save (ofstream& outFile)  // save fonksiyonunu implementasyon
        {
            //şeklin tüm özelliklerini dosyaya kaydediyor
            outFile << getType() << " " << x << " " << y << " " << z << " " << width << " " << height << " " << cizimKarakteri << endl;
        }




        
// 'draw' fonksiyonunun  implementasyonu:
void Triangle::draw(char** screenBuffer) {
    
    // Satır satır (y ekseni) ilerle
    for (int i = 0; i < this->height; ++i) { // i = 0'dan (height-1)'e
        
        int gecerliSatir = this->y + i;

        // Dikey Sınır Kontrolü:
        if (gecerliSatir < 0 || gecerliSatir >= SCREEN_HEIGHT) {
            continue; 
        }

        // 1. Bu satırın genişliğini 'height'e göre hesapla (1, 3, 5...)
        //    (i = 0 ise genişlik 1, i = 1 ise genişlik 3, ...)
        int satirGenisligi = (i * 2) + 1;

        // 2. Piramidi, 'this->width' tarafından tanımlanan
        //    sınırlayıcı kutunun (bounding box) içinde merkezle.
        int boslukSayisi = (this->width - satirGenisligi) / 2;

        // 3. Çizime başlanacak Sütun (X) koordinatını hesapla
        int baslangicSutunu = this->x + boslukSayisi;

        // 4. Hesaplanan satır genişliği kadar karakteri çiz
        for (int j = 0; j < satirGenisligi; ++j) {
            
            int gecerliSutun = baslangicSutunu + j;

            // Yatay Sınır Kontrolü:
            if (gecerliSutun >= 0 && gecerliSutun < SCREEN_WIDTH) {
                screenBuffer[gecerliSatir][gecerliSutun] = this->cizimKarakteri;
            }
        }
    }
}