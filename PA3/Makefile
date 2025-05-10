CFLAGS = -I include

all: output

output: obj/main.o obj/heap.o
	g++ -o bin/pa3 obj/main.o obj/heap.o

obj/main.o: ./src/main.c ./include/heap.h | obj
	g++ $(CFLAGS) -c ./src/main.c -o obj/main.o

obj/heap.o: ./src/heap.c ./include/heap.h | obj
	g++ $(CFLAGS) -c ./src/heap.c -o obj/heap.o 
