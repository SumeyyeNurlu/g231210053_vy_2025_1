#ifndef SCREEN_HPP
#define SCREEN_HPP
#include "DoublyLinkedList.hpp"

using namespace std;

class Screen
{
    private:

    //ekran verisi
    char** buffer; 
    int width;
    int height;

    public:

    //kurucu 
    Screen(int w, int h); 

    // Yıkıcı: Belleği temizler
    ~Screen();



    //ekranı sildi
    void clear();
    
   //ekranı yazdırır
    void print();
    
    //ekran verisini döndürür
    char** getBuffer();
    
    //çizim arayüzü
    void drawUI(DoublyLinkedList* mainList);



};




#endif