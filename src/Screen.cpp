#include "Screen.hpp"
#include <iostream>
#include <iomanip>

using namespace std;


//kurucu
Screen::Screen(int w, int h) : width(w), height(h) 
{
    buffer = new char*[height];
    for (int i = 0; i < height; ++i) {
        buffer[i] = new char[width];
        for (int j = 0; j < width; ++j) {
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
    // Üst kısmın çizimi
    for (int j = 0; j < width + 2; ++j) cout << "-";
    cout << "\n";

    
    for (int i = 0; i < height; ++i) {
        cout << "|"; // sol kenarın çizimi
        for (int j = 0; j < width; ++j) {
            cout << buffer[i][j];
        }
        cout << "|\n"; // sağ kenarın çizimi
    }

    // alt ksımn çzimi
    for (int j = 0; j < width + 2; ++j) cout << "-";
    cout << "\n";
    
    // komutlar
    cout << "(w/s) Hareket | (f) Sekil Islemleri | (c) Cikis \n";
}








// ekran verisi 
char** Screen::getBuffer() {
    return buffer;
}


// ARAYÜZ ÇİZİMİ (SAYFALAMA / PAGINATION VERSİYONU)
void Screen::drawUI(DoublyLinkedList* mainList) {
    if (!mainList) return;

    int boxHeight = 3; 
    int gap = 1;       
    int itemTotalH = boxHeight + gap; 
    
    int startY = 1;   

    // 1. Ekrana kaç tane kutu sığar? (Örn: 6 tane)
    int maxVisibleItems = (height - startY) / itemTotalH;

    // 2. Şu anki imleç kaçıncı sırada? (0'dan başlayarak)
    int cursorIndex = mainList->getCursorIndex() - 1; 
    if (cursorIndex < 0) cursorIndex = 0;

    // --- DEĞİŞEN KISIM (SAYFALAMA MANTIĞI) ---
    
    // Hangi "sayfada" olduğumuzu bulalım (Tamsayı bölmesi)
    // Örnek: cursor=5, max=6 -> sayfa=0
    // Örnek: cursor=6, max=6 -> sayfa=1
    int pageNumber = cursorIndex / maxVisibleItems;

    // Çizime başlayacağımız düğüm, sayfanın ilk düğümüdür
    int startNodeIndex = pageNumber * maxVisibleItems;

    // --- DEĞİŞEN KISIM SONU ---

    // 4. Listeyi 'startNodeIndex' kadar ilerlet (Atla)
    auto current = mainList->head;
    int skipCounter = 0;
    while (current != nullptr && skipCounter < startNodeIndex) {
        current = current->next;
        skipCounter++;
    }

    // 5. Şimdi ekrana sığdığı kadarını çiz
    int screenIndex = 0; 

    while (current != nullptr && screenIndex < maxVisibleItems) {
        int topY = startY + (screenIndex * itemTotalH);
        
        // --- KUTU ÇİZİMİ (AYNI) ---
        for (int j = 0; j < 9; ++j) buffer[topY][j] = '*';
        
        buffer[topY + 1][0] = '*'; 
        buffer[topY + 1][8] = '*'; 
        
        int count = current->shapeList->getCount();
        buffer[topY + 1][4] = (count < 10) ? (count + '0') : 'X'; 

        for (int j = 0; j < 9; ++j) buffer[topY + 2][j] = '*';

        // --- İMLEÇ ÇİZİMİ (AYNI) ---
        if (current == mainList->cursor) {
            if (12 < width) { 
                buffer[topY + 1][10] = '<';
                buffer[topY + 1][11] = '-';
                buffer[topY + 1][12] = '-';
            }
        }

        current = current->next;
        screenIndex++; 
    }
}