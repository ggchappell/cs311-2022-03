// esarray_main2.cpp
// Glenn G. Chappell
// 2022-10-25
//
// For CS 311 Fall 2022
// Simple program using ESArray
// Requires esarray.h, esarray.cpp

#include "esarray.h"  // For class ESArray
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <iterator>
using std::begin;
using std::end;
#include <algorithm>
using std::sort;
#include <cassert>
// For assert


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Do some things with ESArray. Avoid assignment, resizing, swapping of
// ESArray values.
int main()
{
    const ESArray::size_type ASIZE = 20;  // Size of our array

    // Print intro message
    cout << "*** Using an ESArray ***\n";
    cout << "Size: " << ASIZE << "\n\n";

    // Create an ESArray and put some data in it.
    ESArray data(ASIZE);
    assert(data.size() == ASIZE);
    assert(!data.empty());
    for (ESArray::size_type i = 0; i < data.size(); ++i)
    {
        data[i] = 2*i < ASIZE ? 20*((ASIZE-1)/2-i) : 20*(ASIZE-1-i)+10;
    }

    // Print initial data
    cout << "Initial data:\n";
    for (auto n : data)  // Range-based for-loop!
    {
        cout << n << " ";
    }
    cout << "\n\n";

    // Sort data
    sort(begin(data), end(data));  // STL algorithm!

    // Print sorted data
    cout << "Sorted data:\n";
    for (auto n : data)  // Another range-based for-loop!
    {
        cout << n << " ";
    }
    cout << "\n" << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

