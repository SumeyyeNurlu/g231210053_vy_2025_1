#include "SinglyLinkedList.hpp"
#include <iostream>
using namespace std;

SinglyLinkedList::ShapeNode::ShapeNode(Shape* shapeData) : data(shapeData), next(nullptr) {}

SinglyLinkedList::SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {} 


// yıkıcı liste silindiğinde çalışır bellek sızıntısı olmasın diye her şeyi sileriz 
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

    //listede düğüm varsa sonuncunun arkasına bağlarım
    else 
    {
        tail->next = newNode; //direkt listenin sonuna ekleme yaptım
        tail = newNode;
    }
    count++;
}

//çizim methodum

void SinglyLinkedList::draw(char** screenBuffer) 
{
    
    if (head == nullptr) return;
    if (head == tail) 
    {
        head->data->draw(screenBuffer);
        return;
    }

    
    Shape** tempArray = new Shape*[count];
    
    
    ShapeNode* current = head;
    int index = 0;
    while (current != nullptr) 
    {
        tempArray[index] = current->data;
        current = current->next;
        index++;
    }

    for (int i = 0; i < count - 1; ++i) 
    {
        for (int j = 0; j < count - i - 1; ++j) 
        {
            if (tempArray[j]->getZ() > tempArray[j + 1]->getZ()) 
            {
                // yer değiştirme
                Shape* temp = tempArray[j];
                tempArray[j] = tempArray[j + 1];
                tempArray[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; ++i) 
    {
        tempArray[i]->draw(screenBuffer);
    }

    delete[] tempArray;
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


void SinglyLinkedList::resetCursor() 
{
    cursor = head; // En başa dön
}

void SinglyLinkedList::moveNext() 
{
    if (cursor != nullptr && cursor->next != nullptr) 
    {
        cursor = cursor->next;
    } 
    
    else 
    {
        cursor = head;
    }
}

Shape* SinglyLinkedList::getCurrentShape() const 
{
    if (cursor != nullptr) 
    {
        return cursor->data;
    }
    return nullptr;
}

// SEÇİLİ ELEMANI SİLME 
void SinglyLinkedList::deleteCurrent() 
{
    if (cursor == nullptr || head == nullptr) return;

    // silinecek eleman BAŞTAYSA
    if (cursor == head) 
    {
        ShapeNode* temp = head;
        head = head->next;
        
        // Eğer tek eleman varsaaaa tail de silinmeli
        if (head == nullptr) tail = nullptr;
        
        delete temp->data; 
        delete temp;       
        
        cursor = head; 
    }


    
    else 
    {
         ShapeNode* prev = head;
        while (prev->next != cursor) 
        {
            prev = prev->next;
        }

        prev->next = cursor->next;

        if (cursor == tail) 
        {
            tail = prev;
        }

        delete cursor->data;
        delete cursor;

       
        cursor = prev->next;
        if (cursor == nullptr) cursor = head;
    }

    count--;
}


void SinglyLinkedList::movePrevious() {
    // Liste boşsa veya imleç yoksa işlem yapma
    if (head == nullptr || cursor == nullptr) return;

    // Eğer imleç baştaysa, en sona sar (Loop)
    if (cursor == head) {
        // En son elemanı bul
        ShapeNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        cursor = temp; // İmleci sona taşı
    } 
    // İmleç arada veya sondaysa
    else {
        // İmleçten bir önceki düğümü bul
        ShapeNode* prev = head;
        while (prev->next != cursor) {
            prev = prev->next;
        }
        cursor = prev; // İmleci bir geriye al
    }
}