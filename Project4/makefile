CPPFLAGS=-std=c++14 -g -O3 -Wall
EXECUTABLE=wgraph

all: $(EXECUTABLE)

$(EXECUTABLE): main.o WeightedDigraph.o	
	g++ $(CPPFLAGS) main.o WeightedDigraph.o -o $(EXECUTABLE)

WeightedDigraph.o: WeightedDigraph.cpp WeightedDigraph.h
	g++ $(CPPFLAGS) -c WeightedDigraph.cpp

Main.o: Main.cpp WeightedDigraph.o
	g++ $(CPPFLAGS) -c main.cpp

clean: 
	rm -f *.o $(EXECUTABLE)
