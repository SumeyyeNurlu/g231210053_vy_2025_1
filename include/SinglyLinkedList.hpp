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
            ShapeNode(Shape* shapeData): data(shapeData), next(nullptr) {} // Constructor
        };
        
        ShapeNode* head; // Listenin başı
        ShapeNode* tail; // Listenin sonu
        int count; // Eleman sayısı

    public:
        SinglyLinkedList(); // Constructor
        ~SinglyLinkedList(); // Destructor

        void append(Shape* shape); // Listeye eleman ekler
        void draw (char** screenBuffer); // Ekrana çizer
        void save(ofstream& outFile); // Şekilleri dosyaya kaydeder
        int getCount() const; // Eleman sayısını döndürür

    
};


#endif