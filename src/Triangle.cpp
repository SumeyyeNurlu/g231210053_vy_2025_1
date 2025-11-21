#include "Triangle.hpp"
#include <fstream>

#include "Screen.hpp"
using namespace std;

    Triangle::Triangle (int x, int y, int z, int width, int height, char karakter): Shape (x, y, z, width, height, karakter){} 
    Triangle::~Triangle(){}
        


    string Triangle::getType()const  
        {
            return "Triangle"; 
        }


    void Triangle::save(std::ofstream& file) 
    {
    file << getType() 
         << "\t| X: " << this->x 
         << " \t| Y: " << this->y 
         << " \t| Z: " << this->z 
         << " \t| Gen: " << this->width 
         << " \t| Yuk: " << this->height 
         << " \t| Sembol: " << this->cizimKarakteri << "\n";
    }



void Triangle::draw(char** screenBuffer)
 {
    
    
    for (int i = 0; i < this->height; ++i) 
    { 
        int gecerliSatir = this->y + i;

        // dikey sınır kontrolü
        if (gecerliSatir < 0 || gecerliSatir >= SCREEN_HEIGHT) 
        {
            continue; 
        }

        int satirGenisligi = (i * 2) + 1;
        int boslukSayisi = (this->width - satirGenisligi) / 2;
        int baslangicSutunu = this->x + boslukSayisi;

        for (int j = 0; j < satirGenisligi; ++j) 
        {
             int gecerliSutun = baslangicSutunu + j;
             if (gecerliSutun < 16) continue; 
             if (gecerliSutun >= SCREEN_WIDTH) continue;

            screenBuffer[gecerliSatir][gecerliSutun] = this->cizimKarakteri;
        }
    }
}