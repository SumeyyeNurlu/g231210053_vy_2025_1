#include "Star.hpp"
#include <fstream>
using namespace std;


//BURAYA MUTLAKA BAK SONRA
// NOT: Bu sabitler geçicidir ve daha sonra merkezi bir Screen
// sınıfı veya yapılandırma dosyası tarafından yönetilmelidir.
const int SCREEN_WIDTH = 80; //Ekran genişliği
const int SCREEN_HEIGHT = 25; //Ekran yüksekliği

    Star::Star (int x, int y, int z, int width, int height, char karakter)
    : Shape (x, y, z, width, height, karakter) //ana sınıfın constructorını çağırdım
        {
            //kurucu gövdesi genelde boş olmalı çünkü iş başlatma listesinde yapılır
        }

        
    Star::~Star()
        {
            //sınıfta new ile özel bir bellek alanı ayrılmadığı için yıkıcının gövdesi boş kalsın
        }


    string Star::getType()const  // getType fonksiyonunu implementasyon
        {
            return "Star"; //şeklin türünü "Star" döndürüyor
        }


    void Star::save (ofstream& outFile)  // save fonksiyonunu implementasyon
        {
            //şeklin tüm özelliklerini dosyaya kaydediyor
            outFile << getType() << " " << x << " " << y << " " << z << " " << width << " " << height << " " << cizimKarakteri << endl;
        }



    
            //BURAYI KONTROL EDECEĞİZ YİNE MUTLAKAAAAAA
  void Star::draw(char** screenBuffer) 
  {
    
    // --- Çizim Mantığı ---

    // 1. Yatay çizgiyi çiz
    // Tamsayı bölmesi sayesinde hem tek (örn: 5/2 = 2)
    // hem de çift (örn: 6/2 = 3) yükseklikler için çalışır.
    int ortaSatir = this->y + (this->height / 2); 

    // Dikey sınır kontrolü (Satır ekran dışında mı?)
    if (ortaSatir >= 0 && ortaSatir < SCREEN_HEIGHT) {
        // Genişlik (width) boyunca tüm sütunları çiz
        for (int j = 0; j < this->width; ++j) {
            int gecerliSutun = this->x + j;
            // Yatay sınır kontrolü (Sütun ekran dışında mı?)
            if (gecerliSutun >= 0 && gecerliSutun < SCREEN_WIDTH) {
                screenBuffer[ortaSatir][gecerliSutun] = this->cizimKarakteri;
            }
        }
    }

    // 2. Dikey çizgiyi çiz
    // Tamsayı bölmesi sayesinde hem tek (örn: 5/2 = 2)
    // hem de çift (örn: 6/2 = 3) genişlikler için çalışır.
    int ortaSutun = this->x + (this->width / 2); 

    // Yatay sınır kontrolü (Sütun ekran dışında mı?)
    if (ortaSutun >= 0 && ortaSutun < SCREEN_WIDTH) {
        // Yükseklik (height) boyunca tüm satırları çiz
        for (int i = 0; i < this->height; ++i) {
            int gecerliSatir = this->y + i;
            // Dikey sınır kontrolü (Satır ekran dışında mı?)
            if (gecerliSatir >= 0 && gecerliSatir < SCREEN_HEIGHT) {
                screenBuffer[gecerliSatir][ortaSutun] = this->cizimKarakteri;
            }
        }
    }
}