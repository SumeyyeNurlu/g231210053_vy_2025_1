#include "DoublyLinkedList.hpp"
#include <iostream>
using namespace std;

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
    while (current != nullptr) {
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
        cursor = newNode; //imleç ilk elemeanda olsun
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

int DoublyLinkedList::getCursorIndex() const {
    int index = 1;
    Node* temp = head;
    
    while (temp != nullptr) {
        if (temp == cursor) {
            return index; 
        }
        temp = temp->next;
        index++;
    }
    return -1; 
}