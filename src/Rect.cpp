#include "Rect.hpp"
#include <fstream>

#include "Screen.hpp"
using namespace std;

    Rect::Rect (int x, int y, int z, int width, int height, char karakter) : Shape (x, y, z, width, height, karakter) 
        {
            //kurucu gövdesi genelde boş 
        }

        
    Rect::~Rect()
        {
            //sınıfta new ile özel bir bellek alanı ayrılmadığı için yıkıcının gövdesi boş kalsın
        }


    string Rect::getType()const  
        {
            return "Rect"; 
        }


    void Rect::save(std::ofstream& file) 
    {
    file << getType() 
         << "\t| X: " << this->x 
         << " \t| Y: " << this->y 
         << " \t| Z: " << this->z 
         << " \t| Gen: " << this->width 
         << " \t| Yuk: " << this->height 
         << " \t| Sembol: " << this->cizimKarakteri << "\n";
    }


            
    void Rect::draw(char** screenBuffer)  
        {
            for (  int i = this->y;    i < this->y + this->height;     ++i  ) 

                    {   
                    
                        if (i < 0 || i >= SCREEN_HEIGHT)
                            {
                                continue;
                            }

                        for (int j = this->x; j < this->x + this->width; ++j) 
                            {
                                if (j < 16) continue; 
            
                                    if (j >= SCREEN_WIDTH) continue;

                                screenBuffer[i][j] = this->cizimKarakteri;
                            }
                    }
        }





    