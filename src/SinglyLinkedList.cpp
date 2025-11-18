#include "SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {} // Constructor yeni boş bir liste oluşturur
SinglyLinkedList::~SinglyLinkedList() // Destructor listeyi temizler
{
    ShapeNode* current = head;
    while (current != nullptr) 
    {
        ShapeNode* nextNode = current->next;
        delete current->data; // Shape nesnesini sil
        delete current; // Node'u sil
        current = nextNode;
    }


    // BURAYI SONRA SİLEBİLİRİZ
    //BAK
    //
    //
    cout << "SinglyLinkedList yikicisi calisti, " << count << " sekil silindi." << endl;
}

void SinglyLinkedList::append(Shape* newShape) // Listeye yeni bir şekil ekler
{
    ShapeNode* newNode = new ShapeNode(newShape);
    if (head == nullptr) 
    {
        head = newNode;
        tail = newNode;
    } 
    else 
    {
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}