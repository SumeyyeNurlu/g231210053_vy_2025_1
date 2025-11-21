#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "SinglyLinkedList.hpp"

class DoublyLinkedList
{    
    friend class Screen; //screen sınıfı listenin içinde gezinebilsin 
    private:
    struct Node
    {
        SinglyLinkedList* shapeList;
        Node* next;
        Node* prev;

        Node();  
        ~Node(); 
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

    //imlecin gösterdiği düğümü siler
    void deleteCurrentNode();

   //imlecin olduğu listeyi gösterir
    SinglyLinkedList* getCurrentList() const;
    
    //imlecin indexi
    int getCursorIndex() const;


    //dosyaya kaydetme
    void saveToFile(string filename);
    
    //kaydettiğimiz verileri yükleme
    void loadFromFile(string filename);

};



#endif