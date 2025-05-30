CFLAGS = -I include

all: output

output: obj/main.o obj/unionFind.o obj/minHeap.o
	g++ -o bin/pa4.out obj/main.o obj/unionFind.o obj/minHeap.o

obj/main.o: ./src/main.c ./include/unionFind.h | obj
	g++ $(CFLAGS) -c ./src/main.c -o obj/main.o

obj/unionFind.o: ./src/unionFind.c ./include/unionFind.h | obj
	g++ $(CFLAGS) -c ./src/unionFind.c -o obj/unionFind.o 

obj/minHeap.o: ./src/minHeap.c ./include/minHeap.h | obj
	g++ $(CFLAGS) -c ./src/minHeap.c -o obj/minHeap.o 
