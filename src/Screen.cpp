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





// ARAYÜZ ÇİZİMİ (Soldaki Kutular ve Ok)
void Screen::drawUI(DoublyLinkedList* mainList) {
    if (!mainList) return;

    // Listenin başına eriş (friend olduğu için erişebilir)
    auto current = mainList->head;
    int index = 0;
    int boxHeight = 3; // Kutunun yüksekliği
    int startY = 1;    // Çizime yukarıdan biraz boşlukla başla

    while (current != nullptr) {
        // Kutunun Y koordinatını hesapla (her kutu arası 4 birim boşluk olsun)
        int topY = startY + (index * 4);
        
        // Ekran dışına taşarsa çizme
        if (topY + boxHeight >= height) break;

        // --- KUTUYU ÇİZ ---
        // 1. Üst kenar (*********)
        for (int j = 0; j < 9; ++j) buffer[topY][j] = '*';
        
        // 2. Orta kısım (* 5   *)
        buffer[topY + 1][0] = '*'; // Sol duvar
        buffer[topY + 1][8] = '*'; // Sağ duvar
        
        // İçindeki sayıyı yaz (Listede kaç şekil var?)
        int count = current->shapeList->getCount();
        // Basitçe ASCII'ye çevir (Sadece tek haneli sayılar için örnek)
        // Çok haneli sayılar için string dönüşümü gerekebilir ama şimdilik basit tutalım.
        buffer[topY + 1][4] = (count < 10) ? (count + '0') : 'X'; 

        // 3. Alt kenar (*********)
        for (int j = 0; j < 9; ++j) buffer[topY + 2][j] = '*';

        // --- İMLEÇ (OK) ÇİZİMİ ---
        // Eğer bu düğüm cursor ise yanına ok koy (<--)
        if (current == mainList->cursor) {
            if (12 < width) { // Ekranda yer varsa
                buffer[topY + 1][10] = '<';
                buffer[topY + 1][11] = '-';
                buffer[topY + 1][12] = '-';
            }
        }

        current = current->next;
        index++;
    }
}