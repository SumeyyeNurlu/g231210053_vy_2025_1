#include <iostream>
#include <conio.h> 
#include <cstdlib> 
#include <ctime>   

// --- DÜZELTME BURADA ---
#define NOGDI // Windows'un Rectangle fonksiyonunu iptal et!
#include <windows.h> 
// -----------------------

#include "Screen.hpp"
#include "DoublyLinkedList.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Star.hpp"

using namespace std;

// ... (Kodun geri kalanı tamamen aynı)

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

// --- EKRAN TİTREMESİNİ ÖNLEYEN FONKSİYON ---
// İmleci konsolun sol üst köşesine (0, 0) taşır.
// Böylece ekranı silmeden (cls yapmadan) üzerine yazabiliriz.
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// --- İMLECİ GİZLEME FONKSİYONU (İsteğe bağlı estetik) ---
// Konsoldaki yanıp sönen o küçük beyaz tireyi gizler.
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void rastgeleVeriOlustur(DoublyLinkedList* tren) {
    int vagonSayisi = 20; 

    for (int i = 0; i < vagonSayisi; ++i) {
        tren->appendNode();
    }

    while (tren->getCursorIndex() > 1) {
        tren->moveUp();
    }

    for (int i = 0; i < vagonSayisi; ++i) {
        SinglyLinkedList* liste = tren->getCurrentList();
        int sekilSayisi = (rand() % 6) + 2; 

        for (int j = 0; j < sekilSayisi; ++j) {
            int x = rand() % 70; 
            int y = rand() % 20; 
            int w = (rand() % 10) + 3; 
            int h = (rand() % 10) + 3; 
            int z = rand() % 10; 
            
            char karakterler[] = {'#', '*', '+', '@', 'o', 'X', '$', '%', '&'};
            char c = karakterler[rand() % 9];
            int tip = rand() % 3;

            if (tip == 0) liste->append(new Rectangle(x, y, z, w, h, c));
            else if (tip == 1) liste->append(new Triangle(x, y, z, w, h, c));
            else liste->append(new Star(x, y, z, w, h, c));
        }

        if (i < vagonSayisi - 1) tren->moveDown();
    }

    while (tren->getCursorIndex() > 1) tren->moveUp();
}

int main() {
    srand(time(0));
    hideCursor(); // Yanıp sönen imleci gizle

    Screen ekran(SCREEN_WIDTH, SCREEN_HEIGHT);
    DoublyLinkedList* tren = new DoublyLinkedList();

    cout << "Veriler nasil olusturulsun?\n";
    cout << "(r) Rastgele\n";
    cout << "(d) Dosyadan (Henuz aktif degil)\n";
    cout << "Secim: ";
    char secim;
    cin >> secim;

    // Seçim sonrası ekranı bir kere tamamen temizle
    system("cls"); 

    if (secim == 'r' || secim == 'R') {
        rastgeleVeriOlustur(tren);
    } else {
        tren->appendNode(); 
    }

    // --- OYUN DÖNGÜSÜ ---
    while (true) {
        // 1. İmleci en başa al (Silme YOK!)
        gotoxy(0, 0);

        // 2. İç tamponu temizle (Bellekteki sayfa)
        ekran.clear();
        
        // 3. Yeni durumu çiz
        ekran.drawUI(tren);
        
        SinglyLinkedList* seciliVagon = tren->getCurrentList();
        if (seciliVagon != nullptr) {
            seciliVagon->draw(ekran.getBuffer());
        }

        // 4. Tamponu ekrana bas (Eskinin üzerine yazar)
        ekran.print();

        int tus = _getch();

        if (tus == 'w') tren->moveUp();
        else if (tus == 's') tren->moveDown();
        else if (tus == 'c') break;
    }

    delete tren;
    return 0;
}