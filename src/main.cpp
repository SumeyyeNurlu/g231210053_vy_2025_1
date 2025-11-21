#include <iostream>
#include <conio.h> 
#include <cstdlib> 
#include <ctime>   

            
#include <windows.h>      

#include "Screen.hpp"     
#include "DoublyLinkedList.hpp"
#include "Rect.hpp"
#include "Triangle.hpp"
#include "Star.hpp"

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void rastgeleVeriOlustur(DoublyLinkedList* tren) {
    int vagonSayisi = 20; 
    for (int i = 0; i < vagonSayisi; ++i) tren->appendNode();
    
    while (tren->getCursorIndex() > 1) tren->moveUp();

    for (int i = 0; i < vagonSayisi; ++i) {
        SinglyLinkedList* liste = tren->getCurrentList();
        int sekilSayisi = (rand() % 6) + 2; 

        for (int j = 0; j < sekilSayisi; ++j) {
            int x = (rand() % 50) + 17; 
            int y = rand() % 20; 
            int w = (rand() % 8) + 3; 
            int h = (rand() % 8) + 3; 
            int z = rand() % 10; 
            
            char chars[] = {'#', '*', '+', '@', 'o', 'X', '$', '%', '&'};
            char c = chars[rand() % 9];
            int tip = rand() % 3;

            if (tip == 0) liste->append(new Rect(x, y, z, w, h, c));
            else if (tip == 1) liste->append(new Triangle(x, y, z, w, h, c));
            else liste->append(new Star(x, y, z, w, h, c));
        }
        if (i < vagonSayisi - 1) tren->moveDown();
    }
    while (tren->getCursorIndex() > 1) tren->moveUp();
}

int main() {
    system("mode con: cols=100 lines=40"); // Pencere boyutu
    srand(time(0));
    hideCursor();

    Screen ekran(80, 25); 
    DoublyLinkedList* tren = new DoublyLinkedList();

    cout << "--- SEKIL YONETIM SISTEMI ---\n";
    cout << "(r) Rastgele Veri Uret\n";
    cout << "(d) Dosyaya Son Kaydedileni Yukle\n";
    cout << "Secim: ";
    char secim;
    cin >> secim;
    
    system("cls"); 



    
    if (secim == 'r' || secim == 'R') 
    {
        rastgeleVeriOlustur(tren);
    } 
    else if (secim == 'd' || secim == 'D')
    { 
        tren->loadFromFile("Data.txt");
        
        if (tren->getCursorIndex() == -1) 
        {
            tren->appendNode();
        }
        system("pause"); 
    }

    else 
    {
        tren->appendNode(); 
    }




    bool listeModu = false; 

    while (true) 
    {
        gotoxy(0, 0);
        ekran.clear();
        ekran.drawUI(tren);
        
        SinglyLinkedList* seciliVagon = tren->getCurrentList();
        if (seciliVagon != nullptr) 
        {
            seciliVagon->draw(ekran.getBuffer());
        }

        ekran.print();

        // --- YENİ MENÜ YAZILARI ---
        if (!listeModu) 
        {
            // --- ANA LİSTE MENÜSÜ (KISA) ---
            cout << " MOD: [ANA LISTEDESINIZ]                                         \n";
            cout << " (w/s) Hareket | (f) Listeyi Sec | (c) Sil | (q) Cikis    \n";
            cout << "                                                                 \n"; 
            // Altta kalan eski yazıları temizlemek için BOŞ SATIRLAR basıyoruz:
            cout << "                                                                 \n";
            cout << "                                                                 \n";
            cout << "                                                                 \n";
            cout << "                                                                 \n";
            cout << "                                                                 \n";
        }
        
        else 
        {
            // --- İÇERİK DÜZENLEME MENÜSÜ (UZUN) ---
            cout << " MOD: [ICERIK DUZENLEME]                                         \n";
            cout << " (w/a/s/d) Hareket | (q) Onceki | (e) Sonraki                    \n";
            cout << " (c) Sekli Sil     | (g) Listeye Don                             \n"; 
            
            if (seciliVagon && seciliVagon->getCurrentShape()) {
                Shape* s = seciliVagon->getCurrentShape();
                cout << " Secili Sekil: " << s->getType() << " [Z:" << s->getZ() << "] "
                     << "                                          \n"; 
            } else {
                cout << " Liste Bos!                                                      \n";
            }
            // Uzunlukları eşitlemek için buraya da gerekirse 1-2 boş satır atılabilir
            cout << "                                                                 \n";
            cout << "                                                                 \n";
        }

        int tus = _getch();

        

          
        if (!listeModu) {
            if (tus == 'q') break; // PROGRAMDAN ÇIKIŞ
            
            if (tus == 'w') tren->moveUp();
            else if (tus == 's') tren->moveDown();
            else if (tus == 'c') {
                tren->deleteCurrentNode();
                if (tren->getCursorIndex() == -1) tren->appendNode();
            }
            else if (tus == 'f') {
                if (seciliVagon != nullptr && seciliVagon->getCount() > 0) {
                    seciliVagon->resetCursor();
                    listeModu = true; // İçeri gir
                }
            }
        } 
        // --- MOD B: İÇERİK DÜZENLEME (YENİ KONTROLLER) ---
        else {
            if (tus == 'g') { // GERİ DÖN
                listeModu = false;
            }
            else if (tus == 'e') { // SONRAKİ ŞEKİL
                if (seciliVagon) seciliVagon->moveNext();
            }
            else if (tus == 'q') { // ÖNCEKİ ŞEKİL
                if (seciliVagon) seciliVagon->movePrevious();
            }
            else if (tus == 'c') { // ŞEKLİ SİL
                if (seciliVagon) {
                    seciliVagon->deleteCurrent();
                    if (seciliVagon->getCount() == 0) listeModu = false;
                }
            }
            // --- HAREKET (WASD) ---
            else if (tus == 'w' || tus == 'a' || tus == 's' || tus == 'd') {
                if (seciliVagon) {
                    Shape* s = seciliVagon->getCurrentShape();
                    if (s != nullptr) {
                        if (tus == 'w') s->move(0, -1);      // Yukarı
                        else if (tus == 's') s->move(0, 1);  // Aşağı
                        else if (tus == 'a') s->move(-1, 0); // Sola
                        else if (tus == 'd') s->move(1, 0);  // Sağa
                    }
                }
            }
        }
    }

    system("cls"); 

    
    cout << "Cikis yapiliyor ve veriler kaydediliyor...\n";
    
    
    tren->saveToFile("Data.txt");

    
    delete tren;
    
    //kapanmadan 1.5 saniye bekle (Mesaj okunsun diye)
    Sleep(1500); 
    
    return 0;
}