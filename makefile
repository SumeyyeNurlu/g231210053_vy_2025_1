hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Shape.o -c ./src/Shape.cpp
	g++ -I ./include/ -o ./lib/Rect.o -c ./src/Rect.cpp
	g++ -I ./include/ -o ./lib/Triangle.o -c ./src/Triangle.cpp   
	g++ -I ./include/ -o ./lib/Star.o -c ./src/Star.cpp         
	g++ -I ./include/ -o ./lib/SinglyLinkedList.o -c ./src/SinglyLinkedList.cpp
	g++ -I ./include/ -o ./lib/DoublyLinkedList.o -c ./src/DoublyLinkedList.cpp  
	g++ -I ./include/ -o ./lib/Screen.o -c ./src/Screen.cpp

	g++ -I ./include/ -o ./bin/program ./lib/Shape.o ./lib/Rect.o ./lib/Triangle.o ./lib/Star.o ./lib/SinglyLinkedList.o ./lib/DoublyLinkedList.o ./lib/Screen.o ./src/main.cpp

calistir:
	./bin/program