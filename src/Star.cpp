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


    //yıldız çizme *
void Star::draw(char** screenBuffer) 
{
  
    int ortaNokta = this->height / 2;

    for (int i = 0; i < this->height; ++i) 
    {
        int gecerliSatir = this->y + i;
        if (gecerliSatir < 0 || gecerliSatir >= SCREEN_HEIGHT) continue;

        int yildizSayisi = 0;
        if (i <= ortaNokta)
        {
            yildizSayisi = (int)( ((float)(i + 1) / (ortaNokta + 1)) * this->width );
        }
        else 
        {
            int alttanSira = this->height - 1 - i;
            yildizSayisi = (int)( ((float)(alttanSira + 1) / (ortaNokta + 1)) * this->width );
        }
        
        if (yildizSayisi % 2 == 0)
        {
            yildizSayisi--;
        }

        if (yildizSayisi < 1) yildizSayisi = 1;
        
        if (yildizSayisi > this->width) yildizSayisi = this->width;

        int solBosluk = (this->width - yildizSayisi) / 2;
        int baslangicSutun = this->x + solBosluk;

        for (int j = 0; j < yildizSayisi; ++j) 
        {
            int gecerliSutun = baslangicSutun + j;

            if (gecerliSutun < 16) continue; 
            if (gecerliSutun >= SCREEN_WIDTH) continue; 

            screenBuffer[gecerliSatir][gecerliSutun] = this->cizimKarakteri;
        }
    }
}