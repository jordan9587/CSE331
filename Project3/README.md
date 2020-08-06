# Project 3: Unweighted Graphs

In this project, you will implement an algorithm to find Euler Circuits in an unweighted graph. You have been given code to implement a program that will load a graph input file, construct a graph and perform operations related to some properties of the graph. Make sure that you understand algorithms before implementing them.
LetG=(V,E)be a graph where V is a set of vertices, E is a set of edges. Your job is to complete the implementation of the following functions in Unweighted Graph class:

1. IsConnected: Returns true if the graph G is connected, and false other- wise. The running time should be O(|V | + |E|). You may use depth-first-search (DFS) or breadth-first-search (BFS); the important part is you need to perform DFS or BFS only once using arbitrary vertex as an initial vertex. The graph is connected if and only if all vertices are visited.

2. IsEulerian: Returns true if the graph is Eulerian, and false otherwise. A graph is Eulerian if and only if it contains Euler cycle. Euler cycle is a cycle that visits every edge exactly once. The running time should be O(|V | + |E|). You can assume in this function that the graph G is connected. When constructing a graph, store degree sequence into another vector. A graph is Eulerian if and only if all degrees of vertices are even.

3. FindEulerCycle: Returns an Euler cycle as a sequence of vertices from starting vertex to ending vertex. An example of Euler cycle is given in Figure ??. In this function, you can assume that the graph is connected and Eulerian. The running time should be O(|V | + |E|).
(a) Make sure you understand the algorithm.
(b) You may need to use additional appropriate data structure to make this function efficient. For example, we can check if an edge is visited in O(1) time with appropriate data structure.
(c) STL list is useful for splicing paths to avoid repetitious scanning of adjacency lists. This can be done by having a pointer to last used edges for each vertex since you need to visit each edge only once.
(d) Once a path is spliced in, you have to find a new vertex that has unvisited edge. This new vertex can be found in the current cycle. You can store a pointer to the start of the splice point so that you do not have to scan from the beginning. If none of them has unvisited edges, we are done.

4. VerifyEulerCycle: Returns true if the input list (i.e., a sequence of vertices) forms an Euler cycle, and false otherwise. The running time should be O(|V | + |E|). Correctness of this function is the most important since findEulerCycle’s correctness is based on this function for the testing purpose.

For this project you may use anything from the STL library. An STL list is handy for representing a path. With STL list, we can use splice() function to merge paths together. STL list is also a doubly linked list. This means you can erase an item in constant time using iterators, so it may also be useful for storing adjacency lists.

## Main File

The program takes as input adjacency lists. Adjacency lists are given as a file containing exactly n lines. Line i contains i-th vertex followed by numbers (other vertices that i is adjacent with) separated by space. The program then read file and create a graph accordingly.
The program will build a graph based on the input file, and checks if the graph is an Eulerian graph. If so, it finds Eulerian cycle and verifies the result.

## Project Deliverables

1. UnweightedGraph.h - contains your class prototype of unweighted graph.
2. UnweightedGraph.cpp-contains your implementation of unweighted graph class.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

The things you need before installing the software.

* Visual Studio 2019 Community Edition
* C++ compiler (Homebrew Mac OS X)

### Installation and Execution

A step by step guide that will tell you how to get the development environment up and running.

```
$ Create directory from the name of the files
$ ls into desired directory you want to access downloaded files
$ make      @ Run Makefile to compile all files
$ ./unweightgraph FILENAME    @ Execute program 
```

## Usage

A few examples of useful commands and/or tasks.
![](project3.gif)


