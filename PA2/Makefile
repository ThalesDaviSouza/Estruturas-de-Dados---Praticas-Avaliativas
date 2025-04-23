CFLAGS = -I include

all: output

output: obj/main.o obj/graph.o obj/list.o
	g++ -o bin/pa2 obj/main.o obj/graph.o obj/list.o

obj/main.o: ./src/main.c ./include/graph.h | obj
	g++ $(CFLAGS) -c ./src/main.c -o obj/main.o

obj/list.o: ./src/list.c ./include/list.h | obj
	g++ $(CFLAGS) -c ./src/list.c -o obj/list.o 

obj/graph.o: ./src/graph.c ./include/graph.h | obj
	g++ $(CFLAGS) -c ./src/graph.c -o obj/graph.o 
