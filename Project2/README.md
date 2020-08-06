# Project 2: Binary Search Tree

In this project, you will implement a binary search tree. Your binary search tree will be used to store and manipulate data from given text file.
You have been given code to implement a program that will load and manipulate the data from the numbers.txt file. The main program stores the numbers in a vector, and then builds a binary search tree based on the vector.
Your job is to complete the implementation of the following methods in BinarySearchTree class:

1. Insert: Inserts an item into the tree. No need to balance the tree. This should be O(h) where h is height of the tree.
2. InorderTraverse: Traverses the tree in order. In addition, there is another parameter: vector. The vector is expected to have all elements in the tree by the same order as visited by each recursion. This should be O(n).
3. DeleteNode: Deletes an element of the tree. This should be O(h).
4. Filter: Deletes all nodes that do not have the desired property keeping only ones with the property. This should be O(n). Provide a memory efficient implementation, i.e., O(1) space.
5. ForEachInterval: perform some function to each node of the tree in range of interval [a,b] where a,b are parameters of the method. Provide a memory efficient implementation, i.e., O(1) space. The running time should be equal to h plus number of elements satisfying the interval.
6. VerifyBinarySearchTree: returns true if the tree has properties of binary search tree, e.g., value of left child node is less than that of its parent. Return false otherwise. This should be O(n). Provide a memory efficient implementation, i.e., O(1) space.

I recommend that you implement all your functions in the private space, and then place calls to private methods in the public methods. This will reduce the amount of code you write when overloading the const methods.
You may not use anything from the STL for this project. You may use IO for debugging but be sure to remove it from your completed project. You will be marked down for any debugging IO left in your project. As usual, you may not change the signatures of the public methods, or the way in which the tree class interacts with the rest of the program. You may add any private member variables or methods to BinarySearchTree class to help you complete the project.

## Checklist

Make sure that your implementation has
```
• no memory leaks. That is, every pointer that allocated the memory is eventually deallocated. Every new operation has the corresponding delete operation when its job is done.
• no segmentation fault. Be careful when managing pointers during insertion/deletion of nodes.
• running time requirement as above.
• comments according to project guideline.
```

## Sample Test Cases
The program will take one input which is a file containing integers line-by-line. Your program will then read the file and store the integers in a vector.
The program builds a binary search tree by inserting elements from the vector. Then, it traverses the tree in order and puts values according to the order visited into another vector. There will be manipulation of the tree using filter, forEachInterval, delete method. As usual, main.cpp does the job for you. You have to complete implementation of the BinarySearchTree class.

## Project Deliverables

1. Tree.h - contains your implementation of binary search tree.

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
$ ./tree     @ Execute program 
```

## Issues
The BinarySearchTree deconstructor function wasn't completed as annotated. It should be using _filter function recursively instead of having current new _emptyTree function.

## Usage

A few examples of useful commands and/or tasks.
![](project2.gif)

## Known Unit Test Cases
### delete small:
Input-
```
BinarySearchTree<int> tree;
vector<int> v1 = {7,4,8,6,5,2,1,3};
for(auto& s : v1) tree.insert(s);
tree.deleteNode(1);
tree.deleteNode(3);
tree.deleteNode(6);
tree.deleteNode(8);
tree.display();
```

Output-
```
        __7

                __5

            __4

                __2
```

### Filter small-
Input-
```
BinarySearchTree<int> tree;
vector<int> vi = {5,10,9,2,1,3,7,6,11,12}; 
for(int n : vi) tree.insert(n); 
int k = 2;
auto isDivisibleByK = [k](int x){ return x % k == 0; };
tree.filter(isDivisibleByK); 
tree.inOrderTraverse(traverse_out);
for(int n : traverse_out) {
    cout << n << " ";
}
cout << endl;
```

Output-
```
2 6 10 12 
```

### ForEachInterval 1-
Input-
```
BinarySearchTree<int> tree;
v1 = {7,4,8,6,5,2,1,3};
int count = 0;
for(auto& s : v1) tree.insert(s);
tree.forEachInterval(4,7, [&count](int n) {
    count++;
});
cout << count << endl;
```

Output-
```
4
```

### Insert and traverse-
Input-
```
BinarySearchTree<int> tree;
vector<int> v1 = {7,4,8,6,5,2,1,3};
for(auto& s : v1) tree.insert(s);
tree.inOrderTraverse(traverse_out);
for_each(begin(traverse_out),end(traverse_out),[](int n){
    cout << n << " ";
});
```

Output-
```
1 2 3 4 5 6 7 8 
```

### Insert and traverse-
Input-
```
BinarySearchTree<int> tree;
vector<int> v1 = {7,4,8,6,5,2,1,3};
for(auto& s : v1) tree.insert(s);
tree.inOrderTraverse(traverse_out);
for_each(begin(traverse_out),end(traverse_out),[](int n){
    cout << n << " ";
});
```

Output-
```
1 2 3 4 5 6 7 8 
```
 

