/**
 * \file InsertionSort.h
 *
 * \author Jordan Hybki
 *
 * Holds the Inserstion Sort function. Begins with first element of vector<int> a. Loops over input untill array empty, removing the next right element
 * from current item. Compare next item to current item, starting from minimum element at start and working down the vector to highest element. When
 * next item is lower than current item, swap value into the previous elements, repeating with next lowest result. Else the current item in right location
 * and will check next item from current item.
 *
 */
#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_
#include <vector>
#include <fstream>

/**
 * Insertion Sort vector of int's. Side-effect: vector 'a' is sorted in non-decreasing order. Note: to prevent integer overflow, long long is used for 
 * counting number of comparisons.
 * \param a vector of ints
 * \return long long that represents number of key comparisons by InsertionSort algorithm. (Size of array + number of elements swapped)
 */
long long InsertionSort(std::vector<int> &a); //do not change this line 

//you can add helper functions here

#endif
