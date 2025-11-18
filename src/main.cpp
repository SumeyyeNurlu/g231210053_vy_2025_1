#include <iostream>

#include "Rectangle.hpp" 
#include "Star.hpp"
#include "Triangle.hpp"


//buraya sonra bakalım 
// Daha sonra bu sabitleri merkezi bir 'Screen.hpp' dosyasına taşıyacağız.
const int SCREEN_HEIGHT = 25;
const int SCREEN_WIDTH = 80;



char** createScreenBuffer() {
    // Önce 'satır' işaretçileri için yer ayırıyoruz
    char** buffer = new char*[SCREEN_HEIGHT];

    // Sonra her satır için 'sütun' karakterleri için yer ayırıyoruz
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        buffer[i] = new char[SCREEN_WIDTH];
        
        // Bu satırdaki tüm sütunları 'boşluk' karakteri ile dolduruyoruz
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            buffer[i][j] = ' '; // Temiz bir ekran için boşluk ata
        }
    }
    return buffer;
}



void printScreenBuffer(char** buffer) {
    // Üst çerçeve
    for (int j = 0; j < SCREEN_WIDTH + 2; ++j) std::cout << "-";
    std::cout << "\n";

    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        std::cout << "|"; // Sol çerçeve
        for (int j = 0; j < SCREEN_WIDTH; ++j) {
            std::cout << buffer[i][j];
        }
        std::cout << "|\n"; // Sağ çerçeve
    }

    // Alt çerçeve
    for (int j = 0; j < SCREEN_WIDTH + 2; ++j) std::cout << "-";
    std::cout << "\n";
}




void deleteScreenBuffer(char** buffer) {
    // Önce her 'satır' için ayrılan 'sütun' belleğini serbest bırak
    for (int i = 0; i < SCREEN_HEIGHT; ++i) {
        delete[] buffer[i];
    }
    // Son olarak 'satır' işaretçilerinin tutulduğu diziyi serbest bırak
    delete[] buffer;
}


// --- ANA TEST PROGRAMI (ÜÇ ŞEKİL İLE) ---
int main() {
    std::cout << "3 Sekil Test Programi Baslatiliyor...\n";

    // 1. Ekran tamponunu oluştur
    char** ekran = createScreenBuffer();

    // 2. Polimorfizm kullanarak 3 şekli de oluştur
    //    Shape(x, y, z, w, h, karakter)
    
    // (Z değeri şimdilik önemli değil, Z-sorting eklemedik)
    Shape* sekil1 = new Rectangle(5, 3, 1, 20, 8, '@');
    Shape* sekil2 = new Triangle(40, 5, 1, 12, 12, '*');
    Shape* sekil3 = new Star(60, 2, 1, 9, 9, '+'); // 9x9 "Artı" şekli

    // 3. Tüm şekilleri AYNI ekran tamponuna çizdir
    std::cout << "Sekiller ciziliyor...\n";
    sekil1->draw(ekran);
    sekil2->draw(ekran);
    sekil3->draw(ekran);

    // 4. Ekran tamponunun son halini konsola yazdır
    std::cout << "Cizim sonrasi ekran tamponu:\n";
    printScreenBuffer(ekran);

    // 5. Belleği temizle (ÇOK ÖNEMLİ)
    delete sekil1; 
    delete sekil2;
    delete sekil3;
    deleteScreenBuffer(ekran); 

    std::cout << "Test programi tamamlandi.\n";
    
    return 0;
}