#include "Screen.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

//kurucu
Screen::Screen(int w, int h) : width(w), height(h) 
{
    buffer = new char*[height];
    for (int i = 0; i < height; ++i) 
    {
        buffer[i] = new char[width];
        for (int j = 0; j < width; ++j) 
        {
            buffer[i][j] = ' ';
        }
    }
}

//yıkıcı belleği temizle
Screen::~Screen() 
{
    for (int i = 0; i < height; ++i) 
    {
        delete[] buffer[i];
    }
    delete[] buffer;
}

//ekranı silme
void Screen::clear() 
{
    for (int i = 0; i < height; ++i) 
    {
        for (int j = 0; j < width; ++j) 
        {
            buffer[i][j] = ' ';
        }
    }
}

//ekranı yazdırma
void Screen::print()
 {
    
    for (int i = 0; i < height; ++i) 
    {
        for (int j = 0; j < width; ++j) 
        {
            cout << buffer[i][j];
        }
        cout << "\n"; 
    }
}



// ekran verisi 
char** Screen::getBuffer() 
{
    return buffer;
}


//çizim arayüzü
void Screen::drawUI(DoublyLinkedList* mainList) 
{
    if (!mainList) return;

    int boxHeight = 3; 
    int gap = 1;       
    int itemTotalH = boxHeight + gap; 
    
    int startY = 0;   

    int maxVisibleItems = (height - startY) / itemTotalH;

    //  imleç kaçıncı sırada
    int cursorIndex = mainList->getCursorIndex() - 1; 
    if (cursorIndex < 0) cursorIndex = 0;
    int pageNumber = cursorIndex / maxVisibleItems;

    // başlayacağımız düğüm sayfanın ilk düğümüdür
    int startNodeIndex = pageNumber * maxVisibleItems;

    auto current = mainList->head;
    int skipCounter = 0;
    while (current != nullptr && skipCounter < startNodeIndex) 
    {
        current = current->next;
        skipCounter++;
    }


    // ekrana sığdığı kadarını çiz
    int screenIndex = 0; 

    while (current != nullptr && screenIndex < maxVisibleItems) 
    {
        int topY = startY + (screenIndex * itemTotalH);
        
        for (int j = 0; j < 9; ++j) buffer[topY][j] = '*';
        
        buffer[topY + 1][0] = '*'; 
        buffer[topY + 1][8] = '*'; 
        
        int count = current->shapeList->getCount();
        buffer[topY + 1][4] = (count < 10) ? (count + '0') : 'X'; 

        for (int j = 0; j < 9; ++j) buffer[topY + 2][j] = '*';

        if (current == mainList->cursor) 
        {
            if (12 < width) 
            { 
                buffer[topY + 1][10] = '<';
                buffer[topY + 1][11] = '-';
                buffer[topY + 1][12] = '-';
            }
        }

        current = current->next;
        screenIndex++; 
    }
}