// da3.h  SKELETON
// Glenn G. Chappell
// 2022-09-22
//
// For CS 311 Fall 2022
// Header for Assignment 3 functions

#ifndef FILE_DA3_H_INCLUDED
#define FILE_DA3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function


template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    return ValueType();  // Dummy return
    // TODO: WRITE THIS!!!
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);


template <typename FDIter>
bool checkSorted(FDIter first,
                 FDIter last)
{
    return false;  // Dummy return
    // TODO: WRITE THIS!!!
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DA3_H_INCLUDED

