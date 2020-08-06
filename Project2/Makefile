CPPFLAGS=-std=c++11 -g -O3

bstree: main.o 
	g++ main.o -o tree

main.o: main.cpp Tree.h 
	g++ $(CPPFLAGS) -c main.cpp

clean:
	rm *.o -f
