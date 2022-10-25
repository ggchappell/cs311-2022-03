// esarray.cpp  UNFINISHED
// VERSION 5
// Glenn G. Chappell
// Started: 2022-10-18
// Updated: 2022-10-25
//
// For CS 311 Fall 2022
// Source for class ESArray
// Extremely smart array of int
// Preliminary to Assignment 5


#include "esarray.h"  // For class ESArray definition
#include <algorithm>
using std::copy;


// *********************************************************************
// class ESArray - Member function definitions
// *********************************************************************


// Copy ctor
// See header for info.
ESArray::ESArray(const ESArray & other)
    :_size(other.size()),
     _data(other.size() == 0 ? nullptr
                             : new value_type[other.size()])
{
    copy(other.begin(), other.end(), begin());
    // The above call to std::copy does not throw, since it copies int
    // values. But if value_type is changed, then the call may throw, in
    // which case this copy ctor may need to be rewritten.
}


// Move ctor
// See header for info.
ESArray::ESArray(ESArray && other) noexcept
    :_size(other._size),
     _data(other._data)
{
    other._size = 0;
    other._data = nullptr;
}


// Copy assignment operator
// See header for info.
ESArray & ESArray::operator=(const ESArray & other)
{
    // TODO: WRITE THIS!!!
    return *this; // DUMMY
}


// Move assignment operator
// See header for info.
ESArray & ESArray::operator=(ESArray && other) noexcept
{
    // TODO: WRITE THIS!!!
    return *this; // DUMMY
}


// resize
// See header for info.
void ESArray::resize(ESArray::size_type newsize)
{
    // TODO: WRITE THIS!!!
}


// insert
// See header for info.
ESArray::iterator ESArray::insert(ESArray::iterator pos,
                                  const ESArray::value_type & item)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// erase
// See header for info.
ESArray::iterator ESArray::erase(ESArray::iterator pos)
{
    // TODO: WRITE THIS!!!
    return begin();  // DUMMY
}


// swap
// See header for info.
void ESArray::swap(ESArray & other) noexcept
{
    // TODO: WRITE THIS!!!
}

