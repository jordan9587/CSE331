/**
 * \file VerifySort.h
 *
 * \author Jordan Hybki
 *
 * Checks if vector is sorted or not. Holds the functions that sorts vector, using Insertion Sort Verify. Check equivelance between original vector a and sorted vector,
 * return 1 if equivalent, return 0 if false.
 *
 */

#ifndef _VERIFYSORT_H_
#define _VERIFYSORT_H_
#include <vector>
#include <fstream>
#include <iostream>
#include "VerifySort.h"	

/**
 * Checks if vector is sorted or not.
 * \param a vector of ints
 * \return true if 'a' is sorted in in non-decreasing order, and false otherwise.
 */
bool VerifySort(const std::vector<int> &a); //do not change this line

/**
 * Insertion Sort vector of int's. Side-effect: vector 'a' is sorted in non-decreasing order. Note: to prevent integer overflow, long long is used for
 * counting number of comparisons.
 * \param a vector of ints
 * \return vector of ints that is sorted in non descending order.
 */
void InsertionSortVerify(std::vector<int>& a);
//you can add helper functions here

#endif
