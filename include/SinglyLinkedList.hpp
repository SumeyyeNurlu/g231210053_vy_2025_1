#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP
#include "Shape.hpp" 
#include <fstream> //save fonksiyonu için

using namespace std;


class SinglyLinkedList 
{

    private:
        struct ShapeNode
        {
            Shape* data; 
            ShapeNode* next; 
            ShapeNode(Shape* shapeData): data(shapeData), next(nullptr) {} 
        };
        
        ShapeNode* head; //  başı
        ShapeNode* tail; // sonu
        int count; // eleman sayısı


        ShapeNode* cursor; // imleç hangi şeklin seçili olduğunu tutar

    public:
        SinglyLinkedList(); 
        ~SinglyLinkedList(); 

        void append(Shape* shape); //  eleman ekler
        void draw (char** screenBuffer); //  çizer
        void save(ofstream& outFile); //  dosyaya kaydeder
        int getCount() const; // sayısını döndürür



    // imleci başa alır
    void resetCursor(); 
    
    // sonraki şekle taşır
    void moveNext(); 
    
    // imlecin gösterdiği şekli döndürür
    Shape* getCurrentShape() const;
    
    void deleteCurrent();
    
};


#endif