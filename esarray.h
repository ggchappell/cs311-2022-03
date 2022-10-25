// esarray.h  UNFINISHED
// VERSION 5
// Glenn G. Chappell
// Started: 2022-10-18
// Updated: 2022-10-25
//
// For CS 311 Fall 2022
// Header for class ESArray
// Extremely smart array of int
// Preliminary to Assignment 5

// History:
// - v1:
//   - Bare-bones only, does not compile. Header & source files,
//     #ifndef, #include, empty class definition.
// - v2:
//   - Add member types value_type, size_type, iterator, const_iterator.
//   - Add dummy versions (at least) of all member functions, including
//     dummy return statements for non-void functions. Package compiles.
//   - Add data members.
//   - Add class invariants.
//   - Write (untested versions of) the following member functions:
//     default ctor, ctor from size (these two are single func), dctor,
//     op[], size, empty, begin, end, push_back, pop_back.
// - v3:
//   - Document exception-safety guarantees for most functions.
//   - Write copy ctor.
// - v4:
//   - Revise class invariants to allow for _data being nullptr if _size
//     is zero.
//   - Revise ctor from size, copy ctor accordingly.
//   - Write move ctor.
//   - Mark various functions as noexcept.
// - v5:
//   - Move func defs to source file: copy & move ops, resize, insert,
//     erase, swap.

#ifndef FILE_ESARRAY_H_INCLUDED
#define FILE_ESARRAY_H_INCLUDED

#include <cstddef>
// For std::size_t


// *********************************************************************
// class ESArray - Class definition
// *********************************************************************


// class ESArray
// Extremely Smart Array of int.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     _size >= 0.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _size value_type values -- UNLESS
//      _size == 0, in which case _data may be nullptr.
class ESArray {

// ***** ESArray: types *****
public:

    // value_type: type of data items
    using value_type = int;

    // size_type: type of sizes & indices
    using size_type = std::size_t;

    // iterator, const_iterator: random-access iterator types
    using iterator = value_type *;
    using const_iterator = const value_type *;

// ***** ESArray: ctors, op=, dctor *****
public:

    // Default ctor & ctor from size
    // Strong Guarantee
    explicit ESArray(size_type size=0)
        :_size(size),
         _data(size == 0 ? nullptr
                         : new value_type[size])
    {}

    // Copy ctor
    // Strong Guarantee
    ESArray(const ESArray & other);

    // Move ctor
    // No-Throw Guarantee
    ESArray(ESArray && other) noexcept;

    // Copy assignment operator
    // ??? Guarantee
    ESArray & operator=(const ESArray & other);

    // Move assignment operator
    // No-Throw Guarantee
    ESArray & operator=(ESArray && other) noexcept;

    // Dctor
    // No-Throw Guarantee
    ~ESArray()
    {
        delete [] _data;
    }

// ***** ESArray: general public operators *****
public:

    // operator[] - non-const & const
    // Pre:
    //     ???
    // No-Throw Guarantee
    value_type & operator[](size_type index)
    {
        return _data[index];
    }
    const value_type & operator[](size_type index) const
    {
        return _data[index];
    }

// ***** ESArray: general public functions *****
public:

    // size
    // No-Throw Guarantee
    size_type size() const noexcept
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const noexcept
    {
        return size() == 0;
    }

    // begin - non-const & const
    // No-Throw Guarantee
    iterator begin() noexcept
    {
        return _data;
    }
    const_iterator begin() const noexcept
    {
        return _data;
    }

    // end - non-const & const
    // No-Throw Guarantee
    iterator end() noexcept
    {
        return begin() + size();
    }
    const_iterator end() const noexcept
    {
        return begin() + size();
    }

    // resize
    // ??? Guarantee
    void resize(size_type newsize);

    // insert
    // ??? Guarantee
    iterator insert(iterator pos,
                    const value_type & item);

    // erase
    // ??? Guarantee
    iterator erase(iterator pos);

    // push_back
    // ??? Guarantee
    void push_back(const value_type & item)
    {
        insert(end(), item);
    }

    // pop_back
    // ??? Guarantee
    void pop_back()
    {
        erase(end()-1);
    }

    // swap
    // No-Throw Guarantee
    void swap(ESArray & other) noexcept;

// ***** ESArray: data members *****
private:

    size_type    _size;  // Size of our array
    value_type * _data;  // Pointer to our array

};  // End class ESArray


#endif  //#ifndef FILE_ESARRAY_H_INCLUDED

