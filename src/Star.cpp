#include "Star.hpp"
#include <fstream>
#include "Screen.hpp"
using namespace std;

    Star::Star (int x, int y, int z, int width, int height, char karakter) : Shape (x, y, z, width, height, karakter) {} 
    Star::~Star(){}

        
    //tür adını döndüren method
    string Star::getType()const  
        {
            return "Star";
        }


    void Star::save(std::ofstream& file) 
    {
    file << getType() 
         << "\t\t| X: " << this->x   // Star kelimesi kısa olduğu için 2 tane \t koydum hizalansın diye
         << " \t| Y: " << this->y 
         << " \t| Z: " << this->z 
         << " \t| Gen: " << this->width 
         << " \t| Yuk: " << this->height 
         << " \t| Sembol: " << this->cizimKarakteri << "\n";
    }



    
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
            if (gecerliSutun < 16) continue;
            // ------------------

            if (gecerliSutun >= 0 && gecerliSutun < SCREEN_WIDTH) {
                screenBuffer[ortaSatir][gecerliSutun] = this->cizimKarakteri;
        }
    }

    // 2. Dikey çizgiyi çiz
    // Tamsayı bölmesi sayesinde hem tek (örn: 5/2 = 2)
    // hem de çift (örn: 6/2 = 3) genişlikler için çalışır.
    int ortaSutun = this->x + (this->width / 2); 
if (ortaSutun >= 16 && ortaSutun < SCREEN_WIDTH) 
{ 
    // --------------------------------------------------------------
        for (int i = 0; i < this->height; ++i) 
        {
            int gecerliSatir = this->y + i;
            if (gecerliSatir >= 0 && gecerliSatir < SCREEN_HEIGHT) 
            {
                screenBuffer[gecerliSatir][ortaSutun] = this->cizimKarakteri;
         }}}


}}   