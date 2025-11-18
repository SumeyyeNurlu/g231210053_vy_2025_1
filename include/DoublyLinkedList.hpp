#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "SinglyLinkedList.hpp"

class DoublyLinkedList
{

    //Bu izin sayesinde Screen sınıfı, listenin içinde gezinebilecek.
    friend class Screen;

    private:

    struct Node
    {
        SinglyLinkedList*shapeList;
        Node* next;
        Node* prev;

        Node()
        {
            shapeList = new SinglyLinkedList();
            next = nullptr;
            prev = nullptr;
        }

        //ana düğümü sildiğimde  singly linked listi de silmesi için
        ~Node()
        {
            delete shapeList;
        }
    };

    Node* head;
    Node* tail;
    Node* cursor;



public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    //listenin sonuna boş düğüm 
    void appendNode();

    //imleci yukarı taşır
    void moveUp();

    //imleci aşağı taşır
    void moveDown();

   //imlecin olduğu listeyi gösterir
    SinglyLinkedList* getCurrentList() const;
    
    //imlecin indexi
    int getCursorIndex() const;

};



#endif