/**
 * \file InsertionSort.cpp
 *
 * \author Jordan Hybki
 *
 * Holds the Inserstion Sort function. Begins with first element of vector<int> a. Loops over input untill array empty, removing the next right element
 * from current item. Compare next item to current item, starting from minimum element at start and working down the vector to highest element. When
 * next item is lower than current item, swap value into the previous elements, repeating with next lowest result. Else the current item in right location
 * and will check next item from current item.
 *
 */


#include <iostream>
#include "InsertionSort.h"
using namespace std;

/**
 * Insertion Sort vector of int's. Side-effect: vector 'a' is sorted in non-decreasing order. Note: to prevent integer overflow, long long is used for
 * counting number of comparisons.
 * \param a vector of ints
 * \return long long that represents number of key comparisons by InsertionSort algorithm. (Size of array + number of elements swapped)
 */
long long InsertionSort(vector<int> &a)
{
    // Size of parameter a.
    long long N = a.size();
    long long CurrentPosition, NextPosition, Buffer;
    // Number of comparisons for n + (number of element swaps)
    long long ComparisonCounter = N;
    for (NextPosition = 1; NextPosition < N; NextPosition++)
    {
        CurrentPosition = NextPosition;
        // Store the next value in Buffer and compare it to current item.
        Buffer = a[NextPosition];

        /* Change position of item a[0..i-1], with next item greater than current item.
        of their current position */
        while (CurrentPosition > 0 && Buffer < a[CurrentPosition - 1])
        {
            // Swap the current item with item to one position behind.
            a[CurrentPosition] = a[CurrentPosition - 1];
            CurrentPosition -= 1;
            ComparisonCounter += 1;
        }
        a[CurrentPosition] = Buffer;
    }
    return ComparisonCounter;

}
