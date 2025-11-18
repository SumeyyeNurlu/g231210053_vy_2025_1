hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Shape.o -c ./src/Shape.cpp
	g++ -I ./include/ -o ./lib/Rectangle.o -c ./src/Rectangle.cpp
	g++ -I ./include/ -o ./lib/Triangle.o -c ./src/Triangle.cpp   
	g++ -I ./include/ -o ./lib/Star.o -c ./src/Star.cpp         
	g++ -I ./include/ -o ./bin/program ./lib/Shape.o ./lib/Rectangle.o ./lib/Triangle.o ./lib/Star.o ./src/main.cpp 

calistir:
	./bin/program