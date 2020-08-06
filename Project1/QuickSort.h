/**
 * \file QuickSort.h
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

#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_
#include <vector>
#include <fstream>

 /**
  * Swaps two integers together.
  * \param a integer
  * \param a integer
  */
void Swap(int* Int1, int* Int2);

/**
 * Partitions the vector. Establishing a pivot and sorting less than pivot to left and greater than pivot to right.
 * \param a vector of ints
 * \param int of Left position
  * \param int of Right position
 * \return int that represents Buffer for recursive quick sorting location.
 */
long long Partition(std::vector<int>& a, int& Left, int& Right);

/**
 * Quick Sort the vector recursively. Partitioning and switching vector when comparing sub vectors and their pivots.
 * Call upon itself to split a sub array before the pivot and after the pivot. Calculate number of key comparisons that happen
 * for quicksort. You add (size of sub vector - 1) each time a recursive call happens to calculate key comparisons.
 * \param a vector of ints
 * \param int of Left position
 * \param int of Right position
 * \return long long of key comarisons in quick sort.
 */
long long QuickSortHelper(std::vector<int>& a, int& Left, int& Right);

/*
 * side-effect: vector 'a' is sorted in non-decreasing order. Note: to prevent integer overflow, long long is used for counting number of comparisons.
 * \param: a vector of integers.
 * \return number of comparisons by QuickSort algorithm.
 * side-effect: vector 'a' is sorted in non-decreasing order. 
 *
*/
long long QuickSort(std::vector<int> & a); //do not change this line 



#endif

