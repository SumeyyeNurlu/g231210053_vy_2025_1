#include "DoublyLinkedList.hpp"
#include <iostream>
#include <fstream>
#include "Rect.hpp"
#include "Triangle.hpp"
#include "Star.hpp"
using namespace std;


    // düğüm kurucu 
    DoublyLinkedList::Node::Node() 
    {
        shapeList = new SinglyLinkedList();
        next = nullptr;
        prev = nullptr;
    }

    // düğüm yıkıcı
    DoublyLinkedList::Node::~Node() 
    {
        delete shapeList;
    }


    //kurucu
    DoublyLinkedList::DoublyLinkedList() 
    {
        head = nullptr;
        tail = nullptr;
        cursor = nullptr;
    }

    //yıkıcı
    DoublyLinkedList::~DoublyLinkedList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* nextNode = current->next;
            delete current; 
            current = nextNode;
        }
    }


    //yeni düğüm ekleme 
    void DoublyLinkedList::appendNode() 
    {
        Node* newNode = new Node();

        if (head == nullptr) 
        {
            head = newNode;
            tail = newNode;
            cursor = newNode; 
        } 

        else
        {
            tail->next = newNode;
            newNode->prev = tail; 
            tail = newNode;       
        }
    }

    //yukarı hareket
    void DoublyLinkedList::moveUp() 
    {
        if (cursor != nullptr && cursor->prev != nullptr) 
        {
            cursor = cursor->prev;
        }
    }


    //aşağı hareket
    void DoublyLinkedList::moveDown() 
    {
        if (cursor != nullptr && cursor->next != nullptr) 
        {
            cursor = cursor->next;
        }
    }


    // seçili olan listeyi getirier
    SinglyLinkedList* DoublyLinkedList::getCurrentList() const 
    {
        if (cursor != nullptr) 
        {
            return cursor->shapeList;
        }
        return nullptr;
    }


    //imlecin indexini döndürür
    int DoublyLinkedList::getCursorIndex() const 
    {
        int index = 1;
        Node* temp = head;
        
        while (temp != nullptr) 
        {
            if (temp == cursor) 
            {
                return index; 
            }
            temp = temp->next;
            index++;
        }
        return -1; 
    }



    //seçili düğümü siler
    void DoublyLinkedList::deleteCurrentNode()
    {
        if (head == nullptr || cursor == nullptr) return;

        Node* toDelete = cursor; 

        if (toDelete == head) 
        {
            head = head->next; 
            if (head != nullptr) 
            {
                head->prev = nullptr; 
                cursor = head; 
            } 

            else 
            {
                tail = nullptr;
                cursor = nullptr;
            }
        }


        // silinecek düğüm SONDA İSE
        else if (toDelete == tail) 
        {
            tail = tail->prev;
            if (tail != nullptr) 
            {
                tail->next = nullptr;
                cursor = tail; 
            }
        }

        //silinecek düğüm ARADA İSE
        else {
            Node* prevNode = toDelete->prev;
            Node* nextNode = toDelete->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            cursor = nextNode; 
        }

        // düğümü ve içindeki her şeyi silmek için
        delete toDelete;
    }


//dosyaya kaydetme
void DoublyLinkedList::saveToFile(string filename) 
{
    ofstream file(filename); 
    
    if (!file.is_open()) return;

    file << "=== SEKIL YONETIM SISTEMI VERI DOSYASI ===\n";
    file << "Format: [Tip] | [Koordinatlar] | [Boyutlar] | [Sembol]\n\n";

    Node* current = head;
    int vagonNo = 1;

    while (current != nullptr) 
    {
        file << "--- LISTE #" << vagonNo << " BASLANGIC ---\n";
        
        if (current->shapeList != nullptr) 
        {
            current->shapeList->save(file);
        }
        
        file << "--- LISTE #" << vagonNo << " BITIS ---\n\n"; 
        
        current = current->next;
        vagonNo++;
    }
    file.close();
    cout << "\nVeriler " << filename << " dosyasina kaydedildi.\n";
}

//dosyadan yükleme
void DoublyLinkedList::loadFromFile(string filename) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cout << "Dosya bulunamadi! Bos baslaniyor.\n";
        return;
    }

    
    Node* temp = head;
    while (temp != nullptr) 
    {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }

    head = nullptr; 
    tail = nullptr; 
    cursor = nullptr;

    string kelime;
    

    while (file >> kelime) 
    {
        if (kelime == "BASLANGIC") 
        {
            appendNode(); 
        }

        else if (kelime == "Rect" || kelime == "Triangle" || kelime == "Star") {
            
            string cop; 
            int x, y, z, w, h;
            char sembol;
            
            file >> cop >> cop >> x 
                 >> cop >> cop >> y 
                 >> cop >> cop >> z 
                 >> cop >> cop >> w 
                 >> cop >> cop >> h 
                 >> cop >> cop >> sembol;

            
            if (tail != nullptr) 
            {
                if (kelime == "Rect") tail->shapeList->append(new Rect(x, y, z, w, h, sembol));
                else if (kelime == "Triangle") tail->shapeList->append(new Triangle(x, y, z, w, h, sembol));
                else if (kelime == "Star") tail->shapeList->append(new Star(x, y, z, w, h, sembol));
            }
        }
    }
    file.close();
    
    if (head != nullptr) cursor = head;
    cout << "Veriler dosyadan basariyla yuklendi.\n";
}