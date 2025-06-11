CFLAGS = -I include

all: output

output: obj/main.o obj/Set.o
	g++ -o bin/pa5 obj/main.o obj/Set.o

obj/main.o: ./src/main.cpp ./include/Set.hpp | obj
	g++ $(CFLAGS) -c ./src/main.cpp -o obj/main.o

obj/Set.o: ./src/Set.cpp ./include/Set.hpp | obj
	g++ $(CFLAGS) -c ./src/Set.cpp -o obj/Set.o 

