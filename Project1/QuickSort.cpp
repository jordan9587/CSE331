/**
 * \file QuickSort.cpp
 *
 * \author Jordan Hybki
 *
 * Holds the Quick Sort functions. Quick Sort chooses Pivot that is the last item in the sub vector. 
 * Create sub-vector of a that ensure if value is less than Pivot, swap it to before Pivot. When all items
 * are greater than come after the Pivot, swap it after Pivot. Call upon Quick Sort recursively to create
 * sub-vector of vector a between Left and Buffer - 1, and a sub-vector between Buffer + 1 and Right.
 * We ignore the Pivot as it is already in the correct position. Continue until each item is greater 
 * that the next until reaching the end of vector.
 *
 */

#include <iostream>
#include <vector>
#include "QuickSort.h"

using namespace std;


/**
 * Swaps two integers together.
 * \param a integer
 * \param a integer
 */
void Swap(int* Int1, int* Int2)
{
    int CopyInt1;
    // Males Copy of First integer input.
    CopyInt1 = *Int1;
    // Sets First integer input as Second integer input.
    *Int1 = *Int2;
    // Set Second integer input as Copy of First integer input.
    *Int2 = CopyInt1;
}

/**
 * Partitions the vector. Establishing a pivot and sorting less than pivot to left and greater than pivot to right
 * \param a vector of ints
 * \param int of Left position
  * \param int of Right position
 * \return int that represents Buffer for recursive quick sorting location.
 */
long long Partition(std::vector<int>& a, int& Left, int& Right)
{

    int Buffer = (Left - 1);

    // Store pivot as the Right most value in vector of int a.
    int Pivot = a[Right];

    for (int i = Left; i <= Right - 1; i+=1)
    {
        // Check if item less than pivot.
        if (a[i] < Pivot)
        {
            Buffer += 1;

            Swap(&a[Buffer], &a[i]);
        }
    }
    // Swap last Next item and right most item.
    Swap(&a[Buffer + 1], &a[Right]);

    return (Buffer + 1);
}

/**
 * Quick Sort the vector recursively. Partitioning and switching vector when comparing sub vectors and their pivots.
 * Call upon itself to split a sub array before the pivot and after the pivot. Calculate number of key comparisons that happen
 * for quicksort. You add (size of sub vector - 1) each time a recursive call happens to calculate key comparisons.
 * \param a vector of ints
 * \param int of Left position
 * \param int of Right position
 * \return long long of key comarisons in quick sort.
 */
long long QuickSortHelper(std::vector<int>& a, int& Left, int& Right)
{
    int Pivot = 0;

    long long ComparisonCounter = 0;

    if (Left < Right)
    {
        int Buffer = Partition(a, Left, Right);

        // All values Left of pivot will be sorted in this sub vector.
        int SubBuffer = Buffer - 1;

        QuickSortHelper(a, Left, SubBuffer);

        ComparisonCounter += (a.size() - 1);

        // All values Right of pivot will be sorted in this sub vector.
        SubBuffer = Buffer + 1;

        QuickSortHelper(a, SubBuffer, Right);

        ComparisonCounter += (a.size() - 1);
    }

    return ComparisonCounter;
}

/**
 * Calls upon quick sort helper function to do actual quick sort recursively, giving function Left position and most Right position
 * of vector a. Return what the quick sort helper gives this function, which is key comparison counter.
 * \param a vector of ints
 * \return long long of key comarisons in quick sort.
 */
long long QuickSort(std::vector<int>& a)
{
    // Instantiate Left and Right values for Quicksort.
    int Left = 0;

    int Right = (a.size() - 1);
    // Calls upon Quick Sorter Helper to calculate Comparison counter.
    long long ComparisonCounter = QuickSortHelper(a, Left, Right);

    return ComparisonCounter;
}
