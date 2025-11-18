#include "SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {} // Constructor yeni boş bir liste oluşturur


// destructor liste silindiğinde çalışır bellek sızıntısı olmasın diye her şeyi sileriz 
SinglyLinkedList::~SinglyLinkedList() 
{
    ShapeNode* current = head;
    while (current != nullptr) 
    {
        ShapeNode* nextNode = current->next; 
        delete current->data;  //şekli siler
        delete current;  // düğümü siler
        current = nextNode; //sıradakine geçer
    }
}



// listeye yeni bir şekli en sona ekler
void SinglyLinkedList::append(Shape* newShape) 
{
    ShapeNode* newNode = new ShapeNode(newShape);
    if (head == nullptr) 
    {
        head = newNode;
        tail = newNode; 
    } 

    
    //listede düğüm varsa sonuncunun arkasına bağlayalım
    else 
    {
        tail->next = newNode; //direkt listenin sonuna ekleme yaptık (hızlı )
        tail = newNode;
    }
    count++;
}

//çizim methodum
void SinglyLinkedList::draw(char** screenBuffer) 
{
    ShapeNode* current = head;
    while (current != nullptr) 
    {
        current->data->draw(screenBuffer); 
        current = current->next; 
    }
}

//kaydetme methodum
void SinglyLinkedList::save(ofstream& file) 
{
    ShapeNode* current = head;
    while (current != nullptr) 
    {
        current->data->save(file); 
        current = current->next; 
    }
}


//eleman sayısını döndürür
int SinglyLinkedList::getCount() const 
{
    return this->count;
}