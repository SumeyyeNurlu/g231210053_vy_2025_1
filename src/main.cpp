#include <iostream>
#include <conio.h> // Klavye okumak için gerekli (_getch)
#include "Screen.hpp"
#include "DoublyLinkedList.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Star.hpp"

using namespace std;

const int SCREEN_WIDTH = 80;
const int SCREEN_HEIGHT = 25;

int main() {
    // 1. Kurulum
    Screen ekran(SCREEN_WIDTH, SCREEN_HEIGHT);
    DoublyLinkedList* tren = new DoublyLinkedList();

    // --- TEST VERİLERİ OLUŞTURMA ---
    // 1. Vagon (Kareler)
    tren->appendNode();
    tren->getCurrentList()->append(new Rectangle(20, 5, 0, 10, 5, '#'));
    
    // 2. Vagon (Üçgenler - Aşağı inince görülecek)
    tren->appendNode();
    tren->moveDown(); // 2'ye geçip ekleyelim
    tren->getCurrentList()->append(new Triangle(40, 5, 0, 11, 11, 'o'));

    // 3. Vagon (Yıldızlar)
    tren->appendNode();
    tren->moveDown(); // 3'e geçip ekleyelim
    tren->getCurrentList()->append(new Star(60, 5, 0, 7, 7, '*'));

    // Başlangıçta en başa dönelim
    tren->moveUp(); 
    tren->moveUp(); 

    // --- ANA PROGRAM DÖNGÜSÜ (GAME LOOP) ---
    while (true) {
        // A. EKRANI TEMİZLEME
        // Ekran sınıfının içindeki tamponu temizle
        ekran.clear(); 
        // Windows konsol ekranını temizle (titreşimi önlemek için en basit yol)
        system("cls"); 

        // B. ÇİZİM İŞLEMLERİ
        // 1. Arayüzü (sol tarafı) çiz
        ekran.drawUI(tren);
        
        // 2. Eğer bir vagon seçiliyse, içindeki şekilleri çiz
        SinglyLinkedList* seciliVagon = tren->getCurrentList();
        if (seciliVagon != nullptr) {
            seciliVagon->draw(ekran.getBuffer());
        }

        // C. GÖSTERİM
        ekran.print();

        // D. KULLANICI GİRİŞİ (INPUT)
        // Kullanıcı bir tuşa basana kadar program burada bekler.
        int tus = _getch();

        // E. TUŞ KONTROLÜ
        if (tus == 'w') {
            tren->moveUp();
        }
        else if (tus == 's') {
            tren->moveDown();
        }
        else if (tus == 'c') { // 'c' tuşu ile çıkış
            break; 
        }
        // Buraya ileride 'f' (işlem menüsü) eklenecek
    }

    // Temizlik
    delete tren;
    return 0;
}