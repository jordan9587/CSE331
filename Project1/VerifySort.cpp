/**
 * \file VerifySort.cpp
 *
 * \author Jordan Hybki
 *
 * Checks if vector is sorted or not. Holds the functions that sorts vector, using Insertion Sort Verify. Check equivelance between original vector a and sorted vector,
 * return 1 if equivalent, return 0 if false.
 *
 */

#include "VerifySort.h"	

using namespace std;

bool VerifySort(const vector<int> &a)
{
    // Since parameter is constant, make a copy of vector a by storing its contents into Sorted Vector.
    std::vector<int> SortedVector = a;
    // Sort vector by using Insertion Sort Verify function.
    InsertionSortVerify(SortedVector);
    // If there is a equivalent relation between SortedVector and vector a, return true.
    if (SortedVector == a)
    {
        return true;
    }
    else
    {
        // There is difference between vectors, return false.
        return false;
    }
}
/**
 * Insertion Sort vector of int's. Side-effect: vector 'a' is sorted in non-decreasing order. Note: to prevent integer overflow, long long is used for
 * counting number of comparisons.
 * \param a vector of ints
 * \return vector of ints that is sorted in non descending order.
 */
void InsertionSortVerify(std::vector<int>& a)
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


}